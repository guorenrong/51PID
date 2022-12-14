/*
******************************************************************************************************
Name		:REGtenxTM52F1376.h
Version		:V1.0
Author		:MFTu
Date		:2020.09.11
******************************************************************************************************
*/
#ifndef __TM52F1376_H__
#define __TM52F1376_H__
/*
******************************************************************************************************
BYTE Registers
******************************************************************************************************
*/
sfr 	P0    		= 0x80;			//Port 0 data
	//--------------------------------------------------------------------------------------------
	sbit 		P0_7		= P0^7;
	sbit 		P0_6		= P0^6;
	sbit 		P0_5		= P0^5;
	sbit 		P0_4		= P0^4;
	sbit 		P0_3		= P0^3;
	sbit 		P0_2		= P0^2;
	sbit 		P0_1		= P0^1;
	sbit 		P0_0		= P0^0;
/*
******************************************************************************************************
*/
sfr 	SP   		= 0x81;			//Stack Point
/*
******************************************************************************************************
*/
sfr 	DPL   		= 0x82;			//Data Point Low byte
sfr 	DPH   		= 0x83;   		//Data Point High byte

/*
******************************************************************************************************
*/
sfr 	INTPORT		= 0x85;   		//
	#define		P3IF		0x08	//Port3 Pin Change Interrupt Flag.
	#define		P2IF		0x04	//Port2 Pin Change Interrupt Flag.
	#define		P1IF		0x02	//Port1 Pin Change Interrupt Flag.
	#define		P0IF		0x01	//Port0 Pin Change Interrupt Flag.
	
/*
******************************************************************************************************
*/
sfr 	INTPWM		= 0x86;   		//
	#define		PWM2IF		0x04	//PWM2 Interrupt Flag. 1: interrupt asserted, write 0 to clear int flag
	#define		PWM1IF		0x02	//PWM1 Interrupt Flag. 1: interrupt asserted, write 0 to clear int flag
	#define		PWM0IF		0x01	//PWM0 Interrupt Flag. 1: interrupt asserted, write 0 to clear int flag

/*
******************************************************************************************************
*/
sfr 	PCON  		= 0x87;			//????????????,????????????
	//--------------------------------------------------------------------------------------------
	#define 	SMOD	0x80		//PCON Bit[7],1=??????????
	//--------------------------------------------------------------------------------------------
	#define 	GF1		0x08		//PCON Bit[3],????????????????
	#define 	GF0		0x04		//PCON Bit[2],????????????????
	//--------------------------------------------------------------------------------------------
	#define 	PD		0x02		//PCON Bit[1],??????1,????????stop????
	//--------------------------------------------------------------------------------------------
	#define 	IDL		0x01		//PCON Bit[0],??????1,????????IDL????
	//---------------------------------------------------------------------------------------------
	#define		ENTER_IDLE_MODE		PCON=(PCON&0xfe)|IDL
	#define		LEAVE_IDLE_MODE		PCON=(PCON&0xfe)
	#define		ENTER_STOP_MODE		PCON=(PCON&0xfd)|PD
	#define		LEAVE_STOP_MODE		PCON=(PCON&0xfd)
	
/*
******************************************************************************************************
*/
sfr 	TCON  		= 0x88;
	//--------------------------------------------------------------------------------------------
	sbit 		TF1 		= TCON^7;	//??????T1????????,??????????????????,TF1??????????????,??CPU????T1????????????????
	sbit 		TR1 		= TCON^6;	//T1??????????????,??1??????T1????
	//--------------------------------------------------------------------------------------------
	sbit 		TF0 		= TCON^5;	//??????T0????????,??????????????????,TF0??????????????,??CPU????T0????????????????
	sbit 		TR0			= TCON^4;	//T0??????????????,??1??????T0????
	//--------------------------------------------------------------------------------------------
	sbit 		IE1 		= TCON^3;	//????????1??????(INT1,P3.3)????;IE1??????????????,??CPU????????????????????IE1(????????????)
	sbit 		IT1 		= TCON^2;	//??????????1??????????????,IT1??0,????????1??????????????????;??INT1??P3.3??????????????,????IE1
	//--------------------------------------------------------------------------------------------
	sbit 		IE0 		= TCON^1;	//????????0??????(INT1,P3.2)????;IE0??????????????,??CPU????????????????????IE0(????????????)
	sbit 		IT0 		= TCON^0;	//??????????0??????????????,IT0??0,????????0??????????????????;??INT0??P3.2??????????????,????IE0
/*
******************************************************************************************************
*/
sfr 	TMOD  		= 0x89;				//????????????,????????????
	//--------------------------------------------------------------------------------------------
	#define 	T1_Mask		~0xf0		//T1????????????Mask
	//--------------------------------------------------------------------------------------------
	#define 	GATE1		0x80		//??????1??????????????
					 	 				//??GATE1=1??,INT1????????????,????TCON????TR1????????1??,????/??????1??????????
					 	 				//??GATE1=0??,????????TR1??????????1??????/??????1??????????
	#define 	CT1			0x40		//????/??????1????????????
					 	 				//CT1=1????????,????????????T1????????????
					 	 				//CT1=0????????,??????????????????????????????
	//--------------------------------------------------------------------------------------------
	#define 	T1_Mode0		0x00		//T1??13??????/??????
	#define 	T1_Mode1		0x10		//T1??16??????/??????
	#define 	T1_Mode2		0x20		//T1??8??????????????/?????? 
	#define 	T1_Mode3		0x30		//timer stop
	//--------------------------------------------------------------------------------------------
	#define 	T0_Mask			~0x0f		//T0????????????Mask
	//--------------------------------------------------------------------------------------------
	#define 	GATE0			0x08		//??????0??????????????
					 	 				//??GATE0=1??,INT0????????????,????TCON????TR0????????1??,????/??????0??????????
					 	 				//??GATE0=0??,????????TR0??????????1??????/??????0??????????
	#define 	CT0				0x04		//????/??????0????????????
					 	 				//CT0=1????????,????????????T0????????????
					 	 				//CT0=0????????,??????????????????????????????
	//--------------------------------------------------------------------------------------------
	#define 	T0_Mode0			0x00		//T0??13??????/?????? 
	#define 	T0_Mode1			0x01		//T0??16??????/?????? 
	#define 	T0_Mode2			0x02		//T0??8??????????????/??????
	#define 	T0_Mode3			0x03		//????????T0,T0??????????????8????????/??????TH0??TL0,??????????T1????????
/*
******************************************************************************************************
*/	
sfr 	TL0   		= 0x8A;				//Timer 0 data low byte
sfr 	TH0   		= 0x8C;				//Timer 0 data high byte
/*
******************************************************************************************************
*/
sfr 	TL1   		= 0x8B;				//Timer 1 data low byte
sfr 	TH1   		= 0x8D;			  //Timer 1 data high byte
/*
******************************************************************************************************
*/
sfr 	SCON2  		= 0x8E;			  //
	#define		SM				0x80
	#define 	UART2_9Bits		SCON2=(SCON2&0x7f)|SM
	#define 	UART2_8Bits		SCON2=(SCON2&0x7f)

	#define		REN2			0x10
	#define 	UART2_RECEPTION_ENABLE		SCON2=(SCON2&0xef)|REN2
	#define 	UART2_RECEPTION_DISABLE		SCON2=(SCON2&0xef)

	#define		TB82		0x08	//Uart2 transmit Bit 8
	#define		RB82		0x04	//Uart2 Receive Bit 8
	#define		TI2			0x02	//Uart2 Transmit interrupt flag
	#define		RI2			0x01	//Uart2  receive interrupt flag
/*
******************************************************************************************************
*/
sfr 	SBUF2  		= 0x8F;			//Uart2 transmit and receive data

/*
******************************************************************************************************
*/
sfr 	P1    		= 0x90;				//Port 1 data
	//--------------------------------------------------------------------------------------------
	sbit 		P1_7		= P1^7;
	sbit 		P1_6		= P1^6;	
	sbit 		P1_5		= P1^5;	
	sbit 		P1_4		= P1^4;	
	sbit 		P1_3		= P1^3;	
	sbit 		P1_2		= P1^2;	
	sbit 		P1_1		= P1^1;	
	sbit 		P1_0		= P1^0;	
/*
******************************************************************************************************
*/
sfr		PORTIDX		= 0x91;				//
	//--------------------------------------------------------------------------------------------
	//PORTIDX:PORTIDX Bit[1:0],	//Pin Mode Index
								//00~11: Port0~Port3 Pin Mode
								//others: Reserved

/*
******************************************************************************************************
*/
sfr 	OPTION    	= 0x94;
	//--------------------------------------------------------------------------------------------
	#define		TM3CKS		0x40		//Timer3 Clock Source Select. 0: SLOW (SXT/SRC), 1: FRC/512 (36KHz)
	
	//--------------------------------------------------------------------------------------------
	//WDT:OPTION Bit[5:4],WDT Prescale.  
	#define		WDTPSC_1	  0x00	  //Watch Dog Timer Prescale 3=Fastest   
	#define		WDTPSC_2		0x10		//Watch Dog Timer Prescale 3=Fastest   
	#define		WDTPSC_3 		0x20		//Watch Dog Timer Prescale 3=Fastest   
	#define		WDTPSC_4 		0x30		//Watch Dog Timer Prescale 3=Fastest   
	
	#define		WDTPSC_00		0x00	  	//Watch Dog Timer Prescale 0  
	#define		WDTPSC_01		0x10		//Watch Dog Timer Prescale 1   
	#define		WDTPSC_02 		0x20		//Watch Dog Timer Prescale 2   
	#define		WDTPSC_03		0x30		//Watch Dog Timer Prescale 3
		
	#define  	WDTPSC0    OPTION=OPTION&0xcf			//Watch Dog Timer Prescale 3=Fastest   
	#define  	WDTPSC1    OPTION=(OPTION&0xcf)|0x10	//Watch Dog Timer Prescale 3=Fastest   
	#define  	WDTPSC2    OPTION=(OPTION&0xcf)|0x20	//Watch Dog Timer Prescale 3=Fastest   
	#define  	WDTPSC3    OPTION=(OPTION&0xcf)|0x30	//Watch Dog Timer Prescale 3=Fastest   
	
	//--------------------------------------------------------------------------------------------
	//ADCKS:OPTION Bit[3:2],ADC Clock Rate 
	#define		ADCKS_Mask		 ~0x0C		//ADC Clock Rate Mask
	#define		ADCKS_sys_32	  0x00	    //Interrupt rate is 32768 system clock cycle
	#define		ADCKS_sys_16		0x04		//Interrupt rate is 16384 system clock cycle
	#define		ADCKS_sys_8 		0x08		// Interrupt rate is 8192 system clock cycle
	#define		ADCKS_sys_4 		0x0c		//Interrupt rate is 128 system clock cycle

/*
******************************************************************************************************
*/
sfr 	INTFLG    	= 0x95;
	//--------------------------------------------------------------------------------------------
	#define		LVDIF	0x80		//Low Voltage Detect Flag, write 0 to clear int flag
	//--------------------------------------------------------------------------------------------
	//#define		TKIF	0x20		//Touch Key ??????????HW clear while TKSOC set
	//--------------------------------------------------------------------------------------------
	#define		ADIF	0x10		//ADC ??????????HW clear while ADSOC set
	//--------------------------------------------------------------------------------------------
	//#define		IE2		0x04		//INT2 ??????????1=????????2????
	//--------------------------------------------------------------------------------------------
	//#define 	P1IF	0x02		//P1??????????????1=P1????????
	//--------------------------------------------------------------------------------------------
	#define 	PCIF	0x02		//Pin Change???????? (INTVEC=43h)
	//--------------------------------------------------------------------------------------------
	#define 	TF3		0x01		//TM3????????,1=TM3????
/*
******************************************************************************************************
*/
sfr		INTPIN		= 0x96;						
	#define		PIN7IF	0x80		//Px.7 Change Interrupt Flag., x define by PINIDX, write 0 to clear int flag
	#define		PIN6IF	0x40		//Px.6 Change Interrupt Flag., x define by PINIDX, write 0 to clear int flag
	#define		PIN5IF	0x20		//Px.5 Change Interrupt Flag., x define by PINIDX, write 0 to clear int flag
	#define		PIN4IF	0x10		//Px.4 Change Interrupt Flag., x define by PINIDX, write 0 to clear int flag
	#define		PIN3IF	0x08		//Px.3 Change Interrupt Flag., x define by PINIDX, write 0 to clear int flag
	#define		PIN2IF	0x04		//Px.2 Change Interrupt Flag., x define by PINIDX, write 0 to clear int flag
	#define		PIN1IF	0x02		//Px.1 Change Interrupt Flag., x define by PINIDX, write 0 to clear int flag
	#define		PIN0IF	0x01		//Px.0 Change Interrupt Flag., x define by PINIDX, write 0 to clear int flag
/*
******************************************************************************************************
*/
sfr		SWCMD		= 0x97;			//Write 56h to this register will generate SW Reset 
									//Write 65h to this register to enable IAP all area, other value to disable IAP all

	#define		WDTO	0x02		//WatchDog Time-Out flag
	#define		IAPALL	0x01		//IAP Enable Control
/*
******************************************************************************************************
*/
sfr 	SCON  		= 0x98;
	//--------------------------------------------------------------------------------------------
	sbit 		SM0 		= SCON^7;	//???????????????????? Bit[0]
	sbit 		SM1 		= SCON^6;	//???????????????????? Bit[1]
	#define		Uart_ModeMask	~0xC0	//????????Mask
	#define		Uart_Mode0		0x00	//00 ????0????????????????????????:??????????/12
	#define		Uart_Mode1		0x40	//01 ????1????????????????T1??T2??????????SMOD????:2SMOD*(T1??????)/32
	#define		Uart_Mode2		0x80	//10 ????2??????????????????????SMOD????:2SMOD*??????????/64
	#define		Uart_Mode3		0xc0	//11 ????3????????????????T1??T2??????????SMOD????:2SMOD*(T1??????)/32
	
	//--------------------------------------------------------------------------------------------
	sbit 		SM2 		= SCON^5;	//??????????????*/
										//????????????????????2??????3??SM2??????????????2??????3????????
					 	 				//??????????????????2??3:
					 	 				//??SM2=1??,??????????????9??????(RB8)??1??,??????????????8??????????SBUF,??????RI????????????,????????????????????????
					 	 				//??SM2=0??,????????9????????0????1,????????????SBUF,??????????????,??????????0????SM2??????0
	//--------------------------------------------------------------------------------------------
	sbit 		REN 		= SCON^4;	//??????????:
					 	 				//REN????????????????????????????,REN=1??,????????,REN=0??,????????
	//--------------------------------------------------------------------------------------------
	sbit 		TB8 		= SCON^3;	//??????????8??
	sbit 		RB8 		= SCON^2;	//??????????8??
	//--------------------------------------------------------------------------------------------
	sbit 		TI 			= SCON^1;	//????????????????
					 	 				//????0??,????????8????????,??????????
					 	 				//??????????,??????????,TI=1??????????????,TI????????????
	//--------------------------------------------------------------------------------------------
	sbit 		RI 			= SCON^0;	//????????????????
					 	 				//????0??,????????8????????,??????????
					 	 				//??????????,??????????,RI=1??????????????
/*
******************************************************************************************************
*/
sfr 	SBUF  		= 0x99;				//??????????????,UART transmit and receive data
/*
******************************************************************************************************
*/
sfr 	P2    		= 0xA0;			//Port 2 data
	//--------------------------------------------------------------------------------------------
	sbit 		P2_5		= P2^5;	
	sbit 		P2_4		= P2^4;	
	sbit 		P2_3		= P2^3;	
	sbit 		P2_2		= P2^2;	
	sbit 		P2_1		= P2^1;	
	sbit 		P2_0		= P2^0;							
/*
******************************************************************************************************
*/
sfr		PWMCON		= 0xA1;
	//--------------------------------------------------------------------------------------------
	//PWM2CKS:PWMCON Bit[5:4],PWM2 Clock source. 3=IRC18M*2, 2=IRC18M, 1=Cpuclk, 

	//--------------------------------------------------------------------------------------------
	//PWM1CKS:PWMCON Bit[3:2],PWM1 Clock source. 3=IRC18M*2, 2=IRC18M, 1=Cpuclk, 

	//--------------------------------------------------------------------------------------------
	//PWM0CKS:PWMCON Bit[1:0],PWM0 Clock source. 3=IRC18M*2, 2=IRC18M, 1=Cpuclk, 

/*
******************************************************************************************************
*/
sfr		PINMOD10		= 0xA2;
	//--------------------------------------------------------------------------------------------
	//PINMOD1:PINMOD10 Bit[7:4],Px.1 Pin Control, x define by PINIDX

	//--------------------------------------------------------------------------------------------
	//PINMOD0:PINMOD10 Bit[3:0],Px.0 Pin Control, x define by PINIDX

/*
******************************************************************************************************
*/
sfr		PINMOD32		= 0xA3;
	//--------------------------------------------------------------------------------------------
	//PINMOD3:PINMOD32 Bit[7:4],Px.3 Pin Control, x define by PINIDX

	//--------------------------------------------------------------------------------------------
	//PINMOD2:PINMOD32 Bit[3:0],Px.2 Pin Control, x define by PINIDX

/*
******************************************************************************************************
*/
sfr		PINMOD54		= 0xA4;
	//--------------------------------------------------------------------------------------------
	//PINMOD5:PINMOD54 Bit[7:4],Px.5 Pin Control, x define by PINIDX

	//--------------------------------------------------------------------------------------------
	//PINMOD4:PINMOD54 Bit[3:0],Px.4 Pin Control, x define by PINIDX

/*
******************************************************************************************************
*/
sfr		PINMOD76		= 0xA5;
	//--------------------------------------------------------------------------------------------
	//PINMOD7:PINMOD76 Bit[7:4],Px.7 Pin Control, x define by PINIDX

	//--------------------------------------------------------------------------------------------
	//PINMOD6:PINMOD76 Bit[3:0],Px.6 Pin Control, x define by PINIDX

/*
******************************************************************************************************
*/
sfr 	PINMOD  		= 0xA6;
	#define		HSNK2EN		0x80//Pin H-sink enable (Group 2 = P06, P07, P22~P25, P30~P33)
								//0: Group 2 H-sink disable
								//1: Group 2 H-sink enable

	#define		HSNK1EN		0x40//Pin H-sink enable (Group 1 = P04, P05, P10~P17)
								//0: Group 1 H-sink disable
								//1: Group 1 H-sink enable

	#define		HSNK0EN		0x20//Pin H-sink enable  (Group 0 = P00~P03, P20, P21, P34~P37)
								//0: Group 0 H-sink disable
								//1: Group 0 H-sink enable

	#define		IICPS		0x10//IIC Pin Select
								//0: SCL/SDA = P0.0/P0.1
								//1: SCL/SDA = P3.0/P3.1
								
	//--------------------------------------------------------------------------------------------
	//UART2PS:PINMOD Bit[3:2],UART2 Pin Select
							//00: RXD2/TXD2 = P0.0/P0.1
							//01: RXD2/TXD2 = P3.5/P3.6
							//10: RXD2/TXD2 = P0.1/P0.0
							//11: RXD2/TXD2 = P3.6/P3.5							
	
	//--------------------------------------------------------------------------------------------
	//UARTPS:PINMOD Bit[1:0],UART Pin Select
							//00: RXD/TXD = P3.0/P3.1
							//01: RXD/TXD = P3.2/P3.3
							//10: RXD/TXD = P3.1/P3.0
							//11: RXD/TXD = P3.3/P3.2
	
//------------------------------------------------------------------------------------------------------------
sfr		PWMCON2			=0xA7;
	#define		PWM2IE			0x40	//PWM2 Interrupt Enable. 1: enable, 0: disable
	#define		PWM1IE			0x20	//PWM1 Interrupt Enable. 1: enable, 0: disable
	#define		PWM0IE			0x10	//PWM0 Interrupt Enable. 1: enable, 0: disable

	#define		PWM2CLR			0x04	//Clear PWM2
	#define		PWM1CLR			0x02	//Clear PWM1
	#define		PWM0CLR			0x01	//Clear PWM0
/*
******************************************************************************************************
*/
sfr 	IE    		= 0xA8;
	//--------------------------------------------------------------------------------------------
	sbit 		EA 			= IE^7;		//EA=0??,????????????;EA=1??,??????????????????????????????
	sbit		ET2			= IE^5;		//????2????????
	sbit 		ES 			= IE^4;		//??????????????(ES=1????,ES=0????)
	sbit 		ET1 		= IE^3;		//????1????????
	sbit 		EX1 		= IE^2;		//??????INT1????????
	sbit 		ET0 		= IE^1;		//??????0????????
	sbit 		EX0 		= IE^0;		//????????INT0??????????
/*
******************************************************************************************************
*/
sfr		INTE1		= 0xA9;
	#define		PWMIE		0x80		//PWM Interrupt Enable ????????
	//--------------------------------------------------------------------------------------------
	#define		I2CE		0x40		//I2C Interrupt Enable ????????
	//--------------------------------------------------------------------------------------------
	#define		ES2			0x20		//Uart2 Interrupt Enable ????????
	//--------------------------------------------------------------------------------------------
	//#define		SPIE		0x10		//SPI ????????
	//--------------------------------------------------------------------------------------------
	#define		ADIE 		0x08		//ADC/Touch Key  ????????
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	#define		LVDIE		0x04		//LVD ????????
	//--------------------------------------------------------------------------------------------
	#define	 	PCIE		0x02		//Pin????????????
	//--------------------------------------------------------------------------------------------
	#define		TM3IE		0x01		//TM3????????		
/*
******************************************************************************************************
*/
sfr		ADCDL		= 0xAA;
	//--------------------------------------------------------------------------------------------
	//ADCDL:ADCDL Bit[7:4],ADC Data 3~0

/*
******************************************************************************************************
*/
sfr		ADCDH		= 0xAB;//ADC Data 11~4
	//--------------------------------------------------------------------------------------------
	//ADCDH:ADCDH Bit[7:0],ADC Data 11~4
	
/*
******************************************************************************************************
*/
sfr 	P3    		= 0xB0;				//Port 3 data
	//--------------------------------------------------------------------------------------------
	sbit 		P3_7		= P3^7;
	sbit 		P3_6		= P3^6;
	sbit 		P3_5		= P3^5;
	sbit 		P3_4		= P3^4;
	sbit 		P3_3		= P3^3;
	sbit 		P3_2		= P3^2;
	sbit 		P3_1		= P3^1;
	sbit 		P3_0		= P3^0;
/*
******************************************************************************************************
*/
sfr		LEDCON		= 0xB1;
							
	//LED PN-Mode Enable, 0:LED disable, 1: 1/8 duty, 2: 1/9 duty, 3: 1/10 duty
	#define	LEDEN_DIV8		0x40
	#define	LEDEN_DIV9		0x80
	#define	LEDEN_DIV10		0xC0
	
	#define LEDEN_DUTY_DIV8		LEDCON=(LEDCON&0x3f)|LEDEN_DIV8
	#define LEDEN_DUTY_DIV9		LEDCON=(LEDCON&0x3f)|LEDEN_DIV9
	#define LEDEN_DUTY_DIV10	LEDCON=(LEDCON&0x3f)|LEDEN_DIV10
	#define LEDEN_DISABLE		LEDCON=(LEDCON&0x3f)
	
	//LEDPSC:LEDCON Bit[5:4],
	//LED Clock divided by, 0: 64, 1: 32, 2: 16  3: 8  ( LEDCLK  > 100K )
	#define	LEDPSC_64	0x00
	#define	LEDPSC_32	0x10
	#define	LEDPSC_16	0x20
	#define	LEDPSC_8	0x30

	//LED hold , 1:hold LED scan, all LED pin state are Hi-Z, 0: release to run LED scan
	#define LEDHOLD		0x08
	#define	LEDHOLD_HOLD	LEDCON=(LEDCON&0xf7)|LEDHOLD
	#define	LEDHOLD_RELEASE	LEDCON=(LEDCON&0xf7)

	//LEDBRIT:LEDCON Bit[2:0]
	//LED SEG0-~3- & COM0-~3- Brightness. 000: Most darkness, 111: Most brightness
	#define	LCDBRIT_0	0x00	// most darkness
	#define	LCDBRIT_1	0x01	// 
	#define	LCDBRIT_2	0x02	// 
	#define	LCDBRIT_3	0x03	// 
	#define	LCDBRIT_4	0x04	// 
	#define	LCDBRIT_5	0x05	// 
	#define	LCDBRIT_6	0x06	// 
	#define	LCDBRIT_7	0x07	// Most brightness
/*
******************************************************************************************************
*/
sfr		LEDCON2		= 0xB2;

	#define LEDBRTM 0x80		//brightness control
								//0: Uniform brightness mode (????????????)
								//1: Brightness enhancement mode (????????????)

	//LEDBRIT2:LEDCON2 Bit[6:4],"LED PN Mode:LED SEG5- Brightness. 000: Most darkness, 111: Most brightness
								//LED BD Mode: Brightness. 000: Most darkness, 111: Most brightness"
	#define	LCDBRIT2_0	0x00	// most darkness
	#define	LCDBRIT2_1	0x10	// 
	#define	LCDBRIT2_2	0x20	// 
	#define	LCDBRIT2_3	0x30	// 
	#define	LCDBRIT2_4	0x40	// 
	#define	LCDBRIT2_5	0x50	// 
	#define	LCDBRIT2_6	0x60	// 
	#define	LCDBRIT2_7	0x70	// Most brightness
	
	#define LEDMTEN 0x08		//0: LED BD-Mode disable
								//1: LED BD-Mode enable
	
	//LEDBRIT1:LEDCON2 Bit[2:0],LED SEG4- Brightness. 000: Most darkness, 111: Most brightness
	#define	LCDBRIT1_0	0x00	// most darkness
	#define	LCDBRIT1_1	0x01	// 
	#define	LCDBRIT1_2	0x02	// 
	#define	LCDBRIT1_3	0x03	// 
	#define	LCDBRIT1_4	0x04	// 
	#define	LCDBRIT1_5	0x05	// 
	#define	LCDBRIT1_6	0x06	// 
	#define	LCDBRIT1_7	0x07	// Most brightness	

/*
******************************************************************************************************
*/
sfr		ADCHS		= 0xB6;
	//ADCHS:ADCHS,Bit[4:0]
	//ADC Channel Select
	//00000: AD0 (P0.4)
	//00001: AD1 (P0.5)
	//00010: AD2 (P2.0)
	//00011: AD3 (P2.1)
	//00100: AD4 (P1.0)
	//00101: AD5 (P1.1)
	//00110: AD6 (P1.2)
	//00111: AD7 (P1.3)
	//01000: AD8 (P1.4)
	//01001: AD9 (P1.5)
	//01010: AD10 (P1.6)
	//01011: VBG (Internal Bandgap Reference Voltage)
	//01100: AD12 (P1.7)
	//01101: AD13 (P2.2)
	//01110: AD14 (P2.3)
	//01111: AD15 (P2.4)
	//10000:AD16 (P2.5)
	//10001:AD17 (P0.6)
	//10010:AD18 (P0.7)
	//10011:AD19 (P0.0)
	//10100:AD20 (P0.1)
	//10101:AD21 (P0.2)
	//10110:AD22 (P0.3)
	//10111:1/4VCC

/*
******************************************************************************************************
*/
sfr 	IP    		= 0xB8;
	//--------------------------------------------------------------------------------------------
	sbit		PT2			  = IP^5;		//????2??????????????
	sbit 		PS			  = IP^4;		//????????????????????
	sbit 		PT1	    	= IP^3;		//????1??????????????
	sbit 		PX1	    	= IP^2;		//??????INT1??????????????
	sbit 		PT0	    	= IP^1;		//????0??????????????
	sbit 		PX0	    	= IP^0;		//??????INT0??????????????
/*
******************************************************************************************************
*/
sfr 	IPH    		= 0xB9;
	//--------------------------------------------------------------------------------------------
//	sbit		PT2H		  = IP^5;		//????2??????????????
//	sbit 		PSH			  = IP^4;		//????????????????????
//	sbit 		PT1H	    = IP^3;		//????1??????????????
//	sbit 		PX1H	    = IP^2;		//??????INT1??????????????
//	sbit 		PT0H	    = IP^1;		//????0??????????????
//	sbit 		PX0H	    = IP^0;		//??????INT0??????????????/*
	#define		IPH_Mask	  ~0x3F		//
	#define		IPH_PT2H    0x20		//????2??????????????       
	#define		IPH_PSH     0x10 	  //????????????????????      
	#define		IPH_PT1H    0x08	  //????1??????????????       
	#define		IPH_PX1H    0x04		//??????INT1??????????????  
	#define		IPH_PT0H    0x02		//????0??????????????       
	#define		IPH_PX0H    0x01 	  //??????INT0??????????????/*
/*
******************************************************************************************************
*/	
sfr 	IP1  		= 0xBA;
	//--------------------------------------------------------------------------------------------
	#define		PPWM		0x80		//PWM ??????????????
	#define		PI2C		0x40		//I2C ??????????????
	#define		PS2			0x20		//UART2??????????????
	//#define		PSPI		0x10		//SPI??????????????
	#define 	PADI		0x08		//ADC ??????????????
	#define		PLVD		0x04		//LVD T2??????????????
	#define 	PPC			0x02		//Pin change??????????????
	#define		PT3			0x01		//????3??????????????
/*
******************************************************************************************************
*/
sfr 	IP1H   		= 0xBB;
	//--------------------------------------------------------------------------------------------
	#define		PPWMH		0x80		//PWM ??????????????
	#define		PI2CH		0x40		//I2C ??????????????
	#define		PS2H 		0x20		//UART2??????????????
	//#define		PSPIH 		0x10		//SPI??????????????
	#define 	PADIH		0x08		//ADC ??????????????
	#define		PLVDH		0x04		//LVD T2??????????????
	#define 	PPCH		0x02		//Pin change??????????????
	#define 	PT3H    	0x01		//????3??????????????

/*
******************************************************************************************************
*/
sfr 	LVDS   		= 0xBF;
	#define		LVDPD		0x80	//1: LVD disable, 0: LVD enable
	#define		LVDO		0x40	//
	//LVDS:LVDS,Bit[3:0]	LVD Select
	//1111: LVD 4.35V
	//1110: LVD 4.2V
	//1101: LVD 4.05V
	//1100: LVD 3.9V
	//1011: LVD 3.75V
	//1010: LVD 3.6V
	//1001: LVD 3.45V
	//1000: LVD 3.3V
	//0111: LVD 3.15V
	//0110: LVD 3V
	//0101: LVD 2.85V
	//0100: LVD 2.7V
	//0011: LVD 2.55V
	//0010: LVD 2.4V
	//0001: LVD 2.25V
	//0000: LVD 2.1V

	
/*
******************************************************************************************************
*/

/*
******************************************************************************************************
*/

sfr 	T2CON  		= 0xC8;
	//--------------------------------------------------------------------------------------------
	sbit 		TF2  		  = T2CON^7;		//??????T2??????????????TF2??????????????????0??????T2????????????????????????TF2??????????1????
	sbit 		EXF2    	= T2CON^6;		//????????2??????EXEN2??1??????T2EX??P1.1????????????????1????????DXF2??EXF2??????????????????0????
	sbit 		RCLK    	= T2CON^5;		//????????????????????????????TCLK=1????T2??????mode 1 or 3??
	sbit 		TCLK 		  = T2CON^4;		//??????????????????????????????RCLK??1????T2??????mode 1 or 3??
	sbit 		EXEN2   	= T2CON^3;		//????????2??????????
	sbit 		TR2     	= T2CON^2;		//??????????/??????????????C/T2=1????T2??????????????????????????????T2??P1.0????C/T2=0????T2??????????????????????????????????????????????
	sbit 		CT2     	= T2CON^1;		//T2????/????????????TR1??1??????????????0????????????
	sbit 		CPRL2   	= T2CON^0;		//??????????????????????????????????1????????????????????0??T2????????????????????????????TCLK??RCLK??1????CP/RL2????????T2??????????????????????????????
/*
******************************************************************************************************
*/
sfr		IAPWE_SFR	= 0xC9;	//Write 47h to enable main ROM IAP write, Write E2h to enable EEPROM  write, other value to disable IAP write
							
	#define	IAPWE	0x80	//Write: Write 47h to enable main ROM IAP write, Write E2h to enable EEPROM  write, 
							//		 other value to disable IAP write"
							//Read : IAPWE Enable Flag
							
	#define	IAPTO	0x40	//IAP Time-Out flag,? H/W auto clear when IAPWE =0
	#define	EEPWE	0x20	//EEPWE Enable Flag

/*
******************************************************************************************************
*/

sfr 	RCP2L  	 = 0xCA;				//??????????P1.1????????/????????????????????????????????
sfr 	RCP2H  	 = 0xCB;				//??????????P1.1????????/????????????????????????????????
/*
******************************************************************************************************
*/
sfr 	TL2   		= 0xCC;			  	//Timer2 data low byte
sfr 	TH2   		= 0xCD;			    //Timer2 data high byte
/*
******************************************************************************************************
*/
sfr 	EXA2   		= 0xCE;
	//EXA2:EXA2,Bit[7:0],extra ACC for 32/16 bit division operation
/*
******************************************************************************************************
*/
sfr 	EXA3   		= 0xCF;
	//EXA3:EXA3,Bit[7:0],extra ACC for 32/16 bit division operation
/*
******************************************************************************************************
*/
sfr 	PSW   		= 0xD0;
	//--------------------------------------------------------------------------------------------
	sbit 		CY 		= PSW^7;		//????????,??????????,CY??1;??????????,CY??0
	sbit 		AC 		= PSW^6;		//??????????
	sbit 		F0 		= PSW^5;		//????????????????
	sbit 		RS1 	= PSW^4;		//????????????????[RS1:RS0]
	sbit 		RS0 	= PSW^3;		//00--0??,01--1??,10--2??,11--3??
	sbit 		OV 		= PSW^2;		//??????????????????,??????,OV=1;??????,OV??0
	sbit 		F1 		= PSW^1;		//??????????????
	sbit 		P 		= PSW^0;		//????????ALU????????????????????1??????????????,????????,??P=1,??????0
	
/*
******************************************************************************************************
*/
//"extra condition: write sequence:  pwmxprdl then pwmxprdh
//extra condition: read sequence:  pwmxprdh then pwmxprdl"
sfr		PWM0DH		= 0xD1;	
							
		//PWM0DH:PWM0DH,Bit[7:0],PWM0 duty high byte		
		
sfr		PWM0DL		= 0xD2;								
		//PWM0DL:PWM0DL,Bit[7:0],PWM0 duty high byte		

/*
******************************************************************************************************
*/
//"extra condition: write sequence:  pwmxprdl then pwmxprdh
//extra condition: read sequence:  pwmxprdh then pwmxprdl"
sfr		PWM1DH		= 0xD3;							
		//PWM1DH:PWM1DH,Bit[7:0],PWM1 duty high byte		
		
sfr		PWM1DL		= 0xD4;
		//PWM1DL:PWM1DL,Bit[7:0],PWM1 duty high byte		

/*
******************************************************************************************************
*/
//"extra condition: write sequence:  pwmxprdl then pwmxprdh
//extra condition: read sequence:  pwmxprdh then pwmxprdl"
sfr		PWM2DH		= 0xD5;							
		//PWM2DH:PWM2DH,Bit[7:0],PWM1 duty high byte		
		
sfr		PWM2DL		= 0xD6;
		//PWM2DL:PWM2DL,Bit[7:0],PWM1 duty high byte		

/*
******************************************************************************************************
*/
sfr		CLKCON		= 0xD8;
	sbit 		SCKTYPE = CLKCON^7;		//????????????????Slow Clock Type. 1=SXT, 0=SRC
	sbit 		FCKTYPE = CLKCON^6;		//Fast clock Type. 0=FRC, 1=FXT.
	sbit 		STPSCK 	= CLKCON^5;		//Stop Slow Clock in PDOWN
	sbit 		STPPCK 	= CLKCON^4;		//1=????IDL??????Stop UART/Timer0/Timer1/Timer2 Clock in Idle mode
	sbit 		STPFCK 	= CLKCON^3;		//1=????????????0=??????????
	sbit 		SELFCK 	= CLKCON^2;		//1=????????????????????????0=??????????????????
	sbit 		CLKPSC_H 	= CLKCON^1;	
	sbit 		CLKPSC_L	= CLKCON^0;	
	//********************************************************************************************************
	#define  	SCKTYPE_SRC    	CLKCON=(CLKCON&0x7f)
	#define  	SCKTYPE_SXT    	CLKCON=(CLKCON&0x7f)|0x80
	#define		FCKTYPE_FRC		CLKCON=(CLKCON&0x9f)
	#define		FCKTYPE_FXT		CLKCON=(CLKCON&0x9f)|0x40
	#define		STPPCK_OPEN		CLKCON=(CLKCON&0xef)|0x10
	#define		STPPCK_OFF		CLKCON=(CLKCON&0xef)
	#define		STPFCK_OPEN		CLKCON=(CLKCON&0xf7)|0x08
	#define		STPFCK_OFF		CLKCON=(CLKCON&0xf7)
	#define		SELFCK_SLOW		CLKCON=(CLKCON&0xfb)
	#define		SELFCK_FAST		CLKCON=(CLKCON&0xfb)|0x04
	//--------------------------------------------------------------------------------------------
	//CLKPSC:CLKCON Bit[1:0],????????????????SYSCLK Prescaler, 0:div16, 1:div4, 2:div2, 3:div1
	#define		CLKPSC_Mask							~0x03
	#define		CLKPSC_Div16		0x00
	#define		CLKPSC_Div4			0x01
	#define		CLKPSC_Div2			0x02
	#define		CLKPSC_Div1			0x03							
	#define		SYSCLOCK_DIV_16		CLKCON=(CLKCON&0xfc)
	#define		SYSCLOCK_DIV_4		CLKCON=(CLKCON&0xfc)|CLKPSC_Div4
	#define		SYSCLOCK_DIV_2		CLKCON=(CLKCON&0xfc)|CLKPSC_Div2
	#define		SYSCLOCK_DIV_1		CLKCON=(CLKCON&0xfc)|CLKPSC_Div1	
/*
******************************************************************************************************
*/
//"extra condition: write sequence:  pwmxprdl then pwmxprdh
//extra condition: read sequence:  pwmxprdh then pwmxprdl"
sfr		PWM0PRDH		= 0xD9;							
		//PWM0PRDH:PWM0PRDH,Bit[7:0],PWM0 Period high byte
		
sfr		PWM0PRDL		= 0xDA;
		//PWM0PRDL:PWM0PRDL,Bit[7:0],PWM0 Period low byte
/*
******************************************************************************************************
*/
//"extra condition: write sequence:  pwmxprdl then pwmxprdh
//extra condition: read sequence:  pwmxprdh then pwmxprdl"
sfr		PWM1PRDH		= 0xDB;							
		//PWM1PRDH:PWM1PRDH,Bit[7:0],PWM1 Period high byte
		
sfr		PWM1PRDL		= 0xDC;
		//PWM1PRDL:PWM1PRDL,Bit[7:0],PWM1 Period low byte
/*
******************************************************************************************************
*/
//"extra condition: write sequence:  pwmxprdl then pwmxprdh
//extra condition: read sequence:  pwmxprdh then pwmxprdl"
sfr		PWM2PRDH		= 0xDD;							
		//PWM2PRDH:PWM2PRDH,Bit[7:0],PWM2 Period high byte
		
sfr		PWM2PRDL		= 0xDE;
		//PWM2PRDL:PWM2PRDL,Bit[7:0],PWM2 Period low byte
/*
******************************************************************************************************
*/
sfr 	ACC   		= 0xE0;		//Accumulator

/*
******************************************************************************************************
*/
sfr 	MICON   	= 0xE1;		//
	#define		MIEN		0x80		//Master IIC enable
										//0: disable
										//1: enable

	#define		MIACKO		0x40		//When Master IIC receive data, send acknowledge to IIC Bus
										//0: ACK to slave device
										//1: NACK to slave device

	#define		MIIF		0x20		//Master IIC Interrupt flag
										//1: Master IIC transmit or receive one byte complete
										//0: H/W write 0 to clear it

	#define		MIACKI		0x10		//"When Master IIC transmission, acknowledgement form IIC bus (read only)
										//0: ACK received
										//1: NACK received"

	#define		MISTART		0x08		//"Master IIC Start bit 
										//1: start IIC bus transmit
										//period of MISTART=0 must longer than a IIC clock period"

	#define		MISTOP		0x04		//" Master IIC Stop bit
										//1: send STOP signal to stop IIC bus"

	//MICR:MICON,Bit[1:0],	//00: Fsys/4    (ex. If Fsys=16MHz, IIC clock is  4M Hz)
							//01: Fsys/16   (ex. If Fsys=16MHz, IIC clock is  1M Hz)
							//10: Fsys/64   (ex. If Fsys=16MHz, IIC clock is 250K Hz)
							//11: Fsys/256  (ex. If Fsys=16MHz, IIC clock is 62.5K Hz)"

	
/*
******************************************************************************************************
*/
sfr 	MIDAT   		= 0xE2;		
	//MIDAT:MIDAT,Bit[7:0], //Master IIC data shift register
							//(W): After Start and before Stop condition, write this register will resume trasmission to IIC bus
							//(R): After Start and before Stop condition, read this register will resume receiving from IIC bus"

/*
******************************************************************************************************
*/
sfr 	EXA   		= 0xE6;		
	//EXA:EXA,Bit[7:0], extra ACC for 16 bit mul/div operation

/*
******************************************************************************************************
*/
sfr 	EXB   		= 0xE7;		
	//EXB:EXB,Bit[7:0], extra B for 16 bit mul/div operation
	
/*
******************************************************************************************************
*/
sfr 	SIADR   		= 0xE9;		
	//SA:SIADR,Bit[7:1], 	//Write: I2C Slave address assigned
							//Read: address received at I2C Slave"

	#define		SIEN		0x01	//"Slave IIC enable
									//0: disable
									//1: enable"


/*
******************************************************************************************************
*/
sfr 	SICON   		= 0xEA;		

	#define	MIIE	0x80
	//MIIE: I2C Master INT enable
	//0: Disable	1: Enable

	#define	TXDIE	0x40
	//TXDIE: I2C Slave data transmit INT enable
	//0: Disable	1: Enable

	#define	RCD2IE	0x20
	//RCD2IE: I2C Slave SIRCD2 receive INT enable
	//0: Disable	1: Enable

	#define	RCD1IE	0x10
	//RCD1IE: I2C Slave SIRCD1 receive INT enable
	//0: Disable	1: Enable

	#define	TXDF	0x04
	//I2C Slave data transmit INT flag, it will not transmit SITXD data and return NACK while 1
	//1: Set by H/W when Slave IIC SITXD transmit one byte complete
	//0: S/W write 0 to clear it

	#define	RCD2F	0x02
	//I2C Slave data received INT flag, it will not receive SITXD data and return NACK while 1
	//1: Set by H/W when Slave IIC SITXD receive one byte complete
	//0: S/W write 0 to clear it

	#define	RCD1F	0x01
	//I2C Slave data received INT flag, it will not receive SIRCD1 data and return NACK while 1
	//1: Set by H/W when Slave IIC RCVD1 receive one byte complete
	//0: S/W write 0 to clear it

/*
******************************************************************************************************
*/
sfr 	SIRCD1   		= 0xEB;
	//SIRCD1:SIRCD1,Bit[7:0],Slave IIC data receive register1

/*
******************************************************************************************************
*/
sfr 	SITXRCD2   		= 0xEC;
	//SITXRCD2:SITXRCD2,Bit[7:0], Write: Slave IIC data transmit register (data-out)
								//Read: Slave IIC data receive register2 (data-in)
/*
******************************************************************************************************
*/
sfr 	PCL   		= 0xED;		//Will not display on datasheet, TEST ONLY
	//PCL:PCL,Bit[7:0],PC counter LSB 7~0

sfr 	PCH   		= 0xEE;		//Will not display on datasheet, TEST ONLY
	//PCH:PCH,Bit[7:0],PC counter MSB 7~0
/*
******************************************************************************************************
*/
sfr 	AUX3   		= 0xEF;		

	//TM3PSC:AUX3,Bit[5:3]
	//Timer3 Int Prescale. 
	//000=32768*Clk, 001=16384*Clk, 010=8192*Clk, 011=4096*Clk
	//100=2048*Clk, 101=1024*Clk, 110=512*Clk, 111=256*Clk

	#define	VBGEN	0x04
	#define VBGEN_ENABLE	AUX3=(AUX3&0xfb)|VBGEN
	#define VBGEN_DISABLE	AUX3=(AUX3&0xfb)

	#define	ADVREFS_00	0x00	//VCC
	#define	ADVREFS_01	0x01	//2.5V
	#define	ADVREFS_02	0x02	//3V
	#define	ADVREFS_03	0x03	//4V
	#define	SET_ADVREFS_00	AUX3=(AUX3&0xfc)
	#define	SET_ADVREFS_01	AUX3=(AUX3&0xfc)|ADVREFS_01
	#define	SET_ADVREFS_02	AUX3=(AUX3&0xfc)|ADVREFS_02
	#define	SET_ADVREFS_03	AUX3=(AUX3&0xfc)|ADVREFS_03
//******************************************************************************************************
sfr 	B   		= 0xF0;		//B register
//******************************************************************************************************
sfr 	CRCDL   		= 0xF1;
	//--------------------------------------------------------------------------------------------
	//CRCDL:CRCDL Bit[7:0],CRC16 Data 7~0
//******************************************************************************************************
sfr 	CRCDH   		= 0xF2;
	//--------------------------------------------------------------------------------------------
	//CRCDH:CRCDH Bit[7:0],CRC16 Data 15~8
//******************************************************************************************************
sfr 	CRCIN   		= 0xF3;
	//--------------------------------------------------------------------------------------------
	//CRCIN:CRCIN Bit[7:0],CRC16 input
	
/*
******************************************************************************************************
*/	
sfr 	TESTMODE   		= 0xF4;	//Will not display on datasheet, TEST ONLY
	#define	TSTREG_5	0x20	
	//0:  High Sink setting by HSNKxEN
	//1:  All pin force enable  High Sink
	
	#define	TSTREG_4	0x10	
	//0:  LEDDRV is controled by LEDEN
	//1:  force LEDDRV=1"
	
	#define	TSTREG_3	0x08
	//0: EEPROM Read, wait 5 clock
	//1: disable EEPROM read delay (for test EEPROM access time)"

	#define	TSTREG_2	0x04
	//0: POR always enable
	//1:  disable POR, force PORPD=1

/*
******************************************************************************************************
*/	
sfr 	CFGBG   		= 0xF5;
	//--------------------------------------------------------------------------------------------
	//BGTRIM:CFGBG Bit[4:0],VBG trimming value
sfr 	CFGWL   		= 0xF6;
	//--------------------------------------------------------------------------------------------
	//FRCF:CFGWL Bit[6:0],FRC freq
	
/*
******************************************************************************************************
*/	
sfr 	AUX2		= 0xF7;
	//--------------------------------------------------------------------------------------------
	//WDTE:AUX2 Bit[7:6],WDT Control
	//#define 	WDT_EN		         	0xC0		
	//#define 	WDT_ENFS_DISILDE		0x80		
	//#define 	WDT_DIS         		0x00		
	
	#define  	WDT_IS_OPEN                         AUX2=(AUX2&0x3f)|0xC0	//11??WDT Always Enable
	#define   	WDT_RUN_FAST_DIS_ILDE               AUX2=(AUX2&0x3f)|0x80	//10: WDT Enable in Fast/Slow, Disable in Idle/Stop mode
	#define  	WDT_IS_STOP                         AUX2=AUX2&0x3f  		//0X: WDT Disable

	//1: LVR disable at IDLE/PDOWN, 0: LVR enable at IDLE/PDOWN
	#define		PWRSAV		0x20
	#define		PDOWN_LVD_ENABLE	AUX2=(AUX2&0xdf)
	#define		PDOWN_LVD_DISABLE	AUX2=(AUX2&0xdf)|PWRSAV
	
	//
	//1: VBG output to P3.2,   0: P32 as normal IO
	//(extra condition: VBGEN =1 or ADCHS=1011b or ADVREFS??00b)"
	#define		VBGOUT		0x10	//1: VBG output to P3.2,   0: P32 as normal IO
	#define		VBG_OUTPUT	AUX2=(AUX2&0xef)|VBGOUT
	#define		VBG_NORMAL	AUX2=(AUX2&0xef)
	
	#define		DIV32		0x08	//only active when MULDVI16 =1
									//0: insturction div as 16/16 bit division operation
									//1: insturction div as 32/16 bit division operation"

	
	//
	//IAPTE:AUX2 Bit[2:1],IAP TIMEOUT Enable  00:Disable  01: 2.8mS   10:  11mS  11:22mS
	#define		IAPTE_2P8_MS	AUX2=(AUX2&0xf9)|0x02
	#define		IAPTE_11_MS		AUX2=(AUX2&0xf9)|0x04
	#define		IAPTE_22_MS		AUX2=(AUX2&0xf9)|0x06
	#define		IAPTE_DISABLE	AUX2=(AUX2&0xf9)
	
	#define		MULDIV16		0x01	
	//0: instruction mul/div as 8*8, 8/8 operation
	//1: instruction mul/div as 16*16, 16/16 or 32/16 operation

/*
******************************************************************************************************
*/	
sfr 	AUX1   		= 0xF8;
	//--------------------------------------------------------------------------------------------
    sbit 		CLRWDT		= AUX1^7;	//Clear WatchDog, HW auto clear
    #define     CLR_WDT		CLRWDT=1                   //??????????????????????,H/W????????????????????????     	
	sbit 		CLRTM3		= AUX1^6;//????TM3????????TM3
    sbit 		ADSOC		= AUX1^4;//ADC????????????????????????
    sbit 		LVRPD		= AUX1^3;//1: LVR disable, 0: LVR enable
    sbit 		T2SEL		= AUX1^2;//Timer2 counter mode input, 0=P1.0 pin, 1=SLOWCLK/16
    sbit 		T1SEL		= AUX1^1;//Timer1 counter mode input, 0=P3.5 pin, 1=SLOWCLK/16
    sbit 		DPSEL		= AUX1^0;//0??????DPTR;1??????DPTR1

/*
******************************************************************************************************
*/	
sfr 	ICECON 		= 0xF9;
	#define 	HWBRK		      0x80		//H/W Break
	#define 	RETROREQ          0x40		//Retro-OPCode Request,HW set at SWBRK,clear at NMI return
	#define 	TXRDY		      0x20		//Transmitt Ready
	#define 	CMDRDY	          0x10		//Ready for Command
	#define 	XFIRCK	          0x08		//Swich to FIRC 4MHZ
	#define 	WRFAIL	          0x01		//EEPROM Write Fail
/*
******************************************************************************************************
*/	
sfr 	RETROCODE 		= 0xFA;	//ICE Mode Retro-OPCode
/*
******************************************************************************************************
*/	
sfr 	ICERCD 		= 0xFB;	//ICE Mode Receive Data
/*
******************************************************************************************************
*/	
sfr 	ICECMDL		= 0xFC;	//ICE Mode Command Low Byte
/*
******************************************************************************************************
*/	
sfr 	ICECMDH		= 0xFD;	//Bit[3:0],ICE Mode Command High Byte
/*
******************************************************************************************************
*/	
sfr 	ICETXD		= 0xFE;	//ICE Mode Transmit Data
/*
******************************************************************************************************
*/	
sfr 	INDSFR		= 0xFF;	//SFR direct Adr replaced by ICECMDL in NMI "mov dir,a" & "mov a,dir"
/*
******************************************************************************************************
*/	

#define	 All_Interrupt_Enable()		EA = 1		//????????????
#define	 All_Interrupt_Disable()	EA = 0		//????????????
/*
******************************************************************************************************
*/
#define	 PowerDown()			PCON = PCON | PD	//????????????
#define	 PowerIdel()			PCON = PCON | IDL	//????IDEL????
/*
******************************************************************************************************
*/
#endif
/*
******************************************************************************************************
*/
