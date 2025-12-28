# Como Ejecutar el Codigo - Guia Paso a Paso

## Requisitos Previos

### 1. Verificar que tienes FreeRTOS

El Makefile espera FreeRTOS en el directorio padre:
```
../FreeRTOS-Kernel/
```

**Si no lo tienes:**

```bash
# Desde el directorio padre de rtos-basic
cd ..
git clone https://github.com/FreeRTOS/FreeRTOS-Kernel.git
cd FreeRTOS-Kernel
git checkout V10.5.1  # O la version que necesites
cd ../rtos-basic
```

**Verificar estructura:**
```bash
# En WSL, desde rtos-basic/
ls ../FreeRTOS-Kernel/portable/GCC/ARM_CM4F/port.c
ls ../FreeRTOS-Kernel/include/FreeRTOS.h
```

Si estos archivos existen, FreeRTOS esta instalado correctamente.

---

### 2. Verificar herramientas ARM instaladas

```bash
# En WSL
arm-none-eabi-gcc --version
qemu-system-arm --version
gdb-multiarch --version
```

**Si no estan instaladas:**
```bash
sudo apt update
sudo apt install -y gcc-arm-none-eabi qemu-system-arm gdb-multiarch
```

---

## Pasos para Ejecutar

### Paso 1: Limpiar compilaciones anteriores (opcional)

```bash
# En WSL, desde el directorio rtos-basic/
make clean
```

---

### Paso 2: Compilar el proyecto

```bash
make
```

**Que deberia pasar:**
- Compila todos los archivos .c a .o
- Enlaza todo en `main.elf`
- Genera `main.lst` (listado en ensamblador)

**Si hay errores:**
- Verifica que FreeRTOS esta en `../FreeRTOS-Kernel/`
- Verifica que el port `ARM_CM4F` existe en FreeRTOS
- Revisa los mensajes de error

---

### Paso 3: Ejecutar en QEMU

#### Opcion A: Ejecutar normalmente

```bash
make run
```

Esto iniciara QEMU y ejecutara el programa. Para salir de QEMU:
- Presiona `Ctrl+A`
- Luego presiona `X`

#### Opcion B: Ejecutar en modo debug

**Terminal 1:**
```bash
make debug
```
QEMU se quedara esperando la conexion de GDB.

**Terminal 2:**
```bash
arm-none-eabi-gdb main.elf
```

Dentro de GDB:
```gdb
(gdb) target remote :1234
(gdb) break main
(gdb) continue
(gdb) step
(gdb) quit
```

---

## Flujo Completo (Resumen)

```bash
# 1. Entrar a WSL y al directorio del proyecto
cd /mnt/c/code/rtos-basic

# 2. Verificar que FreeRTOS existe
ls ../FreeRTOS-Kernel/include/FreeRTOS.h

# 3. Limpiar (si es necesario)
make clean

# 4. Compilar
make

# 5. Ejecutar
make run
```

---

## Solucion de Problemas Comunes

### Error: "FreeRTOS-Kernel/portable/GCC/ARM_CM4F/port.c: No such file"

**Problema**: FreeRTOS no tiene el port ARM_CM4F, o esta en otra ubicacion.

**Solucion 1**: Verificar que existe el port:
```bash
ls ../FreeRTOS-Kernel/portable/GCC/ARM_CM4F/
```

**Solucion 2**: Si no existe ARM_CM4F, puedes usar ARM_CM4 (sin FPU):
- Modifica el Makefile cambiando `ARM_CM4F` por `ARM_CM4`
- Quita los flags `-mfpu=fpv4-sp-d16 -mfloat-abi=hard` del Makefile

**Solucion 3**: Descargar/clonar FreeRTOS completo:
```bash
cd ..
git clone https://github.com/FreeRTOS/FreeRTOS-Kernel.git
cd rtos-basic
```

---

### Error: "arm-none-eabi-gcc: command not found"

**Problema**: Las herramientas ARM no estan instaladas.

**Solucion**:
```bash
sudo apt update
sudo apt install -y gcc-arm-none-eabi qemu-system-arm gdb-multiarch
```

---

### Error: "qemu-system-arm: invalid option"

**Problema**: QEMU no soporta la placa `mps2-an385` o tiene version diferente.

**Solucion**: Verifica las placas disponibles:
```bash
qemu-system-arm -M help
```

Si `mps2-an385` no aparece, puedes usar otra placa que soporte Cortex-M4, o modificar el Makefile.

---

### Error de compilacion: "undefined reference"

**Problema**: Falta algun archivo fuente o hay error en el linker script.

**Solucion**:
1. Verifica que todos los archivos .c existen
2. Verifica que el linker script `stm32_flash.ld` esta en el directorio
3. Revisa los errores de linker para ver que simbolos faltan

---

### El programa compila pero no hace nada en QEMU

**Normal**: El `main.c` actual solo crea una tarea que hace delay. No hay salida visible porque no hay UART configurado.

**Para ver algo**:
- Usa `make debug` y conecta GDB para ver que el programa esta corriendo
- O agrega codigo para enviar mensajes por UART/serial

---

## Verificacion Rapida

Ejecuta este comando para verificar que todo esta listo:

```bash
# Script de verificacion rapida
echo "Verificando herramientas..."
arm-none-eabi-gcc --version > /dev/null 2>&1 && echo "✓ GCC ARM instalado" || echo "✗ GCC ARM NO instalado"
qemu-system-arm --version > /dev/null 2>&1 && echo "✓ QEMU instalado" || echo "✗ QEMU NO instalado"
[ -f "../FreeRTOS-Kernel/include/FreeRTOS.h" ] && echo "✓ FreeRTOS encontrado" || echo "✗ FreeRTOS NO encontrado"
[ -f "stm32_flash.ld" ] && echo "✓ Linker script existe" || echo "✗ Linker script NO existe"
[ -f "main.c" ] && echo "✓ main.c existe" || echo "✗ main.c NO existe"
[ -f "boot.c" ] && echo "✓ boot.c existe" || echo "✗ boot.c NO existe"
```

---

## Siguiente Paso

Una vez que compiles y ejecutes exitosamente, puedes:
1. Modificar `main.c` para agregar mas tareas
2. Configurar UART para ver salida del programa
3. Agregar mas funcionalidades a las tareas
4. Depurar con GDB para entender el comportamiento

