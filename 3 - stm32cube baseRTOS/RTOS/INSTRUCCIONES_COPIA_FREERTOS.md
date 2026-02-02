# Instrucciones para Copiar Archivos de FreeRTOS

## Archivos a Copiar

### 1. Archivos Fuente Principales (.c)
Desde: `FreeRTOS-Kernel/`
Hacia: `RTOS/FreeRTOS/Source/`

- `tasks.c`
- `queue.c`
- `list.c`
- `timers.c`
- `event_groups.c`
- `stream_buffer.c`

### 2. Port ARM_CM4F
Desde: `FreeRTOS-Kernel/portable/GCC/ARM_CM4F/`
Hacia: `RTOS/FreeRTOS/Source/portable/GCC/ARM_CM4F/`

- `port.c` (ya tienes `portmacro.h` copiado)

### 3. Heap Manager
Desde: `FreeRTOS-Kernel/portable/MemMang/`
Hacia: `RTOS/FreeRTOS/Source/portable/MemMang/`

- `heap_4.c`

### 4. Headers (.h)
Desde: `FreeRTOS-Kernel/include/`
Hacia: `RTOS/FreeRTOS/include/`

**Copiar TODOS los archivos .h:**
- `FreeRTOS.h`
- `task.h`
- `queue.h`
- `semphr.h`
- `timers.h`
- `event_groups.h`
- `stream_buffer.h`
- `list.h`
- `projdefs.h`
- `portable.h`
- `stack_macros.h`
- `StackMacros.h`
- `message_buffer.h`
- `croutine.h`
- `mpu_wrappers.h`
- `mpu_prototypes.h`
- `deprecated_definitions.h`
- `atomic.h`
- Y cualquier otro .h que esté en el directorio

## Método Recomendado

1. **Desde el Explorador de Windows:**
   - Abre ambas carpetas lado a lado
   - Selecciona los archivos y arrastra/copia

2. **Desde STM32CubeIDE:**
   - Click derecho en la carpeta destino
   - Paste (si ya copiaste desde el explorador)

## Verificación

Después de copiar, verifica que tengas:

```
RTOS/FreeRTOS/
├── Source/
│   ├── tasks.c ✓
│   ├── queue.c ✓
│   ├── list.c ✓
│   ├── timers.c ✓
│   ├── event_groups.c ✓
│   ├── stream_buffer.c ✓
│   └── portable/
│       ├── GCC/ARM_CM4F/
│       │   ├── port.c ✓
│       │   └── portmacro.h ✓
│       └── MemMang/
│           └── heap_4.c ✓
├── include/
│   └── [todos los .h] ✓
└── Config/
    └── FreeRTOSConfig.h (se creará después)
```
