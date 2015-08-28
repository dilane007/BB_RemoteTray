.include "asm_ppc.h"
.include "asm_span.h"
.include "asm_pro.h"

#define VINC1
#define SHORT_HISTORY

// for exception 0x200
 .set STACK_ME_R0, 		0x01800
 .set STACK_ME_R1, 		0x01804 
 .set STACK_ME_LR,		0x01880
 .set STACK_ME_CR,		0x01884
 .set STACK_ME_XER,		0x01888
 .set STACK_ME_CTR,		0x0188c
// for exception 0x300  
 .set STACK_DSI_R0, 		0x01900
 .set STACK_DSI_R1, 		0x01904
 .set STACK_DSI_LR,		0x01980
 .set STACK_DSI_CR,		0x01984
 .set STACK_DSI_XER,		0x01988
 .set STACK_DSI_CTR,		0x0198c
// for exception 0x400
 .set STACK_ISI_R0, 		0x01a00
 .set STACK_ISI_R1, 		0x01a04
 .set STACK_ISI_LR,		0x01a80
 .set STACK_ISI_CR,		0x01a84
 .set STACK_ISI_XER,		0x01a88
 .set STACK_ISI_CTR,		0x01a8c
// for exception 0x500   
 .set STACK_INT_R0, 		0x01b00
 .set STACK_INT_R1, 		0x01b04
 .set STACK_INT_LR,		0x01b80
 .set STACK_INT_CR,		0x01b84
 .set STACK_INT_XER,		0x01b88
 .set STACK_INT_CTR,		0x01b8c
// for exception 0x600   
 .set STACK_ALIGN_R0, 		0x01c00
 .set STACK_ALIGN_R1, 		0x01c04
 .set STACK_ALIGN_LR,		0x01c80
 .set STACK_ALIGN_CR,		0x01c84
 .set STACK_ALIGN_XER,		0x01c88
 .set STACK_ALIGN_CTR,		0x01c8c
// for exception 0x700   
 .set STACK_PRPG_R0, 		0x01d00
 .set STACK_PRPG_R1, 		0x01d04
 .set STACK_PRPG_LR,		0x01d80
 .set STACK_PRPG_CR,		0x01d84
 .set STACK_PRPG_XER,		0x01d88
 .set STACK_PRPG_CTR,		0x01d8c
// for exception 0x800 
 .set STACK_FP_R0, 		0x01e00
 .set STACK_FP_R1, 		0x01e04
 .set STACK_FP_LR,		0x01e80
 .set STACK_FP_CR,		0x01e84
 .set STACK_FP_XER,		0x01e88
 .set STACK_FP_CTR,		0x01e8c
// for exception 0x900  
 .set STACK_DEC_R0, 		0x01f00
 .set STACK_DEC_R1, 		0x01f04
 .set STACK_DEC_LR,		0x01f80
 .set STACK_DEC_CR,		0x01f84
 .set STACK_DEC_XER,		0x01f88
 .set STACK_DEC_CTR,		0x01f8c
// for exception 0xc00  
 .set STACK_SC_R0, 		0x02200
 .set STACK_SC_R1, 		0x02204
 .set STACK_SC_LR,		0x02280
 .set STACK_SC_CR,		0x02284
 .set STACK_SC_XER,		0x02288
 .set STACK_SC_CTR,		0x0228c
// for exception 0xd00 
 .set STACK_TRACE_R0, 		0x02300
 .set STACK_TRACE_R1, 		0x02304
 .set STACK_TRACE_LR,		0x02380
 .set STACK_TRACE_CR,		0x02384
 .set STACK_TRACE_XER,		0x02388
 .set STACK_TRACE_CTR,		0x0238c
// for exception 0xf00  
 .set STACK_PM_R0, 		0x02500
 .set STACK_PM_R1, 		0x02504
 .set STACK_PM_LR,		0x02580
 .set STACK_PM_CR,		0x02584
 .set STACK_PM_XER,		0x02588
 .set STACK_PM_CTR,		0x0258c
// for exception 0xf20  
 .set STACK_AVD_R0, 		0x02900
 .set STACK_AVD_R1, 		0x02904
 .set STACK_AVD_LR,		0x02980
 .set STACK_AVD_CR,		0x02984
 .set STACK_AVD_XER,		0x02988
 .set STACK_AVD_CTR,		0x0298c
// for exception 0x1300  
 .set STACK_IABP_R0, 		0x02920
 .set STACK_IABP_R1, 		0x02920
 .set STACK_IABP_LR,		0x02920
 .set STACK_IABP_CR,		0x02920
 .set STACK_IABP_XER,		0x02920
 .set STACK_IABP_CTR,		0x02920
// for exception 0x1400 
 .set STACK_SMI_R0,		0x02a00		
 .set STACK_SMI_R28,		0x02a70
 .set STACK_SMI_R29,		0x02a74
 .set STACK_SMI_LR,		0x02a80
 .set STACK_SMI_CR,		0x02a84
 .set STACK_SMI_XER,		0x02a88
 .set STACK_SMI_CTR,		0x02a8c
// for exception 0x1600 
 .set STACK_AV_R0, 		0x02C00	
 .set STACK_AV_R1, 		0x02C04	
 .set STACK_AV_LR,		0x02C80	
 .set STACK_AV_CR,		0x02C84	
 .set STACK_AV_XER,		0x02C88	
 .set STACK_AV_CTR,		0x02C8c	
// for exception 0x1700 
 .set STACK_THERM_R0, 		0x02D00
 .set STACK_THERM_R1, 		0x02D04
 .set STACK_THERM_LR,		0x02D80
 .set STACK_THERM_CR,		0x02D84
 .set STACK_THERM_XER,		0x02D88
 .set STACK_THERM_CTR,		0x02D8c
 
 .set Sh_Int_Hist,		0x07000
 .set CNT_SMI,			0x0180

// decrementor
 .set DEC_COUNTER, 		0x09f0
 .set DEC_VALUE,		0x09f4
 .set DEC_TBL,			0x09f8


// branch accros one instruction forward 
 .set BR_2,			0x48000008
 .set LI_R3_VECT,		0x38600000 
 .set NOP,			0x60000000                 
 .set NOP_DEC, 			0x0930	
 
 // Special sets for tricky programming of Pro
 .set INT__STATUS, 		-0x80
 .set INT__MSTATUS, 		-0x7c
 .set INT__ENABLE,		-0x78	
 .set INT__GENERATE,		-0x74	
 .set INT__POLARITY,		-0x70
 .set INT__TRIGGER,		-0x6c
 .set INT__VBAADDR,		-0x68
 .set INT__VINC,		-0x64	
 .set INT__VECTOR,		-0x60
 .set INT__SOFTSET,		-0x5c
 .set INT__SOFTSRC,		-0x58
  
// .set __SP_INIT,       	0x00030000 	// this is for stack
 .set __SP_INIT,       	0x07000000 	// this is for stack   
   
 .set USER_ENTRY, main
 
	.globl    _start, START, ENTRY
	.extern   main

// these function for cache and change endian
	.global flush
	.global flushcache	
	.global readEndian
	.global writeEndian
	.global disableInterrupt
	.global enableInterrupt	
	
// simple function for read/write control registers	
	.global get_MMCR0 
	.global set_MMCR0
	.global get_MMCR1
	.global set_MMCR1
	.global get_MMCR2
	.global set_MMCR2
	.global get_PMC1 
	.global set_PMC1
	.global get_PMC2 
	.global set_PMC2
	.global get_PMC3 
	.global set_PMC3
	.global get_PMC4
	.global set_PMC4
	.global get_THRM1
	.global get_THRM2
	.global get_THRM3
	.global set_THRM1
	.global set_THRM2
	.global set_THRM3
	.global get_PVR		
	.global get_Dec		
	.global set_Dec		
	.global get_TBL		
	.global get_TBU		
	.global get_TB			// get 64 bit value
	.global get_HID0
	.global set_HID0
	.global set_RetMSR_EE_bit	// MSR[EE] <= r3, return previous MSR[EE]
	.global fastchange_endianess_byte
	.global fastchange_endianess_word
	.global total_stop
	.global memcpy_rx	
	.global br_jump_table		// for level1
	.global no_handler
	.type br_jump_table, @function
	.type nop_dec,  @function
	.type nop_dec_handler,  @function
	.type nop_pm_handler,  @function

//   Use any of the following 3 labels as the demo entry point. 
//   Note: __SP_INIT/__SP_END are defined in the $(TARGET).lnk 

	.org  0x0100	// System reset


InitTundraProInterruptController:

	li 	r3, -1			// reset all interrupts 
	stw	r4,INT__STATUS(r0)	// INT_STATUS <= 0xFFFFFFFF
	li 	r4,0x0			// all interrupts are disable
	stw 	r4,INT__ENABLE(r0)	// INT_ENABLE <= 0 
	stw 	r4,INT__GENERATE(r0)	// Generate PB_INT for all sources INT_GENEGATE <= SMI
	lis 	r5,0xffc7		// INT_POLARITY = INT_POL_POS & INT10_POL_NEG & INT11_POL_NEG &
	ori 	r5,r5,0x3ff		// INT12_POL_NEG & INT16_POL_NEG & INT17_POL_NEG &
	stw 	r5,INT__POLARITY(r0)	// INT18_POL_NEG & INT19_POL_NEG & INT20_POL_NEG  & INT21_POL_NEG	
	stw 	r3,INT__TRIGGER(r0)	// edge sensetive INT_TRIGGER = 0xffffffff;
	stw 	r4,INT__VBAADDR(r0)	// Interrupt Vector Base Address INT_VBADDR = 0x00000000; 
	stw 	r4,INT__VINC(r0)	// Offset is 0x100 and Int //0 is most significant INT_VINC <= 0 
	stw 	r4,0x1a4(r3)		// all soft interrupt are disable INT_SOFTSET <= 0;
// patch for INT1-INT7, INT14, INT15, think about INT13
 	lis 	r5, 0xffc3		// r6 <= 0xffc30000
 	stw 	r5, INT__SOFTSRC(r0)	// INT_SOFTSRC <= 0xffc30000

	lis 	r5,0x003c		// INT_ENABLE = INT21_EN | INT20_EN | INT13_EN |
	ori 	r5,r5,0x0c00		// INT12_EN | INT11_EN | INT10_EN |  
	stw 	r6,INT__ENABLE(r0)

// set priority for 31 as high and 0 as low
	lis 	r6, 0x0100		// r6 <= 0x01000000
	stw 	r6, INT__VINC(r0)	// INT_VINT <= (PRI := 1)     
	stw	r3,INT__STATUS(r0)	// Reset again INT_STATUS <= 0xFFFFFFFF
	
// zeroing TBL and TBU 	

//	li 	r3, 0x00		 
//	mtspr	269, r3			// TBU <- 0
//	mtspr	286, r3			// TBL <- 0
	
	b 	START	

/*=================================================================*/
	
	.org 0x0200			// Machine check
ex_200:
	mtspr 	sprg3, r3
	li 	r3, 0x0200		// or ba ex_200_c 
	b 	all_excepts
	
ex_200_c:
	li 	r3, 0x0030 		// set MSR[IR] and MSR[DR](0x2030 for MSR[FP]) 
	mtmsr 	r3			// after this instruction cache is ON
	mfspr 	r3, sprg3		// restore r3
	
	stw	r0, STACK_ME_R0(r0)	// save r0
	stmw 	r1, STACK_ME_R1(r0) 	// save r1 - r31
	mflr	r0
	stw	r0, STACK_ME_LR(r0)
    	mfctr   r0
	stw	r0, STACK_ME_CTR(r0)
	mfxer	r0
	stw	r0, STACK_ME_XER(r0)
	mfcr	r0
	stw	r0, STACK_ME_CR(r0)
	
	nop

	lwz	r0, STACK_ME_CR(r0)
	mtcr 	r0
	lwz	r0, STACK_ME_XER(r0)
    	mtxer   r0
	lwz	r0, STACK_ME_CTR(r0)
	mtctr	r0
	lwz	r0, STACK_ME_LR(r0)
	mtlr	r0
	lmw	r1, STACK_ME_R1(r0)
	lwz	r0, STACK_ME_R0(r0)
	
	rfi

/*=================================================================*/

get_MMCR0: 
	mfspr 	r3, mmcr0;	blr;
set_MMCR0:
	mtspr 	mmcr0, r3;	blr;
get_MMCR1:
	mfspr 	r3, mmcr1;	blr;
set_MMCR1:
	mtspr 	mmcr1, r3;	blr;
get_MMCR2:
	mfspr 	r3, mmcr2;	blr;
set_MMCR2:
	mtspr 	mmcr2, r3;	blr;
get_PMC1: 
	mfspr 	r3, pmc1;	blr;
set_PMC1:
	mtspr 	pmc1, r3;	blr;
get_PMC2: 
	mfspr 	r3, pmc2;	blr;
set_PMC2:
	mtspr 	pmc2, r3;	blr;
get_PMC3: 
	mfspr 	r3, pmc3;	blr;
set_PMC3:
	mtspr 	pmc3, r3;	blr;
get_PMC4:
	mfspr 	r3, pmc4;	blr;
set_PMC4:
	mtspr 	pmc4, r3;	blr;

/*=================================================================*/
	
	.org 0x0300			// DSI
ex_300:
	mtspr 	sprg3, r3
	li 	r3, 0x0300
	b 	all_excepts
ex_300_c:
	li 	r3, 0x0030 		// set MSR[IR] and MSR[DR](0x2030 for MSR[FP]) 
	mtmsr 	r3			// after this instruction cache is ON
	mfspr 	r3, sprg3		// restore r3
	
	stw	r0, STACK_DSI_R0(r0)	// save r0
	stmw 	r1, STACK_DSI_R1(r0) 	// save r1 - r31
	mflr	r0
	stw	r0, STACK_DSI_LR(r0)
    	mfctr   r0
	stw	r0, STACK_DSI_CTR(r0)
	mfxer	r0
	stw	r0, STACK_DSI_XER(r0)
	mfcr	r0
	stw	r0, STACK_DSI_CR(r0)
	
	nop

	lwz	r0, STACK_DSI_CR(r0)
	mtcr 	r0
	lwz	r0, STACK_DSI_XER(r0)
    	mtxer   r0
	lwz	r0, STACK_DSI_CTR(r0)
	mtctr	r0
	lwz	r0, STACK_DSI_LR(r0)
	mtlr	r0
	lmw	r1, STACK_DSI_R1(r0)
	lwz	r0, STACK_DSI_R0(r0)
	
	rfi
/*=================================================================*/

get_THRM1:
	mfspr 	r3, thrm1;	blr;	
get_THRM2:
	mfspr 	r3, thrm2;	blr;
get_THRM3:
	mfspr 	r3, thrm3;	blr;
set_THRM1:
	mtspr 	thrm1, r3;	blr;
set_THRM2:
	mtspr 	thrm2, r3;	blr;
set_THRM3:
	mtspr 	thrm3, r3;	blr;
get_PVR:		
	mfspr 	r3, pvr;	blr;	
get_Dec:			
	mfspr 	r3, dec;	blr;
set_Dec:			
	mtspr 	dec, r3;	blr;
get_TBL:			
	mfspr 	r3, tbl;	blr;
get_TBU:		
	mfspr 	r3, tbu;	blr;
get_HID0:
	mfspr 	r3, hid0;	blr;
set_HID0:
	sync;	mtspr 	hid0, r3;	sync;	blr;

/*=================================================================*/
	.org 0x0400	// ISI
ex_400:
	mtspr 	sprg3, r3
	li 	r3, 0x0400
	b 	all_excepts
ex_400_c:
	li 	r3, 0x0030 		// set MSR[IR] and MSR[DR](0x2030 for MSR[FP]) 
	mtmsr 	r3			// after this instruction cache is ON
	mfspr 	r3, sprg3		// restore r3
	
	stw	r0, STACK_ISI_R0(r0)	// save r0
	stmw 	r1, STACK_ISI_R1(r0) 	// save r1 - r31
	mflr	r0
	stw	r0, STACK_ISI_LR(r0)
    	mfctr   r0
	stw	r0, STACK_ISI_CTR(r0)
	mfxer	r0
	stw	r0, STACK_ISI_XER(r0)
	mfcr	r0
	stw	r0, STACK_ISI_CR(r0)
	
	nop

	lwz	r0, STACK_ISI_CR(r0)
	mtcr 	r0
	lwz	r0, STACK_ISI_XER(r0)
    	mtxer   r0
	lwz	r0, STACK_ISI_CTR(r0)
	mtctr	r0
	lwz	r0, STACK_ISI_LR(r0)
	mtlr	r0
	lmw	r1, STACK_ISI_R1(r0)
	lwz	r0, STACK_ISI_R0(r0)
	
	rfi
/*=================================================================*/

get_HID1:
	mfspr 	r3, hid1;	blr;
get_L2CR:
	mfspr 	r3, l2cr;	blr;
set_L2CR: 
	mtspr 	l2cr, r3;	isync;	blr;
get_MSR:
	mfmsr 	r3;		blr;
flush:	
	dcbf 	r0, r3;		blr;

flushcache:			// r3 = address, r4 = times
	dcbf 	r0, r3
	addi 	r3, r3, 0x20	// flushed block 32 bytes 
	addic. 	r4, r4, -0x01
	bne 	flushcache
	blr

fastchange_endianess_byte:	// r3 - address, r4 - number of byte
	srawi 	r4, r4, 2	// divide by 4
fastchange_endianess_word:	// r3 - address, r4 - number of words
	mtctr 	r4		// load counter
	addi 	r3, r3, -4 	// adjust the destination for the loop
loopReverse:
	lwzu   	r5, 4(r3)
	stwbrx 	r5, r0, r3
	bdnz 	loopReverse
	blr

total_stop:
	mfmsr 	r3
	rlwinm 	r3,r3, 0, 17, 15
	mtmsr 	r3
total_stop_stop:	
	b 	total_stop_stop

/*=================================================================*/

	.org 0x0500			// External interrupt PB_INT
ex_500:
	mtspr 	sprg3, r3
	li 	r3, 0x0400
	b 	all_excepts
ex_500_c:
	li 	r3, 0x0030 			// set MSR[IR] and MSR[DR](0x2030 for MSR[FP]) 
	mtmsr 	r3			// after this instruction cache is ON
	mfspr 	r3, sprg3			// restore r3
	
	stw	r0, STACK_INT_R0(r0)	// save r0
	stmw 	r1, STACK_INT_R1(r0) 	// save r1 - r31
	mflr	r0
	stw	r0, STACK_INT_LR(r0)
    	mfctr   r0
	stw	r0, STACK_INT_CTR(r0)
	mfxer	r0
	stw	r0, STACK_INT_XER(r0)
	mfcr	r0
	stw	r0, STACK_INT_CR(r0)
	
	nop

	lwz	r0, STACK_INT_CR(r0)
	mtcr 	r0
	lwz	r0, STACK_INT_XER(r0)
    	mtxer   r0
	lwz	r0, STACK_INT_CTR(r0)
	mtctr	r0
	lwz	r0, STACK_INT_LR(r0)
	mtlr	r0
	lmw	r1, STACK_INT_R1(r0)
	lwz	r0, STACK_INT_R0(r0)
	
	rfi	

/*=================================================================*/
	
readEndian:			// read with endian  in r4 from address (r3)
	lwbrx 	r3, r0, r3;	blr;

writeEndian:			// write with endian: r3 - address, r4 - value
	stwbrx	 r4, r0,  r3;	blr;

get_TB:
	mfspr 	r3, tbu 	// load from TBU
	mfspr 	r4, tbl 	// load from TBL
	mfspr 	r5, tbu 	// load from TBU
	cmpw 	r5, r3 		// see if ‘old’ = ‘new’
	bne 	get_TB 		// loop if carry occurred
	blr			// output r3 - Major part, r4 - Minor part

// r3 = base address of the source buffer  
// r4 = base address of the destination buffer 
// r5 = counter Words
 
memcpy_rx:
  	mtctr	r5  		// load count register  
 	addi  	r4,r4,-4  	// adjust the destination for the loop  
 	subf  	r6,r4,r3  	// difference between source and destination  
rx_loop:     
 	lwbrx  	r5,r4,r6  	// load byte-reverse at (dest + diff)  
 	stwu  	r5,4(r4)  	// store with update to destination  
 	bdnz  	rx_loop  	// branch to loop if ctr != 0  
	blr	

disableInterrupt:
	mfmsr 	r3
	rlwinm 	r3,r3, 0, 17, 15
	mtmsr 	r3
	blr

enableInterrupt:
	mfmsr 	r3
	ori 	r3, r3, 32768
	mtmsr 	r3
	blr

/*=================================================================*/

	.org 0x0600			// Aligment
ex_600:	
	mtspr 	sprg3, r3
	li 	r3, 0x0600
	b 	all_excepts	
ex_600_c:
	li 	r3, 0x0030 		// set MSR[IR] and MSR[DR](0x2030 for MSR[FP]) 
	mtmsr 	r3			// after this instruction cache is ON
	mfspr 	r3, sprg3		// restore r3
	
	stw	r0, STACK_ALIGN_R0(r0)	// save r0
	stmw 	r1, STACK_ALIGN_R1(r0) 	// save r1 - r31
	mflr	r0
	stw	r0, STACK_ALIGN_LR(r0)
    	mfctr   r0
	stw	r0, STACK_ALIGN_CTR(r0)
	mfxer	r0
	stw	r0, STACK_ALIGN_XER(r0)
	mfcr	r0
	stw	r0, STACK_ALIGN_CR(r0)
	
	nop

	lwz	r0, STACK_ALIGN_CR(r0)
	mtcr 	r0
	lwz	r0, STACK_ALIGN_XER(r0)
    	mtxer   r0
	lwz	r0, STACK_ALIGN_CTR(r0)
	mtctr	r0
	lwz	r0, STACK_ALIGN_LR(r0)
	mtlr	r0
	lmw	r1, STACK_ALIGN_R1(r0)
	lwz	r0, STACK_ALIGN_R0(r0)
	
	rfi

/*=================================================================*/

set_RetMSR_EE_bit:
	mfmsr	r5			// read MSR
	srawi 	r4, r5, 15		// shift right 15 bits 
	clrlwi 	r4, r4, 31		// clear left 31 bits (rlwinm rA, rS, 0, n, 31)
	cmpwi 	r3, 0			// argument (r3) is 0 ? 
	beq 	bitIEreset
bitIEset:
	ori 	r5, r5, 0x8000		// MSR[IE] <- 1 
	b 	msrwrite
bitIEreset:
	or 	r3, r5, r5 		// r3 <- r5 
	rlwinm 	r5, r3, 0, 17, 15	// MSR[IE] <-- 0
msrwrite:
	mtmsr 	r5
	or 	r3, r4, r4		// r3 <-- r4  return code 
	blr

set_save_reg:				// void set_save_reg(unsigned vect); r3 vect

	addi 	r3, r3, 0x04		// address of second instruction
	lis 	r4, BR_2@h		// set in r4 pattern of branch forward accross one instruction
	ori 	r4, r4, BR_2@l
	lwz 	r4, 0x0(r3)		// write at the vect + 0x04

	dcbf 	0, r3			// all syncronize
	sync;	icbi 	0, r3;
	sync;	isync;	blr;

set_handler_for_vec:			// void set_handler_for_vec(unsigned vect, void *addrOfFunc);
	
	addi 	r3,r3, 0x40		// r3 - vect, r4 - address of handler
	subf	r4,r3,r4		// newaddres = address - (vect + 0x40)
	oris	r4,r4,0x4800		// bpattern | newaddress
	stw	r4,0x0(r3)		// write back

	dcbf	r0,r3			// syncronize all
	sync;	icbi	r0,r3;
	sync;	isync;	blr;

/*=================================================================*/

	.org 0x0700			// Program
ex_700:
	mtspr 	sprg3, r3
	li 	r3, 0x0700
	b 	all_excepts
ex_700_c:
	li 	r3, 0x0030 		// set MSR[IR] and MSR[DR](0x2030 for MSR[FP]) 
	mtmsr 	r3			// after this instruction cache is ON
	mfspr 	r3, sprg3		// restore r3
	
	stw	r0, STACK_PRPG_R0(r0)	// save r0
	stmw 	r1, STACK_PRPG_R1(r0) 	// save r1 - r31
	mflr	r0
	stw	r0, STACK_PRPG_LR(r0)
    	mfctr   r0
	stw	r0, STACK_PRPG_CTR(r0)
	mfxer	r0
	stw	r0, STACK_PRPG_XER(r0)
	mfcr	r0
	stw	r0, STACK_PRPG_CR(r0)
	
	nop

	lwz	r0, STACK_PRPG_CR(r0)
	mtcr 	r0
	lwz	r0, STACK_PRPG_XER(r0)
    	mtxer   r0
	lwz	r0, STACK_PRPG_CTR(r0)
	mtctr	r0
	lwz	r0, STACK_PRPG_LR(r0)
	mtlr	r0
	lmw	r1, STACK_PRPG_R1(r0)
	lwz	r0, STACK_PRPG_R0(r0)
	
	rfi	

/*=================================================================*/
unset_save_reg:				// void unset_save_reg(unsigned vect)

	addi 	r3, r3, 0x04		// address of second instruction
	lis 	r4, LI_R3_VECT@h        // pattern of instruction li r3, vect
	or  	r4, r4, r3		// pattern or vect
	addi 	r3, r3, 0x04		// address of second instruction
	lwz 	r4, 0x0(r3)		// write new  instruction at place vect + 0x04
	
	dcbf 	0, r3			// all syncronize
	sync;	icbi 	0, r3;
	sync;	isync;	blr;

unset_handler_for_vec:			// unset_handler_for_vec(unsigend vect)
	
	addi 	r3,r3, 0x40		// r3 - vect, r4 - address of handler
	subf	r4,r3,r4		// newaddres = address - (vect + 0x40)
	lis     r4, NOP@h		// r4 <-- nop
	stw	r4,0x0(r3)		// write back

	dcbf	r0,r3			// syncronize all
	sync;	icbi	r0,r3;
	sync;	isync;	blr;


/*=================================================================*/
	.org 0x0800			// Floating-point inavailable
ex_800:
	mtspr 	sprg3, r3
	li 	r3,  0x0800
	b 	all_excepts
ex_800_c:
	li 	r3, 0x0030 		// set MSR[IR] and MSR[DR](0x2030 for MSR[FP]) 
	mtmsr 	r3			// after this instruction cache is ON
	mfspr 	r3, sprg3		// restore r3
	
	stw	r0, STACK_FP_R0(r0)	// save r0
	stmw 	r1, STACK_FP_R1(r0) 	// save r1 - r31
	mflr	r0
	stw	r0, STACK_FP_LR(r0)
    	mfctr   r0
	stw	r0, STACK_FP_CTR(r0)
	mfxer	r0
	stw	r0, STACK_FP_XER(r0)
	mfcr	r0
	stw	r0, STACK_FP_CR(r0)
	
	nop

	lwz	r0, STACK_FP_CR(r0)
	mtcr 	r0
	lwz	r0, STACK_FP_XER(r0)
    	mtxer   r0
	lwz	r0, STACK_FP_CTR(r0)
	mtctr	r0
	lwz	r0, STACK_FP_LR(r0)
	mtlr	r0
	lmw	r1, STACK_FP_R1(r0)
	lwz	r0, STACK_FP_R0(r0)
	
	rfi
/*=================================================================*/

set_save_reg_dec:			// void set_save_reg_dec(void)

	li	r3, nop_dec@l 		// address of nop
	lis	r4, BR_2@h		// set in r4 pattern of branch forward accross one instruction
	ori 	r4, r4, BR_2@l
	lwz 	r4, 0x0(r3)		// write at nop_dec

	dcbf 	0, r3			// all syncronize
	sync;	icbi 	0, r3;
	sync;	isync;	blr;
	
unset_save_reg_dec:			// void unset_save_reg(void)

	li	r3, nop_dec@l 		// address of nop
	lis 	r4, NOP@h            	// pattern of nop
	lwz 	r4, 0x0(r3)		// write nop at address nop_dec
	
	dcbf 	0, r3			// all syncronize
	sync;	icbi 	0, r3;
	sync;	isync;	blr;

/*=================================================================*/
	.org 0x0900 			// Decrementor
ex_900:
	mtsprg	3,r3
	mfmsr	r3
	ori	r3,r3,0x0030
// reload decrementer	
	lwz	r3, DEC_VALUE(r0)
	mtspr 	dec, r3
// get TBL and save for next handling	
	mfspr 	r3, tbl
	stw 	r3, DEC_TBL(r0)
// increment counter	
	lwz 	r3, DEC_COUNTER(r0)
	addi	r3, r3, 1
	stw	r3, DEC_COUNTER(r0)
	mtmsr	r3
	mfsprg	r3,3
// point of call save reg and c handler			
nop_dec:	
	nop
	rfi

ex_900_c:
	stw	r0, STACK_DEC_R0(r0)	// save r0
	stmw 	r1, STACK_DEC_R1(r0) 	// save r1 - r31
	mflr	r0
	stw	r0, STACK_DEC_LR(r0)
    	mfctr   r0
	stw	r0, STACK_DEC_CTR(r0)
	mfxer	r0
	stw	r0, STACK_DEC_XER(r0)
	mfcr	r0
	stw	r0, STACK_DEC_CR(r0)
nop_dec_handler:	
	nop

	lwz	r0, STACK_DEC_CR(r0)
	mtcr 	r0
	lwz	r0, STACK_DEC_XER(r0)
    	mtxer   r0
	lwz	r0, STACK_DEC_CTR(r0)
	mtctr	r0
	lwz	r0, STACK_DEC_LR(r0)
	mtlr	r0
	lmw	r1, STACK_DEC_R1(r0)
	lwz	r0, STACK_DEC_R0(r0)
	
	rfi

/*=================================================================*/

set_handler_for_dec:			// void set_handler_for_dec(void *addrOfFunc);
					// r3 - address of handler
	li 	r5, nop_dec_handler@l	
	subf	r4,r5,r3		// newaddres = address - nop_dec_handler
	oris	r4,r4,0x4800		// bpattern | newaddress
	stw	r4,0x0(r5)		// write back

	dcbf	r0,r5			// syncronize all
	sync;	icbi	r0,r5;
	sync;	isync;	blr;

unset_handler_for_dec:			// unset_handler_for_vec(void)
	
	li 	r3, nop_dec_handler@l	
	lis     r4, NOP@h		// r4 <-- nop
	stw	r4,0x0(r3)		// write back

	dcbf	r0,r3			// syncronize all
	sync;	icbi	r0,r3;
	sync;	isync;	blr;
	
/*=================================================================*/

	.org 0x9f0
	.long 0x0000			// 0x9f0 counter
	.long 0x61a8			// 0x9f4 current decrementor, by default 1 ms = 25000 clocks(0x61a8)	
	.long 0x0000			// 0x9f8
	.long 0x0000			// 0x9fc	
/*=================================================================*/
	
	.org 0x0a00			// store general and ctrl registers in low memory
all_excepts:

	stw 	r3, 0x1f0(r0)		// save exception number at address 0x1f0
	mfspr 	r3, srr0
	stw 	r3, 0x1f4(r0)		// save EA for Instruction in Interrupted Program Flow at 0x1f4
	mfspr 	r3, srr1		
	stw 	r3, 0x1f8(r0)		// save Exception-Specific Informatin and MSR at 0x1f8 

// ========= ALL IMPORTANT IS SAVED =============================

	stmw 	r0, 0xe00(r0)		// save all register, except r3	
	mfspr 	r3, sprg3		// save r3
	stw 	r3, 0xe0c(r0)       	// must be 0xe0c 

// at this moment I can use registers	
// save in this memory region LR, CTR, CR, XER

	mfspr 	r3, lr			// save LR
	stw 	r3, 0x0e80(r0)		
	mfspr 	r3, ctr			// save CTR
	stw 	r3, 0x0e84(r0)
	mfcr 	r3			// save CR 
	stw 	r3, 0x0e88(r0)
	mfspr 	r3, xer			// save XER
	stw 	r3, 0x0e8c(r0)

// set IR - instruction address translation DR - data address translation into MSR
	
	li 	r3, 0x0030		
	mtmsr 	r3
	sync				// at this moment MMU works

save_ctrl:
	mfspr 	r3, hid0;	stw 	r3, 0x1200(r0);
	mfspr 	r3, hid1;	stw 	r3, 0x1204(r0);
	mfspr 	r3, ibat0u;	stw 	r3, 0x1208(r0);
	mfspr 	r3, ibat0l;	stw 	r3, 0x120c(r0);
	mfspr 	r3, ibat1u;	stw 	r3, 0x1210(r0);
	mfspr 	r3, ibat1l;	stw 	r3, 0x1214(r0);
	mfspr 	r3, ibat2u;	stw 	r3, 0x1218(r0);
	mfspr 	r3, ibat2l;	stw 	r3, 0x121c(r0);
	mfspr 	r3, ibat3u;	stw 	r3, 0x1220(r0);
	mfspr 	r3, ibat3l;	stw 	r3, 0x1224(r0);
	mfspr 	r3, dbat0u;	stw 	r3, 0x1228(r0);
	mfspr 	r3, dbat0l;	stw 	r3, 0x122c(r0);
	mfspr 	r3, dbat1u;	stw 	r3, 0x1230(r0);
	mfspr 	r3, dbat1l;	stw 	r3, 0x1234(r0);
	mfspr 	r3, dbat2u;	stw 	r3, 0x1238(r0);
	mfspr 	r3, dbat2l;	stw 	r3, 0x123c(r0);
	mfspr 	r3, dbat3u;	stw 	r3, 0x1240(r0);
	mfspr 	r3, dbat3l;	stw 	r3, 0x1244(r0);
	mfspr 	r3, dar;	stw 	r3, 0x1248(r0);
	mfspr 	r3, dsisr;	stw 	r3, 0x124c(r0);
	mfspr 	r3, sia;	stw 	r3, 0x1250(r0);
	mfspr 	r3, bamr;	stw 	r3, 0x1254(r0);
	mfspr 	r3, ear;	stw 	r3, 0x1258(r0);
	mfspr 	r3, dabr;	stw 	r3, 0x125c(r0);
	mfspr 	r3, l2cr;	stw 	r3, 0x1260(r0);
	mfspr 	r3, iabr;	stw 	r3, 0x1264(r0);
	mfspr 	r3, msscr0;	stw 	r3, 0x1268(r0);
	mfspr 	r3, msscr1;	stw 	r3, 0x126c(r0);
	mfspr 	r3, thrm1;	stw 	r3, 0x1270(r0);
	mfspr 	r3, thrm2;	stw 	r3, 0x1274(r0);
	mfspr 	r3, thrm3;	stw 	r3, 0x1278(r0);
	mfspr 	r3, ictc;	stw 	r3, 0x127c(r0);
	mfspr 	r3, mmcr0;	stw 	r3, 0x1280(r0);
	mfspr 	r3, mmcr1;	stw 	r3, 0x1284(r0);
	mfspr 	r3, mmcr2;	stw 	r3, 0x1288(r0);
	mfspr 	r3, pmc1;	stw 	r3, 0x128c(r0);
	mfspr	r3, pmc2;	stw 	r3, 0x1290(r0);
	mfspr 	r3, pmc3;	stw 	r3, 0x1294(r0);
	mfspr 	r3, pmc4;	stw 	r3, 0x1298(r0);
	mfspr 	r3, tbl;	stw 	r3, 0x129c(r0);
	mfspr 	r3, tbu;	stw 	r3, 0x12a0(r0);
	mfspr 	r3, dec;	stw 	r3, 0x12a4(r0);
	mfspr 	r3, pvr;	stw 	r3, 0x12a8(r0);
	mfspr 	r3, sprg0;	stw 	r3, 0x12ac(r0);
	mfspr 	r3, sprg1;	stw 	r3, 0x12b0(r0);
	mfspr 	r3, sprg2;	stw 	r3, 0x12b4(r0);
	mfspr 	r3, sprg3;	stw 	r3, 0x12b8(r0);
	mfspr 	r3, srr0;	stw 	r3, 0x12bc(r0);
	mfspr 	r3, srr1;	stw 	r3, 0x12c0(r0);

// try to flush almost all memory
	li 	r3, 0x000		// r3 <- start adr = 0
	lis 	r4, 0x003f		// r4 <- 0x003f.ffff  
	ori 	r4, r4, 0xffff
	bl 	flushcache		// flush all from cache to memory
	
	lis 	r3, TUNDRA_SPAN_BASE@h	// set Base address of Tundra Pro 
	li 	r6, 0x0080		// bit SEM7 for SEMA1
	stw 	r6, SEMA1(r3)       	// set 0x00000080 in SEMA1(offset = 0x0474)
	isync				// host read this register at every ReadSyncFlag() call
	eieio
	sync
all_exc_loop:
	b 	all_exc_loop

/*=================================================================*/
	.org 0x0c00			// System call
ex_c00:
	mtspr 	sprg3, r3
	li 	r3, 0x0c00
	b 	all_excepts
	
ex_c00_c:
	li r3, 	0x0030 			// set MSR[IR] and MSR[DR](0x2030 for MSR[FP]) 
	mtmsr 	r3			// after this instruction cache is ON
	mfspr 	r3, sprg3		// restore r3
	
	stw	r0, STACK_SC_R0(r0)	// save r0
	stmw 	r1, STACK_SC_R1(r0) 	// save r1 - r31
	mflr	r0
	stw	r0, STACK_SC_LR(r0)
    	mfctr   r0
	stw	r0, STACK_SC_CTR(r0)
	mfxer	r0
	stw	r0, STACK_SC_XER(r0)
	mfcr	r0
	stw	r0, STACK_SC_CR(r0)
	
	nop

	lwz	r0, STACK_SC_CR(r0)
	mtcr 	r0
	lwz	r0, STACK_SC_XER(r0)
    	mtxer   r0
	lwz	r0, STACK_SC_CTR(r0)
	mtctr	r0
	lwz	r0, STACK_SC_LR(r0)
	mtlr	r0
	lmw	r1, STACK_SC_R1(r0)
	lwz	r0, STACK_SC_R0(r0)
	
	rfi	
/*=================================================================*/

/*=================================================================*/

	
	.org 0x0d00			// Trace
ex_d00:
	mtspr 	sprg3, r3
	li 	r3, 0x0d00
	b 	all_excepts

ex_d00_c:
	li 	r3, 0x0030 		// set MSR[IR] and MSR[DR](0x2030 for MSR[FP]) 
	mtmsr 	r3			// after this instruction cache is ON
	mfspr 	r3, sprg3		// restore r3
	
	stw	r0, STACK_TRACE_R0(r0)	// save r0
	stmw 	r1, STACK_TRACE_R1(r0) 	// save r1 - r31
	mflr	r0
	stw	r0, STACK_TRACE_LR(r0)
    	mfctr   r0
	stw	r0, STACK_TRACE_CTR(r0)
	mfxer	r0
	stw	r0, STACK_TRACE_XER(r0)
	mfcr	r0
	stw	r0, STACK_TRACE_CR(r0)
	
	nop

	lwz	r0, STACK_TRACE_CR(r0)
	mtcr 	r0
	lwz	r0, STACK_TRACE_XER(r0)
    	mtxer   r0
	lwz	r0, STACK_TRACE_CTR(r0)
	mtctr	r0
	lwz	r0, STACK_TRACE_LR(r0)
	mtlr	r0
	lmw	r1, STACK_TRACE_R1(r0)
	lwz	r0, STACK_TRACE_R0(r0)
	
	rfi

/*=================================================================*/

	.org 0xe00			// exception dump of r1-r31, free 32 instructions
	.skip 0x100
	
	.org 0x0f00			// Performace monitor
ex_f00:
	mtspr 	sprg3, r3
	li 	r3, 0x0f00
	b 	all_excepts	
ex_f00_c:
	li 	r3, 0x0030 		// set MSR[IR] and MSR[DR](0x2030 for MSR[FP]) 
	mtmsr 	r3			// after this instruction cache is ON
	mfspr 	r3, sprg3		// restore r3
	b 	ex_f00_c_continue
	
	.org 0x0f20			// Altivec unavailable
ex_f20:
	mtspr 	sprg3, r3
	li 	r3, 0x0f20
	b 	all_excepts
	
ex_f00_c_continue:

	
	stw	r0, STACK_PM_R0(r0)	// save r0
	stmw 	r1, STACK_PM_R1(r0) 	// save r1 - r31
	mflr	r0
	stw	r0, STACK_PM_LR(r0)
    	mfctr   r0
	stw	r0, STACK_PM_CTR(r0)
	mfxer	r0
	stw	r0, STACK_PM_XER(r0)
	mfcr	r0
	stw	r0, STACK_PM_CR(r0)
nop_pm_handler:	
	nop

	lwz	r0, STACK_PM_CR(r0)
	mtcr 	r0
	lwz	r0, STACK_PM_XER(r0)
    	mtxer   r0
	lwz	r0, STACK_PM_CTR(r0)
	mtctr	r0
	lwz	r0, STACK_PM_LR(r0)
	mtlr	r0
	lmw	r1, STACK_PM_R1(r0)
	lwz	r0, STACK_PM_R0(r0)
	
	rfi

/*=================================================================*/

set_handler_for_pm:			// void set_handler_for_pm(void *addrOfFunc);
					// r3 - address of handler
	li 	r5, nop_pm_handler@l	
	subf	r4,r5,r3		// newaddres = address - nop_dec_handler
	oris	r4,r4,0x4800		// bpattern | newaddress
	stw	r4,0x0(r5)		// write back

	dcbf	r0,r5			// syncronize all
	sync;	icbi	r0,r5;
	sync;	isync;	blr;

unset_handler_for_pm:			// unset_handler_for_pm(void)
	
	li 	r3, nop_pm_handler@l	
	lis     r4, NOP@h		// r4 <-- nop
	stw	r4,0x0(r3)		// write back

	dcbf	r0,r3			// syncronize all
	sync;	icbi	r0,r3;
	sync;	isync;	blr;
	
//	.org 0x1000			// target to host buffer
//	.skip 0x100
//	.org 0x1100			// host to target buffer 
//	.skip 0x100
//	.org 0x1200			// exception dump of control registers, free a few

/*=================================================================*/

	.org 0x1300			// Instrucion address breakpoint
ex_1300:

	mtspr 	sprg3, r3
	li 	r3, 0x1300
	b 	all_excepts	
ex_1300_c:
	li 	r3, 0x0030 		// set MSR[IR] and MSR[DR](0x2030 for MSR[FP]) 
	mtmsr 	r3			// after this instruction cache is ON
	mfspr 	r3, sprg3		// restore r3
	
	stw	r0, STACK_IABP_R0(r0)	// save r0
	stmw 	r1, STACK_IABP_R1(r0) 	// save r1 - r31
	mflr	r0
	stw	r0, STACK_IABP_LR(r0)
    	mfctr   r0
	stw	r0, STACK_IABP_CTR(r0)
	mfxer	r0
	stw	r0, STACK_IABP_XER(r0)
	mfcr	r0
	stw	r0, STACK_IABP_CR(r0)
	
	nop

	lwz	r0, STACK_IABP_CR(r0)
	mtcr 	r0
	lwz	r0, STACK_IABP_XER(r0)
    	mtxer   r0
	lwz	r0, STACK_IABP_CTR(r0)
	mtctr	r0
	lwz	r0, STACK_IABP_LR(r0)
	mtlr	r0
	lmw	r1, STACK_IABP_R1(r0)
	lwz	r0, STACK_IABP_R0(r0)
	
	rfi
/*=================================================================*/
/*=================================================================*/
	
	.org  0x1400			// System management interrupt
ex_1400:

	mtspr 	sprg3, r3		// save r3	
	li 	r3, 0x0030 		// set MSR[IR] and MSR[DR](0x2030 for MSR[FP]) 
	mtmsr 	r3			// after this instruction cache is ON

	stmw  	r28, STACK_SMI_R28(r0)	// save r28 - r31 register
// this is diagnostic - get time
	
	mfspr	r28, tbl		// get start clock

	mfspr  	r3, lr
	stw	r3, STACK_SMI_LR(0)	// save LR  	 
	
	mfcr	r3
	stw 	r3, STACK_SMI_CR(0)	// save CR
	
	mfxer	r3
	stw 	r3, STACK_SMI_XER(r0)	// save XER
	
	mfctr	r3
	stw 	r3, STACK_SMI_CTR(r0)	// save CTR

	lwz 	r3, INT__VECTOR(r0)	// read INT_VECTOR(TRICKY)

#ifdef VINC1
// start of PATCH FOR INT_VINC(PRI:=1)
	li 	r30, 0x1f00	
	sub 	r3, r30, r3
// end of PATCH FOR INT_VINC(PRI:=1)
#endif
	li 	r30, CNT_SMI		// r30 is base address for counters, etc.
	
// shift right at 6 bits, 
// for example INT[10] A*0x100 = 0xA00 = 1010 0000 0000 >> 6 = 10 1000 = 0x28  
// counter for  INT[10] is at address 0x1500 + 0x28 = 1528
	
	srawi 	r3, r3, 6		// offset INT_VECTOR >> 6

	lwzx 	r29, r30, r3		// read counter at address (r30 = 0x1500) + (r3 = offset)
	addi 	r29, r29, 0x01		// + 1 to counter
	stwx 	r29, r30, r3
	
#ifdef SHORT_HISTORY
// start store short interrupt history
	andi. 	r29, r29, 0x1f   	// use only 32 times this counter	
	slwi 	r29, r29, 2 		// offset in block
	slwi 	r3, r3, 5		// offset for block
	add  	r29, r29, r3		// offset of block + offset inside block
	stw 	r28, Sh_Int_Hist(r29)   // store time 
	srwi 	r3, r3, 5		// restore state of r3
// end	store short interrupt history
#endif


// set in LR address in br_jump_table(0x1460 address of table)

	addi 	r29, r3, br_jump_table@l // get jump address br_jump_table (0x145c)
	mtspr 	lr, r29			 // set br_jump_table address in LR

// shift right at 2 bit, for example INT[10]
//// 10 1000 = 0x28 10 1000>> 2 = 1010 = 0xA 
// shift left at r3 bit to get necessary bit for reset INT_STATUS
	
	srawi 	r3, r3, 2		// shift right for 2 bits
	lis 	r29, 0x8000		// set 0 bit
	srw 	r29, r29, r3		// r29 has mask for reset

	stw 	r29, INT__STATUS(r0)	// reset interrupt bit in INT_STATUS(TRICKY) 
//	eieio				// enforce in order execution of I/O 
//	sync				// must be	

// use the jump table

	blr 				// jump to jump table 

br_jump_table:
	b 	no_handler		// INT00 not used
	b 	no_handler		// INT01	not used
	b 	no_handler		// INT02 not used
	b 	no_handler		// INT03 not used
	b 	no_handler		// INT04 not used
	b 	no_handler		// INT05 not used
	b 	no_handler		// INT06 not used
	b 	no_handler		// INT07 not used
	b 	no_handler		// INT08 not used
	b 	no_handler		// INT09 not used
	b 	no_handler		// INT10 <= INT0(SPAN)
	b 	no_handler		// INT11 <= INT1(SPAN)
	b 	no_handler		// INT12 <= INT2(SPAN)
	b 	no_handler		// INT13 <= INT3(SPAN) = HARD RESET
	b 	no_handler		// INT14 not used 
	b 	no_handler		// INT15 not used
	b 	no_handler		// INT16 <= PPC_INT0(FPGA)
	b 	no_handler		// INT17 <= PPC_INT1(FPGA)
	b 	no_handler		// INT18 <= PPC_INT2(FPGA)
        b 	no_handler		// INT19 <= PPC_INT3(FPGA)
        b 	no_handler		// INT20 <= INT4(SPAN) 
	b 	no_handler		// INT21 <= INT5(SPAN)	
	b 	no_handler		// INT22 Watchdog time-out
	b 	no_handler		// INT23 UART1
	b 	no_handler		// INT24 UART2
	b 	no_handler		// INT25 PB address match
	b 	no_handler		// INT26 I2CO and I2C1 Act bit
	b 	no_handler		// INT27	GPT Capture and trigger _smi_int27x
	b 	no_handler		// INT28 SDRAM ECC uncorrectable error
	b 	no_handler		// INT29 SDARM ECC correctable error
	b 	no_handler		// INT30 PB Address parity error
	b 	no_handler		// INT31 PB Data parity error

no_handler:				// restore registers
	
	lwz 	r3, STACK_SMI_LR(0)	// restore LR
	mtspr  	lr, r3
	lwz 	r3, STACK_SMI_CR(0)	// restore CR
	mtcr 	r3
	lwz 	r3, STACK_SMI_XER(r0);	// restore XER
	mtxer	r3
	lwz 	r3, STACK_SMI_CTR(r0);	// restore CTR
	mtctr	r3	
	
	lmw   	r28, STACK_SMI_R28(r0)	// restore r29 - r31
	mfspr 	r3, sprg3		// restore r3
	eieio				// enforce in order execution of I/O 
	sync				// patch for SMI_INT00
	rfi				// exit from SMI exeption

/*=================================================================*/
/*=================================================================*/
	.org 0x1600			// Altivec assist
ex_1600:

	mtspr 	sprg3, r3
	li 	r3, 0x1600
	b 	all_excepts
ex_1600_c:
	li 	r3, 0x0030 		// set MSR[IR] and MSR[DR](0x2030 for MSR[FP]) 
	mtmsr 	r3			// after this instruction cache is ON
	mfspr 	r3, sprg3		// restore r3
	
	stw	r0, STACK_AV_R0(r0)	// save r0
	stmw 	r1, STACK_AV_R1(r0) 	// save r1 - r31
	mflr	r0
	stw	r0, STACK_AV_LR(r0)
    	mfctr   r0
	stw	r0, STACK_AV_CTR(r0)
	mfxer	r0
	stw	r0, STACK_AV_XER(r0)
	mfcr	r0
	stw	r0, STACK_AV_CR(r0)
	
	nop

	lwz	r0, STACK_AV_CR(r0)
	mtcr 	r0
	lwz	r0, STACK_AV_XER(r0)
    	mtxer   r0
	lwz	r0, STACK_AV_CTR(r0)
	mtctr	r0
	lwz	r0, STACK_AV_LR(r0)
	mtlr	r0
	lmw	r1, STACK_AV_R1(r0)
	lwz	r0, STACK_AV_R0(r0)
	
	rfi
/*=================================================================*/

/*=================================================================*/
	.org 0x1700			// Thermal management
ex_1700:

	mtspr 	sprg3, r3
	li 	r3, 0x1700
	b 	all_excepts

ex_1700_c:
	li 	r3, 0x0030 		// set MSR[IR] and MSR[DR](0x2030 for MSR[FP]) 
	mtmsr 	r3			// after this instruction cache is ON
	mfspr 	r3, sprg3		// restore r3
	
	stw	r0, STACK_THERM_R0(r0)	// save r0
	stmw 	r1, STACK_THERM_R1(r0) 	// save r1 - r31
	mflr	r0
	stw	r0, STACK_THERM_LR(r0)
    	mfctr   r0
	stw	r0, STACK_THERM_CTR(r0)
	mfxer	r0
	stw	r0, STACK_THERM_XER(r0)
	mfcr	r0
	stw	r0, STACK_THERM_CR(r0)
	
	nop

	lwz	r0, STACK_THERM_CR(r0)
	mtcr 	r0
	lwz	r0, STACK_THERM_XER(r0)
    	mtxer   r0
	lwz	r0, STACK_THERM_CTR(r0)
	mtctr	r0
	lwz	r0, STACK_THERM_LR(r0)
	mtlr	r0
	lmw	r1, STACK_THERM_R1(r0)
	lwz	r0, STACK_THERM_R0(r0)
	
	rfi
/*=================================================================*/

/*=================================================================*/

//	.org 0x1800		// stack for ME
//	.skip 0x100
//	.org 0x1900		// stack for DSI
//	.skip 0x100
//	.org 0x1a00		// stack for ISI
//	.skip 0x100
//	.org 0x1b00		// stack for EI
//	.skip 0x100	
//	.org 0x1c00		// stack for AE
//	.skip 0x100
//	.org 0x1d00		// stack for PE
//	.skip 0x100	
//	.org 0x1e00		// stack for FP
//	.skip 0x100
//	.org 0x1f00		// stack for DEC
//	.skip 0x100	

	.org 0x2000	// free space1 for quick functions 128 instructions

// end of free space1 (128 instructions)

	.org 0x2400	// free space2 for quich functions 64  instructions
	.org 0x2600	// free space3 for quich functions 196 instructions
	.org 0x2b00	// free space4 for quich functions 64  instructions
	.org 0x2e00	// free space5 for quich functions 128 instructions
	
	.org 0x8000
START:
ENTRY:
_start:    

	li 	r3, -512			// base tundra Pro
	
	lis 	r4, 0x0000			// PB_ARB_CNTRL <-- 0
	stw 	r4, 0x08(r3)
	
	li 	r4, -1			// reset interrupt controller
	stw 	r4, INT__STATUS(r0)
	isync
	
__eabi:

// Get small data area locations as per PPC EABI

    	addis   r1, r0,__SP_INIT@ha     // Initial STACK_ Pointer
    	addi    r1, r1,__SP_INIT@l      

    	addis   r13, r0,_SDA_BASE_@ha    // Small Data Area
    	addi    r13, r13,_SDA_BASE_@l    

    	addis   r2, r0,_SDA2_BASE_@ha    // Small Data Area 2
    	addi    r2, r2,_SDA2_BASE_@l     

    	bl	main  			// Go to main and NEVER RETURN !

	bl 	disableInterrupt	// disable interrupt and goto stop

deadloop:       			//  Just in case main routine returns, hang forever.                   
    	b	deadloop                 

//   Increment the passed in parameter by one.

//	.globl  addone
//addone:
//    	addi    r3,r3,1 		// increment parameter...
//    	bclr    20,0    		// go back


