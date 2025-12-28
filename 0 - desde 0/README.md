# 0 - Desde Cero (Makefile + FreeRTOS)

Este directorio contiene la implementacion basica de FreeRTOS usando Makefile desde cero.

## Contenido

- **boot.c**: Codigo de inicializacion y vector de interrupciones
- **main.c**: Programa principal con tarea Hello World
- **portFunctions.c**: Funciones del port para FreeRTOS
- **FreeRTOSConfig.h**: Configuracion de FreeRTOS
- **stm32_flash.ld**: Linker script para STM32L4R5ZI / QEMU
- **Makefile**: Sistema de compilacion
- **EJECUTAR_CODIGO.md**: Guia de ejecucion
- **MEMORY_MAP.md**: Documentacion del mapa de memoria

## Compilar y Ejecutar

```bash
# Compilar
make clean
make

# Ejecutar en QEMU (Cortex-M3 por defecto)
make run

# Para hardware real (STM32L4R5ZI)
make CPU=cortex-m4 clean
make CPU=cortex-m4
```

## Dependencias

- FreeRTOS-Kernel debe estar en `../FreeRTOS-Kernel/`
- Herramientas: `gcc-arm-none-eabi`, `qemu-system-arm`, `gdb-multiarch`

