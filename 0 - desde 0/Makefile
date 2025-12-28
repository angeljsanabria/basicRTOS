PROJ = main
# CPU: cortex-m4 (hardware real) o cortex-m3 (para QEMU)
CPU ?= cortex-m3
# BOARD: mps2-an385 (solo M3) 
BOARD ?= mps2-an385

# Port de FreeRTOS: ARM_CM4F (M4 con FPU) o ARM_CM3 (M3)
# Se ajusta automaticamente segun CPU
ifeq ($(CPU),cortex-m4)
    FREERTOS_PORT = ARM_CM4F
    FPU_FLAGS = -mfpu=fpv4-sp-d16 -mfloat-abi=hard
else
    FREERTOS_PORT = ARM_CM3
    FPU_FLAGS =
endif

FREERTOS_PATH = ../FreeRTOS-Kernel

OBJ = boot.o \
      main.o \
      portFunctions.o \
      $(FREERTOS_PATH)/tasks.o \
      $(FREERTOS_PATH)/list.o \
      $(FREERTOS_PATH)/portable/MemMang/heap_4.o \
      $(FREERTOS_PATH)/portable/GCC/$(FREERTOS_PORT)/port.o

INC = -I$(FREERTOS_PATH)/portable/GCC/$(FREERTOS_PORT)/ \
      -I$(FREERTOS_PATH)/include/ \
      -I./ \
      -I.

CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
OBJDUMP = arm-none-eabi-objdump
GDB = arm-none-eabi-gdb

CFLAGS = -mcpu=$(CPU) \
         -mthumb \
         $(FPU_FLAGS) \
         -Wall \
         -O0 \
         -g \
         -ffreestanding \
         -fno-builtin \
         $(INC)

LDFLAGS = -mcpu=$(CPU) \
          -mthumb \
          $(FPU_FLAGS) \
          -Tstm32_flash.ld \
          -nostartfiles \
          -Wl,--gc-sections

.PHONY: all
all: $(PROJ).elf

$(PROJ).elf: $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $@
	$(OBJDUMP) -D $@ > $(PROJ).lst

boot.o: boot.c
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

portFunctions.o: portFunctions.c
	$(CC) $(CFLAGS) -c $< -o $@

$(FREERTOS_PATH)/tasks.o: $(FREERTOS_PATH)/tasks.c
	$(CC) $(CFLAGS) -c $< -o $@

$(FREERTOS_PATH)/list.o: $(FREERTOS_PATH)/list.c
	$(CC) $(CFLAGS) -c $< -o $@

$(FREERTOS_PATH)/portable/MemMang/heap_4.o: $(FREERTOS_PATH)/portable/MemMang/heap_4.c
	$(CC) $(CFLAGS) -c $< -o $@

$(FREERTOS_PATH)/portable/GCC/$(FREERTOS_PORT)/port.o: $(FREERTOS_PATH)/portable/GCC/$(FREERTOS_PORT)/port.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: run
run: $(PROJ).elf
	qemu-system-arm \
		-M $(BOARD) \
		-cpu $(CPU) \
		-nographic \
		-kernel $(PROJ).elf

.PHONY: debug
debug: $(PROJ).elf
	qemu-system-arm \
		-M $(BOARD) \
		-cpu $(CPU) \
		-nographic \
		-kernel $(PROJ).elf \
		-S -gdb tcp::1234

.PHONY: clean
clean:
	rm -f *.out *.elf .gdb_history *.lst *.debug *.o
	rm -f $(FREERTOS_PATH)/tasks.o \
	      $(FREERTOS_PATH)/list.o \
	      $(FREERTOS_PATH)/portable/MemMang/heap_4.o \
	      $(FREERTOS_PATH)/portable/GCC/$(FREERTOS_PORT)/port.o 2>/dev/null || true
