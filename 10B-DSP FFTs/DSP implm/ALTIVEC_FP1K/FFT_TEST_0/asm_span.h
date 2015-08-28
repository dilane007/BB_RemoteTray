# span_asm.h

# Base Address of Tundra Span
.set TUNDRA_SPAN_BASE,       0x30000000

# PCI-1 Configuration Registers
.set P1_ID,          			0x000	# PCI-1 ID Register
.set P1_CSR,        			0x004	# PCI-1 Control and Status Register
.set P1_CLASS, 	     		0x008	# PCI-1 Class Register
.set P1_MISC0,       		0x00C	# PCI-1 Miscellaneous 0 Register
.set P1_BSI2O,       		0x010	# PCI-1 I2O Target Image Base Address Register
.set P1_BSREG,       		0x014	# PCI-1 Register Image Base Address Register
.set P1_BST0,   	     		0x018	# PCI-1 Target Image 0 Base Address Register
.set P1_BST1,   	     		0x01C	# PCI-1 Target Image 1 Base Address Register
.set P1_BST2,   	     		0x020	# PCI-1 Target Image 2 Base Address Register
.set P1_BST3,   	     		0x024	# PCI-1 Target Image 3 Base Address Register
.set P1_SID,         			0x02C	# PCI-1 Subsystem ID Register
.set P1_CAP,        	 		0x034	# PCI-1 Capability Pointer Register
.set P1_MISC1,       		0x03C	# PCI-1 Miscellaneous 1 Register
.set P1_HS_CSR,      		0x0E4	# PCI-1 Compact PCI Hot Swap Control and Status Register
.set P1_VPDC,        		0x0E8	# PCI-1 Vital Product Data Capability Register
.set P1_VPDD,        		0x0EC	# PCI-1 Vital Product Data Data Register
.set P1_TI0_CTL,     		0x100	# PCI-1 Target Image 0 Control Register
.set P1_TI0_TADDR,   	0x104	# PCI-1 Target Image 0 Translation Address Register
.set P1_TI1_CTL,     		0x110	# PCI-1 Target Image 1 Control Register
.set P1_TI1_TADDR,   	0x114	# PCI-1 Target Image 1 Translation Address Register
.set P1_TI2_CTL,     		0x120	# PCI-1 Target Image 2 Control Register
.set P1_TI2_TADDR,   	0x124	# PCI-1 Target Image 2 Translation Address Register
.set P1_TI3_CTL,     		0x130	# PCI-1 Target Image 3 Control Register
.set P1_TI3_TADDR,   	0x134	# PCI-1 Target Image 3 Translation Address Register
.set P1_CONF_INFO,   	0x144	# PCI-1 to PCI-2 Configuration Cycle Information Register
.set P1_CONF_DATA,  	0x148	# PCI-1 to PCI-2 Configuration Cycle Data Register
.set P1_IACK,   	     		0x14C	# PCI-1 to PCI-2 Interrupt Acknowledge Cycle Generation Register
.set P1_ERRCS, 	     		 0x150	# PCI-1 Bus Error Control and Status Register
.set P1_AERR,        		0x154	# PCI-1 Address Error Log Register
.set P1_MISC_CSR,    		0x160	# PCI-1 Miscellaneous Control and Status Register
.set P1_ARB_CTRL,    		0x164	# PCI-1 Bus Arbiter Control Register

# Processor Bus Registers
.set PB_SI0_CTL,     		0x200	# 60x Bus Slave Image 0 Control Register
.set PB_SI0_TADDR,  	 	0x204	# 60x Bus Slave Image 0 Translation Address Register
.set PB_SI0_BADDR,   		0x208	# 60x Bus Slave Image 0 Base Address Register
.set PB_SI1_CTL,     		0x210	# 60x Bus Slave Image 1 Control Register
.set PB_SI1_TADDR,  	 	0x214	# 60x Bus Slave Image 1 Translation Address Register
.set PB_SI1_BADDR,   		0x218	# 60x Bus Slave Image 1 Base Address Register
.set PB_SI2_CTL,     		0x220	# 60x Bus Slave Image 2 Control Register
.set PB_SI2_TADDR,  	 	0x224	# 60x Bus Slave Image 2 Translation Address Register
.set PB_SI2_BADDR,   		0x228	# 60x Bus Slave Image 2 Base Address Register
.set PB_SI3_CTL,     		0x230	# 60x Bus Slave Image 3 Control Register
.set PB_SI3_TADDR,  	 	0x234	# 60x Bus Slave Image 3 Translation Address Register
.set PB_SI3_BADDR,   		0x238	# 60x Bus Slave Image 3 Base Address Register
.set PB_SI4_CTL,     		0x240	# 60x Bus Slave Image 4 Control Register
.set PB_SI4_TADDR,  	 	0x244	# 60x Bus Slave Image 4 Translation Address Register
.set PB_SI4_BADDR,   		0x248	# 60x Bus Slave Image 4 Base Address Register
.set PB_SI5_CTL,     		0x250	# 60x Bus Slave Image 5 Control Register
.set PB_SI5_TADDR,  	 	0x254	# 60x Bus Slave Image 5 Translation Address Register
.set PB_SI5_BADDR,   		0x258	# 60x Bus Slave Image 5 Base Address Register
.set PB_SI6_CTL,     		0x260	# 60x Bus Slave Image 6 Control Register
.set PB_SI6_TADDR,  	 	0x264	# 60x Bus Slave Image 6 Translation Address Register
.set PB_SI6_BADDR,   		0x268	# 60x Bus Slave Image 6 Base Address Register
.set PB_SI7_CTL,     		0x270	# 60x Bus Slave Image 7 Control Register
.set PB_SI7_TADDR,  	 	0x274	# 60x Bus Slave Image 7 Translation Address Register
.set PB_SI7_BADDR,   		0x278	# 60x Bus Slave Image 7 Base Address Register
.set PB_REG_BADDR,  		0x280	# 60x Bus Register Image Base Address Register
.set PB_CONF_INFO,  		0x290	# 60x Bus PCI Configuration Cycle Information Register
.set PB_CONF_DATA, 		0x294	# 60x Bus PCI Configuration Cycle Data Register
.set PB_P1_IACK,     		0x2A0	# 60x Bus to PCI 1 Interrupt Acknowledge Cycle Generation Register
.set PB_P2_IACK,     		0x2A4	# 60x Bus to PCI-2 Interrupt Acknowledge Cycle Generation Register
.set PB_ERRCS,       		0x2B0	# 60x Bus Error Control and Status Register
.set PB_AERR,        			0x2B4	# 60x Bus Address Error Log Register
.set PB_MISC_CSR,    		0x2C0	# 60x Bus Miscellaneous Control and Status Register
.set PB_ARB_CTRL,    		0x2D0	# 60x Bus Arbiter Control Register

# DMA Registers
.set DMA0_SRC_ADDR, 	0x304	# DMA0 Source Address Register
.set DMA0_DST_ADDR,  	0x30C	# DMA0 Destination Address Register
.set DMA0_TCR,       		0x314	# DMA0 Transfer Control Register
.set DMA0_CPP,       		0x31C	# DMA0 Command Packet Pointer Register
.set DMA0_GCSR,      		0x320	# DMA0 General Control Register
.set DMA0_ATTR,      		0x324	# DMA0 Attributes Register
.set DMA1_SRC_ADDR,  	0x334	# DMA1 Source Address Register
.set DMA1_DST_ADDR,  	0x33C	# DMA1 Destination Address Register
.set DMA1_TCR,       		0x344	# DMA1 Transfer Control Register
.set DMA1_CPP,       		0x34C	# DMA1 Command Packet Pointer Register
.set DMA1_GCSR,     		0x350	# DMA1 General Control and Status Register
.set DMA1_ATTR,      		0x354	# DMA1 Attributes Register
.set DMA2_SRC_ADDR,  	0x364	# DMA2 Source Address Register
.set DMA2_DST_ADDR,  	0x36C	# DMA2 Destination Address Register
.set DMA2_TCR,       		0x374	# DMA2 Transfer Control Register
.set DMA2_CPP,       		0x37C	# DMA2 Command Packet Pointer Register
.set DMA2_GCSR,     		0x380	# DMA2 General Control and Status Register
.set DMA2_ATTR,      		0x384	# DMA2 Attributes Register
.set DMA3_SRC_ADDR,  	0x394	# DMA3 Source Address Register
.set DMA3_DST_ADDR,  	0x39C	# DMA3 Destination Address Register
.set DMA3_TCR,       		0x3A4	# DMA3 Transfer Control Register
.set DMA3_CPP,       		0x3AC	# DMA3 Command Packet Pointer Register
.set DMA3_GCSR,     		0x3B0	# DMA3 General Control and Status Register
.set DMA3_ATTR,     		0x3B4	# DMA3 Attributes Register

#Miscellaneous Registers
.set MISC_CSR,       		0x400	# Miscellaneous Control and Status Register
.set CLOCK_CTL,      		0x404	# Clock Control Register
.set I2C_CSR,        			0x408	# I_2_C Interface Control and Status Register
.set RST_CSR,        		0x40C	# Reset Control and Status Register
.set ISR0,           			0x410	# Interrupt Status Register 0
.set ISR1,           			0x414	# Interrupt Status Register 1
.set IER0,           			0x418	# Interrupt Enable Register 0
.set IER1,           			0x41C	# Interrupt Enable Register 1
.set IMR_MBOX,       		0x420	# Interrupt Map Register: Mailbox
.set IMR_DB,         			0x424	# Interrupt Map Register: Doorbell
.set IMR_DMA,        		0x428	# Interrupt Map Register: DMA
.set IMR_HW,         		0x42C	# Interrupt Map Register: Hardware
.set IMR_P1,         			0x430	# Interrupt Map Register: P1
.set IMR_P2,         			0x434	# Interrupt Map Register: P2
.set IMR_PB,         			0x438	# Interrupt Map Register: PB
.set IMR2_PB,        			0x43C	# Interrupt Map Register Two: PB
.set IMR_MISC,       		0x440	# Interrupt Map Register: Miscellaneous
.set IDR,            			0x444	# Interrupt Direction Register
.set MBOX0,         			0x450	# Mailbox 0 Register
.set MBOX1,          			0x454	# Mailbox 1 Register
.set MBOX2,          			0x458	# Mailbox 2 Register
.set MBOX3,	       			0x45C	# Mailbox 3 Register
.set MBOX4,          			0x460	# Mailbox 4 Register
.set MBOX5,          			0x464	# Mailbox 5 Register
.set MBOX6,          			0x468	# Mailbox 6 Register
.set MBOX7,          			0x46C	# Mailbox 7 Register
.set SEMA0,          			0x470	# Semaphore 0 Register
.set SEMA1,          			0x474	# Semaphore 1 Register

# I_2_O Registers
.set PCI_TI2O_CTL,   		0x500	# PCI I_2_O Target Image Control Register
.set PCI_TI2O_TADDR, 	0x504	# PCI I_2_O Target Image Translation Address Register
.set I2O_CSR,        			0x508	# I_2_O Control and Status Register
.set I2O_QUEUE_BS,  	 	0x50C	# I_2_O Queue Base Address Register
.set IFL_BOT,        			0x510	# I_2_O Inbound Free List Bottom Pointer Register
.set IFL_TOP,        			0x514	# I_2_O Inbound Free List Top Pointer Register
.set IFL_TOP_INC,   		0x518	# I_2_O Inbound Free List Top Pointer Increment Register
.set IPL_BOT,        			0x51C	# I_2_O Inbound Post List Bottom Pointer Register
.set IPL_BOT_INC,    		0x520	# I_2_O Inbound Post List Bottom Pointer Increment Register
.set IPL_TOP,        			0x524	# I_2_O Inbound Post List Top Pointer Register
.set OFL_BOT,       			0x528	# I_2_O Outbound Free List Bottom Pointer Register
.set OFL_BOT_INC,    		0x52C	# I_2_O Outbound Free List Bottom Pointer Increment Register
.set OFL_TOP,        		0x530	# I_2_O Outbound Free List Top Pointer Register
.set OPL_BOT,        		0x534	# I_2_O Outbound Post List Bottom Pointer Register
.set OPL_TOP,        		0x538	# I_2_O Outbound Post List Top Pointer Register
.set OPL_TOP_INC,    		0x53C	# I_2_O Outbound Post List Top Pointer Increment Register
.set HOST_OIO,       		0x540	# I_2_O Host Outbound Index Offset Register
.set HOST_OIA,       		0x544	# I_2_O Host Outbound Index Alias Register
.set IOP_OI,         			0x548	# I_2_O IOP Outbound Index Register
.set IOP_OI_INC,     		0x54C	# I_2_O IOP Outbound Index Increment Register

# PCI-2 Configuration Registers
.set P2_ID,          			0x800	# PCI-2 ID Register
.set P2_CSR,        			0x804	# PCI-2 Control and Status Register
.set P2_CLASS,      			0x808	# PCI-2 Class Register
.set P2_MISC0,       		0x80C	# PCI-2 Miscellaneous 0 Register
.set P2_BSI2O,       		0x810	# PCI-2 I_2_O Target Image Base Address Register
.set P2_BSREG,       		0x814	# PCI-2 Register Image Base Address Register
.set P2_BST0,        			0x818	# PCI-2 Target Image 0 Base Address Register
.set P2_BST1,        			0x81C	# PCI-2 Target Image 1 Base Address Register
.set P2_BST2,        			0x820	# PCI-2 Target Image 2 Base Address Register
.set P2_BST3,        			0x824	# PCI-2 Target Image 3 Base Address Register
.set P2_SID,         			0x82C	# PCI-2 Subsystem ID Register
.set P2_CAP,        			0x834	# PCI-2 Capability Pointer Register
.set P2_MISC1,      			0x83C	# PCI-2 Miscellaneous 1 Register
.set P2_HS_CSR,      		0x8E4	# PCI-2 Compact PCI Hot Swap Control and Status Register
.set P2_VPDC,        		0x8E8	# PCI-2 Vital Product Data Capability Register
.set P2_VPDD,        		0x8EC	# PCI-2 Vital Product Data Data Register
.set P2_TI0_CTL,     		0x900	# PCI-2 Target Image 0 Control Register
.set P2_TI0_TADDR,  		0x904	# PCI-2 Target Image 0 Translation Address Register
.set P2_TI1_CTL,     		0x910	# PCI-2 Target Image 1 Control Register
.set P2_TI1_TADDR,   	0x914	# PCI-2 Target Image 1 Translation Address Register
.set P2_TI2_CTL,     		0x920	# PCI-2 Target Image 2 Control Register
.set P2_TI2_TADDR,  	 	0x924	# PCI-2 Target Image 2 Translation Address Register
.set P2_TI3_CTL,     		0x930	# PCI-2 Target Image 3 Control Register
.set P2_TI3_TADDR,   	0x934	# PCI-2 Target Image 3 Translation Address Register
.set P2_CONF_INFO,   	0x944	# PCI-2 to PCI 1 Configuration Cycle Information Register
.set P2_CONF_DATA,   	0x948	# PCI-2 to PCI 1 Configuration Cycle Data Register
.set P2_IACK,        			0x94C	# PCI-2 to PCI 1 Interrupt Acknowledge Cycle Generation Register
.set P2_ERRCS,      			0x950	# PCI-2 Bus Error Control and Status Register
.set P2_AERR,        		0x954	# PCI-2 Address Error Log Register
.set P2_MISC_CSR,    		0x960	# PCI-2 Miscellaneous Control and Status Register
.set P2_ARB_CTRL,    		0x964	# PCI-2 Bus Arbiter Control Register


# DMA
.set dmax_tcr_SRC_PORT_P1,  	0x00000000
.set dmax_tcr_SRC_PORT_P2,  	0x40000000
.set dmax_tcr_SRC_PORT_PB,  	0x80000000
.set dmax_tcr_DST_PORT_P1,  	0x00000000
.set dmax_tcr_DST_PORT_P2,  	0x10000000
.set dmax_tcr_DST_PORT_PB,  	0x20000000
.set dmax_tcr_END_LE,  				0x00000000
.set dmax_tcr_END_PPC_LE,  		0x00000000
.set dmax_tcr_END_BE,  				0x00000000

.set dmax_cpp_LAST,  				0x00000001

.set dmax_gcsr_GO,  					0x80000000
.set dmax_gcsr_CHAIN,  			0x40000000
.set dmax_gcsr_STOP_REQ,  0x04000000
.set dmax_gcsr_HALT_REQ,  0x02000000
.set dmax_gcsr_DACT,  0x00800000
.set dmax_gcsr_OFF_0, 		 0x00000000
.set dmax_gcsr_OFF_128, 	 0x00010000
.set dmax_gcsr_OFF_256, 	 0x00020000
.set dmax_gcsr_OFF_512, 	 0x00030000
.set dmax_gcsr_OFF_1024, 	 0x00040000
.set dmax_gcsr_OFF_2048, 	 0x00050000
.set dmax_gcsr_OFF_4096, 	 0x00060000
.set dmax_gcsr_OFF_8192, 	 0x00070000
.set dmax_gcsr_P1_ERR,  0x00002000
.set dmax_gcsr_P2_ERR,  0x00001000
.set dmax_gcsr_PB_ERR,  0x00000800
.set dmax_gcsr_STOP,  0x00000400
.set dmax_gcsr_HALT,  0x00000200
.set dmax_gcsr_DONE,  0x00000100
.set dmax_gcsr_P1_ERR_EN,  0x00000020
.set dmax_gcsr_P2_ERR_EN,  0x00000010
.set dmax_gcsr_PB_ERR_EN,  0x0000008
.set dmax_gcsr_STOP_EN,  0x00000004
.set dmax_gcsr_HALT_EN,  0x00000002
.set dmax_gcsr_DONE_EN,  0x00000001

.set dmax_attr_CP_PORT_P1,  0x00000000
.set dmax_attr_CP_PORT_P2,  0x10000000
.set dmax_attr_CP_PORT_PB,  0x20000000
.set dmax_attr_WRITE_WITH_FLUSH, 0x00000200
.set dmax_attr_WRITE_WITH_KILL, 0x00000600
.set dmax_attr_READ, 0x000A0000
.set dmax_attr_GBL_,  0x10000000
.set dmax_attr_CI_,  0x08000000

# MISC

.set misc_csr_VPD_EN,  0x00008000
.set misc_csr_VPD_CS,  0x00000000
.set misc_csr_ELOAD_OPT,  0x00000000
.set misc_csr_P1_LOCKOUT,  0x00000000
.set misc_csr_P2_LOCKOUT,  0x00000000
.set misc_csr_PCI_ARB_CFG,  0x00000000
.set misc_csr_PCI_M7,  0x00000000
.set misc_csr_PCI_M6,  0x00000000
.set misc_csr_PCI_M5,  0x00000000

.set clock_ctl_PB_TUNE,  0x00000000
.set clock_ctl_P1_TUNE,  0x00000000
.set clock_ctl_P2_TUNE,  0x00000000

.set i2c_csr_RW_W,  0x00000100
.set i2c_csr_ACT,  0x00000080
.set i2c_csr_ERR , 0x00000040
.set rst_csr_PB_RST_DIR,  0x80000000
.set rst_csr_PB_ARB_EN,  0x40000000
.set rst_csr_PB_FAST,  0x20000000
.set rst_csr_PCI_BOOT,  0x10000000
.set rst_csr_CONFIG_SLAVE,  0x08000000
.set rst_csr_P1_RST_DIR,  0x00800000
.set rst_csr_P1_ARB_EN,  0x0040000
.set rst_csr_P1_M66EN,  0x00200000
.set rst_csr_P1_R64_EN,  0x00020000
.set rst_csr_P1_D64,  0x00010000
.set rst_csr_P2_RST_DIR,  0x00008000
.set rst_csr_P2_ARB_EN,  0x00004000
.set rst_csr_P2_M66EN,  0x00002000
.set rst_csr_PRI_PCI,  0x00000100
.set rst_csr_DEBUG_EN,  0x00000040
.set rst_csr_BYPASS_EN,  0x00000020
.set rst_csr_ELOAD,  0x00000008

.set isr0_ISR1_ACTV,  0x80000000
.set isr0_I2O_HOST,  0x20000000
.set isr0_I2O_IOP,  0x10000000
.set isr0_DMA3,  0x08000000
.set isr0_DMA2,  0x04000000
.set isr0_DMA1,  0x02000000
.set isr0_DMA0,  0x01000000
.set isr0_P2_HW,  0x00800000
.set isr0_P1_HW,  0x00400000
.set isr0_INT5_HW,  0x00200000
.set isr0_INT4_HW,  0x00100000
.set isr0_INT3_HW,  0x00080000
.set isr0_INT2_HW,  0x00040000
.set isr0_INT1_HW,  0x00020000
.set isr0_INT0_HW,  0x00010000
.set isr0_DB7,  0x00008000
.set isr0_DB6,  0x00004000
.set isr0_DB5,  0x00002000
.set isr0_DB4,  0x00001000
.set isr0_DB3,  0x00000800
.set isr0_DB2,  0x00000400
.set isr0_DB1,  0x00000200
.set isr0_DB0,  0x00000100
.set isr0_MBOX7,  0x00000080
.set isr0_MBOX6,  0x00000040
.set isr0_MBOX5,  0x00000020
.set isr0_MBOX4,  0x00000010
.set isr0_MBOX3,  0x00000008
.set isr0_MBOX2,  0x00000004
.set isr0_MBOX1,  0x00000002
.set isr0_MBOX0,  0x00000001

.set isr1_ISR0_ACTV,  0x80000000
.set isr1_PB_P1_RETRY,  0x08000000
.set isr1_PB_P2_RETRY,  0x04000000
.set isr1_PB_PB_RETRY,  0x02000000
.set isr1_PB_P1_ERR,  0x00800000
.set isr1_PB_P2_ERR,  0x00400000
.set isr1_PB_PB_ERR,  0x00200000
.set isr1_PB_A_PAR,  0x00100000
.set isr1_PB_P1_D_PAR,  0x00080000
.set isr1_PB_P2_D_PAR,  0x00040000
.set isr1_PB_PB_D_PAR,  0x000200000
.set isr1_P2_P1_ERR,  0x00008000
.set isr1_P2_PB_ERR,  0x00004000
.set isr1_P2_P2_ERR,  0x00002000
.set isr1_P2_A_PAR,  0x000001000
.set isr1_P2_P1_RETRY,  0x00000800
.set isr1_P2_PB_RETRY,  0x00000400
.set isr1_P2_P2_RETRY,  0x00000200
.set isr1_P1_P2_ERR,  0x00000080
.set isr1_P1_PB_ERR,  0x00000040
.set isr1_P1_P1_ERR,  0x00000020
.set isr1_P1_A_PAR,  0x00000010
.set isr1_P1_P2_RETRY,  0x00000008
.set isr1_P1_PB_RETRY,  0x00000004
.set isr1_P1_P1_RETRY,  0x00000002

.set ier0_I2O_HOST_MASK,  0x20000000
.set ier0_I2O_IOP_EN,  0x10000000
.set ier0_DMA3_EN,  0x08000000
.set ier0_DMA2_EN,  0x04000000
.set ier0_DMA1_EN,  0x02000000
.set ier0_DMA0_EN,  0x01000000
.set ier0_P2_HW_EN,  0x00800000
.set ier0_P1_HW_EN,  0x00400000
.set ier0_INT5_HW_EN,  0x00200000
.set ier0_INT4_HW_EN,  0x00100000
.set ier0_INT3_HW_EN,  0x00080000
.set ier0_INT2_HW_EN,  0x00040000
.set ier0_INT1_HW_EN,  0x00020000
.set ier0_INT0_HW_EN,  0x00010000
.set ier0_DB7_EN,  0x00008000
.set ier0_DB6_EN,  0x00004000
.set ier0_DB5_EN,  0x00002000
.set ier0_DB4_EN,  0x00001000
.set ier0_DB3_EN,  0x00000800
.set ier0_DB2_EN,  0x00000400
.set ier0_DB1_EN,  0x00000200
.set ier0_DB0_EN,  0x00000100
.set ier0_MBOX7_EN,  0x00000080
.set ier0_MBOX6_EN,  0x00000040
.set ier0_MBOX5_EN,  0x00000020
.set ier0_MBOX4_EN,  0x00000010
.set ier0_MBOX3_EN,  0x00000008
.set ier0_MBOX2_EN,  0x00000004
.set ier0_MBOX1_EN,  0x00000002
.set ier0_MBOX0_EN,  0x00000001

.set ier1_PB_P1_RETRY_EN,  0x08000000
.set ier1_PB_P2_RETRY_EN,  0x04000000
.set ier1_PB_PB_RETRY_EN,  0x02000000
.set ier1_PB_P1_ERR_EN,  0x0080000
.set ier1_PB_P2_ERR_EN,  0x00400000
.set ier1_PB_PB_ERR_EN,  0x00200000
.set ier1_PB_A_PAR_EN,  0x00100000
.set ier1_PB_P1_D_PAR_EN,  0x00080000
.set ier1_PB_P2_D_PAR_EN,  0x00040000
.set ier1_PB_PB_D_PAR_EN,  0x00020000
.set ier1_P2_P1_ERR_EN,  0x00008000
.set ier1_P2_PB_ERR_EN,  0x00004000
.set ier1_P2_P2_ERR_EN,  0x00002000
.set ier1_P2_A_PAR_EN,  0x00000100
.set ier1_P2_P1_RETRY_EN,  0x00000800
.set ier1_P2_PB_RETRY_EN,  0x00000400
.set ier1_P2_P2_RETRY_EN,  0x00000200
.set ier1_P1_P2_ERR_EN,  0x00000080
.set ier1_P1_PB_ERR_EN,  0x00000040
.set ier1_P1_P1_ERR_EN,  0x00000020
.set ier1_P1_A_PAR_EN,  0x00000010
.set ier1_P1_P2_RETRY_EN,  0x00000008
.set ier1_P1_PB_RETRY_EN,  0x00000004
.set ier1_P1_P1_RETRY_EN,  0x00000002

.set imr_mbox_MBOX7_MAP_P1_INTA,  	0x00000000
.set imr_mbox_MBOX7_MAP_P2_INTA,  	0x20000000
.set imr_mbox_MBOX7_MAP_INT0,  		0x40000000
.set imr_mbox_MBOX7_MAP_INT1,  		0x60000000
.set imr_mbox_MBOX7_MAP_INT2,  		0x80000000
.set imr_mbox_MBOX7_MAP_INT3,  		0xA0000000
.set imr_mbox_MBOX7_MAP_INT4,  		0xC0000000
.set imr_mbox_MBOX7_MAP_INT5,  		0xE0000000
.set imr_mbox_MBOX6_MAP_P1_INTA,  	0x00000000
.set imr_mbox_MBOX6_MAP_P2_INTA,  	0x02000000
.set imr_mbox_MBOX6_MAP_INT0,  		0x04000000
.set imr_mbox_MBOX6_MAP_INT1,  		0x06000000
.set imr_mbox_MBOX6_MAP_INT2,  		0x08000000
.set imr_mbox_MBOX6_MAP_INT3,  		0x0A000000
.set imr_mbox_MBOX6_MAP_INT4,  		0x0C000000
.set imr_mbox_MBOX6_MAP_INT5,  		0x0E000000
.set imr_mbox_MBOX5_MAP_P1_INTA,  	0x00000000
.set imr_mbox_MBOX5_MAP_P2_INTA,  	0x00200000
.set imr_mbox_MBOX5_MAP_INT0,  		0x00400000
.set imr_mbox_MBOX5_MAP_INT1,  		0x00600000
.set imr_mbox_MBOX5_MAP_INT2,  		0x00800000
.set imr_mbox_MBOX5_MAP_INT3,  		0x00A00000
.set imr_mbox_MBOX5_MAP_INT4,  		0x00C00000
.set imr_mbox_MBOX5_MAP_INT5,  		0x00E00000
.set imr_mbox_MBOX4_MAP_P1_INTA,  	0x00000000
.set imr_mbox_MBOX4_MAP_P2_INTA,  	0x00020000
.set imr_mbox_MBOX4_MAP_INT0,  		0x00040000
.set imr_mbox_MBOX4_MAP_INT1,  		0x00060000
.set imr_mbox_MBOX4_MAP_INT2,  		0x00080000
.set imr_mbox_MBOX4_MAP_INT3,  		0x000A0000
.set imr_mbox_MBOX4_MAP_INT4,  		0x000C0000
.set imr_mbox_MBOX4_MAP_INT5,  		0x000E0000
.set imr_mbox_MBOX3_MAP_P1_INTA,  	0x00000000
.set imr_mbox_MBOX3_MAP_P2_INTA,  	0x00002000
.set imr_mbox_MBOX3_MAP_INT0,  		0x00004000
.set imr_mbox_MBOX3_MAP_INT1,  		0x00006000
.set imr_mbox_MBOX3_MAP_INT2,  		0x00008000
.set imr_mbox_MBOX3_MAP_INT3,  		0x0000A000
.set imr_mbox_MBOX3_MAP_INT4,  		0x0000C000
.set imr_mbox_MBOX3_MAP_INT5,  		0x0000E000
.set imr_mbox_MBOX2_MAP_P1_INTA,  	0x00000000
.set imr_mbox_MBOX2_MAP_P2_INTA,  	0x00000200
.set imr_mbox_MBOX2_MAP_INT0,  		0x00000400
.set imr_mbox_MBOX2_MAP_INT1,  		0x00000600
.set imr_mbox_MBOX2_MAP_INT2,  		0x00000800
.set imr_mbox_MBOX2_MAP_INT3,  		0x00000A00
.set imr_mbox_MBOX2_MAP_INT4,  		0x00000C00
.set imr_mbox_MBOX2_MAP_INT5,  		0x00000E00
.set imr_mbox_MBOX1_MAP_P1_INTA,  	0x00000000
.set imr_mbox_MBOX1_MAP_P2_INTA,  	0x00000200
.set imr_mbox_MBOX1_MAP_INT0,  		0x00000400
.set imr_mbox_MBOX1_MAP_INT1,  		0x00000600
.set imr_mbox_MBOX1_MAP_INT2,  		0x00000800
.set imr_mbox_MBOX1_MAP_INT3,  		0x00000A00
.set imr_mbox_MBOX1_MAP_INT4,  		0x00000C00
.set imr_mbox_MBOX1_MAP_INT5,  		0x00000E00
.set imr_mbox_MBOX0_MAP_P1_INTA,  	0x00000000
.set imr_mbox_MBOX0_MAP_P2_INTA,  	0x00000200
.set imr_mbox_MBOX0_MAP_INT0,  		0x00000400
.set imr_mbox_MBOX0_MAP_INT1,  		0x00000600
.set imr_mbox_MBOX0_MAP_INT2,  		0x00000800
.set imr_mbox_MBOX0_MAP_INT3,  		0x00000A00
.set imr_mbox_MBOX0_MAP_INT4,  		0x00000C00
.set imr_mbox_MBOX0_MAP_INT5,  		0x00000E00

.set imr_db_DB7_MAP_P1_INTA,  	0x00000000
.set imr_db_DB7_MAP_P2_INTA,  	0x20000000
.set imr_db_DB7_MAP_INT0,  			0x40000000
.set imr_db_DB7_MAP_INT1,  			0x60000000
.set imr_db_DB7_MAP_INT2,  			0x80000000
.set imr_db_DB7_MAP_INT3,  			0xA0000000
.set imr_db_DB7_MAP_INT4,  			0xC0000000
.set imr_db_DB7_MAP_INT5,  			0xE0000000
.set imr_db_DB6_MAP_P1_INTA,  	0x00000000
.set imr_db_DB6_MAP_P2_INTA,  	0x02000000
.set imr_db_DB6_MAP_INT0,  			0x04000000
.set imr_db_DB6_MAP_INT1,  			0x06000000
.set imr_db_DB6_MAP_INT2,  			0x08000000
.set imr_db_DB6_MAP_INT3,  			0x0A000000
.set imr_db_DB6_MAP_INT4,  			0x0C000000
.set imr_db_DB6_MAP_INT5,  			0x0E000000
.set imr_db_DB5_MAP_P1_INTA, 	0x00000000
.set imr_db_DB5_MAP_P2_INTA,  	0x00200000
.set imr_db_DB5_MAP_INT0,  			0x00400000
.set imr_db_DB5_MAP_INT1,  			0x00600000
.set imr_db_DB5_MAP_INT2,  			0x00800000
.set imr_db_DB5_MAP_INT3,  			0x00A00000
.set imr_db_DB5_MAP_INT4,  			0x00C00000
.set imr_db_DB5_MAP_INT5,  			0x00E00000
.set imr_db_DB4_MAP_P1_INTA,  	0x00000000
.set imr_db_DB4_MAP_P2_INTA,  	0x00020000
.set imr_db_DB4_MAP_INT0,  			0x00040000
.set imr_db_DB4_MAP_INT1,  			0x00060000
.set imr_db_DB4_MAP_INT2,  			0x00080000
.set imr_db_DB4_MAP_INT3,  			0x000A0000
.set imr_db_DB4_MAP_INT4,  			0x000C0000
.set imr_db_DB4_MAP_INT5,  			0x000E0000
.set imr_db_DB3_MAP_P1_INTA,  	0x00000000
.set imr_db_DB3_MAP_P2_INTA,  	0x00002000
.set imr_db_DB3_MAP_INT0,  			0x00004000
.set imr_db_DB3_MAP_INT1,  			0x00006000
.set imr_db_DB3_MAP_INT2,  			0x00008000
.set imr_db_DB3_MAP_INT3,  			0x0000A000
.set imr_db_DB3_MAP_INT4,  			0x0000C000
.set imr_db_DB3_MAP_INT5,  			0x0000E000
.set imr_db_DB2_MAP_P1_INTA,  	0x00000000
.set imr_db_DB2_MAP_P2_INTA,  	0x00000200
.set imr_db_DB2_MAP_INT0,  			0x00000400
.set imr_db_DB2_MAP_INT1,  			0x00000600
.set imr_db_DB2_MAP_INT2,  			0x00000800
.set imr_db_DB2_MAP_INT3,  			0x00000A00
.set imr_db_DB2_MAP_INT4,  			0x00000C00
.set imr_db_DB2_MAP_INT5,  			0x00000E00
.set imr_db_DB1_MAP_P1_INTA,  	0x00000000
.set imr_db_DB1_MAP_P2_INTA,  	0x00000020
.set imr_db_DB1_MAP_INT0,  			0x00000040
.set imr_db_DB1_MAP_INT1,  			0x00000060
.set imr_db_DB1_MAP_INT2,  			0x00000080
.set imr_db_DB1_MAP_INT3,  			0x000000A0
.set imr_db_DB1_MAP_INT4,  			0x000000C0
.set imr_db_DB1_MAP_INT5,  			0x000000E0
.set imr_db_DB0_MAP_P1_INTA,  	0x00000000
.set imr_db_DB0_MAP_P2_INTA,  	0x00000002
.set imr_db_DB0_MAP_INT0,  			0x00000004
.set imr_db_DB0_MAP_INT1,  			0x00000006
.set imr_db_DB0_MAP_INT2,  			0x00000008
.set imr_db_DB0_MAP_INT3,  			0x0000000A
.set imr_db_DB0_MAP_INT4,  			0x0000000C
.set imr_db_DB0_MAP_INT5,  			0x0000000E

.set imr_dma_DMA3_MAP_P1_INTA,  	0x00000000
.set imr_dma_DMA3_MAP_P2_INTA,  	0x00002000
.set imr_dma_DMA3_MAP_INT0,  		0x00004000
.set imr_dma_DMA3_MAP_INT1,  		0x00006000
.set imr_dma_DMA3_MAP_INT2,  		0x00008000
.set imr_dma_DMA3_MAP_INT3,  		0x0000A000
.set imr_dma_DMA3_MAP_INT4,  		0x0000C000
.set imr_dma_DMA3_MAP_INT5,  		0x0000E000
.set imr_dma_DMA2_MAP_P1_INTA,  	0x00000000
.set imr_dma_DMA2_MAP_P2_INTA,  	0x00000200
.set imr_dma_DMA2_MAP_INT0,  		0x00000400
.set imr_dma_DMA2_MAP_INT1,  		0x00000600
.set imr_dma_DMA2_MAP_INT2,  		0x00000800
.set imr_dma_DMA2_MAP_INT3,  		0x00000A00
.set imr_dma_DMA2_MAP_INT4,  		0x00000C00
.set imr_dma_DMA2_MAP_INT5,  		0x00000E00
.set imr_dma_DMA1_MAP_P1_INTA,  	0x00000000
.set imr_dma_DMA1_MAP_P2_INTA,  	0x00000020
.set imr_dma_DMA1_MAP_INT0,  		0x00000040
.set imr_dma_DMA1_MAP_INT1,  		0x00000060
.set imr_dma_DMA1_MAP_INT2,  		0x00000080
.set imr_dma_DMA1_MAP_INT3,  		0x000000A0
.set imr_dma_DMA1_MAP_INT4,  		0x000000C0
.set imr_dma_DMA1_MAP_INT5,  		0x000000E0
.set imr_dma_DMA0_MAP_P1_INTA,  	0x00000000
.set imr_dma_DMA0_MAP_P2_INTA,  	0x00000002
.set imr_dma_DMA0_MAP_INT0,  		0x00000004
.set imr_dma_DMA0_MAP_INT1,  		0x00000006
.set imr_dma_DMA0_MAP_INT2,  		0x00000008
.set imr_dma_DMA0_MAP_INT3,  		0x0000000A
.set imr_dma_DMA0_MAP_INT4,  		0x0000000C
.set imr_dma_DMA0_MAP_INT5,  		0x0000000E

.set imr_hw_P2_HW_MAP_P1_INTA,  	0x00000000
.set imr_hw_P2_HW_MAP_P2_INTA,  	0x20000000
.set imr_hw_P2_HW_MAP_INT0,  			0x40000000
.set imr_hw_P2_HW_MAP_INT1,  			0x60000000
.set imr_hw_P2_HW_MAP_INT2,  			0x80000000
.set imr_hw_P2_HW_MAP_INT3,  			0xA0000000
.set imr_hw_P2_HW_MAP_INT4,  			0xC0000000
.set imr_hw_P2_HW_MAP_INT5,  			0xE0000000
.set imr_hw_P1_HW_MAP_P1_INTA,  	0x00000000
.set imr_hw_P1_HW_MAP_P2_INTA,  	0x02000000
.set imr_hw_P1_HW_MAP_INT0,  			0x04000000
.set imr_hw_P1_HW_MAP_INT1,  			0x06000000
.set imr_hw_P1_HW_MAP_INT2,  			0x08000000
.set imr_hw_P1_HW_MAP_INT3,  			0x0A000000
.set imr_hw_P1_HW_MAP_INT4,  			0x0C000000
.set imr_hw_P1_HW_MAP_INT5,  			0x0E000000
.set imr_hw_INT5_HW_MAP_P1_INTA,  0x00000000
.set imr_hw_INT5_HW_MAP_P2_INTA,  0x00200000
.set imr_hw_INT5_HW_MAP_INT0,  		0x00400000
.set imr_hw_INT5_HW_MAP_INT1,  		0x00600000
.set imr_hw_INT5_HW_MAP_INT2,  		0x00800000
.set imr_hw_INT5_HW_MAP_INT3,  		0x00A00000
.set imr_hw_INT5_HW_MAP_INT4,  		0x00C00000
.set imr_hw_INT5_HW_MAP_INT5,  		0x00E00000
.set imr_hw_INT4_HW_MAP_P1_INTA,  0x00000000
.set imr_hw_INT4_HW_MAP_P2_INTA,  0x00020000
.set imr_hw_INT4_HW_MAP_INT0,  		0x00040000
.set imr_hw_INT4_HW_MAP_INT1,  		0x00060000
.set imr_hw_INT4_HW_MAP_INT2,  		0x00080000
.set imr_hw_INT4_HW_MAP_INT3,  		0x000A0000
.set imr_hw_INT4_HW_MAP_INT4,  		0x000C0000
.set imr_hw_INT4_HW_MAP_INT5,  		0x000E0000
.set imr_hw_INT3_HW_MAP_P1_INTA,  0x00000000
.set imr_hw_INT3_HW_MAP_P2_INTA,  0x00002000
.set imr_hw_INT3_HW_MAP_INT0,  		0x00004000
.set imr_hw_INT3_HW_MAP_INT1,  		0x00006000
.set imr_hw_INT3_HW_MAP_INT2,  		0x00008000
.set imr_hw_INT3_HW_MAP_INT3,  		0x0000A000
.set imr_hw_INT3_HW_MAP_INT4,  		0x0000C000
.set imr_hw_INT3_HW_MAP_INT5,  		0x0000E000
.set imr_hw_INT2_HW_MAP_P1_INTA,  0x00000000
.set imr_hw_INT2_HW_MAP_P2_INTA,  0x00000200
.set imr_hw_INT2_HW_MAP_INT0,  		0x00000400
.set imr_hw_INT2_HW_MAP_INT1,  		0x00000600
.set imr_hw_INT2_HW_MAP_INT2,  		0x00000800
.set imr_hw_INT2_HW_MAP_INT3,  		0x00000A00
.set imr_hw_INT2_HW_MAP_INT4,  		0x00000C00
.set imr_hw_INT2_HW_MAP_INT5,  		0x00000E00
.set imr_hw_INT1_HW_MAP_P1_INTA,  0x00000000
.set imr_hw_INT1_HW_MAP_P2_INTA,  0x00000020
.set imr_hw_INT1_HW_MAP_INT0,  		0x00000040
.set imr_hw_INT1_HW_MAP_INT1,  		0x00000060
.set imr_hw_INT1_HW_MAP_INT2,  		0x00000080
.set imr_hw_INT1_HW_MAP_INT3,  		0x000000A0
.set imr_hw_INT1_HW_MAP_INT4,  		0x000000C0
.set imr_hw_INT1_HW_MAP_INT5,  		0x000000E0
.set imr_hw_INT0_HW_MAP_P1_INTA,  0x00000000
.set imr_hw_INT0_HW_MAP_P2_INTA,  0x00000002
.set imr_hw_INT0_HW_MAP_INT0,  		0x00000004
.set imr_hw_INT0_HW_MAP_INT1,  		0x00000006
.set imr_hw_INT0_HW_MAP_INT2,  		0x00000008
.set imr_hw_INT0_HW_MAP_INT3,  		0x0000000A
.set imr_hw_INT0_HW_MAP_INT4,  		0x0000000C
.set imr_hw_INT0_HW_MAP_INT5,  		0x0000000E

.set imr_p1_P1_P2_ERR_MAP_P1_INTA,  	0x00000000
.set imr_p1_P1_P2_ERR_MAP_P2_INTA,  	0x20000000
.set imr_p1_P1_P2_ERR_MAP_INT0,  		0x40000000
.set imr_p1_P1_P2_ERR_MAP_INT1,  		0x60000000
.set imr_p1_P1_P2_ERR_MAP_INT2,  		0x80000000
.set imr_p1_P1_P2_ERR_MAP_INT3,  		0xA0000000
.set imr_p1_P1_P2_ERR_MAP_INT4,  		0xC0000000
.set imr_p1_P1_P2_ERR_MAP_INT5,  		0xE0000000
.set imr_p1_P1_PB_ERR_MAP_P1_INTA,  	0x00000000
.set imr_p1_P1_PB_ERR_MAP_P2_INTA,  	0x02000000
.set imr_p1_P1_PB_ERR_MAP_INT0,  		0x04000000
.set imr_p1_P1_PB_ERR_MAP_INT1,  		0x06000000
.set imr_p1_P1_PB_ERR_MAP_INT2,  		0x08000000
.set imr_p1_P1_PB_ERR_MAP_INT3,  		0x0A000000
.set imr_p1_P1_PB_ERR_MAP_INT4,  		0x0C000000
.set imr_p1_P1_PB_ERR_MAP_INT5,  		0x0E000000
.set imr_p1_P1_P1_ERR_MAP_P1_INTA,  	0x00000000
.set imr_p1_P1_P1_ERR_MAP_P2_INTA,  	0x00200000
.set imr_p1_P1_P1_ERR_MAP_INT0,  		0x00400000
.set imr_p1_P1_P1_ERR_MAP_INT1,  		0x00600000
.set imr_p1_P1_P1_ERR_MAP_INT2,  		0x00800000
.set imr_p1_P1_P1_ERR_MAP_INT3,  		0x00A00000
.set imr_p1_P1_P1_ERR_MAP_INT4,  		0x00C00000
.set imr_p1_P1_P1_ERR_MAP_INT5,  		0x00E00000
.set imr_p1_P1_A_PAR_MAP_P1_INTA,  	0x00000000
.set imr_p1_P1_A_PAR_MAP_P2_INTA,  	0x00020000
.set imr_p1_P1_A_PAR_MAP_INT0,  			0x00040000
.set imr_p1_P1_A_PAR_MAP_INT1,  			0x00060000
.set imr_p1_P1_A_PAR_MAP_INT2,  			0x00080000
.set imr_p1_P1_A_PAR_MAP_INT3,  			0x000A0000
.set imr_p1_P1_A_PAR_MAP_INT4,  			0x000C0000
.set imr_p1_P1_A_PAR_MAP_INT5,  			0x000E0000
.set imr_p1_P1_P2_RETRY_MAP_P1_INTA,  0x00000000
.set imr_p1_P1_P2_RETRY_MAP_P2_INTA,  0x00002000
.set imr_p1_P1_P2_RETRY_MAP_INT0,  	 0x00004000
.set imr_p1_P1_P2_RETRY_MAP_INT1,  	 0x00006000
.set imr_p1_P1_P2_RETRY_MAP_INT2,  	 0x00008000
.set imr_p1_P1_P2_RETRY_MAP_INT3,  	 0x0000A000
.set imr_p1_P1_P2_RETRY_MAP_INT4,  	 0x0000C000
.set imr_p1_P1_P2_RETRY_MAP_INT5,  	 0x0000E000
.set imr_p1_P1_PB_RETRY_MAP_P1_INTA,  0x00000000
.set imr_p1_P1_PB_RETRY_MAP_P2_INTA,  0x00000200
.set imr_p1_P1_PB_RETRY_MAP_INT0,  	 0x00000400
.set imr_p1_P1_PB_RETRY_MAP_INT1,  	 0x00000600
.set imr_p1_P1_PB_RETRY_MAP_INT2,  	 0x00000800
.set imr_p1_P1_PB_RETRY_MAP_INT3,  	 0x00000A00
.set imr_p1_P1_PB_RETRY_MAP_INT4,  	 0x00000C00
.set imr_p1_P1_PB_RETRY_MAP_INT5,  	 0x00000E00
.set imr_p1_P1_P1_RETRY_MAP_P1_INTA,  0x00000000
.set imr_p1_P1_P1_RETRY_MAP_P2_INTA,  0x00000020
.set imr_p1_P1_P1_RETRY_MAP_INT0,  	 0x00000040
.set imr_p1_P1_P1_RETRY_MAP_INT1,  	 0x00000060
.set imr_p1_P1_P1_RETRY_MAP_INT2,  	 0x00000080
.set imr_p1_P1_P1_RETRY_MAP_INT3,  	 0x000000A0
.set imr_p1_P1_P1_RETRY_MAP_INT4,  	 0x000000C0
.set imr_p1_P1_P1_RETRY_MAP_INT5,  	 0x000000E0

.set imr_p2_P2_P1_ERR_MAP_P1_INTA,  	0x00000000
.set imr_p2_P2_P1_ERR_MAP_P2_INTA,  	0x20000000
.set imr_p2_P2_P1_ERR_MAP_INT0,  		0x40000000
.set imr_p2_P2_P1_ERR_MAP_INT1,  		0x60000000
.set imr_p2_P2_P1_ERR_MAP_INT2,  		0x80000000
.set imr_p2_P2_P1_ERR_MAP_INT3,  		0xA0000000
.set imr_p2_P2_P1_ERR_MAP_INT4,  		0xC0000000
.set imr_p2_P2_P1_ERR_MAP_INT5,  		0xE0000000
.set imr_p2_P2_PB_ERR_MAP_P1_INTA,  	0x00000000
.set imr_p2_P2_PB_ERR_MAP_P2_INTA,  	0x02000000
.set imr_p2_P2_PB_ERR_MAP_INT0,  		0x04000000
.set imr_p2_P2_PB_ERR_MAP_INT1,  		0x06000000
.set imr_p2_P2_PB_ERR_MAP_INT2,  		0x08000000
.set imr_p2_P2_PB_ERR_MAP_INT3,  		0x0A000000
.set imr_p2_P2_PB_ERR_MAP_INT4,  		0x0C000000
.set imr_p2_P2_PB_ERR_MAP_INT5,  		0x0E000000
.set imr_p2_P2_P2_ERR_MAP_P1_INTA,  	0x00000000
.set imr_p2_P2_P2_ERR_MAP_P2_INTA,  	0x00200000
.set imr_p2_P2_P2_ERR_MAP_INT0,  		0x00400000
.set imr_p2_P2_P2_ERR_MAP_INT1,  		0x00600000
.set imr_p2_P2_P2_ERR_MAP_INT2,  		0x00800000
.set imr_p2_P2_P2_ERR_MAP_INT3,  		0x00A00000
.set imr_p2_P2_P2_ERR_MAP_INT4,  		0x00C00000
.set imr_p2_P2_P2_ERR_MAP_INT5,  		0x00E00000
.set imr_p2_P2_A_PAR_MAP_P1_INTA,  	0x00000000
.set imr_p2_P2_A_PAR_MAP_P2_INTA,  	0x00020000
.set imr_p2_P2_A_PAR_MAP_INT0,  		 	0x00040000
.set imr_p2_P2_A_PAR_MAP_INT1,  			0x00060000
.set imr_p2_P2_A_PAR_MAP_INT2,  			0x00080000
.set imr_p2_P2_A_PAR_MAP_INT3,  			0x000A0000
.set imr_p2_P2_A_PAR_MAP_INT4,  			0x000C0000
.set imr_p2_P2_A_PAR_MAP_INT5,  			0x000E0000
.set imr_p2_P2_P1_RETRY_MAP_P1_INTA,  0x00000000
.set imr_p2_P2_P1_RETRY_MAP_P2_INTA,  0x00002000
.set imr_p2_P2_P1_RETRY_MAP_INT0,  	 0x00004000
.set imr_p2_P2_P1_RETRY_MAP_INT1,  	 0x00006000
.set imr_p2_P2_P1_RETRY_MAP_INT2,  	 0x00008000
.set imr_p2_P2_P1_RETRY_MAP_INT3,  	 0x0000A000
.set imr_p2_P2_P1_RETRY_MAP_INT4,  	 0x0000C000
.set imr_p2_P2_P1_RETRY_MAP_INT5,  	 0x0000E000
.set imr_p2_P2_PB_RETRY_MAP_P1_INTA,  0x00000000
.set imr_p2_P2_PB_RETRY_MAP_P2_INTA,  0x00000200
.set imr_p2_P2_PB_RETRY_MAP_INT0,  	 0x00000400
.set imr_p2_P2_PB_RETRY_MAP_INT1,  	 0x00000600
.set imr_p2_P2_PB_RETRY_MAP_INT2,  	 0x00000800
.set imr_p2_P2_PB_RETRY_MAP_INT3,  	 0x00000A00
.set imr_p2_P2_PB_RETRY_MAP_INT4,  	 0x00000C00
.set imr_p2_P2_PB_RETRY_MAP_INT5,  	 0x00000E00
.set imr_p2_P2_P2_RETRY_MAP_P1_INTA,  0x00000000
.set imr_p2_P2_P2_RETRY_MAP_P2_INTA,  0x00000020
.set imr_p2_P2_P2_RETRY_MAP_INT0,  	 0x00000040
.set imr_p2_P2_P2_RETRY_MAP_INT1,  	 0x00000060
.set imr_p2_P2_P2_RETRY_MAP_INT2,  	 0x00000080
.set imr_p2_P2_P2_RETRY_MAP_INT3,  	 0x000000A0
.set imr_p2_P2_P2_RETRY_MAP_INT4,  	 0x000000C0
.set imr_p2_P2_P2_RETRY_MAP_INT5,  	 0x000000E0

.set imr_pb_PB_P1_ERR_MAP_P1_INTA,  	0x00000000
.set imr_pb_PB_P1_ERR_MAP_P2_INTA,  	0x20000000
.set imr_pb_PB_P1_ERR_MAP_INT0,  		0x40000000
.set imr_pb_PB_P1_ERR_MAP_INT1,  		0x60000000
.set imr_pb_PB_P1_ERR_MAP_INT2,  		0x80000000
.set imr_pb_PB_P1_ERR_MAP_INT3,  		0xA0000000
.set imr_pb_PB_P1_ERR_MAP_INT4,  		0xC0000000
.set imr_pb_PB_P1_ERR_MAP_INT5,  		0xE0000000
.set imr_pb_PB_P2_ERR_MAP_P1_INTA,  	0x00000000
.set imr_pb_PB_P2_ERR_MAP_P2_INTA,  	0x02000000
.set imr_pb_PB_P2_ERR_MAP_INT0,  		0x04000000
.set imr_pb_PB_P2_ERR_MAP_INT1,  		0x06000000
.set imr_pb_PB_P2_ERR_MAP_INT2,  		0x08000000
.set imr_pb_PB_P2_ERR_MAP_INT3,  		0x0A000000
.set imr_pb_PB_P2_ERR_MAP_INT4,  		0x0C000000
.set imr_pb_PB_P2_ERR_MAP_INT5,  		0x0E000000
.set imr_pb_PB_PB_ERR_MAP_P1_INTA,  	0x00000000
.set imr_pb_PB_PB_ERR_MAP_P2_INTA,  	0x00200000
.set imr_pb_PB_PB_ERR_MAP_INT0,  		0x00400000
.set imr_pb_PB_PB_ERR_MAP_INT1,  		0x00600000
.set imr_pb_PB_PB_ERR_MAP_INT2,  		0x00800000
.set imr_pb_PB_PB_ERR_MAP_INT3,  		0x00A00000
.set imr_pb_PB_PB_ERR_MAP_INT4,  		0x00C00000
.set imr_pb_PB_PB_ERR_MAP_INT5,  		0x00E00000
.set imr_pb_PB_A_PAR_MAP_P1_INTA,  	0x00000000
.set imr_pb_PB_A_PAR_MAP_P2_INTA,  	0x00020000
.set imr_pb_PB_A_PAR_MAP_INT0,  			0x00040000
.set imr_pb_PB_A_PAR_MAP_INT1,  			0x00060000
.set imr_pb_PB_A_PAR_MAP_INT2,  			0x00080000
.set imr_pb_PB_A_PAR_MAP_INT3,  			0x000A0000
.set imr_pb_PB_A_PAR_MAP_INT4,  			0x000C0000
.set imr_pb_PB_A_PAR_MAP_INT5,  			0x000E0000
.set imr_pb_PB_P1_D_PAR_MAP_P1_INTA,  	0x00000000
.set imr_pb_PB_P1_D_PAR_MAP_P2_INTA,  	0x00002000
.set imr_pb_PB_P1_D_PAR_MAP_INT0,  		0x00004000
.set imr_pb_PB_P1_D_PAR_MAP_INT1,  		0x00006000
.set imr_pb_PB_P1_D_PAR_MAP_INT2,  		0x00008000
.set imr_pb_PB_P1_D_PAR_MAP_INT3,  		0x0000A000
.set imr_pb_PB_P1_D_PAR_MAP_INT4,  		0x0000C000
.set imr_pb_PB_P1_D_PAR_MAP_INT5,  		0x0000E000
.set imr_pb_PB_P2_D_PAR_MAP_P1_INTA,  	0x00000000
.set imr_pb_PB_P2_D_PAR_MAP_P2_INTA,  	0x00000200
.set imr_pb_PB_P2_D_PAR_MAP_INT0,  		0x00000400
.set imr_pb_PB_P2_D_PAR_MAP_INT1,  		0x00000600
.set imr_pb_PB_P2_D_PAR_MAP_INT2,  		0x00000800
.set imr_pb_PB_P2_D_PAR_MAP_INT3,  		0x00000A00
.set imr_pb_PB_P2_D_PAR_MAP_INT4,  		0x00000C00
.set imr_pb_PB_P2_D_PAR_MAP_INT5,  		0x00000E00
.set imr_pb_PB_PB_D_PAR_MAP_P1_INTA,  	0x00000000
.set imr_pb_PB_PB_D_PAR_MAP_P2_INTA,  	0x00000020
.set imr_pb_PB_PB_D_PAR_MAP_INT0,  		0x00000040
.set imr_pb_PB_PB_D_PAR_MAP_INT1,  		0x00000060
.set imr_pb_PB_PB_D_PAR_MAP_INT2,  		0x00000080
.set imr_pb_PB_PB_D_PAR_MAP_INT3,  		0x000000A0
.set imr_pb_PB_PB_D_PAR_MAP_INT4,  		0x000000C0
.set imr_pb_PB_PB_D_PAR_MAP_INT5,  		0x000000E0
.set imr2_pb_PB_P1_RETRY_MAP_P1_INTA,  	0x00000000
.set imr2_pb_PB_P1_RETRY_MAP_P2_INTA,  	0x20000000
.set imr2_pb_PB_P1_RETRY_MAP_INT0,  		0x40000000
.set imr2_pb_PB_P1_RETRY_MAP_INT1,  		0x60000000
.set imr2_pb_PB_P1_RETRY_MAP_INT2,  		0x80000000
.set imr2_pb_PB_P1_RETRY_MAP_INT3,  		0xA0000000
.set imr2_pb_PB_P1_RETRY_MAP_INT4,  		0xC0000000
.set imr2_pb_PB_P1_RETRY_MAP_INT5,  		0xE0000000
.set imr2_pb_PB_P2_RETRY_MAP_P1_INTA,  	0x00000000
.set imr2_pb_PB_P2_RETRY_MAP_P2_INTA,  	0x02000000
.set imr2_pb_PB_P2_RETRY_MAP_INT0,  		0x04000000
.set imr2_pb_PB_P2_RETRY_MAP_INT1,  		0x06000000
.set imr2_pb_PB_P2_RETRY_MAP_INT2,  		0x08000000
.set imr2_pb_PB_P2_RETRY_MAP_INT3,  		0x0A000000
.set imr2_pb_PB_P2_RETRY_MAP_INT4,  		0x0C000000
.set imr2_pb_PB_P2_RETRY_MAP_INT5,  		0x0E000000
.set imr2_pb_PB_PB_RETRY_MAP_P1_INTA,  	0x00000000
.set imr2_pb_PB_PB_RETRY_MAP_P2_INTA,  	0x00200000
.set imr2_pb_PB_PB_RETRY_MAP_INT0,  		0x00400000
.set imr2_pb_PB_PB_RETRY_MAP_INT1,  		0x00600000
.set imr2_pb_PB_PB_RETRY_MAP_INT2,  		0x00800000
.set imr2_pb_PB_PB_RETRY_MAP_INT3,  		0x00A00000
.set imr2_pb_PB_PB_RETRY_MAP_INT4,  		0x00C00000
.set imr2_pb_PB_PB_RETRY_MAP_INT5,  		0x00E00000

.set imr_misc_I2O_HOST_MAP_P1_INTA,  0x00000000
.set imr_misc_I2O_HOST_MAP_P2_INTA,  0x20000000
.set imr_misc_I2O_HOST_MAP_INT0,  		0x40000000
.set imr_misc_I2O_HOST_MAP_INT1,  		0x60000000
.set imr_misc_I2O_HOST_MAP_INT2,  		0x80000000
.set imr_misc_I2O_HOST_MAP_INT3,  		0xA0000000
.set imr_misc_I2O_HOST_MAP_INT4,  		0xC0000000
.set imr_misc_I2O_HOST_MAP_INT5,  		0xE0000000
.set imr_misc_I2O_IOP_MAP_P1_INTA,  	0x00000000
.set imr_misc_I2O_IOP_MAP_P2_INTA,  	0x02000000
.set imr_misc_I2O_IOP_MAP_INT0,		0x04000000
.set imr_misc_I2O_IOP_MAP_INT1,  		0x06000000
.set imr_misc_I2O_IOP_MAP_INT2,  		0x08000000
.set imr_misc_I2O_IOP_MAP_INT3,  		0x0A000000
.set imr_misc_I2O_IOP_MAP_INT4,  		0x0C000000
.set imr_misc_I2O_IOP_MAP_INT5,  		0x0E000000

.set idr_P2_HW_DIR,  0x80000000
.set idr_P1_HW_DIR,  0x40000000
.set idr_INT5_HW_DIR,  0x20000000
.set idr_INT4_HW_DIR,  0x10000000
.set idr_INT3_HW_DIR,  0x08000000
.set idr_INT2_HW_DIR,  0x04000000
.set idr_INT1_HW_DIR,  0x02000000
.set idr_INT0_HW_DIR,  0x01000000
