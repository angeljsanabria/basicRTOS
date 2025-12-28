# Mapa de Memoria - STM32L4R5ZI (NUCLEO-L4R5ZI)

## Especificaciones Generales

- **Microcontrolador**: STM32L4R5ZI
- **Arquitectura**: ARM Cortex-M4 con FPU
- **Frecuencia Maxima**: 120 MHz
- **Flash**: 2 MB
- **RAM**: 640 KB

## Importante: Mapeo de Memoria durante el Arranque

En STM32, hay una diferencia entre la **direccion fisica** de la Flash y como la **ve el CPU**:

- **Direccion Fisica de Flash**: 0x08000000 (donde realmente esta la memoria Flash)
- **Vista del CPU al arrancar**: 0x00000000 (el sistema hace remap automatico)

**Como funciona:**
1. El linker script usa **0x08000000** porque esa es la direccion fisica real de la Flash
2. Cuando el CPU arranca, busca el vector de interrupciones en **0x00000000**
3. El hardware de STM32 **remapea automaticamente** 0x00000000 -> 0x08000000
4. Por eso, aunque el programa este en 0x08000000, el CPU lo "ve" desde 0x00000000

**Para el linker script, SIEMPRE usamos 0x08000000** - es la direccion correcta donde se programa la Flash.

---

## Distribucion de Memoria Flash

| Direccion Inicio | Direccion Fin | Tamaño | Descripcion |
|------------------|---------------|--------|-------------|
| 0x0800 0000 | 0x081F FFFF | 2 MB | Flash principal (sector 0-7) |
| 0x1FFF 0000 | 0x1FFF 6FFF | 28 KB | System Memory (Bootloader) |
| 0x1FFF 7000 | 0x1FFF 77FF | 2 KB | Option Bytes |
| 0x1FFF 7800 | 0x1FFF FFFF | 34 KB | System Memory (continuacion) |

### Flash Principal (0x08000000 - 0x081FFFFF)

El programa se carga en la Flash principal. El vector de interrupciones se encuentra al inicio (0x08000000).

**Organizacion del programa en Flash:**

| Seccion | Ubicacion | Contenido |
|---------|-----------|-----------|
| .isr_vector | Inicio (0x08000000) | Vector de interrupciones |
| .text | Despues de .isr_vector | Codigo del programa |
| .rodata | Despues de .text | Constantes y strings |
| .data (LMA) | Despues de .rodata | Datos inicializados (antes de copiar a RAM) |

---

## Distribucion de Memoria RAM

| Direccion Inicio | Direccion Fin | Tamaño | Descripcion |
|------------------|---------------|--------|-------------|
| 0x2000 0000 | 0x2009 FFFF | 640 KB | SRAM principal |

### RAM Principal (0x20000000 - 0x2009FFFF)

**Organizacion de la RAM:**

| Seccion | Ubicacion | Contenido |
|---------|-----------|-----------|
| .data (VMA) | 0x20000000 | Datos inicializados (copiados de Flash) |
| .bss | Despues de .data | Variables no inicializadas (BSS) |
| Heap | Despues de .bss | Memoria dinamica (FreeRTOS heap) |
| Stack | 0x2009FFFF hacia abajo | Stack principal (MSP) |
| Stacks de Tareas | Heap/Stack | Stacks individuales de cada tarea (PSP) |

### Nota sobre Stack

- **MSP (Main Stack Pointer)**: Stack principal, usado por Handler Mode (interrupciones) y Thread Mode privilegiado.
  - Ubicacion: Final de RAM (0x2009FFFF hacia abajo)
  
- **PSP (Process Stack Pointer)**: Stack de proceso, usado por Thread Mode no privilegiado (tareas de usuario).
  - Ubicacion: Asignado dinamicamente por FreeRTOS para cada tarea

---

## Tabla de Mapeo Completa

```
┌─────────────────────────────────────────────────────────────┐
│                    MEMORIA FLASH (2 MB)                      │
├─────────────────────────────────────────────────────────────┤
│ 0x0800 0000 │ Vector de Interrupciones (.isr_vector)        │
│             │ Codigo del Programa (.text)                    │
│             │ Constantes (.rodata)                           │
│             │ Datos inicializados (LMA) (.data)              │
│ 0x081F FFFF │                                                │
├─────────────────────────────────────────────────────────────┤
│                    MEMORIA RAM (640 KB)                      │
├─────────────────────────────────────────────────────────────┤
│ 0x2000 0000 │ Datos inicializados (VMA) (.data)             │
│             │ Variables no inicializadas (.bss)              │
│             │ Heap (FreeRTOS)                                │
│             │ Stacks de Tareas (PSP)                         │
│             │                                                 │
│             │ ↑ Stack Principal (MSP)                        │
│ 0x2009 FFFF │ ↑ Top of Stack                                 │
└─────────────────────────────────────────────────────────────┘
```

---

## Tamaños Recomendados para FreeRTOS

### Stack de Tareas

- **Tarea minima (idle)**: 128 bytes (configMINIMAL_STACK_SIZE)
- **Tarea simple**: 256-512 bytes
- **Tarea con funciones complejas**: 1024+ bytes

### Heap de FreeRTOS

- **Heap minimo**: 4 KB (configTOTAL_HEAP_SIZE = 4096)
- **Recomendado para desarrollo**: 16-32 KB
- **Produccion**: Ajustar segun necesidades

### Ejemplo de Configuracion

```c
/* FreeRTOSConfig.h */
#define configMINIMAL_STACK_SIZE    ((uint16_t)128)
#define configTOTAL_HEAP_SIZE       ((size_t)(32*1024))  /* 32 KB */
```

Con esta configuracion:
- **Heap disponible**: ~32 KB
- **RAM restante**: ~608 KB para stacks y datos

---

## Perifericos (Memory Mapped)

| Direccion | Descripcion |
|-----------|-------------|
| 0x4000 0000 - 0x4001 FFFF | APB1 Peripherals |
| 0x4002 0000 - 0x4003 FFFF | APB2 Peripherals |
| 0x4002 0000 - 0x5003 FFFF | AHB1 Peripherals |
| 0x5000 0000 - 0x500F FFFF | AHB2 Peripherals |
| 0x6000 0000 - 0x600F FFFF | AHB3 Peripherals |

---

## Registros del Sistema

| Direccion | Registro | Descripcion |
|-----------|----------|-------------|
| 0xE000 E010 | SysTick CTRL | Control de SysTick |
| 0xE000 E014 | SysTick LOAD | Valor de recarga |
| 0xE000 E018 | SysTick VAL | Valor actual |
| 0xE000 ED00 | SCB | System Control Block |

---

## Notas Importantes

1. **Flash**: El programa debe empezar en 0x08000000 (vector de interrupciones).

2. **RAM**: Los datos se copian de Flash a RAM durante la inicializacion (Reset_Handler).

3. **Stack Overflow**: El stack principal (MSP) crece hacia direcciones menores. Si se desborda, puede corromper datos.

4. **Heap**: FreeRTOS gestiona el heap. El tamanio se define en `configTOTAL_HEAP_SIZE`.

5. **Stacks de Tareas**: Cada tarea tiene su propio stack. Si una tarea se desborda, solo afecta a esa tarea (si esta en modo no privilegiado).

---

## Referencias

- **Manual del Usuario STM32L4R5ZI**: RM0432
- **Datasheet STM32L4R5ZI**: DS11993
- **FreeRTOS Memory Management**: https://www.freertos.org/a00111.html

