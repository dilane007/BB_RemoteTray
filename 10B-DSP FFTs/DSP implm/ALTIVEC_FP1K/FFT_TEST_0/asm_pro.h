# pro_asm.h

.set TUNDRA_PRO_BASE,       0xFFFFFE00

# Processor Bus Registers
.set PB_REG_ADDR, 	   		0x000	# PB Base address for registers (Can be altered via Power-up)
.set PB_GEN_CTRL,				0x004	# PB General Control and Configuration
.set PB_ARB_CTRL_PRO,		0x008	# PB Arbiter Control
.set PB_ERR_ATTR,				0x00C	# PB Error log - attributes
.set PB_ERR_ADDR,				0x010	# PB Error log - address
.set PB_AM,						0x014	#	PB Address Match  - Address
.set PB_AM_MASK,				0x018	# PB Address Match 	- Mask
.set VERSION_REG,				0x01C   # PowerPro Version Register !!! new
.set TEST_MODE_SELECT, 	0x01F    # Test Mode Select !!! new


# SDRAM Registers
.set SD_REFRESH,				0x020	# SDRAM Refresh interval
.set SD_TIMING,					0x024	# SDRAM Timing Adjustment
.set PLL_FB_TUNE,				0x028	# PLL Feedback Tuning !!! new
.set SD_B0_ADDR,				0x040	# SDRAM Bank 0 Base Address
.set SD_B0_MASK,				0x044	# SDRAM Bank 0 Base Address Compare Mask
.set SD_B0_CTRL,				0x048	# SDRAM Bank 0 Control
.set SD_B1_ADDR,				0x050	# SDRAM Bank 1 Base Address
.set SD_B1_MASK,				0x054	# SDRAM Bank 1 Base Address Compare Mask
.set SD_B1_CTRL,				0x058	# SD_B1_CTRL SDRAM Bank 1 Control
.set SD_B2_ADDR,				0x060	# SDRAM Bank 2 Base Address
.set SD_B2_MASK,				0x064	# SDRAM Bank 2 Base Address Compare Mask
.set SD_B2_CTRL,				0x068	# SDRAM Bank 2 Control
.set SD_B3_ADDR,				0x070	# SDRAM Bank 3 Base Address
.set SD_B3_MASK,				0x074	# SDRAM Bank 3 Base Address Compare Mask
.set SD_B3_CTRL,				0x078	# SDRAM Bank 3 Control

# FLASH/ROM Registers
.set EE_B0_ADDR,				0x080	# ROM Bank 0 Base Address
.set EE_B0_MASK,				0x084	# ROM Bank 0 Base Address Compare
.set EE_B0_CTRL	,				0x088	# ROM Bank 0 Timing and Control
.set EE_B1_ADDR,				0x090	# ROM Bank 1 Base Address
.set EE_B1_MASK,				0x094	# ROM Bank 1 Base Address Compare Mask
.set EE_B1_CTRL	,				0x098	# ROM Bank 1 Timing and Control
.set EE_B2_ADDR,				0x0A0	# ROM Bank 2 Base Address
.set EE_B2_MASK,				0x0A4	# ROM Bank 2 Base Address Compare Mask
.set EE_B2_CTRL	,				0x0A8	# ROM Bank 2 Timing and Control
.set EE_B3_ADDR,				0x0B0	# ROM Bank 3 Base Address
.set EE_B3_MASK,				0x0B4	# ROM Bank 3 Base Address Compare Mask
.set EE_B3_CTRL	,				0x0B8	# ROM Bank 3 Timing and Control
.set I2C0_CSR,					0x0C0	# I2C Interface #0 (primary) Control and Status
.set I2C1_CSR,					0x0C4	# I2C Interface #1 (secondary) Control and Status

# Watchdog Timer Registers
.set WD_CTRL,					0x0F0	# Watchdog Timer Control
.set WD_TIMEOUT,				0x0F4	# WD_TIMEOUT Watchdog Timer Time-out Value
.set WD_COUNT,				0x0F8	# WD_COUNT   Watchdog Timer Current Count
.set WD_BUS,						0x0FC	# Bus Watchdog Timer !!! new

# Purpose Timer Registers
.set GPT0_COUNT,				0x100	# GPT 0 Time Base Count
.set GPT0_CAPTURE,			0x104	# GPT 0 Capture Triggers
.set GPT1_COUNT,				0x108	# GPT 1 Timer Base Count !!! new
.set GPT0_INT,					0x10C	# GPT 0 Capture / Compare Timer Interrupt Control
.set GPT0_ISTATUS,			0x110	# GPT 0 Capture / Compare Timer Interrupt Status
.set GPT1_CAPTURE,			0x114	# GPT 1 Capture Event !!! new
.set GPT1_INT,					0x118	# GPT 1 Interrupt Control !!! new
.set GPT1_ISTATUS,			0x11C	# GPT 1 Inerrupt Status   !!! new
.set GPT0_T0,					0x120	# GTP 0 Timer Capture Trigger 0
.set GPT0_T1,					0x124	# GPT 0 Timer Capture Trigger 1
.set GPT0_T2,					0x128	# GPT 0 Timer Capture Trigger 2
.set GPT0_T3,					0x12C	# GPT 0 Timer Capture Trigger 3
.set GPT1_T0,					0x130	# GTP 1 Timer Capture Trigger 0 !!! new
.set GPT1_T1,					0x134	# GPT 1 Timer Capture Trigger 1 !!! new
.set GPT1_T2,					0x138	# GPT 1 Timer Capture Trigger 2 !!! new
.set GPT1_T3,					0x13C	# GPT 1 Timer Capture Trigger 3 !!! new
.set GPT0_C0,					0x140	# GPT 0 Timer Compare 0
.set GPT0_C1,					0x144	# GPT 0 Timer Compare 1
.set GPT0_C2,					0x148	# GPT 0 Timer Compare 2
.set GPT0_C3,					0x14C	# GPT 0 Timer Compare 3
.set GPT1_C0,					0x150	# GPT 1 Timer Compare 0 !!! new
.set GPT1_C1,					0x154	# GPT 1 Timer Compare 1 !!! new
.set GPT1_C2,					0x158	# GPT 1 Timer Compare 2 !!! new
.set GPT1_C3,					0x15C	# GPT 1 Timer Compare 3 !!! new
.set GPT0_M0,					0x160	# GPT 0 Timer Compare Mask 0
.set GPT0_M1,					0x164	# GPT 0 Timer Compare Mask 1
.set GPT0_M2,					0x168	# GPT 0 Timer Compare Mask 2
.set GPT0_M3,					0x16C	# GPT 0 Timer Compare Mask 3
.set GPT1_M0,					0x170	# GPT 1 Timer Compare Mask 0 !!! new
.set GPT1_M1,					0x174	# GPT 1 Timer Compare Mask 1 !!! new
.set GPT1_M2,					0x178	# GPT 1 Timer Compare Mask 2 !!! new
.set GPT1_M3,					0x17C	# GPT 1 Timer Compare Mask 3 !!! new

# Interrupt Controller Registers
.set INT_STATUS,				0x180	# Interrupt Status
.set INT_MSTATUS,				0x184	# Interrupt Masked Status
.set INT_ENABLE,				0x188	# Interrupt Enable
.set INT_GENERATE,			0x18C	# Interrupt Generation Type
.set INT_POLARITY,			0x190	# Interrupt Polarity
.set INT_TRIGGER,				0x194	# Interrupt Trigger Type
.set INT_VBADDR,				0x198	# Interrupt Vector Base Address
.set INT_VINC,					0x19C	# Interrupt Vector Increment
.set INT_VECTOR,				0x1A0	# Interrupt Vector Address
.set INT_SOFTSET,				0x1A4	# Interrupt Software Set
.set INT_SOFTSRC,				0x1A8	# Interrupt Controller Software Source !!! new

# UART Registers
.set UART0_Rx_Tx,				0x1B0	# UART0 Receive / Transmit Data
.set UART0_IER,					0x1B1	# UART0 Interrupt Enable
.set UART0_ISTAT_FIFO,		0x1B2	# UART0 Interrupt Status / FIFO Control
.set UART0_LCR,				0x1B3	# UART0 Line Control
.set UART0_MCR,				0x1B4	# UART0 Modem Control
.set UART0_LSR,					0x1B5	# UART0 Line Status
.set UART0_MSR,				0x1B6	# UART0 Modem Status
.set UART0_SCR,				0x1B7	# UART0 Scratchpad
.set UART1_Rx_Tx,				0x1C0	# UART1 Receive / Transmit Data
.set UART1_IER,					0x1C1	# UART1 Interrupt Enable
.set UART1_ISTAT_FIFO,		0x1C2	# UART1 Interrupt Status / FIFO Control
.set UART1_LCR,				0x1C3	# UART1 Line Control
.set UART1_MCR,				0x1C4	# UART1 Modem Control
.set UART1_LSR,					0x1C5	# UART1 Line Status
.set UART1_MSR,				0x1C6	# UART1 Modem Status
.set UART1_SCR,				0x1C7	# UART1Scratchpad

# General Purpose I/O Registers
.set GPIO_A,					0x1E0	# GPIO (enable, mask, direction, data 0-7)
.set GPIO_B,					0x1E4	# GPIO (enable, mask, direction, data 8-15)
.set GPIO_C,					0x1E8	# GPIO (enable, mask, direction, data 16-23)
.set GPIO_D,					0x1EC	# GPIO (enable, mask, direction, data 24-31)
.set GPIO_E,					0x1F0	# GPIO (enable, mask, direction, data 32-39)
.set GPIO_F,					0x1F4	# GPIO (enable, mask, direction, data 40-47)
.set GPIO_G,					0x1F8	# GPIO (enable, mask, direction, data 48-49)

.set pb_reg_addr_DEFAULT, 						0xffffe00
.set pb_gen_ctrl_ECC_TEST,						0x80000000
.set pb_gen_ctrl_PLL_EN,		 					0x00000000
.set pb_gen_ctrl_TEA_EN, 							0x00000010
.set pb_gen_ctrl_ARTRY_EN, 						0x00000008
.set pb_gen_ctrl_DP_EN, 							0x00000004
.set pb_gen_ctrl_AP_EN, 							0x00000002
.set pb_gen_ctrl_PARITY_EVEN, 					0x00000001

.set pb_arb_ctrl_M3_EN_PRO, 						0x00080000
.set pb_arb_ctrl_M2_EN_PRO, 						0x00040000
.set pb_arb_ctrl_M1_EN_PRO, 						0x00020000
.set pb_arb_ctrl_M0_EN_PRO, 						0x00010000
.set pb_arb_ctrl_M3_PRI_PRO, 					0x00000800
.set pb_arb_ctrl_M2_PRI_PRO, 					0x00000400
.set pb_arb_ctrl_M1_PRI_PRO, 					0x00000200
.set pb_arb_ctrl_M0_PRI_PRO, 					0x00000100
.set pb_arb_ctrl_PARK_PRO, 						0x00000004
.set pb_arb_ctrl_BM_PARK3, 						0x00000003
.set pb_arb_ctrl_BM_PARK2, 						0x00000002
.set pb_arb_ctrl_BM_PARK1, 						0x00000001
.set pb_arb_ctrl_BM_PARK0, 						0x00000000

.set pb_err_attr_REG, 									0x80000000
.set pb_err_attr_DPAR, 								0x40000000
.set pb_err_attr_ECC_UC, 							0x20000000
.set pb_err_attr_MES, 								0x02000000
.set pb_err_attr_ES, 									0x01000000
.set pb_err_attr_TT_ERR, 							0x0000000
.set pb_err_attr_SIZ_ERR,							0x0000000
.set pb_err_addr_A, 									0x0000000
.set pb_am_addr_A, 									0x0000000
.set pb_am_mask_M,   								0xffffffff

.set sd_refresh_T, 										0x0000061a
.set sd_timing_ENABLE, 								0x8000000
.set sd_timing_DQM_EN,							0x40000000
.set sd_timing_CL_3, 									0x10000000
.set sd_timing_EX_DP, 								0x04000000
.set sd_timing_TUNE_NO_PIPELINED,  			0x00000000
.set sd_timing_TUNE_ONE_PIPELINED_OUT, 0x01000000
.set sd_timing_TUNE_ONE_PIPELINED_IN,  	0x02000000
.set sd_timing_TUNE_TWO_PIPELINED,  		0x03000000
.set sd_timing_ECC_BYP, 							0x01000000
.set sd_timing_T_RC, 								0x00000000

.set sd_bx_addr_ENABLE, 							0x00000001

.set sd_b0_addr_A, 									0x00000000

.set sd_b1_addr_A, 									0x40000000

.set sd_b2_addr_A, 									0x80000000

.set sd_b3_addr_A, 									0xc0000000

.set sd_bx_mask_M_64K, 							0xffff0000
.set sd_bx_mask_M_16M, 							0xff000000
.set sd_bx_mask_M_32M, 							0xfe000000
.set sd_bx_mask_M_64M, 							0xfc000000
.set sd_bx_mask_M_128M, 						0xf8000000
.set sd_bx_mask_M_256M, 						0xf000000
.set sd_bx_mask_M_512M, 						0xe000000
.set sd_bx_mask_M_1G, 							0xc000000
.set sd_bx_mask_M_2G, 							0x8000000


.set sd_bx_ctrl_ECC_EN, 							0x80000000

.set sd_bx_ctrl_ECC_CE, 							0x40000000

.set sd_bx_ctrl_BUF, 									0x20000000

.set sd_bx_ctrl_NBANK_1PH_2LOG,				0x00000000
.set sd_bx_ctrl_NBANK_1PH_4LOG, 				0x08000000
.set sd_bx_ctrl_NBANK_2PH_2LOG, 				0x10000000
.set sd_bx_ctrl_NBANK_2PH_4LOG, 				0x18000000
.set sd_bx_ctrl_A_MODE_8, 						0x00000000
.set sd_bx_ctrl_A_MODE_9, 						0x01000000
.set sd_bx_ctrl_A_MODE_10, 						0x02000000
.set sd_bx_ctrl_A_MODE_11, 						0x03000000
.set sd_bx_ctrl_A_MODE_12, 						0x04000000
.set sd_bx_ctrl_T_RCD_3, 							0x00800000
.set sd_bx_ctrl_T_RP2, 								0x00100000
.set sd_bx_ctrl_T_RP3, 								0x00200000
.set sd_bx_ctrl_T_RP4, 								0x00300000
.set sd_bx_ctrl_T_RAS5,								0x00010000
.set sd_bx_ctrl_T_RAS6, 							0x00020000
.set sd_bx_ctrl_T_RAS7, 							0x00030000
.set sd_bx_ctrl_T_RAS8, 							0x00040000
.set sd_bx_ctrl_BMGT0, 								0x00008000
.set sd_bx_ctrl_BMGT1, 								0x00004000
.set sd_bx_ctrl_BMGT2, 								0x00002000
.set sd_bx_ctrl_BMGT3, 								0x00001000
.set sd_bx_ctrl_ECC_UC, 							0x00000100
.set sd_bx_ctrl_ECC_CO, 							0x00000000

.set ee_bx_addr_A, 									0x00000000
.set ee_bx_addr_MUX00, 							0x00000000
.set ee_bx_addr_MUX01, 							0x00000002
.set ee_bx_addr_MUX10, 							0x00000004
.set ee_bx_addr_MUX11, 							0x00000006
.set ee_bx_addr_ENABLE,							 0x00000001
.set ee_bx_mask_M, 									0x00000000

.set ee_bx_ctrl_BM, 									0x80000000

.set ee_bx_ctrl_FWE, 									0x40000000

.set ee_bx_ctrl_WAIT, 								0x00000000

.set ee_bx_ctrl_CSON00,					   		 0x00000000
.set ee_bx_ctrl_CSON01,							 0x00400000
.set ee_bx_ctrl_CSON10,							 0x00800000
.set ee_bx_ctrl_CSON11,							 0x00c00000

.set ee_bx_ctrl_OEON00, 							0x00000000
.set ee_bx_ctrl_OEON01, 							0x00100000
.set ee_bx_ctrl_OEON10, 							0x00200000
.set ee_bx_ctrl_OEON11, 							0x00300000
.set ee_bx_ctrl_WEON00, 							0x00000000
.set ee_bx_ctrl_WEON01, 							0x00040000
.set ee_bx_ctrl_WEON10, 							0x00080000
.set ee_bx_ctrl_WEON11, 							0x000c0000
.set ee_bx_ctrl_PORT_SDRAM, 					0x00020000
.set ee_bx_ctrl_WEOFF, 								0x00010000
.set ee_bx_ctrl_THRD, 								0x00004000
.set ee_bx_ctrl_THWR, 								0x00000400
.set ee_bx_ctrl_FWT, 									0x000000b0
.set ee_bx_ctrl_RE, 									0x00000000
.set ee_bx_ctrl_ARE_ASYNC, 						0x00000002
.set ee_bx_ctrl_WIDTH_08, 						0x00000000
.set ee_bx_ctrl_WIDTH_16, 						0x00000001
.set ee_bx_ctrl_WIDTH_32, 						0x00000002
.set ee_bx_ctrl_WIDTH_64, 						0x00000003

.set i2c_csr_ADDR, 									0x00000000
.set i2c_csr_DATA, 									0x00000000
.set i2c_csr_DEV_CODE, 							0x00000000
.set i2c_csr_CS, 										0x00000000
.set i2c_csr_RW_PRO,									0x00000100
.set i2c_csr_ACT_PRO, 								0x00000080
.set i2c_csr_ERR_PRO, 								0x00000040

.set wd_ctrl_ENABLE, 									0x80000000
.set wd_ctrl_WD_RST, 								0x00000001

.set wd_timeout_WDT, 								0x00000000

.set wd_count_WDC, 									0x00000000

.set gpt_count_GPTC, 								0x00000000

.set gpt_capture_SEVT_0, 							0x80000000
.set gpt_capture_SEVT_1, 							0x40000000
.set gpt_capture_SEVT_2, 							0x20000000
.set gpt_capture_SEVT_3, 							0x10000000
.set gpt_capture_SD_AM_0,							0x00800000
.set gpt_capture_SD_AM_1, 						0x00400000
.set gpt_capture_SD_AM_2, 						0x00200000
.set gpt_capture_SD_AM_3, 						0x00100000
.set gpt_capture_EE_AM_0, 						0x00008000
.set gpt_capture_EE_AM_1, 						0x00004000
.set gpt_capture_EE_AM_2, 						0x00002000
.set gpt_capture_EE_AM_3, 						0x00001000
.set gpt_capture_PB_AM_0, 						0x00000080
.set gpt_capture_PB_AM_1, 						0x00000040
.set gpt_capture_PB_AM_2, 						0x00000020
.set gpt_capture_PB_AM_3, 						0x00000010

.set gpt_int_T_IEN_0, 								0x80000000
.set gpt_int_T_IEN_1, 								0x40000000
.set gpt_int_T_IEN_2, 								0x20000000
.set gpt_int_T_IEN_3, 								0x10000000
.set gpt_int_C_IEN_0, 								0x00008000
.set gpt_int_C_IEN_1, 								0x00004000
.set gpt_int_C_IEN_2, 								0x00002000
.set gpt_int_C_IEN_3, 								0x00001000

.set gpt_istatus_T_STAT_0, 						0x80000000
.set gpt_istatus_T_STAT_1, 						0x40000000
.set gpt_istatus_T_STAT_2, 						0x20000000
.set gpt_istatus_T_STAT_3, 						0x10000000
.set gpt_istatus_C_STAT_0, 						0x00008000
.set gpt_istatus_C_STAT_1, 						0x00004000
.set gpt_istatus_C_STAT_2, 						0x00002000
.set gpt_istatus_C_STAT_3, 						0x00001000

.set gpt_tx_TT, 											0x00000000

.set gpt_cx_CT, 										0x00000000

.set gpt_mx_CM, 										0x00000000

.set int_status_STAT, 								0x00000000

.set int_mstatus_MSTAT, 							0x00000000

.set int_enable_IE, 									0x00000000

.set int_generate_IGTYPE, 							0x00000000

.set int_polarity_IPOL, 								0xffffffff

.set int_trigger_ITTYPE, 								0xffffffff

.set int_vbaddr_VA, 									0x00000000


.set int_vinc_PRI_31,									0x00010000
.set int_vinc_VINC_100, 							0x00000000
.set int_vinc_VINC_200, 							0x00000001
.set int_vinc_VINC_400, 							0x00000002
.set int_vinc_VINC_800, 							0x00000003
.set int_vector_V, 										0x00000000

.set int_softset_SINT, 								0x00000000

.set uartx_rx_tx_D, 									0x00

.set uartx_ier_ERBFI,									0x80
.set uartx_ier_ETBEI,									0x40
.set uartx_ier_ELSI, 									0x20
.set uartx_ier_EDSI, 									0x00

.set uartx_istat_fifo_B0, 							0x00
.set uartx_istat_fifo_B1, 							0x00
.set uartx_istat_fifo_B2, 							0x00
.set uartx_istat_fifo_B3, 							0x00
.set uartx_istat_fifo_B6, 							0x00
.set uartx_istat_fifo_B7, 							0x00

.set uartx_lcr_WLEN, 									0x00
.set uartx_lcr_STB, 									0x00
.set uartx_lcr_PEN, 									0x00
.set uartx_lcr_EPS, 									0x00
.set uartx_lcr_SP, 										0x00
.set uartx_lcr_SB, 										0x00
.set uartx_lcr_DLAB, 									0x00

.set uartx_mcr_DTR,								 	0x00
.set uartx_mcr_RTS, 									0x00
.set uartx_mcr_Out1, 								0x00
.set uartx_mcr_Out2, 								0x00
.set uartx_mcr_Loop, 								0x00

.set uartx_lsr_DR, 									0x00
.set uartx_lsr_OE, 									0x00
.set uartx_lsr_PE, 										0x00
.set uartx_lsr_FE, 										0x00
.set uartx_lsr_BI, 										0x00
.set uartx_lsr_THRE, 									0x00
.set uartx_lsr_TEMP, 									0x00
.set uartx_lsr_ERF, 									0x00

.set uartx_msr_DCTS, 								0x00
.set uartx_msr_DDSR, 								0x00
.set uartx_msr_TERI, 								0x00
.set uartx_msr_DDCD, 								0x00
.set uartx_msr_CTS, 									0x00
.set uartx_msr_DSR, 									0x00
.set uartx_msr_RI, 										0x00
.set uartx_msr_DCD, 									0x00

.set uartx_csr_SR, 										0x00

.set uartx_baud_B, 									0x00

.set gpiox_ENABLE_0, 								0x80000000
.set gpiox_ENABLE_1, 								0x40000000
.set gpiox_ENABLE_2, 								0x20000000
.set gpiox_ENABLE_3, 								0x10000000
.set gpiox_ENABLE_4, 								0x08000000
.set gpiox_ENABLE_5, 								0x04000000
.set gpiox_ENABLE_6, 								0x02000000
.set gpiox_ENABLE_7, 								0x01000000

.set gpiox_MASK_0, 									0x00800000
.set gpiox_MASK_1, 									0x00400000
.set gpiox_MASK_2, 									0x00200000
.set gpiox_MASK_3, 									0x00100000
.set gpiox_MASK_4, 									0x00080000
.set gpiox_MASK_5, 									0x00040000
.set gpiox_MASK_6, 									0x00020000
.set gpiox_MASK_7, 									0x00010000

.set gpiox_DIR_0, 										0x00008000
.set gpiox_DIR_1, 										0x00004000
.set gpiox_DIR_2, 										0x00002000
.set gpiox_DIR_3, 										0x00001000
.set gpiox_DIR_4, 										0x00000800
.set gpiox_DIR_5, 										0x00000400
.set gpiox_DIR_6, 										0x00000200
.set gpiox_DIR_7, 										0x00000100

.set gpiox_DATA_0,									0x00000080
.set gpiox_DATA_1,				 					0x00000040
.set gpiox_DATA_2,				 					0x00000020
.set gpiox_DATA_3,				 					0x00000010
.set gpiox_DATA_4,				 					0x00000008
.set gpiox_DATA_5,				 					0x00000004
.set gpiox_DATA_6,				 					0x00000002
.set gpiox_DATA_7,				 					0x00000001



