; ************************************************************************
; Prepared by Dr. Han-Way Huang
; Date: 12/31/2004
; HC12SDP256 I/O register locations
; HCS12 peripheral bits definitions
; D-Bug12 I/O functions calling address
; D-Bug12 SRAM interrupt vector table
; Flash and EEPROM commands
; ************************************************************************

.equ PORTA,0   	; port a = address lines a8 - a15
.equ PTA,0	; alternate name for PORTA
.equ PORTB,1   	; port b = address lines a0 - a7
.equ PTB,1	; alternate name for PORTB
.equ DDRA,2   	; port a direction register
.equ DDRB,3   	; port a direction register

.equ PORTE,8   	; port e = mode,irqandcontrolsignals
.equ PTE,8	; alternate name for PORTE
.equ DDRE,9   	; port e direction register
.equ PEAR,0xa  	; port e assignments
.equ MODE,0xb  	; mode register
.equ PUCR,0xc  	; port pull-up control register
.equ RDRIV,0xd  	; port reduced drive control register
.equ EBICTL,0xe  	; e stretch control

.equ INITRM,0x10 	; ram location register
.equ INITRG,0x11 	; register location register
.equ INITEE,0x12 	; eeprom location register
.equ MISC,0x13 	; miscellaneous mapping control
.equ MTST0,0x14 	; reserved
.equ ITCR,0x15 	; interrupt test control register
.equ ITEST,0x16 	; interrupt test register
.equ MTST1,0x17 	; reserved

.equ PARTIDH,0x1a 	; part id high
.equ PARTIDL,0x1b 	; part id low
.equ MEMSIZ0,0x1c 	; memory size
.equ MEMSIZ1,0x1d 	; memory size
.equ INTCR,0x1e 	; interrupt control register
.equ IRQCR,0x1e	; interrupt control register
.equ HPRIO,0x1f 	; high priority reg

.equ BKPCT0,0x28 	; break control register
.equ BKPCT1,0x29 	; break control register
.equ BKP0X,0x2a 	; break 0 index register
.equ BKP0H,0x2b 	; break 0 pointer high
.equ BRP0L,0x2c 	; break 0 pointer low
.equ BKP1X,0x2d	; break 1 index register
.equ BKP1H,0x2e	; break 1 pointer high
.equ BRP1L,0x2f	; break 1 pointer low
.equ PPAGE,0x30 	; program page register

.equ PORTK,0x32 	; port k data
.equ PTK,0x32	; alternate name for PORTK
.equ DDRK,0x33 	; port k direction
.equ SYNR,0x34 	; synthesizer / multiplier register
.equ REFDV,0x35 	; reference divider register
.equ CTFLG,0x36 	; reserved
.equ CRGFLG,0x37 	; pll flags register
.equ CRGINT,0x38 	; pll interrupt register
.equ CLKSEL,0x39 	; clock select register
.equ PLLCTL,0x3a 	; pll control register
.equ RTICTL,0x3b 	; real time interrupt control
.equ COPCTL,0x3c 	; watchdog control
.equ FORBYP,0x3d 	;
.equ CTCTL,0x3e 	;
.equ ARMCOP,0x3f 	; cop reset register

.equ TIOS,0x40 	; timer input/output select
.equ CFORC,0x41 	; timer compare force
.equ OC7M,0x42 	; timer output compare 7 mask
.equ OC7D,0x43 	; timer output compare 7 data
.equ TCNT,0x44 	; timer counter register hi
.equ TSCR1,0x46 	; timer system control register
.equ TSCR,0x46	; 
.equ TTOV,0x47 	; reserved
.equ TCTL1,0x48 	; timer control register 1
.equ TCTL2,0x49 	; timer control register 2
.equ TCTL3,0x4a 	; timer control register 3
.equ TCTL4,0x4b 	; timer control register 4
.equ TMSK1,0x4c 	; timer interrupt mask 1
.equ TIE,0x4C	; 
.equ TSCR2,0x4d 	; timer system control register 2
.equ TFLG1,0x4e 	; timer flags 1
.equ TFLG2,0x4f 	; timer flags 2
.equ TC0,0x50 	; timer capture/compare register 0
.equ TC1,0x52 	; timer capture/compare register 1
.equ TC2,0x54 	; timer capture/compare register 2
.equ TC3,0x56 	; timer capture/compare register 3
.equ TC4,0x58 	; timer capture/compare register 4
.equ TC5,0x5a 	; timer capture/compare register 5
.equ TC6,0x5c 	; timer capture/compare register 6
.equ TC7,0x5e 	; timer capture/compare register 7
.equ PACTL,0x60 	; pulse accumulator controls
.equ PAFLG,0x61 	; pulse accumulator flags
.equ PACNT,0x62	; pulse accumulator A counter
.equ PACN3,0x62 	; pulse accumulator counter 3
.equ PACN2,0x63 	; pulse accumulator counter 2
.equ PBCNT,0x64	; pulse accumulator B counter 
.equ PACN1,0x64 	; pulse accumulator counter 1
.equ PACN0,0x65 	; pulse accumulator counter 0
.equ MCCTL,0x66 	; modulus down conunter control
.equ MCFLG,0x67 	; down counter flags
.equ ICPAR,0x68 	; input pulse accumulator control
.equ DLYCT,0x69 	; delay count to down counter
.equ ICOVW,0x6a 	; input control overwrite register
.equ ICSYS,0x6b 	; input control system control

.equ TIMTST,0x6d 	; timer test register

.equ PBCTL,0x70 	; pulse accumulator b control
.equ PBFLG,0x71 	; pulse accumulator b flags
.equ PA3H,0x72 	; pulse accumulator holding register 3
.equ PA2H,0x73 	; pulse accumulator holding register 2
.equ PA1H,0x74 	; pulse accumulator holding register 1
.equ PA0H,0x75 	; pulse accumulator holding register 0
.equ MCCNT,0x76 	; modulus down counter register
*MCCNTL	equ 	0x77 	; low byte
.equ TCOH,0x78 	; capture 0 holding register
.equ TC1H,0x7a 	; capture 1 holding register
.equ TC2H,0x7c 	; capture 2 holding register
.equ TC3H,0x7e 	; capture 3 holding register

.equ ATD0CTL0,0x80 	; adc control 0 (reserved)
.equ ATD0CTL1,0x81 	; adc control 1 (reserved)
.equ ATD0CTL2,0x82 	; adc control 2
.equ ATD0CTL3,0x83 	; adc control 3
.equ ATD0CTL4,0x84 	; adc control 4
.equ ATD0CTL5,0x85 	; adc control 5
.equ ATD0STAT0,0x86 	; adc status register 0
.equ ATD0TEST0,0x88 	; adc test 0(reserved)
.equ ATD0TEST1,0x89 	; adc test 1(reserved)

.equ ATD0DIEN,0x8d 	; adc0 input enable register
.equ PORTAD0,0x8f 	; port adc = input only
.equ PTAD0,0x8F
.equ ATD0DR0,0x90 	; adc result 0 register
.equ ATD0DR1,0x92 	; adc result 1 register
.equ ATD0DR2,0x94 	; adc result 2 register
.equ ATD0DR3,0x96 	; adc result 3 register
.equ ATD0DR4,0x98 	; adc result 4 register
.equ ATD0DR5,0x9a 	; adc result 5 register
.equ ATD0DR6,0x9c 	; adc result 6 register
.equ ATD0DR7,0x9e 	; adc result 7 register

.equ PWME,0xa0 	; pwm enable
.equ PWMPOL,0xa1 	; pwm polarity
.equ PWMCLK,0xa2 	; pwm clock select register
.equ PWMPRCLK,0xa3 	; pwm prescale clock select register
.equ PWMCAE,0xa4 	; pwm center align select register
.equ PWMCTL,0xa5 	; pwm control register
.equ PWMTST,0xa6 	; reserved
.equ PWMPRSC,0xa7 	; reserved
.equ PWMSCLA,0xa8 	; pwm scale a
.equ PWMSCLB,0xa9 	; pwm scale b
.equ PWMSCNTA,0xaa 	; reserved
.equ PWMSCNTB,0xab 	; reserved
.equ PWMCNT0,0xac 	; pwm channel 0 counter
.equ PWMCNT1,0xad 	; pwm channel 1 counter
.equ PWMCNT2,0xae 	; pwm channel 2 counter
.equ PWMCNT3,0xaf 	; pwm channel 3 counter


.equ PWMCNT4,0xb0 	; pwm channel 4 COUNTER
.equ PWMCNT5,0xb1 	; pwm channel 5 counter
.equ PWMCNT6,0xb2 	; pwm channel 6 counter
.equ PWMCNT7,0xb3 	; pwm channel 7 counter
.equ PWMPER0,0xb4 	; pwm channel 0 period
.equ PWMPER1,0xb5 	; pwm channel 1 period
.equ PWMPER2,0xb6 	; pwm channel 2 period
.equ PWMPER3,0xb7 	; pwm channel 3 period
.equ PWMPER4,0xb8 	; pwm channel 4 period
.equ PWMPER5,0xb9 	; pwm channel 5 period
.equ PWMPER6,0xba 	; pwm channel 6 period
.equ PWMPER7,0xbb 	; pwm channel 7 period
.equ PWMDTY0,0xbc 	; pwm channel 0 duty cycle
.equ PWMDTY1,0xbd 	; pwm channel 1 duty cycle
.equ PWMDTY2,0xbe 	; pwm channel 2 duty cycle
.equ PWMDTY3,0xbf 	; pwm channel 3 duty cycle
.equ PWMDTY4,0xc0 	; pwm channel 0 duty cycle
.equ PWMDTY5,0xc1 	; pwm channel 1 duty cycle
.equ PWMDTY6,0xc2 	; pwm channel 2 duty cycle
.equ PWMDTY7,0xc3 	; pwm channel 3 duty cycle
.equ PWMSDN,0xc4 	; pwm shutdown register

.equ SCI0BDH,0xc8 	; sci 0 baud reg hi byte
.equ SCI0BDL,0xc9 	; sci 0 baud reg lo byte
.equ SCI0CR1,0xca 	; sci 0 control1 reg
.equ SCI0CR2,0xcb 	; sci 0 status reg 1
.equ SCI0SR1,0xcc	; sci 0 status reg 1
.equ SCI0SR2,0xcd 	; sci 0 status reg 2
.equ SCI0DRH,0xce 	; sci 0 data reg hi
.equ SCI0DRL,0xcf 	; sci 0 data reg lo
.equ SCI1BDH,0xd0 	; sci 1 baud reg hi byte
.equ SCI1BDL,0xd1 	; sci 1 baud reg lo byte
.equ SCI1CR1,0xd2 	; sci 1 control1 reg
.equ SCI1CR2,0xd3 	; sci 1 control2 reg
.equ SCI1SR1,0xd4 	; sci 1 status reg 1
.equ SCI1SR2,0xd5 	; sci 1 status reg 2
.equ SCI1DRH,0xd6 	; sci 1 data reg lo
.equ SPI0CR1,0xd8 	; spi 0 control1 reg
.equ SPI0CR2,0xd9 	; spi 0 control2 reg
.equ SPI0BR,0xda 	; spi 0 baud reg
.equ SPI0SR,0xdb 	; spi 0 status reg hi

.equ SPI0DR,0xdd 	; spi 0 data reg

.equ IBAD,0xe0 	; i2c bus address register
.equ IBFD,0xe1 	; i2c bus frequency divider
.equ IBCR,0xe2 	; i2c bus control register
.equ IBSR,0xe3 	; i2c bus status register
.equ IBDR,0xe4 	; i2c bus message data register

.equ DLCBCR1,0xe8 	; bdlc control register 1
.equ DLCBSVR,0xe9 	; bdlc state vector register
.equ DLCBCR2,0xea 	; bdlc control register 2
.equ DLCBDR,0xeb 	; bdlc data register
.equ DLCBARD,0xec 	; bdlc analog delay register
.equ DLCBRSR,0xed 	; bdlc rate select register
.equ DLCSCR,0xee 	; bdlc control register
.equ DLCBSTAT,0xef 	; bdlc status register
.equ SPI1CR1,0xf0 	; spi 1 control1 reg
.equ SPI1CR2,0xf1 	; spi 1 control2 reg
.equ SPI1BR,0xf2 	; spi 1 baud reg
.equ SPI1SR,0xf3 	; spi 1 status reg hi

.equ SP1DR,0xf5 	; spi 1 data reg

.equ SPI2CR1,0xf8 	; spi 2 control1 reg
.equ SPI2CR2,0xf9 	; spi 2 control2 reg
.equ SPI2BR,0xfa 	; spi 2 baud reg
.equ SPI2SR,0xfb 	; spi 2 status reg hi

.equ SP2DR,0xfd 	; spi 2 data reg

.equ FCLKDIV,0x100 	; flash clock divider
.equ FSEC,0x101 	; flash security register
.equ FTSTMOD,0x102
.equ FCNFG,0x103 	; flash configuration register
.equ FPROT,0x104 	; flash protection register
.equ FSTAT,0x105 	; flash status register
.equ FCMD,0x106 	; flash command register
.equ FADDR,0x108	; 16-bit address register
.equ FDATA,0x10A	; 16-bit data register

.equ ECLKDIV,0x110 	; eeprom clock divider
.equ ECNFG,0x113 	; eeprom configuration register
.equ EPROT,0x114 	; eeprom protection register
.equ ESTAT,0x115 	; eeprom status register
.equ ECMD,0x116 	; eeprom command register

.equ ATD1CTL0,0x120 	; adc1 control 0 (reserved)
.equ ATD1CTL1,0x121 	; adc1 control 1 (reserved)
.equ ATD1CTL2,0x122 	; adc1 control 2
.equ ATD1CTL3,0x123 	; adc1 control 3
.equ ATD1CTL4,0x124 	; adc1 control 4
.equ ATD1CTL5,0x125 	; adc1 control 5
.equ ATD1STAT0,0x126 	; adc1 status register
.equ ATD1TEST0,0x128 	; adc1 test register 0 (reserved)
.equ ATD1TEST1,0x129 	; adc1 test register 1 (reserved)
.equ ATD1STAT1,0x12B
.equ ATD1DIEN,0x12d 	; adc1 input enable register

.equ PORTAD1,0x12f 	; port adc1 = input only
.equ PTAD1,0x12F
.equ ATD1DR0,0x130 	; adc1 result 0 register
.equ ATD1DR1,0x132 	; adc1 result 1 register
.equ ATD1DR2,0x134 	; adc1 result 2 register
.equ ATD1DR3,0x136 	; adc1 result 3 register
.equ ATD1DR4,0x138 	; adc1 result 4 register
.equ ATD1DR5,0x13a 	; adc1 result 5 register
.equ ATD1DR6,0x13c 	; adc1 result 6 register
.equ ATD1DR7,0x13e 	; adc1 result 7 register
.equ CAN0CTL0,0x140 	; can0 control register 0
.equ CAN0CTL1,0x141 	; can0 control register 1
.equ CAN0BTR0,0x142 	; can0 bus timing register 0
.equ CAN0BTR1,0x143 	; can0 bus timing register 1
.equ CAN0RFLG,0x144 	; can0 receiver flags
.equ CAN0RIER,0x145 	; can0 receiver interrupt enables
.equ CAN0TFLG,0x146 	; can0 transmit flags
.equ CAN0TIER,0x147 	; can0 transmit interrupt enables
.equ CAN0TARQ,0x148 	; can0 transmit message abort control
.equ CAN0TAAK,0x149 	; can0 transmit message abort status
.equ CAN0TBSEL,0x14a 	; can0 transmit buffer select
.equ CAN0IDAC,0x14b	; can0 identifier acceptance control

.equ CAN0RXERR,0x14e	; can0 receive error counter
.equ CAN0TXERR,0x14f  	; can0 transmit error counter
.equ CAN0IDAR0,0x150 	; can0 identifier acceptance register 0
.equ CAN0IDAR1,0x151 	; can0 identifier acceptance register 1
.equ CAN0IDAR2,0x152 	; can0 identifier acceptance register 2
.equ CAN0IDAR3,0x153 	; can0 identifier acceptance register 3
.equ CAN0IDMR0,0x154 	; can0 identifier mask register 0
.equ CAN0IDMR1,0x155 	; can0 identifier mask register 1
.equ CAN0IDMR2,0x156 	; can0 identifier mask register 2
.equ CAN0IDMR3,0x157 	; can0 identifier mask register 3
.equ CAN0IDAR4,0x158 	; can0 identifier acceptance register 4
.equ CAN0IDAR5,0x159 	; can0 identifier acceptance register 5
.equ CAN0IDAR6,0x15a 	; can0 identifier acceptance register 6
.equ CAN0IDAR7,0x15b 	; can0 identifier acceptance register 7
.equ CAN0IDMR4,0x15c 	; can0 identifier mask register 4
.equ CAN0IDMR5,0x15d 	; can0 identifier mask register 5
.equ CAN0IDMR6,0x15e 	; can0 identifier mask register 6
.equ CAN0IDMR7,0x15f 	; can0 identifier mask register 7
.equ CAN0RXFG,0x160 	; can0 rx foreground buffer thru +0x16f
.equ CAN0RIDR0,0x160	; CAN0 rx foreground buffer identifier register 0
.equ CAN0RIDR1,0x161	; CAN0 rx foreground buffer identifier register 1
.equ CAN0RIDR2,0x162	; CAN0 rx foreground buffer identifier register 2
.equ CAN0RIDR3,0x163	; CAN0 rx foreground buffer identifier register 3
.equ CAN0RDSR0,0x164	; CAN0 rx foreground buffer data segment register 0
.equ CAN0RDSR1,0x165	; CAN0 rx foreground buffer data segment register 1
.equ CAN0RDSR2,0x166	; CAN0 rx foreground buffer data segment register 2
.equ CAN0RDSR3,0x167	; CAN0 rx foreground buffer data segment register 3
.equ CAN0RDSR4,0x168	; CAN0 rx foreground buffer data segment register 4
.equ CAN0RDSR5,0x169	; CAN0 rx foreground buffer data segment register 5
.equ CAN0RDSR6,0x16A	; CAN0 rx foreground buffer data segment register 6
.equ CAN0RDSR7,0x16B	; CAN0 rx foreground buffer data segment register 7
.equ CAN0RDLR,0x16C	; CAN0 rx foreground buffer data length register
.equ CAN0TXFG,0x170 	; can0 tx foreground buffer thru +0x17f
.equ CAN0TIDR0,0x170	; CAN0 tx foreground buffer identifier register 0
.equ CAN0TIDR1,0x171	; CAN0 tx foreground buffer identifier register 1
.equ CAN0TIDR2,0x172	; CAN0 tx foreground buffer identifier register 2
.equ CAN0TIDR3,0x173	; CAN0 tx foreground buffer identifier register 3
.equ CAN0TDSR0,0x174	; CAN0 tx foreground buffer data segment register 0
.equ CAN0TDSR1,0x175	; CAN0 tx foreground buffer data segment register 1
.equ CAN0TDSR2,0x176	; CAN0 tx foreground buffer data segment register 2
.equ CAN0TDSR3,0x177	; CAN0 tx foreground buffer data segment register 3
.equ CAN0TDSR4,0x178	; CAN0 tx foreground buffer data segment register 4
.equ CAN0TDSR5,0x179	; CAN0 tx foreground buffer data segment register 5
.equ CAN0TDSR6,0x17A	; CAN0 tx foreground buffer data segment register 6
.equ CAN0TDSR7,0x17B	; CAN0 tx foreground buffer data segment register 7
.equ CAN0TDLR,0x17C	; CAN0 tx foreground buffer data length register
.equ CAN0TBPR,0x17D	; CAN0 tx foreground buffer transmit buffer priority register
.equ CAN0TSRH,0x17E	; CAN0 tx foreground buffer transmit time stamp register high
.equ CAN0TSRL,0x17F	; CAN0 tx foreground buffer transmit time stamp register low

.equ CAN1CTL0,0x180 	; can1 control register 0
.equ CAN1CTL1,0x181 	; can1 control register 1
.equ CAN1BTR0,0x182 	; can1 bus timing register 0
.equ CAN1BTR1,0x183 	; can1 bus timing register 1
.equ CAN1RFLG,0x184 	; can1 receiver flags
.equ CAN1RIER,0x185 	; can1 receiver interrupt enables
.equ CAN1TFLG,0x186 	; can1 transmit flags
.equ CAN1TIER,0x187 	; can1 transmit interrupt enables
.equ CAN1TARQ,0x188 	; can1 transmit message abort control
.equ CAN1TAAK,0x189 	; can1 transmit message abort status
.equ CAN1TBSEL,0x18a 	; can1 transmit buffer select
.equ CAN1IDAC,0x18b 	; can1 identifier acceptance control

.equ CAN1RXERR,0x18e 	; can1 receive error counter
.equ CAN1TXERR,0x18f 	; can1 transmit error counter
.equ CAN1IDAR0,0x190 	; can1 identifier acceptance register 0
.equ CAN1IDAR1,0x191 	; can1 identifier acceptance register 1
.equ CAN1IDAR2,0x192 	; can1 identifier acceptance register 2
.equ CAN1IDAR3,0x193 	; can1 identifier acceptance register 3
.equ CAN1IDMR0,0x194 	; can1 identifier mask register 0
.equ CAN1IDMR1,0x195 	; can1 identifier mask register 1
.equ CAN1IDMR2,0x196 	; can1 identifier mask register 2
.equ CAN1IDMR3,0x197 	; can1 identifier mask register 3
.equ CAN1IDAR4,0x198 	; can1 identifier acceptance register 4
.equ CAN1IDAR5,0x199 	; can1 identifier acceptance register 5
.equ CAN1IDAR6,0x19a 	; can1 identifier acceptance register 6
.equ CAN1IDAR7,0x19b 	; can1 identifier acceptance register 7
.equ CAN1IDMR4,0x19c 	; can1 identifier mask register 4
.equ CAN1IDMR5,0x19d 	; can1 identifier mask register 5
.equ CAN1IDMR6,0x19e 	; can1 identifier mask register 6
.equ CAN1IDMR7,0x19f 	; can1 identifier mask register 7
.equ CAN1RXFG,0x1a0 	; can1 rx foreground buffer thru +0x1af
.equ CAN1RIDR0,0x1a0	; CAN1 rx foreground buffer identifier register 0
.equ CAN1RIDR1,0x1a1	; CAN1 rx foreground buffer identifier register 1
.equ CAN1RIDR2,0x1a2	; CAN1 rx foreground buffer identifier register 2
.equ CAN1RIDR3,0x1a3	; CAN1 rx foreground buffer identifier register 3
.equ CAN1RDSR0,0x1a4	; CAN1 rx foreground buffer data segment register 0
.equ CAN1RDSR1,0x1a5	; CAN1 rx foreground buffer data segment register 1
.equ CAN1RDSR2,0x1a6	; CAN1 rx foreground buffer data segment register 2
.equ CAN1RDSR3,0x1a7	; CAN1 rx foreground buffer data segment register 3
.equ CAN1RDSR4,0x1a8	; CAN1 rx foreground buffer data segment register 4
.equ CAN1RDSR5,0x169	; CAN1 rx foreground buffer data segment register 5
.equ CAN1RDSR6,0x1aA	; CAN1 rx foreground buffer data segment register 6
.equ CAN1RDSR7,0x1aB	; CAN1 rx foreground buffer data segment register 7
.equ CAN1RDLR,0x1aC	; CAN1 rx foreground buffer data length register
.equ CAN1TXFG,0x1b0 	; can1 tx foreground buffer thru +0x1bf
.equ CAN1TIDR0,0x1b0	; CAN1 tx foreground buffer identifier register 0
.equ CAN1TIDR1,0x1b1	; CAN1 tx foreground buffer identifier register 1
.equ CAN1TIDR2,0x1b2	; CAN1 tx foreground buffer identifier register 2
.equ CAN1TIDR3,0x1b3	; CAN1 tx foreground buffer identifier register 3
.equ CAN1TDSR0,0x1b4	; CAN1 tx foreground buffer data segment register 0
.equ CAN1TDSR1,0x1b5	; CAN1 tx foreground buffer data segment register 1
.equ CAN1TDSR2,0x1b6	; CAN1 tx foreground buffer data segment register 2
.equ CAN1TDSR3,0x1b7	; CAN1 tx foreground buffer data segment register 3
.equ CAN1TDSR4,0x1b8	; CAN1 tx foreground buffer data segment register 4
.equ CAN1TDSR5,0x1b9	; CAN1 tx foreground buffer data segment register 5
.equ CAN1TDSR6,0x1bA	; CAN1 tx foreground buffer data segment register 6
.equ CAN1TDSR7,0x1bB	; CAN1 tx foreground buffer data segment register 7
.equ CAN1TDLR,0x1bC	; CAN1 tx foreground buffer data length register
.equ CAN1TBPR,0x1bD	; CAN1 tx foreground buffer transmit buffer priority register
.equ CAN1TSRH,0x1bE	; CAN1 tx foreground buffer transmit time stamp register high
.equ CAN1TSRL,0x1bF	; CAN1 tx foreground buffer transmit time stamp register low

.equ CAN2CTL0,0x1c0 	; can2 control register 0
.equ CAN2CTL1,0x1c1 	; can2 control register 1
.equ CAN2BTR0,0x1c2 	; can2 bus timing register 0
.equ CAN2BTR1,0x1c3 	; can2 bus timing register 1
.equ CAN2RFLG,0x1c4 	; can2 receiver flags
.equ CAN2RIER,0x1c5 	; can2 receiver interrupt enables
.equ CAN2TFLG,0x1c6 	; can2 transmit flags
.equ CAN2TIER,0x1c7 	; can2 transmit interrupt enables
.equ CAN2TARQ,0x1c8 	; can2 transmit message abort control
.equ CAN2TAAK,0x1c9 	; can2 transmit message abort status
.equ CAN2TBSEL,0x1ca 	; can2 transmit buffer select
.equ CAN2IDAC,0x1cb 	; can2 identifier acceptance control

.equ CAN2RXERR,0x1ce 	; can2 receive error counter
.equ CAN2TXERR,0x1cf 	; can2 transmit error counter
.equ CAN2IDAR0,0x1d0 	; can2 identifier acceptance register 0
.equ CAN2IDAR1,0x1d1 	; can2 identifier acceptance register 1
.equ CAN2IDAR2,0x1d2 	; can2 identifier acceptance register 2
.equ CAN2IDAR3,0x1d3 	; can2 identifier acceptance register 3
.equ CAN2IDMR0,0x1d4 	; can2 identifier mask register 0
.equ CAN2IDMR1,0x1d5 	; can2 identifier mask register 1
.equ CAN2IDMR2,0x1d6 	; can2 identifier mask register 2
.equ CAN2IDMR3,0x1d7 	; can2 identifier mask register 3
.equ CAN2IDAR4,0x1d8 	; can2 identifier acceptance register 4
.equ CAN2IDAR5,0x1d9 	; can2 identifier acceptance register 5
.equ CAN2IDAR6,0x1da 	; can2 identifier acceptance register 6
.equ CAN2IDAR7,0x1db 	; can2 identifier acceptance register 7
.equ CAN2IDMR4,0x1dc 	; can2 identifier mask register 4
.equ CAN2IDMR5,0x1dd 	; can2 identifier mask register 5
.equ CAN2IDMR6,0x1de 	; can2 identifier mask register 6
.equ CAN2IDMR7,0x1df 	; can2 identifier mask register 7
.equ CAN2RXFG,0x1e0 	; can2 rx foreground buffer thru +0x1ef
.equ CAN2RIDR0,0x1e0	; CAN2 rx foreground buffer identifier register 0
.equ CAN2RIDR1,0x1e1	; CAN2 rx foreground buffer identifier register 1
.equ CAN2RIDR2,0x1e2	; CAN2 rx foreground buffer identifier register 2
.equ CAN2RIDR3,0x1e3	; CAN2 rx foreground buffer identifier register 3
.equ CAN2RDSR0,0x1e4	; CAN2 rx foreground buffer data segment register 0
.equ CAN2RDSR1,0x1e5	; CAN2 rx foreground buffer data segment register 1
.equ CAN2RDSR2,0x1e6	; CAN2 rx foreground buffer data segment register 2
.equ CAN2RDSR3,0x1e7	; CAN2 rx foreground buffer data segment register 3
.equ CAN2RDSR4,0x1e8	; CAN2 rx foreground buffer data segment register 4
.equ CAN2RDSR5,0x1e9	; CAN2 rx foreground buffer data segment register 5
.equ CAN2RDSR6,0x1eA	; CAN2 rx foreground buffer data segment register 6
.equ CAN2RDSR7,0x1eB	; CAN2 rx foreground buffer data segment register 7
.equ CAN2RDLR,0x1eC	; CAN2 rx foreground buffer data length register
.equ CAN2TXFG,0x1f0 	; can2 tx foreground buffer thru +0x1ff
.equ CAN2TIDR0,0x1f0	; CAN2 tx foreground buffer identifier register 0
.equ CAN2TIDR1,0x1f1	; CAN2 tx foreground buffer identifier register 1
.equ CAN2TIDR2,0x1f2	; CAN2 tx foreground buffer identifier register 2
.equ CAN2TIDR3,0x1f3	; CAN2 tx foreground buffer identifier register 3
.equ CAN2TDSR0,0x1f4	; CAN2 tx foreground buffer data segment register 0
.equ CAN2TDSR1,0x1f5	; CAN2 tx foreground buffer data segment register 1
.equ CAN2TDSR2,0x1f6	; CAN2 tx foreground buffer data segment register 2
.equ CAN2TDSR3,0x1f7	; CAN2 tx foreground buffer data segment register 3
.equ CAN2TDSR4,0x1f8	; CAN2 tx foreground buffer data segment register 4
.equ CAN2TDSR5,0x1f9	; CAN2 tx foreground buffer data segment register 5
.equ CAN2TDSR6,0x1fA	; CAN2 tx foreground buffer data segment register 6
.equ CAN2TDSR7,0x1fB	; CAN2 tx foreground buffer data segment register 7
.equ CAN2TDLR,0x1fC	; CAN2 tx foreground buffer data length register
.equ CAN2TBPR,0x1fD	; CAN2 tx foreground buffer transmit buffer priority register
.equ CAN2TSRH,0x1fE	; CAN2 tx foreground buffer transmit time stamp register high
.equ CAN2TSRL,0x1fF	; CAN2 tx foreground buffer transmit time stamp register low

.equ CAN3CTL0,0x200 	; can3 control register 0
.equ CAN3CTL1,0x201 	; can3 control register 1
.equ CAN3BTR0,0x202 	; can3 bus timing register 0
.equ CAN3BTR1,0x203 	; can3 bus timing register 1
.equ CAN3RFLG,0x204 	; can3 receiver flags
.equ CAN3RIER,0x205 	; can3 receiver interrupt enables
.equ CAN3TFLG,0x206 	; can3 transmit flags
.equ CAN3TIER,0x207 	; can3 transmit interrupt enables
.equ CAN3TARQ,0x208 	; can3 transmit message abort control
.equ CAN3TAAK,0x209 	; can3 transmit message abort status
.equ CAN3TBSEL,0x20a 	; can3 transmit buffer select
.equ CAN3IDAC,0x20b 	; can3 identifier acceptance control

.equ CAN3RXERR,0x20e 	; can3 receive error counter
.equ CAN3TXERR,0x20f 	; can3 transmit error counter
.equ CAN3IDAR0,0x210 	; can3 identifier acceptance register 0
.equ CAN3IDAR1,0x211 	; can3 identifier acceptance register 1
.equ CAN3IDAR2,0x212 	; can3 identifier acceptance register 2
.equ CAN3IDAR3,0x213 	; can3 identifier acceptance register 3
.equ CAN3IDMR0,0x214 	; can3 identifier mask register 0
.equ CAN3IDMR1,0x215 	; can3 identifier mask register 1
.equ CAN3IDMR2,0x216 	; can3 identifier mask register 2
.equ CAN3IDMR3,0x217 	; can3 identifier mask register 3
.equ CAN3IDAR4,0x218 	; can3 identifier acceptance register 4
.equ CAN3IDAR5,0x219 	; can3 identifier acceptance register 5
.equ CAN3IDAR6,0x21a 	; can3 identifier acceptance register 6
.equ CAN3IDAR7,0x21b 	; can3 identifier acceptance register 7
.equ CAN3IDMR4,0x21c 	; can3 identifier mask register 4
.equ CAN3IDMR5,0x21d 	; can3 identifier mask register 5
.equ CAN3IDMR6,0x21e 	; can3 identifier mask register 6
.equ CAN3IDMR7,0x21f 	; can3 identifier mask register 7
.equ CAN3RXFG,0x220 	; can3 rx foreground buffer thru +0x22f
.equ CAN3RIDR0,0x220	; CAN3 rx foreground buffer identifier register 0
.equ CAN3RIDR1,0x221	; CAN3 rx foreground buffer identifier register 1
.equ CAN3RIDR2,0x222	; CAN3 rx foreground buffer identifier register 2
.equ CAN3RIDR3,0x223	; CAN3 rx foreground buffer identifier register 3
.equ CAN3RDSR0,0x224	; CAN3 rx foreground buffer data segment register 0
.equ CAN3RDSR1,0x225	; CAN3 rx foreground buffer data segment register 1
.equ CAN3RDSR2,0x226	; CAN3 rx foreground buffer data segment register 2
.equ CAN3RDSR3,0x227	; CAN3 rx foreground buffer data segment register 3
.equ CAN3RDSR4,0x228	; CAN3 rx foreground buffer data segment register 4
.equ CAN3RDSR5,0x229	; CAN3 rx foreground buffer data segment register 5
.equ CAN3RDSR6,0x22A	; CAN3 rx foreground buffer data segment register 6
.equ CAN3RDSR7,0x22B	; CAN3 rx foreground buffer data segment register 7
.equ CAN3RDLR,0x22C	; CAN3 rx foreground buffer data length register
.equ CAN3TXFG,0x230 	; can3 tx foreground buffer thru +0x23f
.equ CAN3TIDR0,0x230	; CAN3 tx foreground buffer identifier register 0
.equ CAN3TIDR1,0x231	; CAN3 tx foreground buffer identifier register 1
.equ CAN3TIDR2,0x232	; CAN3 tx foreground buffer identifier register 2
.equ CAN3TIDR3,0x233	; CAN3 tx foreground buffer identifier register 3
.equ CAN3TDSR0,0x234	; CAN3 tx foreground buffer data segment register 0
.equ CAN3TDSR1,0x235	; CAN3 tx foreground buffer data segment register 1
.equ CAN3TDSR2,0x236	; CAN3 tx foreground buffer data segment register 2
.equ CAN3TDSR3,0x237	; CAN3 tx foreground buffer data segment register 3
.equ CAN3TDSR4,0x238	; CAN3 tx foreground buffer data segment register 4
.equ CAN3TDSR5,0x239	; CAN3 tx foreground buffer data segment register 5
.equ CAN3TDSR6,0x23A	; CAN3 tx foreground buffer data segment register 6
.equ CAN3TDSR7,0x23B	; CAN3 tx foreground buffer data segment register 7
.equ CAN3TDLR,0x23C	; CAN3 tx foreground buffer data length register
.equ CAN3TBPR,0x23D	; CAN3 tx foreground buffer transmit buffer priority register
.equ CAN3TSRH,0x23E	; CAN3 tx foreground buffer transmit time stamp register high
.equ CAN3TSRL,0x23F	; CAN3 tx foreground buffer transmit time stamp register low

.equ PTT,0x240 	; portt data register
.equ PTIT,0x241 	; portt input register
.equ DDRT,0x242 	; portt direction register
.equ RDRT,0x243 	; portt reduced drive register
.equ PERT,0x244 	; portt pull device enable
.equ PPST,0x245 	; portt pull polarity select

.equ PTS,0x248 	; ports data register
.equ PTIS,0x249 	; ports input register
.equ DDRS,0x24a 	; ports direction register
.equ RDRS,0x24b 	; ports reduced drive register
.equ PERS,0x24c 	; ports pull device enable
.equ PPSS,0x24d 	; ports pull polarity select
.equ WOMS,0x24e 	; ports wired or mode register

.equ PTM,0x250 	; portm data register
.equ PTIM,0x251 	; portm input register
.equ DDRM,0x252 	; portm direction register
.equ RDRM,0x253 	; portm reduced drive register
.equ PERM,0x254 	; portm pull device enable
.equ PPSM,0x255 	; portm pull polarity select
.equ WOMM,0x256 	; portm wired or mode register
.equ MODRR,0x257 	; portm module routing register
.equ PTP,0x258 	; portp data register
.equ PTIP,0x259 	; portp input register
.equ DDRP,0x25a 	; portp direction register
.equ RDRP,0x25b 	; portp reduced drive register
.equ PERP,0x25c 	; portp pull device enable
.equ PPSP,0x25d 	; portp pull polarity select
.equ PIEP,0x25e 	; portp interrupt enable register
.equ PIFP,0x25f 	; portp interrupt flag register
.equ PTH,0x260 	; porth data register
.equ PTIH,0x261 	; porth input register
.equ DDRH,0x262 	; porth direction register
.equ RDRH,0x263 	; porth reduced drive register
.equ PERH,0x264 	; porth pull device enable
.equ PPSH,0x265 	; porth pull polarity select
.equ PIEH,0x266 	; porth interrupt enable register
.equ PIFH,0x267 	; porth interrupt flag register
.equ PTJ,0x268 	; portp data register
.equ PTIJ,0x269 	; portp input register
.equ DDRJ,0x26a 	; portp direction register
.equ RDRJ,0x26b 	; portp reduced drive register
.equ PERJ,0x26c 	; portp pull device enable
.equ PPSJ,0x26d 	; portp pull polarity select
.equ PIEJ,0x26e 	; portp interrupt enable register
.equ PIFJ,0x26f 	; portp interrupt flag register

.equ CAN4CTL0,0x280 	; can4 control register 0
.equ CAN4CTL1,0x281 	; can4 control register 1
.equ CAN4BTR0,0x282 	; can4 bus timing register 0
.equ CAN4BTR1,0x283 	; can4 bus timing register 1
.equ CAN4RFLG,0x284 	; can4 receiver flags
.equ CAN4RIER,0x285 	; can4 receiver interrupt enables
.equ CAN4TFLG,0x286 	; can4 transmit flags
.equ CAN4TIER,0x287 	; can4 transmit interrupt enables
.equ CAN4TARQ,0x288 	; can4 transmit message abort control
.equ CAN4TAAK,0x289 	; can4 transmit message abort status
.equ CAN4TBSEL,0x28a 	; can4 transmit buffer select
.equ CAN4IDAC,0x28b 	; can4 identifier acceptance control

.equ CAN4RXERR,0x28e 	; can4 receive error counter
.equ CAN4TXERR,0x28f 	; can4 transmit error counter
.equ CAN4IDAR0,0x290 	; can4 identifier acceptance register 0
.equ CAN4IDAR1,0x291 	; can4 identifier acceptance register 1
.equ CAN4IDAR2,0x292 	; can4 identifier acceptance register 2
.equ CAN4IDAR3,0x293 	; can4 identifier acceptance register 3
.equ CAN4IDMR0,0x294 	; can4 identifier mask register 0
.equ CAN4IDMR1,0x295 	; can4 identifier mask register 1
.equ CAN4IDMR2,0x296 	; can4 identifier mask register 2
.equ CAN4IDMR3,0x297 	; can4 identifier mask register 3
.equ CAN4IDAR4,0x298 	; can4 identifier acceptance register 4
.equ CAN4IDAR5,0x299 	; can4 identifier acceptance register 5
.equ CAN4IDAR6,0x29a 	; can4 identifier acceptance register 6
.equ CAN4IDAR7,0x29b 	; can4 identifier acceptance register 7
.equ CAN4IDMR4,0x29c 	; can4 identifier mask register 4
.equ CAN4IDMR5,0x29d 	; can4 identifier mask register 5
.equ CAN4IDMR6,0x29e 	; can4 identifier mask register 6
.equ CAN4IDMR7,0x29f 	; can4 identifier mask register 7
.equ CAN4RXFG,0x2a0 	; can4 rx foreground buffer thru +0x2af
.equ CAN4RIDR0,0x2a0	; CAN4 rx foreground buffer identifier register 0
.equ CAN4RIDR1,0x2a1	; CAN4 rx foreground buffer identifier register 1
.equ CAN4RIDR2,0x2a2	; CAN4 rx foreground buffer identifier register 2
.equ CAN4RIDR3,0x2a3	; CAN4 rx foreground buffer identifier register 3
.equ CAN4RDSR0,0x2a4	; CAN4 rx foreground buffer data segment register 0
.equ CAN4RDSR1,0x2a5	; CAN4 rx foreground buffer data segment register 1
.equ CAN4RDSR2,0x2a6	; CAN4 rx foreground buffer data segment register 2
.equ CAN4RDSR3,0x2a7	; CAN4 rx foreground buffer data segment register 3
.equ CAN4RDSR4,0x2a8	; CAN4 rx foreground buffer data segment register 4
.equ CAN4RDSR5,0x2a9	; CAN4 rx foreground buffer data segment register 5
.equ CAN4RDSR6,0x2aA	; CAN4 rx foreground buffer data segment register 6
.equ CAN4RDSR7,0x2aB	; CAN4 rx foreground buffer data segment register 7
.equ CAN4RDLR,0x2aC	; CAN4 rx foreground buffer data length register
.equ CAN4TXFG,0x2b0 	; can4 tx foreground buffer thru +0x2bf
.equ CAN4TIDR0,0x2b0	; CAN4 tx foreground buffer identifier register 0
.equ CAN4TIDR1,0x2b1	; CAN4 tx foreground buffer identifier register 1
.equ CAN4TIDR2,0x2b2	; CAN4 tx foreground buffer identifier register 2
.equ CAN4TIDR3,0x2b3	; CAN4 tx foreground buffer identifier register 3
.equ CAN4TDSR0,0x2b4	; CAN4 tx foreground buffer data segment register 0
.equ CAN4TDSR1,0x2b5	; CAN4 tx foreground buffer data segment register 1
.equ CAN4TDSR2,0x2b6	; CAN4 tx foreground buffer data segment register 2
.equ CAN4TDSR3,0x2b7	; CAN4 tx foreground buffer data segment register 3
.equ CAN4TDSR4,0x2b8	; CAN4 tx foreground buffer data segment register 4
.equ CAN4TDSR5,0x2b9	; CAN4 tx foreground buffer data segment register 5
.equ CAN4TDSR6,0x2bA	; CAN4 tx foreground buffer data segment register 6
.equ CAN4TDSR7,0x2bB	; CAN4 tx foreground buffer data segment register 7
.equ CAN4TDLR,0x2bC	; CAN4 tx foreground buffer data length register
.equ CAN4TBPR,0x2bD	; CAN4 tx foreground buffer transmit buffer priority register
.equ CAN4TSRH,0x2bE	; CAN4 tx foreground buffer transmit time stamp register high
.equ CAN4TSRL,0x2bF	; CAN4 tx foreground buffer transmit time stamp register low
* end of register definitions
; *************************************************************************************
; flash and EEPROM memory command
; *************************************************************************************
.equ Program,0x20		; program a flash or EEPROM word
.equ EraseVerify,0x05		; Erase and verify flash and EEPROM, BLANK bit will be set
.equ SectorErase,0x40		; Erase a sector of flash or EEPROM
.equ BulkErase,0x41		; Bulk erase the flash or EEPROM
.equ SectorModify,0x60		; Erase a sector (4 bytes), program a word (2 bytes)
; *************************************************************************************
; definitions of bits
; *************************************************************************************
.equ BIT7,0x80
.equ BIT6,0x40
.equ BIT5,0x20
.equ BIT4,0x10
.equ BIT3,0x08
.equ BIT2,0x04
.equ BIT1,0x02
.equ BIT0,0x01
.equ NOACCE,0x80
.equ PIPOE,0x20
.equ NECLK,0x10
.equ LSTRE,0x08
.equ RDWE,0x04
.equ MODC,0x80
.equ MODB,0x40
.equ MODA,0x20
.equ IVIS,0x08
.equ EMK,0x02
.equ EME,0x01
.equ PUPKE,0x80
.equ PUPEE,0x10
.equ PUPBE,0x02
.equ PUPAE,0x01
.equ RDPK,0x80
.equ RDPE,0x10
.equ RDPB,0x02
.equ RDPA,0x01
.equ ESTR,0x01
.equ EXSTR1,0x08
.equ EXSTR0,0x04
.equ ROMHM,0x02
.equ ROMON,0x01
.equ WRINT,0x10
.equ INTE,0x80
.equ INTC,0x40
.equ INTA,0x20
.equ INT8,0x10
.equ INT6,0x08
.equ INT4,0x04
.equ INT2,0x02
.equ INT0,0x01
.equ IRQE,0x80
.equ IRQEN,0x40
.equ BKEN,0x80
.equ BKFULL,0x40
.equ BKBDM,0x20
.equ BKTAG,0x10
.equ BK0RWE,0x08
.equ BK0RW,0x04
.equ BK1RWE,0x02
.equ BK1RW,0x01
.equ RTIF,0x80
.equ PROF,0x40
.equ LOCKIF,0x10
.equ LOCK,0x08
.equ TRACK,0x04
.equ SCMIF,0x02
.equ SCM,0x01
.equ RTIE,0x80
.equ LOCKIE,0x10
.equ SCMIE,0x02
.equ PLLSEL,0x80
.equ PSTP,0x40
.equ SYSWAI,0x20
.equ ROAWAI,0x10
.equ PLLWAI,0x08
.equ CWAI,0x04
.equ RTIWAI,0x02
.equ COPWAI,0x01
.equ CME,0x80
.equ PLLON,0x40
.equ AUTO,0x20
.equ ACQ,0x10
.equ PRE,0x04
.equ PCE,0x02
.equ SCME,0x01
.equ WCOP,0x80
.equ RSBCK,0x40
.equ RTIBYP,0x80
.equ COPBYP,0x40
.equ PLLBYP,0x10
.equ FCM,0x02
.equ TEN,0x80
.equ TSWAI,0x40
.equ TSFRZ,0x20
.equ TFFCA,0x10
.equ C7I,0x80
.equ C6I,0x40
.equ C5I,0x20
.equ C4I,0x10
.equ C3I,0x08
.equ C2I,0x04
.equ C1I,0x02
.equ C0I,0x01
.equ C7F,0x80
.equ C6F,0x40
.equ C5F,0x20
.equ C4F,0x10
.equ C3F,0x08
.equ C2F,0x04
.equ C1F,0x02
.equ C0F,0x01
.equ OC7,0x80
.equ OC6,0x40
.equ OC5,0x20
.equ OC4,0x10
.equ OC3,0x08
.equ OC2,0x04
.equ OC1,0x02
.equ OC0,0x01
.equ IC7,0x80
.equ IC6,0x40
.equ IC5,0x20
.equ IC4,0x10
.equ IC3,0x08
.equ IC2,0x04
.equ IC1,0x02
.equ IC0,0x01
.equ IOS7,0x80
.equ IOS6,0x40
.equ IOS5,0x20
.equ IOS4,0x10
.equ IOS3,0x08
.equ IOS2,0x04
.equ IOS1,0x02
.equ IOS0,0x01
.equ NOVW7,0x80
.equ NOVW6,0x40
.equ NOVW5,0x20
.equ NOVW4,0x10
.equ NOVW3,0x08
.equ NOVW2,0x04
.equ NOVW1,0x02
.equ NOVW0,0x01
.equ TCRE,0x08
.equ PAEN,0x40
.equ PAMOD,0x20
.equ PEDGE,0x10
.equ CLK1,0x08
.equ CLK0,0x04
.equ PAOVI,0x02
.equ PAI,0x01
.equ PAOVF,0x02
.equ PAIF,0x01
.equ MCZI,0x80
.equ MODMC,0x40
.equ RDMCL,0x20
.equ ICLAT,0x10
.equ FLMC,0x08
.equ MCEN,0x04
.equ MCPR1,0x02
.equ MCPR0,0x01
.equ MCZF,0x80
.equ POLF3,0x08
.equ POLF2,0x04
.equ POLF1,0x02
.equ POLF0,0x01
.equ PAEN3,0x08
.equ PAEN2,0x04
.equ PAEN1,0x02
.equ PAEN0,0x01
.equ TFMOD,0x08
.equ PACMX,0x04
.equ BUFEN,0x02
.equ LATQ,0x01
.equ TCBYP,0x02
.equ PBEN,0x40
.equ PBOVI,0x02
.equ PBOVF,0x02
.equ ADPU,0x80
.equ AFFC,0x40
.equ AWAI,0x20
.equ ETRIGLE,0x10
.equ ETRIGP,0x08
.equ ETRIG,0x04
.equ ASCIE,0x02
.equ ASCIF,0x01
.equ SCF,0x80
.equ ETORF,0x20
.equ FIFOR,0x10
.equ CON67,0x80
.equ CON45,0x40
.equ CON23,0x20
.equ CON01,0x10
.equ PSWAI,0x08
.equ PFRZ,0x04
.equ PWMIF,0x80
.equ PWMIE,0x40
.equ PWMRSTRT,0x20
.equ PWMLVL,0x10
.equ PWM7IN,0x04
.equ PWM7INL,0x02
.equ PWM7ENA,0x01
.equ PWME7,0x80
.equ PWME6,0x40
.equ PWME5,0x20
.equ PWME4,0x10
.equ PWME3,0x08
.equ PWME2,0x04
.equ PWME1,0x02
.equ PWME0,0x01
.equ PCLK7,0x80
.equ PCLK6,0x40
.equ PCLK5,0x20
.equ PCLK4,0x10
.equ PCLK3,0x08
.equ PCLK2,0x04
.equ PCLK1,0x02
.equ PCLK0,0x01
.equ PPOL7,0x80
.equ PPOL6,0x40
.equ PPOL5,0x20
.equ PPOL4,0x10
.equ PPOL3,0x08
.equ PPOL2,0x04
.equ PPOL1,0x02
.equ PPOL0,0x01
.equ CAE7,0x80
.equ CAE6,0x40
.equ CAE5,0x20
.equ CAE4,0x10
.equ CAE3,0x08
.equ CAE2,0x04
.equ CAE1,0x02
.equ CAE0,0x01
.equ TIEN,0x80
.equ TCIE,0x40
.equ RIE,0x20
.equ ILIE,0x10
.equ TE,0x08
.equ RE,0x04
.equ RWU,0x02
.equ SBK,0x01
.equ TDRE,0x80
.equ TC,0x40
.equ RDRF,0x20
.equ IDLE,0x10
.equ OR,0x08
.equ NF,0x04
.equ FE,0x02
.equ PF,0x01
.equ BRK13,0x04
.equ TXDIR,0x02
.equ RAF,0x01
.equ R8,0x80
.equ T8,0x40
.equ SPIF,0x80
.equ SPTEF,0x20
.equ MODF,0x10
.equ IBEN,0x80
.equ IBIE,0x40
.equ MSSL,0x20
.equ TXRX,0x10
.equ TXAK,0x08
.equ RSTA,0x04
.equ IBSWAI,0x01
.equ TCF,0x80
.equ IAAS,0x40
.equ IBB,0x20
.equ IBAL,0x10
.equ SRW,0x04
.equ IBIF,0x02
.equ RXAK,0x01
.equ IMSG,0x80
.equ CLKS,0x40
.equ IE,0x02
.equ WCM,0x01
.equ BDLCE,0x10
.equ BIDLE,0x01           ;idle bit of BDLC
.equ WUPIF,0x80
.equ CSCIF,0x40
.equ RSTAT1,0x20
.equ RSTAT0,0x10
.equ TSTAT1,0x08
.equ TSTAT0,0x04
.equ CANE,0x80
.equ OVRIF,0x02
.equ RXF,0x01
.equ INITRQ,0x01
.equ INITAK,0x01
.equ SLPRQ,0x02
.equ SLPAK,0x02
.equ WUPIE,0x80
.equ CSCIE,0x40
.equ RSTATE1,0x20
.equ RSTATE0,0x10
.equ TSTATE1,0x08
.equ TSTATE0,0x04
.equ OVRIE,0x02
.equ RXFIE,0x01
.equ TXE2,0x04
.equ TXE1,0x02
.equ TXE0,0x01
.equ TXEIE2,0x04
.equ TXEIE1,0x02
.equ TXEIE0,0x01
.equ TX2,0x04
.equ TX1,0x02
.equ TX0,0x01
.equ FDIVLD,0x80	; clock divider loaded
.equ EDIVLD,0x80	;	"
.equ PRDIV8,0x40	; enable divider by 8 bit
.equ KEYEN,0x80	; enable backdoor key to security
.equ WRALL,0x10	; write to all register banks
.equ CBEIE,0x80	; command buffer empty interrupt enable
.equ CCIE,0x40	; command completion interrupt enable
.equ KEYACC,0x20	; enable security key writing
.equ FPOPEN,0x80	; Opens the flash for program or erase
.equ EPOPEN,0x80	; Opens the EEPROM for program or erase
.equ EPDIS,0x08	; EEPROM protection address range disable
.equ FPHDIS,0x20	; flash protection higher address range disable
.equ FPLDIS,0x04	; flash protection lower address range disable
.equ CBEIF,0x80	; command buffer empty interrupt flag
.equ CCIF,0x40	; command complete interrupt flag
.equ PVIOL,0x20	; protection violation interrupt flag
.equ ACCERR,0x10	; access error flag
.equ BLANK,0x04	; array has been verified as erased

; D-Bug12 functions addresses
.equ main,0xEE80
.equ getchar,0xEE84
.equ putchar,0xEE86
.equ printf,0xEE88
.equ getcmdline,0xEE8A
.equ sscanhex,0xEE8E
.equ isxdigit,0xEE92
.equ toupper,0xEE94
.equ isalpha,0xEE96
.equ strlen,0xEE98
.equ strcpy,0xEE9A
.equ out2hex,0xEE9C
.equ out4hex,0xEEA0
.equ setuservector,0xEEA4
.equ writeeebyte,0xEEA6
.equ eraseee,0xEEAA
.equ readmem,0xEEAE
.equ writemem,0xEEB2
; D-Bug12 interrut vector nunbers
;userpwmshdn 	equ	6
;userportp 		equ	7
;usermscan4tx	equ	8
;usermscan4rx	equ	9
;usermscan4errs	equ	10
;usermscan4wake	equ	11
;usermscan3tx	equ	12
;usermscan3rx	equ	13
;usermscan3errs	equ	14
;usermscan3wake	equ	15
;usermscan2tx	equ	16
;usermscan2rx	equ	17
;usermscan2errs	equ	18
;usermscan2wake	equ	19
;usermscan1tx	equ	20
;usermscan1rx	equ	21
;usermscan1errs	equ	22
;usermscan1wake	equ	23
;usermscan0tx	equ	24
;usermscan0rx	equ	25
;usermscan0errs	equ	26
;usermscan0wake	equ	27
;userflash		equ	28
;usereeprom		equ	29
;userspi2		equ	30
;userspi1		equ	31
;useriic		equ	32
;userdlc		equ	33
;userscme		equ	34
;usercrg		equ	35
;userpaccbov	equ	36
;usermoddwnctr	equ	37
;userporth		equ	38
;userportj		equ	39
;useratod1		equ	40
;useratod0		equ	41
;usersci1		equ	42
;usersci0		equ	43
;userspi0		equ	44
;userpaccedge	equ	45
;userpaccovf	equ	46
;usertimerovf	equ	47
;usertimerch7	equ	48
;usertimerch6	equ	49
;usertimerch5	equ	50
;usertimerch4	equ	51
;usertimerch3	equ	52
;usertimerch2	equ	53
;usertimerch1	equ	54
;usertimerch0	equ	55
;userrti		equ	56
;userirq		equ	57
;userxirq		equ	58
;userswi		equ	59

;usertrap		equ	60
; end of D-Bug12 interrupt vector number table
; D-Bug12 SRAM vector table
.equ UserRsrv0x80,0x3E00
.equ UserRsrv0x82,0x3E02
.equ UserRsrv0x84,0x3E04
.equ UserRsrv0x86,0x3E06
.equ UserRsrv0x88,0x3E08
.equ UserRsrv0x8a,0x3E0A
.equ UserPWMShDn,0x3E0C
.equ UserPortP,0x3E0E
.equ UserMSCAN4Tx,0x3E10
.equ UserMSCAN4Rx,0x3E12
.equ UserMSCAN4Errs,0x3E14
.equ UserMSCAN4Wake,0x3E16
.equ UserMSCAN3Tx,0x3E18
.equ UserMSCAN3Rx,0x3E1A
.equ UserMSCAN3Errs,0x3E1C
.equ UserMSCAN3Wake,0x3E1E
.equ UserMSCAN2Tx,0x3E20
.equ UserMSCAN2Rx,0x3E22
.equ UserMSCAN2Errs,0x3E24
.equ UserMSCAN2Wake,0x3E26
.equ UserMSCAN1Tx,0x3E28
.equ UserMSCAN1Rx,0x3E2A
.equ UserMSCAN1Errs,0x3E2C
.equ UserMSCAN1Wake,0x3E2E
.equ UserMSCAN0Tx,0x3E30
.equ UserMSCAN0Rx,0x3E32
.equ UserMSCAN0Errs,0x3E34
.equ UserMSCAN0Wake,0x3E36
.equ UserFlash,0x3E38
.equ UserEEPROM,0x3E3A
.equ UserSPI2,0x3E3C
.equ UserSPI1,0x3E3E
.equ UserIIC,0x3E40
.equ UserDLC,0x3E42
.equ UserSCME,0x3E44
.equ UserCRG,0x3E46
.equ UserPAccBOv,0x3E48
.equ UserModDwnCtr,0x3E4A
.equ UserPortH,0x3E4C
.equ UserPortJ,0x3E4E
.equ UserAtoD1,0x3E50
.equ UserAtoD0,0x3E52
.equ UserSCI1,0x3E54
.equ UserSCI0,0x3E56
.equ UserSPI0,0x3E58
.equ UserPAccEdge,0x3E5A
.equ UserPAccOvf,0x3E5C
.equ UserTimerOvf,0x3E5E
.equ UserTimerCh7,0x3E60
.equ UserTimerCh6,0x3E62
.equ UserTimerCh5,0x3E64
.equ UserTimerCh4,0x3E66
.equ UserTimerCh3,0x3E68
.equ UserTimerCh2,0x3E6A
.equ UserTimerCh1,0x3E6C
.equ UserTimerCh0,0x3E6E
.equ UserRTI,0x3E70
.equ UserIRQ,0x3E72
.equ UserXIRQ,0x3E74
.equ UserSWI,0x3E76
.equ UserTrap,0x3E78
; end of user SRAM interrupt vector table
; Axiom CML12SDP256 demo board utils
.equ rprint,0xFF16	; display user registers
.equ outa,0xFF4F	; output ascii character in A
.equ out1byt,0xFF52	; display the hex value pointed to by X
.equ out1bsp,0xFF55	; out1byt followed by a space
.equ out2bsp,0xFF58	; display 2 hex bytes pointed to by X
.equ outcrlf,0xFF5B	; output a carriage return and a line feed to terminal
.equ outstrg,0xFF5E	; display the string pointed to by X (terminated by 0x04) preceded by CR/LF
.equ outstrg0,0xFF5E	; display the string pointed to by X (terminated by 0x04)without initial CR/LF
.equ inchar,0xFF64	; wait for and input a char from terminal
