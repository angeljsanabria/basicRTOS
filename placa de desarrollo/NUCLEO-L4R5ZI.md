# NUCLEO-L4R5ZI - Placa de Desarrollo

## Informacion General

- **Modelo**: NUCLEO-L4R5ZI
- **Fabricante**: STMicroelectronics
- **Microcontrolador**: STM32L4R5ZI

---

## Arquitectura del Microcontrolador STM32L4R5ZI

### Nucleo
- **Arquitectura**: ARM Cortex-M4
- **FPU**: Si (Floating Point Unit)
- **Frecuencia Maxima**: 120 MHz
- **Tipo FPU**: Single Precision (FPv4-SP-D16)

### Caracteristicas
- Arquitectura de 32 bits
- Set de instrucciones Thumb-2
- Pipeline de 3 etapas

**Nota**: Para mas detalles, consultar el manual de referencia RM0432.

---

## Memoria

### Flash
- **Tamaño**: 2 MB (2048 KB)
- **Direccion Inicio**: 0x08000000
- **Direccion Fin**: 0x081FFFFF
- **Tipo**: Memoria Flash no volatil
- **Organizacion**: Paginas/Sectores (consultar datasheet para detalles)

### RAM (SRAM)
- **Tamaño**: 640 KB
- **Direccion Inicio**: 0x20000000
- **Direccion Fin**: 0x2009FFFF
- **Tipo**: SRAM estatica

### Otras Memorias
- **System Memory (Bootloader)**: 0x1FFF0000 - 0x1FFFFFFF
- **Option Bytes**: Configuracion del sistema

**Para Linker Script (.ld)**:
```ld
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 2048K
    RAM (xrw)   : ORIGIN = 0x20000000, LENGTH = 640K
}
```

Stack Pointer inicial recomendado: 0x2009FFFF (final de RAM)

---

## Pinout y Conexiones

### IMPORTANTE: Verificar Documentacion Oficial

**NOTA**: El pinout exacto de la placa NUCLEO-L4R5ZI debe verificarse en la documentacion oficial. La siguiente es informacion general de las placas NUCLEO.

### Pines Pre-conectados en NUCLEO (General)

#### ST-LINK (Programador/Debugger integrado)
- Los pines del ST-LINK estan conectados internamente
- No usar estos pines para otros propositos si se usa el ST-LINK

#### LED de Usuario
- LED1 (verde): Generalmente conectado a un pin GPIO
- LED2 (amarillo/rojo): Para indicacion

#### Boton de Usuario
- B1 (User Button): Generalmente conectado a un pin GPIO con pull-up

#### Pines ARDUINO R3
- Las placas NUCLEO tienen headers compatibles con Arduino R3
- Algunos pines estan duplicados en los headers

### Pines Libres
- **TODOS los otros pines GPIO** estan disponibles en los headers
- Consultar el schematic oficial para ver cuales pines estan realmente libres

---

## Documentacion Oficial (Links para Verificar)

### Manuales de Referencia
- **RM0432**: Manual de referencia del STM32L4 Series (incluye L4R5ZI)
  - URL: https://www.st.com/resource/en/reference_manual/rm0432-stm32l4-series-advanced-armbased-32bit-mcus-stmicroelectronics.pdf

### Datasheet
- **DS11993**: Datasheet del STM32L4R5ZI
  - URL: https://www.st.com/en/microcontrollers-microprocessors/stm32l4r5zi.html
  - Buscar "DS11993" en la pagina del producto

### Documentacion de la Placa NUCLEO-L4R5ZI
- **User Manual**: Manual de usuario de la placa NUCLEO-L4R5ZI
  - URL: https://www.st.com/en/evaluation-tools/nucleo-l4r5zi.html
  - Descargar "User manual" y "Data brief" desde la pagina del producto

### Schematics
- **Schematic**: Diagrama esquematico de la placa
  - Disponible en la pagina del producto NUCLEO-L4R5ZI
  - Seccion "Design Resources" -> "Schematic pack"

---

## Notas Importantes

1. **Este documento es BASICO y debe mejorarse** con informacion de la documentacion oficial
2. **NO se debe confiar** en informacion de pinout sin verificar el schematic oficial
3. **Consultar siempre** la documentacion oficial antes de usar pines especificos
4. **El pinout exacto** varia entre versiones de la placa (verificar revision)

---

## Tareas Pendientes

- [ ] Verificar pinout exacto desde schematic oficial
- [ ] Identificar pines realmente libres vs pre-conectados
- [ ] Documentar LEDs y botones especificos de esta placa
- [ ] Documentar conexiones del ST-LINK integrado
- [ ] Agregar tabla completa de pinout
- [ ] Documentar perifericos pre-conectados (si los hay)

---

## Actualizaciones

**Fecha creacion**: 27/12/2025
**Ultima actualizacion**: 27/12/2025
**Version**: 0.1 (Basico - Requiere verificacion)

