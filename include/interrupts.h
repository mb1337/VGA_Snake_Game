#ifndef _INTERRUPTS_H_
#define _INTERRUPTS_H_


/* Interrupt handler prototype.  */
typedef void (* interrupt_t) (void);

/* Interrupt vectors as a struct.*/
struct interrupt_vectors
{
	interrupt_t res0_handler;        /* 0x80 */
	interrupt_t res1_handler;        /* 0x82 */
	interrupt_t res2_handler;        /* 0x84 */
	interrupt_t res3_handler;        /* 0x86 */
	interrupt_t res4_handler;        /* 0x88 */
	interrupt_t res5_handler;        /* 0x8a */
	interrupt_t pwm_shutdown_handler; /* 0x8c */
	interrupt_t ptpif_handler;
  
	/* ControllerAreaNetworking */
	interrupt_t can4_tx_handler;
	interrupt_t can4_rx_handler;
	interrupt_t can4_err_handler;
	interrupt_t can4_wake_handler;
	interrupt_t can3_tx_handler;
	interrupt_t can3_rx_handler;
	interrupt_t can3_err_handler;
	interrupt_t can3_wake_handler;
	interrupt_t can2_tx_handler;
	interrupt_t can2_rx_handler;
	interrupt_t can2_err_handler;
	interrupt_t can2_wake_handler;
	interrupt_t can1_tx_handler;
	interrupt_t can1_rx_handler;
	interrupt_t can1_err_handler;
	interrupt_t can1_wake_handler;
	interrupt_t can0_tx_handler;
	interrupt_t can0_rx_handler;
	interrupt_t can0_err_handler;
	interrupt_t can0_wake_handler;
  
	interrupt_t flash_handler;
	interrupt_t eeprom_handler;
	interrupt_t spi2_handler;
	interrupt_t spi1_handler;
	interrupt_t iic_handler;
	interrupt_t bdlc_handler;
	interrupt_t selfclk_mode_handler;
	interrupt_t pll_lock_handler;
	interrupt_t accb_overflow_handler;
	interrupt_t mccnt_underflow_handler;
	interrupt_t pthif_handler;
	interrupt_t ptjif_handler;
	interrupt_t atd1_handler;
	interrupt_t atd0_handler;
	interrupt_t sci1_handler;
	interrupt_t sci0_handler;
	interrupt_t spi0_handler;
  
	/* Timer and Accumulator */
	interrupt_t acca_input_handler;
	interrupt_t acca_overflow_handler;
	interrupt_t timer_overflow_handler;
  
	/* InputCapture/OutputCompare Timers */
	interrupt_t tc7_handler;
	interrupt_t tc6_handler;
	interrupt_t tc5_handler;
	interrupt_t tc4_handler;
	interrupt_t tc3_handler;
	interrupt_t tc2_handler;
	interrupt_t tc1_handler;
	interrupt_t tc0_handler;
  
	/* External Interrupts */
	interrupt_t rtii_handler;
	interrupt_t irq_handler;
	interrupt_t xirq_handler;

	/* Software Interrupt  */
	interrupt_t swi_handler;

	/* Illegal Instruction Reset  */
	interrupt_t illegal_handler;

	/* COP Timeout Reset  */
	interrupt_t cop_fail_handler;

	/* Clock Monitor Fail Reset  */
	interrupt_t cop_clock_handler;

	/* Start or Reset vector  */
	interrupt_t reset_handler;
};

typedef struct interrupt_vectors interrupt_vectors_t;


/* Interrupt vector id */
enum interrupt_vector_id
{
	RES0_VECTOR = 0,
	RES1_VECTOR,
	RES2_VECTOR,
	RES3_VECTOR,
	RES4_VECTOR,
	RES5_VECTOR,
	PWM_SHUTDOWN_VECTOR,
	PTPIF_VECTOR,
	CAN4_TX_VECTOR,
	CAN4_RX_VECTOR,
	CAN4_ERR_VECTOR,
	CAN4_WAKE_VECTOR,
	CAN3_TX_VECTOR,
	CAN3_RX_VECTOR,
	CAN3_ERR_VECTOR,
	CAN3_WAKE_VECTOR,
	CAN2_TX_VECTOR,
	CAN2_RX_VECTOR,
	CAN2_ERR_VECTOR,
	CAN2_WAKE_VECTOR,
	CAN1_TX_VECTOR,
	CAN1_RX_VECTOR,
	CAN1_ERR_VECTOR,
	CAN1_WAKE_VECTOR,
	CAN0_TX_VECTOR,
	CAN0_RX_VECTOR,
	CAN0_ERR_VECTOR,
	CAN0_WAKE_VECTOR,
	FLASH_VECTOR,
	EEPROM_VECTOR,
	SPI2_VECTOR,
	SPI1_VECTOR,
	IIC_VECTOR,
	BDLC_VECTOR,
	SELFCLK_MODE_VECTOR,
	PLL_LOCK_VECTOR,
	ACCB_OVERFLOW_VECTOR,
	MCCNT_UNDERFLOW_VECTOR,
	PTHIF_VECTOR,
	PTJIF_VECTOR,
	ATD1_VECTOR,
	ATD0_VECTOR,
	SCI1_VECTOR,
	SCI0_VECTOR,
	SPI0_VECTOR,
	ACCA_INPUT_VECTOR,
	ACCA_OVERFLOW_VECTOR,
	TIMER_OVERFLOW_VECTOR,
	TC7_VECTOR,
	TC6_VECTOR,
	TC5_VECTOR,
	TC4_VECTOR,
	TC3_VECTOR,
	TC2_VECTOR,
	TC1_VECTOR,
	TC0_VECTOR,
	RTI_VECTOR,
	IRQ_VECTOR,
	XIRQ_VECTOR,
	SWI_VECTOR,
	ILLEGAL_OPCODE_VECTOR,
	COP_FAIL_VECTOR,
	COP_CLOCK_VECTOR,
	RESET_VECTOR,
	MAX_VECTORS
};
typedef enum interrupt_vector_id interrupt_vector_id;


/* Interrupt vector table */
extern interrupt_t _vectors_addr[MAX_VECTORS];
extern interrupt_vectors_t _vectors __asm__("_vectors_addr");



/* 
 * Install an interrupt handler.
 * Install the interrupt handler for an exception. 
 * The handler is installed for bootstrap mode and also for normal operating mode.
 * 
 * id: the interrupt number to be installed
 * handler: the interrupt handler entry point
 */
extern void set_interrupt_handler (interrupt_vector_id id, interrupt_t handler);


/* 
 * Default and fatal interrupt handler.
 * 
 * This function is an interrupt handler intended to be used to handle 
 * all interrupt not used by a program.  Since it is an error to 
 * have an interrupt when it is not handled, the default
 * behavior is to print a message and stop.
 */
extern void __attribute__((interrupt, noreturn)) fatal_interrupt (void);


/**
 * By defualt we use it!
 */
#define USE_INTERRUPT_TABLE

/* Only for RAM target. Initializes an interrupt handler vector. */
extern inline void set_interrupt_handler (interrupt_vector_id id ATTR_UNUSED, interrupt_t handler ATTR_UNUSED)
{
  _vectors_addr[id] = handler;
}



/* 
 * Entry point of any program.
 * 
 * This function should never be called by itself.  It represents the entry 
 * point of any program.  It is intended to be used in an interrupt table to 
 * specify the function to jump to after reset.
 */
extern void _start (void);

#endif /* ifndef _INTERRUPTS_H_ */
