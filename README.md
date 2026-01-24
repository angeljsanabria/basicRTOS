# RTOS Basic - Curso Basico de RTOS

Este repositorio contiene ejemplos y proyectos para aprender RTOS (Real-Time Operating System).

## Estructura del Proyecto

### 0 - desde 0
Implementacion basica usando Makefile desde cero, sin IDE.
- Compilacion manual con Makefile
- FreeRTOS configurado manualmente
- Compatible con QEMU (desarrollo) y STM32L4R5ZI (hardware real)

### 1 - STM32 Cube IDE
Implementacion usando STM32CubeIDE (pendiente).

## Hardware

- **Placa de Desarrollo**: NUCLEO-L4R5ZI (STM32L4R5ZI)
- **Microcontrolador**: ARM Cortex-M4 con FPU
- **Flash**: 2 MB
- **RAM**: 640 KB

## Requisitos

### Para desarrollo en WSL/Linux:
- `gcc-arm-none-eabi`
- `qemu-system-arm`
- `gdb-multiarch`
- FreeRTOS-Kernel

### Instalacion:
```bash
sudo apt update
sudo apt install -y gcc-arm-none-eabi qemu-system-arm gdb-multiarch
```

## Compilar y Ejecutar

Ver README.md en cada carpeta para instrucciones especificas.

## Documentacion

- `MEMORY_MAP.md`: Mapa de memoria del STM32L4R5ZI
- `EJECUTAR_CODIGO.md`: Guia de ejecucion

