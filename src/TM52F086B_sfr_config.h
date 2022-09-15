#ifndef __TM52F1376_SFR_CONFIG_H__
#define __TM52F1376_SFR_CONFIG_H__


#define P0_MASK					 (0xff)

/*-------PCOM*******/
#define PCON_MASK        (0XFF)

#define PCON_IDL_MASK    (0X01)
#define PCON_IDL_POS		 (0)
#define PCON_PD_MASK     (0X02)
#define PCON_PD_POS      (1)
#define PCON_GF0_MASK		 (0x04)
#define PCON_GF0_POS		 (2)
#define PCON_GF1_MASK		 (0x08)
#define PCON_GF1_POS		 (3)
#define PCON_SMOD_MASK   (0x80)
#define PCON_SMOD_POS		 (7)

/*--------TCON---------------*/
#define TCON_MASK				(0xff)

/*--------TMOD---------------*/
#define TMOD_MASK				(0xff)
#define TMOD_TMOD0_MASK			(0x03)
#define TMOD_TMOD0_POS			(0)
#define TMOD_CT0N_MASK			(0x04)
#define TMOD_CT0N_POS			  (2)
#define TMOD_GATE0_MASK			(0x08)
#define TMOD_GATE0_POS			(3)
#define TMOD_TMOD1_MASK			(0x30)
#define TMOD_TMOD1_POS			(4)
#define TMOD_CT1N_MASK			(0x40)
#define TMOD_CT1N_POS			  (6)
#define TMOD_GATE1_MASK			(0x80)
#define TMOD_GATE1_POS			(7)

//TL0
#define TL0_MASK				(0xff)
#define TL0_TL0_MASK			(0xff)
#define TL0_TL0_POS				(0)

#define TL1_MASK				(0xff)
#define TL1_TL1_MASK			(0xff)
#define TL1_TL1_POS				(0)

#define TH0_MASK				(0xff)
#define TH0_TH0_MASK			(0xff)
#define TH0_TH0_POS				(0)

#define TH1_MASK				(0xff)
#define TH1_TH1_MASK			(0xff)
#define TH1_TH1_POS				(0)


//SCON
#define SCON_MASK				(0xff)
#define SCON_RI_MASK			(0x01)
#define SCON_RI_POS			(0)
#define SCON_TI_MASK			(0x02)
#define SCON_TI_POS			(1)
#define SCON_RB8_MASK			(0x04)
#define SCON_RB8_POS		(2)
#define SCON_TB8_MASK			(0x08)
#define SCON_TB8_POS		(3)
#define SCON_REN_MASK			(0x10)
#define SCON_REN_POS		(4)
#define SCON_SM2_MASK			(0x20)
#define SCON_SM2_POS		(5)
#define SCON_SM1_MASK     (0X40)
#define SCON_SM1_POS    (6)
#define SCON_SM0_MASK     (0X80)
#define SCON_sm0_pos    (7)

#define P0OE_MASK				(0xff)
#define P0OE_P0OE0_MASK			(0x01)
#define P0OE_P0OE0_POS			(0)
#define P0OE_P0OE1_MASK			(0x02)
#define P0OE_P0OE1_POS			(1)
#define P0OE_P0OE2_MASK			(0x04)
#define P0OE_P0OE2_POS			(2)
#define P0OE_P0OE3_MASK			(0x08)
#define P0OE_P0OE3_POS			(3)
#define P0OE_P0OE4_MASK			(0x10)
#define P0OE_P0OE4_POS			(4)
#define P0OE_P0OE5_MASK			(0x20)
#define P0OE_P0OE5_POS			(5)
#define P0OE_P0OE6_MASK			(0x40)
#define P0OE_P0OE6_POS			(6)
#define P0OE_P0OE7_MASK			(0x80)
#define P0OE_P0OE7_POS			(7)

#define P1LOE_MASK				(0xff)
#define P1LOE_P0LOE_MASK		(0xff)
#define P1LOE_P0LOE_POS			(0)
//////////////////////////////////////////



#define P2MOD_MASK				(0xff)
#define P2MOD_P2MOD0_MASK		(0x03)
#define P2MOD_P2MOD0_POS		(0)
#define P2MOD_P2MOD1_MASK		(0x0c)
#define P2MOD_P2MOD1_POS		(2)


#define OPTION_MASK				  (0xff)
#define OPTION_TM3PSC_MASK  (0X03)
#define OPTION_TM3PSC_POS   (0)
#define OPTION_ADCKS_MASK		(0x0c)
#define OPTION_ADCKS_POS		(2)
#define OPTION_WDTPSC_MASK		(0x30)
#define OPTION_WDTPSC_POS		(4)
#define OPTION_UART1W_MASK		(0x80)
#define OPTION_UART1W_POS		(7)


#define INTFLG_MASK				(0xff)
#define INTFLG_TF3_MASK			(0x01)
#define INTFLG_TF3_POS			(0)
#define INTFLG_PXIF_MASK		(0x02)
#define INTFLG_PXIF_POS			(1)
#define INTFLG_IE2_MASK			(0x04)
#define INTFLG_IE2_POS			(2)
#define INTFLG_ADIF_MASK		(0x10)
#define INTFLG_ADIF_POS			(4)

#define P1WKUP_MASK				(0xff)
#define P1WKUP_P1WKUP0_MASK		(0x01)
#define P1WKUP_P1WKUP0_POS		(0)
#define P1WKUP_P1WKUP1_MASK		(0x02)
#define P1WKUP_P1WKUP1_POS		(1)
#define P1WKUP_P1WKUP2_MASK		(0x04)
#define P1WKUP_P1WKUP2_POS		(2)
#define P1WKUP_P1WKUP3_MASK		(0x08)
#define P1WKUP_P1WKUP3_POS		(3)
#define P1WKUP_P1WKUP4_MASK		(0x10)
#define P1WKUP_P1WKUP4_POS		(4)
#define P1WKUP_P1WKUP5_MASK		(0x20)
#define P1WKUP_P1WKUP5_POS		(5)
#define P1WKUP_P1WKUP6_MASK		(0x40)
#define P1WKUP_P1WKUP6_POS		(6)
#define P1WKUP_P1WKUP7_MASK		(0x80)
#define P1WKUP_P1WKUP7_POS		(7)


#define P0WKUP_MASK				(0xff)
#define P0WKUP_P1WKUP0_MASK		(0x01)
#define P0WKUP_P1WKUP0_POS		(0)
#define P0WKUP_P1WKUP1_MASK		(0x02)
#define P0WKUP_P1WKUP1_POS		(1)
#define P0WKUP_P1WKUP2_MASK		(0x04)
#define P0WKUP_P1WKUP2_POS		(2)
#define P0WKUP_P1WKUP3_MASK		(0x08)
#define P0WKUP_P1WKUP3_POS		(3)
#define P0WKUP_P1WKUP4_MASK		(0x10)
#define P0WKUP_P1WKUP4_POS		(4)
#define P0WKUP_P1WKUP5_MASK		(0x20)
#define P0WKUP_P1WKUP5_POS		(5)
#define P0WKUP_P1WKUP6_MASK		(0x40)
#define P0WKUP_P1WKUP6_POS		(6)
#define P0WKUP_P1WKUP7_MASK		(0x80)
#define P0WKUP_P1WKUP7_POS		(7)


#define P2WKUP_MASK				(0xff)
#define P2WKUP_P1WKUP0_MASK		(0x01)
#define P2WKUP_P1WKUP0_POS		(0)
#define P2WKUP_P1WKUP1_MASK		(0x02)
#define P2WKUP_P1WKUP1_POS		(1)
#define P2WKUP_P1WKUP2_MASK		(0x04)
#define P2WKUP_P1WKUP2_POS		(2)
#define P2WKUP_P1WKUP3_MASK		(0x08)
#define P2WKUP_P1WKUP3_POS		(3)
#define P2WKUP_P1WKUP4_MASK		(0x10)
#define P2WKUP_P1WKUP4_POS		(4)
#define P20WKUP_P1WKUP5_MASK		(0x20)
#define P2WKUP_P1WKUP5_POS		(5)
#define P2WKUP_P1WKUP6_MASK		(0x40)
#define P2WKUP_P1WKUP6_POS		(6)
#define P2WKUP_P1WKUP7_MASK		(0x80)
#define P2WKUP_P1WKUP7_POS		(7)


#define P3WKUP_MASK				(0xff)
#define P3WKUP_P1WKUP0_MASK		(0x01)
#define P3WKUP_P1WKUP0_POS		(0)
#define P3WKUP_P1WKUP1_MASK		(0x02)
#define P3WKUP_P1WKUP1_POS		(1)
#define P3WKUP_P1WKUP2_MASK		(0x04)
#define P3WKUP_P1WKUP2_POS		(2)
#define P3WKUP_P1WKUP3_MASK		(0x08)
#define P3WKUP_P1WKUP3_POS		(3)
#define P3WKUP_P1WKUP4_MASK		(0x10)
#define P3WKUP_P1WKUP4_POS		(4)
#define P30WKUP_P1WKUP5_MASK		(0x20)
#define P3WKUP_P1WKUP5_POS		(5)
#define P3WKUP_P1WKUP6_MASK		(0x40)
#define P3WKUP_P1WKUP6_POS		(6)
#define P3WKUP_P1WKUP7_MASK		(0x80)
#define P3WKUP_P1WKUP7_POS		(7)


#define SWCMD_MASK				(0xff)///!!!


#define PWM0PRDH_MASK			(0xff)
#define PWM0PRDH_PWM0PRDH_MASK	(0xff)
#define PWM0PRDH_PWM0PRDH_POS		(0)

#define PWM0PRDL_MASK    (0XFF)
#define PWM0PRDL_PWM0PRDL_MASK  (0XFF)
#define PEM0PRDL_PWMOPRDL_POS    (0)


#define PWM1PRDH_MASK			(0xff)
#define PWM1PRDH_PWM1PRDH_MASK	(0xff)
#define PWM1PRDH_PWM1PRDH_POS		(0)

#define PWM0PRDL_MASK    (0XFF)
#define PWM1PRDL_PWM1PRDL_MASK  (0XFF)
#define PEM1PRDL_PWM1PRDL_POS    (0)


#define PWM0DH_MASK				(0xff)
#define PWM0DH_PWM0DH_MASK		(0xff)
#define PWM0DH_PWM0DH_POS		(0)
#define PWM0DL_MASK				(0xff)
#define PWM0DL_PWM0DL_MASK		(0xff)
#define PWM0DL_PWM0DL_POS		(0)

#define PWM1DH_MASK				(0xff)
#define PWM1DH_PWM1DH_MASK		(0xff)
#define PWM1DH_PWM1DH_POS		(0)
#define PWM1DL_MASK				(0xff)
#define PWM1DL_PWM1DL_MASK		(0xff)
#define PWM1DL_PWM1DL_POS		(0)

#define PWM2DH_MASK				(0xff)
#define PWM2DH_PWM2DH_MASK		(0xff)
#define PWM2DH_PWM2DH_POS		(0)
#define PWM2DL_MASK				(0xff)
#define PWM2DL_PWM2DL_MASK		(0xff)
#define PWM2DL_PWM2DL_POS		(0)

#define PWM3DH_MASK				(0xff)
#define PWM3DH_PWM2DH_MASK		(0xff)
#define PWM3DH_PWM3DH_POS		(0)
#define PWM3DL_MASK				(0xff)
#define PWM3DL_PWM2DL_MASK		(0xff)
#define PWM3DL_PWM3DL_POS		(0)

#define PWM4DH_MASK				(0xff)
#define PWM4DH_PWM4DH_MASK		(0xff)
#define PWM4DH_PWM4DH_POS		(0)
#define PWM4DL_MASK				(0xff)
#define PWM4DL_PWM4DL_MASK		(0xff)
#define PWM4DL_PWM4DL_POS		(0)

#define PWM5DH_MASK				(0xff)
#define PWM5DH_PWM5DH_MASK		(0xff)
#define PWM5DH_PWM5DH_POS		(0)
#define PWM5DL_MASK				(0xff)
#define PWM5DL_PWM5DL_MASK		(0xff)
#define PWM5DL_PWM5DL_POS		(0)

#define PWM6DH_MASK				(0xff)
#define PWM6DH_PWM6DH_MASK		(0xff)
#define PWM6DH_PWM6DH_POS		(0)
#define PWM6DL_MASK				(0xff)
#define PWM6DL_PWM6DL_MASK		(0xff)
#define PWM6DL_PWM6DL_POS		(0)

#define PWMCON_MASK 						(0XFF)
#define PWMCON_PWM0CKS_MASK  	(0X03)
#define PWMCON_PWM0CKS_POS   	(0)
#define PWMCON_PWM1CKS_MASK    (0X0C)
#define PWMCON_PWM1CKS_POS     (2)
#define PWMCON_PWM2CKS_MASK     (0X30)
#define	PWMCON_PWM2CKS_POS     (4)

#define PWMCON2_MASK     			  (0XFF)
#define PWMCON2_PWM0CLR_MASK     (0X01)
#define PWMCON2_PEM0CLR_POS      (0)
#define PWMCON2_PWM1CLR_MASK     (0X02)
#define PWMCON2_PWM1CLR_POS      (1)
#define PWMCON2_PWM2CLR_MASK   (0X04)
#define PWMCON2_PWM2CLR_POS    (2)
#define PWMCON2_PWM0IE_MASK    (0X10)
#define PWMCON2_PWM0IE_POS     (4)
#define PWMCON2_PWM1IE_MASK    (0X20)
#define PWMCON2_PWM1IE_POS     (5)
#define PWMCON2_PWM2IE_MASK    (0X40)
#define PWMCON2_PWM2IE_POS     (6)

#define P1MODL_MASK				(0xff)
#define P1MODL_P1MOD0_MASK		(0x03)
#define P1MODL_P1MOD0_POS		(0)
#define P1MODL_P1MOD1_MASK		(0x0c)
#define P1MODL_P1MOD1_POS		(2)
#define P1MODL_P1MOD2_MASK		(0x30)
#define P1MODL_P1MOD2_POS		(4)
#define P1MODL_P1MOD3_MASK		(0xc0)
#define P1MODL_P1MOD3_POS		(6)

#define P1MODH_MASK				(0xff)
#define P1MODH_P1MOD4_MASK		(0x03)
#define P1MODH_P1MOD4_POS		(0)
#define P1MODH_P1MOD5_MASK		(0x0c)
#define P1MODH_P1MOD5_POS		(2)
#define P1MODH_P1MOD6_MASK		(0x30)
#define P1MODH_P1MOD6_POS		(4)
#define P1MODH_P1MOD7_MASK		(0xc0)
#define P1MODH_P1MOD7_POS		(6)

#define P3MODL_MASK				(0xff)
#define P3MODL_P3MOD0_MASK		(0x03)
#define P3MODL_P3MOD0_POS		(0)
#define P3MODL_P3MOD1_MASK		(0x0c)
#define P3MODL_P3MOD1_POS		(2)
#define P3MODL_P3MOD2_MASK		(0x30)
#define P3MODL_P3MOD2_POS		(4)
#define P3MODL_P3MOD3_MASK		(0xc0)
#define P3MODL_P3MOD3_POS		(6)


#define P3MODH_MASK				(0xff)
#define P3MODH_P3MOD4_MASK		(0x03)
#define P3MODH_P3MOD4_POS		(0)
#define P3MODH_P3MOD5_MASK		(0x0c)
#define P3MODH_P3MOD5_POS		(2)
#define P3MODH_P3MOD6_MASK		(0x30)
#define P3MODH_P3MOD6_POS		(4)
#define P3MODH_P3MOD7_MASK		(0xc0)
#define P3MODH_P3MOD7_POS		(6)

#define PWMOE0_MASK         (0XFF)
#define PWMOE0_PWM0POE0_MASK    (0X01)
#define PWMOE0_PWM0POE0_POS      (0)
#define PWMOE0_PWM0NOE0_MASK    (0X02)
#define PWMOE0_PWM0NOE0_POS      (1)
#define PWMOE0_PWM0POE1_MASK    (0X04)
#define PWMOE0_PWM0POE1_POS      (2)
#define PWMOE0_PWM0NOE1_MASK    (0X08)
#define PWMOE0_PWM0NOE1_POS      (3)
#define PWMOE0_PWM1OE0_MASK      (0X10)
#define PWMOE0_PWM1OE0_POS        (4)
#define PWMOE0_PWM1OE1_MASK      (0X20)
#define PWMOE0_PWM1OE1_POS        (5)
#define PWMOE0_PWM1OE2_MASK      (0X40)
#define PWMOE0_PWM1OE2_POS        (6)
#define PWMOE0_PWM1OE3_MASK      (0X80)
#define PWMOE0_PWM1OE3_POS        (7)

#define PWMOE1_MASK         	(0XFF)
#define PWMOE1_PWM2OE0_MASK  	(0X01)
#define	PWMOE1_PWM2OE0_POS    (0)
#define PWMOE1_PWM2OE1_MASK  	(0X02)
#define	PWMOE1_PWM2OE1_POS    (1)
#define PWMOE1_PWM3OE0_MASK  	(0X04)
#define	PWMOE1_PWM3OE0_POS    (2)
#define PWMOE1_PWM3OE1_MASK  	(0X08)
#define	PWMOE1_PWM3OE1_POS    (3)
#define PWMOE1_PWM4OE0_MASK  	(0X10)
#define	PWMOE1_PWM4OE0_POS    (4)
#define PWMOE1_PWM4OE1_MASK  	(0X20)
#define	PWMOE1_PWM4OE1_POS    (5)
#define PWMOE1_PWM4OE2_MASK  	(0X40)
#define	PWMOE1_PWM4OE2_POS    (6)
#define PWMOE1_PWM4OE3_MASK  	(0X80)
#define	PWMOE1_PWM4OE3_POS    (7)

#define PWMOE2_MASK (0XFF)
#define PWMOE2_PWM5OE0_MASK 	(0X01)
#define PWMOE2_PWM5OE0_POS   	(0)
#define PWMOE2_PWM5OE1_MASK 	(0X02)
#define PWMOE2_PWM5OE1_POS   	(1)
#define PWMOE2_PWM5OE2_MASK 	(0X04)
#define PWMOE2_PWM5OE2_POS   	(2)
#define PWMOE2_PWM6OE0_MASK 	(0X08)
#define PWMOE2_PWM6OE0_POS   	(3)
#define PWMOE2_PWM6OE1_MASK 	(0X10)
#define PWMOE2_PWM6OE1_POS   	(4)
#define PWMOE2_PWM6OE2_MASK 	(0X20)
#define PWMOE2_PWM6OE2_POS   	(5)
#define PWMOE2_MSCLSEL_MASK   (0X40)
#define PWMOE2_MSCLSEL_POS   	(6)
#define PWMOE2_MSDASEL_MASK   (0X80)
#define PWMOE2_MSDASEL_POS    (7)

#define PINMOD_MASK        		(0XFF)
#define PINMOD_T0OE_MASK  		(0X10)
#define PINMOD_T0OE_POS    		(4)
#define PINMOD_T1OE_MASK  		(0X20)
#define PINMOD_T1OE_POS    		(5)
#define PINMOD_T2OE_MASK  		(0X40)
#define PINMOD_T2OE_POS    		(6)
#define PINMOD_TXRXSEL_MASK  	(0X80)
#define PINMOD_TXRXSEL_POS   	(7)

#define IE_MASK					(0xff)

#define INTE1_MASK      (0XFF)
#define INTE1_TM3IE_MASK   (0X01)
#define INTE1_TM3IE_POS    (0)
#define INTE1_PXIE_MASK    (0X02)
#define INTE1_PXIE_POS     (1)
#define INTE1_EX2_MASK     (0X04)
#define INTE1_EX2_POS      (2)
#define INTE1_ADIE_MASK    (0X08)
#define INTE1_ADIE_POS     (3)
#define INTE1_I2CE_MASK    (0X10)
#define INTE1_I2CE_POS     (4)
#define INTE1_LVDIE_MASK   (0X20)
#define INTE1_LVDIE_POS    (5)
#define INTE1_PWMIE_MASK   (0x80)
#define INTE1_PWMIE_POS    (7)

#define INTFLG2_MASK         (0XFF)
#define INTFLG2_PWM0IE_MASK  (0X20)
#define INTFLG2_PWM0IE_POS   (5)
#define INTFLG2_PWM1IF_MASK  (0X40)
#define INTFLG2_PWM1IF_POS   (6)



#define AUX1_MASK        (0XFF)

#define AUX2_MASK             (0XFF)
#define AUX2_MULDIV16_MASK    (0X01)
#define AUX2_MULDIV16_POS     (0)
#define AUX2_IAPTE_MASK       (0X06)
#define AUX2_IAPTE_POS        (1)
#define AUX2_DIV32_MASK       (0X08)
#define AUX2_DIV32_POS        (3)
#define AUX2_VBGOUT_MASK      (0X10)
#define AUX2_VBGOUT_POS       (4)
#define AUX2_PWRSAV_MASK      (0X20)
#define AUX2_PWRSAV_POS       (5)
#define AUX2_WDTE_MASK        (0XC0)
#define AUX2_WDTE_POS         (6)



#define AUX3_MASK				(0xff)
#define AUX3_ADCVREFS_MASK		(0x03)
#define AUX3_ADCVREFS_POS		(0)
#define AUX3_VBGEN_MASK			(0x4)
#define AUX3_VBGEN_POS			(2)
#define AUX3_TM3PSC_MASK		(0x38)
#define AUX3_TM3PSC_POS			(3)

#define P0DIE_MASK         (0XFF)
#define P0DIE_P0DIE0_MASK  (0X01)
#define P0DIE_P0DIE0_POS   (0)
#define P0DIE_P0DIE1_MASK  (0X02)
#define P0DIE_P0DIE1_POS   (1)
#define P0DIE_P0DIE2_MASK  (0X04)
#define P0DIE_P0DIE2_POS   (2)
#define P0DIE_P0DIE3_MASK  (0X08)
#define P0DIE_P0DIE3_POS   (3)
#define P0DIE_P0DIE4_MASK  (0X10)
#define P0DIE_P0DIE4_POS   (4)
#define P0DIE_P0DIE5_MASK  (0X20)
#define P0DIE_P0DIE5_POS   (5)
#define P0DIE_P0DIE6_MASK  (0X40)
#define P0DIE_P0DIE6_POS   (6)
#define P0DIE_P0DIE7_MASK  (0X80)
#define P0DIE_P0DIE7_POS   (7)


#define T2CON_MASK     (0XFF)



#define RCP2L_MASK				(0xff)
#define RCP2L_RCP2L_MASK	(0xff)
#define RCP2L_RCP2L_POS		(0)

#define RCP2H_MASK				(0xff)
#define RCP2H_RCP2H_MASK	(0xff)
#define RCP2H_RCP2H_POS		(0)

#define TL2_MASK				  (0xff)
#define TL2_TL2_MASK			(0xff)
#define TL2_TL2_POS				(0)

#define TH2_MASK				  (0xff)
#define TH2_TH2_MASK			(0xff)
#define TH2_TH2_POS				(0)

#define ADCDL_MASK        (0XFF)
#define ADCDL_ADCDL_MASK  (0XFF)
#define ADCDL_ADCDL_POS   (0)

#define ADCDH_MASK        (0XFF)
#define ADCDH_ADCDH_MASK  (0XFF)
#define ADCDH_ADCDH_POS   (0)

#define CHSEL_MASK        (0XFF)
#define CHSEL_VBGSEL_MASK (0X03)
#define CHSEL_VBGSEL_POS  (0)
#define CHSEL_ADCVREFS_MASK   (0X04)
#define CHSEL_ADCVREFS_POS (2)
#define CHSEL_ADCHS_MASK  (0XF0)
#define CHSEL_ADCHS_POS   (4)

#define CRCDL_MASK				(0xff)
#define CRCDL_CRCDL_MASK		(0xff)
#define CRCDL_CRCDL_POS			(0)

#define CRCDH_MASK				(0xff)
#define CRCDH_CRCDH_MASK		(0xff)
#define CRCDH_CRCDH_POS			(0)

#define CRCIN_MASK				(0xff)
#define CRCIN_CRCIN_MASK		(0xff)
#define CRCIN_CRCIN_POS			(0)

#define MICON_MASK         (0XFF)
#define MICON_MICR_MASK    (0X03)
#define MICON_MICR_POS     (0)
#define MICON_MISTOP_MASK  (0X04)
#define MICON_MISTOP_POS   (2)
#define MICON_MISTART_MASK (0X08)
#define MICON_MISTART_POS  (3)
#define MICON_MIACKI_MASK  (0X10)
#define MICON_MIACKI_POS   (4)
#define MICON_MIIF_MASK    (0X20)
#define MICON_MIIF_POS     (5)
#define MICON_MIACKO_MASK  (0X40)
#define MICON_MIACKO_POS   (6)
#define MICON_MIEN_MASK    (0X80)
#define MICON_MIEN_POS     (7)

#define MIDAT_MASK    (0XFF)

#define IAPWE_MASK    (0XFF)

#define CFGWH_MASK   (0XFF)
#define CFGWH_LVRE_MASK   (0X3C)
#define CFGWH_LVRE_PPOS   (2)

#define CFGWL_MASK   (0XFF)
#define CFGWL_FRCF_MASK  (0X7F)
#define CFGWL_FRCF_POS    (0)

#define CLKCON_MASK    (0XFF)

#define IPH_MASK         (0XFF)
#define IPH_PX0H_MASK    (0X01)
#define IPH_PX0H_POS     (0)
#define IPH_PT0H_MASK    (0X02)
#define IPH_PT0H_POS     (1)
#define IPH_PX1H_MASK    (0X04)
#define IPH_PX1H_POS     (2)
#define IPH_PT1H_MASK    (0X08)
#define IPH_PT1H_POS     (3)
#define IPH_PSH_MASK     (0X10)
#define IPH_PSH_POS      (4)
#define IPH_PT2H_MASK    (0X20)
#define IPH_PT2H_POS     (5)

#define IP_MASK         (0XFF)
#define IP_PX0_MASK     (0X01)
#define IP_PX0_POS      (0)
#define IP_PT0_MASK     (0X02)
#define IP_PT0_POS      (1)
#define IP_PX1_MASK     (0X04)
#define IP_PX1_POS      (2)
#define IP_PT1_MASK     (0X08)
#define IP_PT1_POS      (3)
#define IP_PS_MASK      (0X10)
#define IP_PS_POS       (4)
#define IP_PT2_MASK     (0X20)
#define IP_PT2_POS      (5)

#define IP1H_MASK        (0XFF)
#define IP1H_PT3H_MASK   (0X01)
#define IP1H_PT3H_POS    (0)
#define IP1H_PPXH_MASK   (0X02)
#define IP1H_PPXH_POS    (1)
#define IP1H_PX2H_MASK   (0X04)
#define IP1H_PX2H_POS    (2)
#define IP1H_PADIH_MASK  (0X08)
#define IP1H_PADIH_POS   (3)
#define IP1H_PI2CH_MASK  (0X10)
#define IP1H_PI2CH_POS   (4)
#define IP1H_PLVDH_MASK  (0X20)
#define IP1H_PLVDH_POS   (5)
#define IP1H_PPWMH_MASK  (0X80)
#define IP1H_PPWMH_POS   (7)

#define IP1_MASK         (0XFF)
#define IP1_PT3_MASK     (0X01)
#define IP1_PT3_POS      (0)
#define IP1_PPX_MASK     (0X02)
#define IP1_PPX_POS      (1)
#define IP1_PX2_MASK     (0X04)
#define IP1_PX2_POS      (2)
#define IP1_PADI_MASK    (0X08)
#define IP1_PADI_POS     (3)
#define IP1_PI2C_MASK    (0X10)
#define IP1_PI2C_POS     (4)
#define IP1_PLVD_MASK    (0X20)
#define IP1_PLVD_POS     (5)
#define IP1_PPWM_MASK    (0X80)
#define IP1_PPWM_POS     (7)

/*--------GPIO---------------*/
//配合PORTIDX使用，指明要配置的PORT口
#define  PORT0   0
#define  PORT1   1
#define  PORT2   2
#define  PORT3   3



//连续4个bit配置一个IO口
#define		PIN_L_Mode_OD 	  	0x01    //开漏
#define		PIN_L_Mode_OD_IPU	  0x00    //开漏带上拉
#define		PIN_L_Mode_OD_IPD	  0x04    //开漏带下拉

#define		PIN_L_Mode_PP		  	0x06      //推挽输出
#define		PIN_L_Mode_ADC		  0x03    //ADC
#define		PIN_L_Mode_LED		  0x07    //LED
#define		PIN_L_Mode_AF 		  0x0B    //PWM TxO CKO
#define		PIN_L_Mode_COM		  0x0F    //LCD 1/2BIAS

#define		PIN_L_Mode_OD_WAKEUP 	  		0x09    //开漏+唤醒
#define		PIN_L_Mode_OD_IPU_WAKEUP	  0x08    //开漏带上拉+唤醒
#define		PIN_L_Mode_OD_IPD_WAKEUP	  0x0C    //开漏带下拉+唤醒

#define		PIN_H_Mode_OD 		  0x10    //开漏
#define		PIN_H_Mode_OD_IPU	  0x00    //开漏带上拉
#define		PIN_H_Mode_OD_IPD	  0x40    //开漏带下拉

#define		PIN_H_Mode_PP		  	0x60    //推挽输出
#define		PIN_H_Mode_ADC		  0x30    //ADC
#define		PIN_H_Mode_LED		  0x70    //LED
#define		PIN_H_Mode_AF 		  0xB0    //PWM TxO CKO
#define		PIN_H_Mode_COM		  0xF0    //LCD 1/2BIAS

#define		PIN_H_Mode_OD_WAKEUP 		    0x90    //开漏+唤醒
#define		PIN_H_Mode_OD_IPU_WAKEUP	  0x80    //开漏带上拉+唤醒
#define		PIN_H_Mode_OD_IPD_WAKEUP	  0xC0    //开漏带下拉+唤醒





#endif







