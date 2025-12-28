/* Linker script para STM32L4R5ZI (NUCLEO-L4R5ZI) o QEMU mps2-an385 */
/* Para STM32L4R5ZI: Flash: 2MB (0x08000000), RAM: 640KB (0x20000000) */
/* Para QEMU mps2-an385: Flash: 16MB (0x00000000), RAM: 8MB (0x20000000) */
/* Usamos direcciones compatibles con QEMU para desarrollo */

ENTRY(Reset_Handler)

/* Stack pointer inicial (final de RAM) */
_estack = 0x20020000;

/* Tamaños minimos para heap y stack */
_Min_Heap_Size = 0x200;
_Min_Stack_Size = 0x400;

/* Definicion de memorias */
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 512K
    RAM (xrw)   : ORIGIN = 0x20000000, LENGTH = 512K
}

/* Secciones */
SECTIONS
{
    /* Vector de interrupciones al inicio de Flash */
    .isr_vector :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        . = ALIGN(4);
    } >FLASH

    /* Codigo del programa */
    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text*)
        *(.glue_7)
        *(.glue_7t)
        *(.eh_frame)
        
        KEEP(*(.init))
        KEEP(*(.fini))
        
        . = ALIGN(4);
        _etext = .;
    } >FLASH

    /* Constantes de solo lectura */
    .rodata :
    {
        . = ALIGN(4);
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
    } >FLASH

    /* Tablas de excepciones ARM */
    .ARM.extab :
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } >FLASH

    .ARM :
    {
        __exidx_start = .;
        *(.ARM.exidx*)
        __exidx_end = .;
    } >FLASH

    /* Arrays de inicializacion y finalizacion */
    .preinit_array :
    {
        PROVIDE_HIDDEN(__preinit_array_start = .);
        KEEP(*(.preinit_array*))
        PROVIDE_HIDDEN(__preinit_array_end = .);
    } >FLASH

    .init_array :
    {
        PROVIDE_HIDDEN(__init_array_start = .);
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array*))
        PROVIDE_HIDDEN(__init_array_end = .);
    } >FLASH

    .fini_array :
    {
        PROVIDE_HIDDEN(__fini_array_start = .);
        KEEP(*(SORT(.fini_array.*)))
        KEEP(*(.fini_array*))
        PROVIDE_HIDDEN(__fini_array_end = .);
    } >FLASH

    /* Datos inicializados (LMA = Load Memory Address en Flash) */
    /* _sidata apunta a donde estan los datos inicializados en Flash */
    _sidata = .;

    .data : AT(_sidata)
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } >RAM

    /* Datos no inicializados (BSS) */
    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        __bss_start__ = _sbss;
        *(.bss)
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
        __bss_end__ = _ebss;
    } >RAM

    /* Heap y Stack del usuario */
    ._user_heap_stack :
    {
        . = ALIGN(8);
        PROVIDE(end = .);
        PROVIDE(_end = .);
        . = . + _Min_Heap_Size;
        . = . + _Min_Stack_Size;
        . = ALIGN(8);
    } >RAM

    /* Remover informacion de librerias estandar */
    /DISCARD/ :
    {
        libc.a(*)
        libm.a(*)
        libgcc.a(*)
    }

    .ARM.attributes 0 : { *(.ARM.attributes) }
}
