#include <stdint.h>

/* Vector de interrupciones */
extern uint32_t _estack;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

/* Prototipos de funciones */
void Reset_Handler(void);
void Default_Handler(void);
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));

/* Vector de interrupciones */
__attribute__((section(".isr_vector")))
const void *vector_table[] = {
    &_estack,              /* Stack pointer inicial */
    Reset_Handler,         /* Reset Handler */
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,                     /* Reservado */
    0,                     /* Reservado */
    0,                     /* Reservado */
    0,                     /* Reservado */
    SVC_Handler,
    DebugMon_Handler,
    0,                     /* Reservado */
    PendSV_Handler,
    SysTick_Handler
};

/* Handler de Reset */
void Reset_Handler(void)
{
    /* Copiar datos inicializados de Flash a RAM */
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;
    
    while(dst < &_edata)
    {
        *dst++ = *src++;
    }

    /* Limpiar BSS (poner en cero) */
    dst = &_sbss;
    while(dst < &_ebss)
    {
        *dst++ = 0;
    }

    /* Llamar a main */
    extern int main(void);
    main();

    /* Si main retorna (no deberia), quedamos aqui */
    while(1);
}

/* Handler por defecto para interrupciones no manejadas */
void Default_Handler(void)
{
    while(1);
}

