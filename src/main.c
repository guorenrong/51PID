/*
							演示效果
			LED1/2/3/4以每隔大约1秒的时间，从左到右，依次点亮，
			每次只亮一个灯，当点亮LED4后，下次再从LED1开始，依次往复。

*/

#include <REGtenxTM52F086B.h>

#include "TM52F086B_bsp.h"

#include <intrins.h>



#define BAUD_RATE  9600


#define RS485_EN  P1_5

#define K1        P0_6
#define K2        P2_3

//#define 485_EN  P1_5Delay4us();

#define S8  signed char
#define U8  unsigned char
#define U16 unsigned int
#define S16 int
#define S32 long int	

/* 偶地址有效 一共128字节 */

///////////////////////////////////////////////////////*******************  Eeprom ******

unsigned char xdata eeprom_address[256]  _at_   0XEE00;             //eeprom指定地址

///////////////////////////////////////////////////////*******************  Eeprom ******


#define NORMAL_DISPLAY 0x01
#define ALARM_DISPLAY 0x02
#define CONTROL_SETTING_SETPOINT 0x03
#define CONTROL_SETTING_ALARM_UPLIMIT 0x4
#define CONTROL_SETTING_ALARM_LOWLIMIT 0x5
#define CALIBRATION_SETTING_UPLIMIT 0x06
#define CALIBRATION_SETTING_LOWLIMIT 0x07
#define CALIBRATION_SETTING_OFFSET 0x08
#define SENSOR_SETTING 0x09
#define OUTPUTTYPE_SETTING 0x0A
#define PID_SETTING_P 0x0B
#define PID_SETTING_I 0x0C
#define PID_SETTING_D 0x0D
#define PID_SETTING_T 0x0E
#define DISPLAY_MAX 0x0F

///////////////////////////////////////////////////////////////////////////////////union
typedef union  
{
   U8 Data[1];
   S8 Data_s8;
}MYUNION_8;

typedef union  
{
   U8 Data[2];
   S16 Data_s16;
}MYUNION_16;

typedef union  
{
   U8 Data[4];
   S32 Data_s32;
}MYUNION_32;

typedef struct	_TEMPR_						//data for up-computer monitor	
{
	S8		Data_Temp;								//packstatus include 
  S32		Data_R;
}TEMPR;
///////////////////////////////////////////////////////////////////////////////////union




unsigned char xdata  DISPLAY_what = 0x01;
unsigned char xdata EDIT_enable = 0x00;

unsigned char xdata t100us_cnt = 0;
unsigned char xdata t4ms_cnt = 0;

unsigned char	xdata CNT_20ms			= 0;

unsigned char	xdata CNT_100ms			= 0;
unsigned int	xdata CNT_500ms			= 0;
unsigned int	xdata CNT_1000ms		= 0;

unsigned char xdata Flag_B_20ms		= 0;
unsigned char xdata Flag_B_100ms	= 0;
unsigned char xdata Flag_B_500ms	= 0;
unsigned char xdata Flag_B_1000ms	= 0;

unsigned char xdata Splinking = 0;


U8  xdata  B_Keypush=0x00;
U8  xdata  CNT_Keypush=0x00;

U8  xdata  B_BackMainMU =0x00;
U8  xdata  CNT_BackMainMU=0x00;
//U8  xdata  DSP_WathBUF[2]={0,0};


//KEY1
U8  xdata  Key1Flag=0x00;
//U8  xdata  Key1ValidCnt=0x00;
//U8  xdata   Key1InvalidCnt=0x00;
U8  xdata 	Key1Value=0x00;
//U8  xdata  Key1OldValue=0x00;
//U8  xdata 	Key1ValueBK=0x00;
U8  xdata  CNT_Key1_On=0x00;

//KEY2
U8 xdata   Key2Flag=0x00;
//U8 xdata   Key2ValidCnt=0x00;
//U8 xdata   Key2InvalidCnt=0x00;
U8 xdata  	Key2Value=0x00;
//U8  xdata  Key2OldValue=0x00;
//U8 xdata  	Key2ValueBK=0x00;
U8  xdata  CNT_Key2_On=0x00;

//KEY3
U8  xdata 	Key3Flag=0x00;
//U8  xdata  Key3ValidCnt=0x00;
//U8  xdata  Key3InvalidCnt=0x00;
U8  xdata 	Key3Value=0x00;
//U8  xdata  Key3OldValue=0x00;
//U8  xdata 	Key3ValueBK=0x00;
U8  xdata  CNT_Key3_On=0x00;

//KEY4
U8  xdata 	Key4Flag=0x00;
//U8  xdata   Key4ValidCnt=0x00;
//U8  xdata  Key4InvalidCnt=0x00;
U8  xdata 	Key4Value=0x00;
//U8  xdata  Key4OldValue=0x00;
//U8  xdata 	Key4ValueBK=0x00;
U8  xdata   CNT_Key4_On=0x00;


U8  xdata LED_Data=16;
U8  xdata Re_Dis_What=0x00;
U8  xdata B_Running=0x00;
U8  xdata value_LED_Running=0xFF;


U8  xdata B_ON_Time=0x00;
U8  xdata B_OFF_Time=0x00;

S16 xdata RunValue_ON_Time=0;
S16 xdata RunValue_OFF_Time=0;
S16 xdata SetValue_ON_Time=10;
S16 xdata SetValue_OFF_Time=10;
U16 xdata Run_Clyle_Time=0x00; //機器運行次數

U16 xdata Current_Set_Value = 0;

S16 xdata Current_Alert =  505;
S16 xdata Temp_UpperLimit = 400;
S16 xdata Temp_LowerLimit = 0;
S16 xdata Temp_SetPoint = 60;
S16 xdata Calibrate_High = 900;
S16 xdata Calibrate_Low = 10;
S16 xdata Calibrate_Offset = 18;
S16 xdata Sensor_Type = 1; // 1,2,3
S16 xdata Output_Type = 2; // 1,2,3,4,5

///////////////////////////////////////////////////////*******************  COM ******

U8  xdata LEN1;		  //??1???0x5A 0xA5??
U8  xdata RX1COMOK; 
U8  xdata Rec_Com1[20];		//??????????
U8  xdata Sed_Com1[20];		//??????????
U8  xdata Rec_Com1_Data[20];		//??????????

U8  xdata COM1_Send_Length;   								  //??????????
U8  xdata COM1_Send_Ptr;

///////////////////////////////////////////////////////*******************  COM ******

///////////////////////////////////////////////////////******************* ADC******

float  xdata  kp_TempCal;
float  xdata  ki_TempCal;

U8     xdata  at_TC = 0;     // 0, disable, 1, enable.
float  xdata  kp_TC = 30;
float  xdata  ki_TC = 120;
float  xdata  kd_TC = 30;
float  xdata  kt_TC = 20;
float  xdata  oh_TC = 2;     //主控回差，kp_TC == 0 显示
float  xdata  ar_TC = 80;    //积分过冲抑制，kp_TC ==0 时不显示

U8     xdata  lock_sys = 0; // 000(Bin)所有参数均可修改，001 SV,AL1,AL2可以修改，011 SV可以修改，111全部不可以修改.

float  xdata  TempSet_Point;
float  xdata  Temp_Disp_Tolerance;
U8  xdata  Temp_Disp_Tolerance_Factor;
U8 xdata    Temp_Disp_Tolerance_Enable = 0;
float  xdata  Temp_SetHigh;
float  xdata  Temp_SetLow;

float  xdata  TempData_Current=36.8;
float  xdata  NowTC_Data_Value=0;

U16  xdata adTC_value=0;
U16  xdata tempTC=0;

U16  xdata  AdcTC_H=0;	
U16  xdata  AdcTC_L=0;			

U8  xdata   List_tempTC=0;	
U16 idata   Buf_tempTC[20];
U16 xdata   DataSum=0, DataMax = 0, DataMin = 0xFFFF;
float xdata   Temp_Error[3];
S16 xdata   Temp_Delta = 0;
U8 xdata    Temp_TC_Ctrl_Cnt = 0;
U8 xdata    Temp_TC_Ctrl_Flag = 0;

U8 xdata    Temp_TC_Period = 40;
U16 xdata    Temp_TC_Period_Flag = 0;
U16 xdata   Temp_TC_Period_Cnt = 0;

///////////////////////////////////////////////////////******************* ADC ******
//////////////////////////////////////////////////////////*******************CAL
U8  xdata  Flag_TCVoltageHighCalibration_OK = 0;
U8  xdata  Flag_TCVoltageLowCalibration_OK = 0;
float xdata TCHighCalibration=0;
float xdata TCLowCalibration=0;
float xdata TCOffsetCalibration = 0;
U16 xdata PTHighCalibration=0;
U16 xdata PTLowCalibration=0;
//////////////////////////////////////////////////////////*******************CAL

void gpio_init(void);

void timer0_init(void);

void uart1_timer2_init(void);
void  SendByte(unsigned char DATA);

void ScanKey1(void);
void ScanKey2(void);
void ScanKey3(void);
void ScanKey4(void);



void Delay4us(void);
void HC595SendData(unsigned char SendVal);
void HC595ShowData();
void select11();
void select12();
void select13();
void select14();
void select21();
void select22();
void select23();
void select24();
void selectled();


void ParseDataFrom_PC(void);
void SendCommandResponse(U8 Cmd,U8 CmdData);
void BackADDataTo_PC(void);
void BackCurrentDataTo_PC(void);
void Write_Com1SBUF(U8 xdata Data,U8 xdata length);

int Calculate_Temp_Output(float input);
void Save_CalibrationParameter(void );
void GetNewTC_KiKpParameter( void );// 校准万用表---AD电压采集
void Write_Eeprom( void );
void Read_Eeprom( void );
float ReadFloat(unsigned char addr);
void SaveFloat(float f,unsigned char addr);
U8 epprom_read_byte(U8 sector,U8 addr);
void  eeprom_write_byte(U8 sector, U8 addr, U8 value );
void iap_eeprom_write(unsigned char addr, unsigned char *buf, unsigned char len);
void iap_eeprom_read(unsigned char addr, unsigned char *buf, unsigned char len);
/******************************************************************************************
** 函数名称: adc_control_init
** 函数描述: ADC counter脚初始化  
** 输入参数: 无
** 输出参数: 无 
*******************************************************************************************/
void adc_control_init();
void adc_init();
unsigned int adc_get_value (unsigned char ch);                 // ADC 值获取函数
/////////////////////////////////////////////////////////////////////

void iap_eeprom_write(unsigned char addr, unsigned char *buf, unsigned char len);    
void iap_eeprom_read(unsigned char addr, unsigned char *buf, unsigned char len);    //eeprom读


unsigned char xdata write_mileage[4];
unsigned char xdata read_mileage[4];


//U8   LED_Data=16;
//U8   value_LED_Running=0xFF;

//U8  TubeTab[] = {0x3f,0x06,0x5b,0x4f,
//                           0x66,0x6d,0x7d,0x07,
//                          0x7f,0x6f,0x77,0x7c,
 //                          0x39,0x5e,0x79,0x71};//0~9,A,b,C,d,E,F 
//共阴数码管显示代码
unsigned char tab[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x7f,0xff,0,0xFE,0xFD,0xFB,0xF7,0xEF,0xEA,0x88,0x92,0x89,0xC7,0xC6,0xC1, 0x8C};
    //  0-9
    //  點
    //  全熄灭
    //  全显示 
    //  全显示 
    //  13  LED 6
		//  14  LED 3
		//  15  LED 5
		//  16  LED 2
		//  17  LED 4
    //  18  LED 4  LED 5 LED 6
	//  19  A
    //  20  S
    //  21  H
    //  22  L
	//  23  C
    //  24  U

///static U8 xdata Kingtab[]={0xc0，0xf9，0xa4，0xb0，0x99，0x92，0x82，0xf8，0x80，0x90，0xbf，0xff，0};

//0-9，-，全灭，全亮——共阳极数码管
////////////////////////////////////////////////////////////////////////////////////////////




/******************************************************************************************
** 函数名称: timer0_int
** 函数描述: time0中断处理函数
** 输入参数: 无
** 输出参数: 无 
*******************************************************************************************/
void timer0_int() interrupt 1
{
	TH0 = (65536 - 4610) / 256;            // 1000US
	TL0 = (65536 - 4610) % 256;  

	      
	//unsigned char	CNT_20ms			= 0;

	//unsigned char	CNT_100ms			= 0;
	//unsigned int	CNT_500ms			= 0;
	//unsigned int	CNT_1000ms		= 0;

	//unsigned char Flag_B_20ms		= 0;
	//unsigned char Flag_B_100ms	= 0;
	//unsigned char Flag_B_500ms	= 0;
	//unsigned char Flag_B_1000ms	= 0;

	
	                                //1ms 
	if(++CNT_20ms>20)
	{
		CNT_20ms=0;
	  Flag_B_20ms	 = 1;
		
		   ScanKey1();
			 ScanKey2();
			 ScanKey3();
			 ScanKey4();
		
	}
	if(++CNT_100ms>100)
	{
		
	  CNT_100ms=0;
		Flag_B_100ms = 1;
       
	   if (B_Keypush)
	   {
			if(++CNT_Keypush>10)
			{
				CNT_Keypush=0x00;
				B_Keypush=0x00;
			}
	   }	
	}
	if(++CNT_500ms>500)
	{
		
	  CNT_500ms=0;
		Flag_B_500ms	= 1;
		
	}
	if(++CNT_1000ms>1000)
	{
		
	    CNT_1000ms=0;
		Flag_B_1000ms	= 1;

		if (B_BackMainMU)
		{
			if (++CNT_BackMainMU>5)
		      { 
				 B_BackMainMU=0;
				 CNT_BackMainMU=0;
				 DISPLAY_what= NORMAL_DISPLAY;
				 EDIT_enable = 0x00;				 
			  }
		}
	

	}
	
	//t100us_cnt++;                         // 100US ++
	
	  
	
	//if (t100us_cnt >= 39)
	//{
	//	t100us_cnt = 0;
	//	t4ms_cnt++;
	//	if (t4ms_cnt >= 249)              //  1S
	//	{
		//	t4ms_cnt = 0;
			//P0_3 = ~P0_3;                 //  1S 变换一次状态
		   //P1_5 = ~P1_5;  
		
	//	}
	//}
}
/******************************************************************************************
** 函数名称: uart1_irq
** 函数描述: uart1中断处理函数
** 输入参数: 发送的数据的首地址
** 输出参数: 无 
*******************************************************************************************/
void uart1_irq() interrupt 4
{
	unsigned char temp;
	unsigned char Dat;
   unsigned char i;
	if (RI)
	{
		Dat = SBUF;
		RI = 0;

		if (LEN1>=1)
		{
			//MessageBox("接受数据成功！");

			if((Dat == 0xA5) && (Rec_Com1[LEN1-1] == 0x5A) )
			{
				// 给接收到的数据加上结束符
				// 清空缓存区，等待下一次接收
				//memset(m_szDataC, 0, sizeof(m_szDataC));
				LEN1 = 1;
				Rec_Com1[0] = 0x5A;
			}
		}

		Rec_Com1[ LEN1 ] = Dat;
		LEN1++;

		if(LEN1<4) return;

			if((Rec_Com1[0] == 0x5A)
		&& (Rec_Com1[1] == 0xA5)  
		&& (LEN1>=Rec_Com1[2])
		)
	   {
	   		if( (Rec_Com1[ LEN1-2] == 0xAA) && (Rec_Com1[ LEN1 - 1 ] == 0x55) )
			  {
				
		//				if( (Rec_Com0[3] ==BoardId) || (Rec_Com0[3] ==0xFF) )
		//				 {
					//if(Rec_Com1[3] == 0x01)   //確定是呼叫本機
					{
							RX1COMOK = 1;	// 单片机完整接收一条消息
							for( i = 0; i < (LEN1); i++ )
							{
										Rec_Com1_Data[i] = Rec_Com1[i];	// 将接收缓存里的数据复制一份，用以数据处理，防止数据干扰。
							} // ********************这里的for循环最好优化一下，比较占用时间，备注时间：2019-11-2****************	
						 //				 }
					}
				  
							
			
			  }
	   	   LEN1 = 0;//MemorySet(Rec_Com1, 0, sizeof(Rec_Com1));
	   }
	   if(LEN1>72) 
			 {LEN1 = 0;//MemorySet(Rec_Com1, 0, sizeof(Rec_Com1));
		 }


	}
	if (TI)
	{
	   TI = 0; 
	 if(COM1_Send_Ptr >= COM1_Send_Length)
		{
			//REN1 = 1;                       				//Allow UART receive data
			COM1_Send_Ptr = 0;
			//MemorySet(Sed_Com1, 0, 3);               	//clr UART buf[0~3] // 为什么只清零3个元素？20191018
			//COM0_485_DisEN();
			RS485_EN=0;
			///UartReadFlg = 0; 
			//EN_485=0;
		}
		else
		{
			SBUF = Sed_Com1[COM1_Send_Ptr];// add:20191018.  COM0_Send_Ptr=1,发送第二个数组元素，第一个数组元素Array[0]之前已经通过SBUF=Array[0]发送过了。
			COM1_Send_Ptr++;// 数组标号指向下一个元素
		}
		
		
  }
}
unsigned char txrx_buf[8] = {0x55};


U16 get_calibration_higherlimit()
{
	return Calibrate_High;
}

U16 get_calibration_lowlimit()
{
	return get_calibration_lowlimit;
}

U16 get_normal_temperature()
{
	U16 res = 37;
	return res;
}

U16 get_alarm()
{
	return 0xFFFF;
}

U16 get_current_setpoint()
{
	return Temp_SetPoint;
}

U16 get_sensor_type()
{
	return Sensor_Type;
}

U16 get_output_type()
{
	return Output_Type;
}

U16 get_set_value(U8 disp_what)
{
	U16 res = 0xffff;
	switch(disp_what)
	{
		case NORMAL_DISPLAY:
			if(Temp_Disp_Tolerance_Enable == 0 || (Temp_Disp_Tolerance< 0.001 && Temp_Disp_Tolerance> -0.001))
			{
				res = TempData_Current*10;
			}			
			else
			{
				if((TempData_Current >= TempSet_Point - Temp_Disp_Tolerance) && (TempData_Current <= TempSet_Point + Temp_Disp_Tolerance))
				{
					res = ((TempData_Current-TempSet_Point)/Temp_Disp_Tolerance_Factor+TempSet_Point)*10;
				}
				else if(TempData_Current > TempSet_Point + Temp_Disp_Tolerance)
				{
					res = (TempData_Current-Temp_Disp_Tolerance)*10;
				}
				else
				{
					//res = TempData_Current*10;
					res = (TempData_Current+Temp_Disp_Tolerance)*10;
				}
			}
			break;
		case ALARM_DISPLAY:
			res = get_alarm();
			break;
		case CONTROL_SETTING_SETPOINT:
			res = TempSet_Point*10;
			break;
		case PID_SETTING_P:
			res = kp_TC*10;
			break;
		case PID_SETTING_I:
			res = ki_TC*10;
			break;
		case PID_SETTING_D:
			res = kd_TC*10;
			break;
		case PID_SETTING_T:
			res = kt_TC*10;
			break;		
		case CONTROL_SETTING_ALARM_UPLIMIT:
			res = Temp_UpperLimit;
			break;
		case CONTROL_SETTING_ALARM_LOWLIMIT:
			res = Temp_LowerLimit;
			break;
		case CALIBRATION_SETTING_UPLIMIT:
			res = Calibrate_High;
			break;
		case CALIBRATION_SETTING_LOWLIMIT:
			res = Calibrate_Low;
			break;
		case CALIBRATION_SETTING_OFFSET:
			res = Calibrate_Offset;
			break;
		case SENSOR_SETTING:
			res = Sensor_Type;
			break;
		case OUTPUTTYPE_SETTING:
			res = Output_Type;
			break;
		default:
			break;
	}
	return res;
}

U16 Judge_Set_Value(U8 disp_what)
{
	return 0;
}

void Save_Set_Value(U8 disp_what, U16 value)
{
	switch(disp_what)
	{
		case CONTROL_SETTING_SETPOINT:
			TempSet_Point = value;
			TempSet_Point = TempSet_Point/10;
			SaveFloat(TempSet_Point, 0x60);
			break;
		case PID_SETTING_P:
			kp_TC = value;
			kp_TC = kp_TC/10;
			SaveFloat(kp_TC, 0x10);
			break;
		case PID_SETTING_I:
			ki_TC = value;
			ki_TC = ki_TC/10;
			SaveFloat(ki_TC,0x18);
			break;
		case PID_SETTING_D:
			kd_TC = value;
			kd_TC = kd_TC/10;
			SaveFloat(kd_TC,0x20);
			break;
		case PID_SETTING_T:
			kt_TC = value;
			kt_TC = kt_TC/10;
			SaveFloat(kt_TC,0x28);
			break;
		case CONTROL_SETTING_ALARM_UPLIMIT:
			Temp_UpperLimit = value;
			break;
		case CONTROL_SETTING_ALARM_LOWLIMIT:
			Temp_LowerLimit = value;
			break;
		case CALIBRATION_SETTING_UPLIMIT:
			Calibrate_High = value;
			break;
		case CALIBRATION_SETTING_LOWLIMIT:
			Calibrate_Low = value;
			break;
		case CALIBRATION_SETTING_OFFSET:
			Calibrate_Offset = value;
			break;
		case SENSOR_SETTING:
			Sensor_Type = value;
			break;
		case OUTPUTTYPE_SETTING:
			Output_Type = value;
			break;
		default:
			break;
	}
	return;
}

int Do_PID_Control()
{
	unsigned char i = 0;
	if( TempSet_Point >  TempData_Current)
	{ 
		if(TempSet_Point - TempData_Current > 40)
		{
			K1 = 1;
			K2 = 1;
			return;
		}
		else
		{
			//for(i = 0; i< kt_TC; i++)
			{
				Temp_TC_Period_Flag = Calculate_Temp_Output(TempData_Current);
			}

			if((Temp_TC_Period_Flag >= Temp_TC_Period) && (TempData_Current < Temp_SetLow) )
			{
				K1 = 1;
				K2 = 1;
				return;
			}
			else
			{
				if((Temp_TC_Period_Cnt++ < Temp_TC_Period_Flag) && (TempData_Current < Temp_SetLow))
				{
					K1 = 1;
					K2 = 1;
				}
				else
				{
					K1 = 0;
					K2 = 0;
				}

				if(Temp_TC_Period_Cnt >= Temp_TC_Period) Temp_TC_Period_Cnt = 0;	
			}
		}
	}
	else if(TempSet_Point <= TempData_Current )
	{
		K1 = 0;
		K2 = 0;
		Temp_Disp_Tolerance_Enable = 1;
		return;
	}
}

int Calculate_Temp_Output(float input)
{
	float rout = 0;
	Temp_Error[0] = Temp_Error[1];
	Temp_Error[1] = Temp_Error[2];
	Temp_Error[2] = 10*(TempSet_Point - input);	

	rout =  kp_TC*(Temp_Error[2]-Temp_Error[1]) + ki_TC*Temp_Error[2]  + kd_TC*(Temp_Error[2]-2*Temp_Error[1]+Temp_Error[0]);
	//rout =  kp_TC*Temp_Error[2];//;-Temp_Error[1]) + ki_TC*Temp_Error[2]  + kd_TC*(Temp_Error[2]-2*Temp_Error[1]+Temp_Error[0]);
	return (int)rout;

}

/******************************************************************************************
** 函数名称: main
** 函数描述: main函数   
** 输入参数: 无
** 输出参数: 无 
*******************************************************************************************/
void main (void)
{ 
	U8   I,i;
	U16  Value,Value0,Value1,Value2,Value3,Value4;
	
	
	bsp_clock_init();            // 系统快钟18.432 div 2 =  9.216Mhz
  
	gpio_init(); 
  
	timer0_init();
	
	//uart1_timer2_init();
	
	 //adc_control_init();
   //adc_init();
  
	
	K1 = 0;
	K2 = 0;

	Temp_Error[0] = 0;
	Temp_Error[1] = 0;
	Temp_Error[2] = 0;
	EA = 1;
	
	
	
	Value=2888;
	Value3=Value/1000;Value=Value%1000;
	Value2=Value/100;Value=Value%100; 
	Value1=Value/10;Value=Value%10; 
	Value0=Value;
	
	
	
	RS485_EN=0;
	
	//Value0=0;
	//Value1=0;
	//Value2=0;	
	//Value3=0;
	//Value4=0;
	
  ///////////////////////////////////////////////////////////////////////
	
//	read_mileage[0] = 0;
//	read_mileage[1] = 0;
//	read_mileage[2] = 0;
//	read_mileage[3] = 0;
//	iap_eeprom_read(0,read_mileage,4);

//	write_mileage[0] = 0x22;
//	write_mileage[1] = 0x33;
//	write_mileage[2] = 0x44;
//	write_mileage[3] = 0x55;
//   	iap_eeprom_write(0,write_mileage,4);      
//	bsp_delay_ms(50);                    


//	read_mileage[0] = 0;
//	read_mileage[1] = 0;
//	read_mileage[2] = 0;
//	read_mileage[3] = 0;
//	iap_eeprom_read(0,read_mileage,4);
//	
//	write_mileage[0] = 0x66;
//	write_mileage[1] = 0x77;
//	write_mileage[2] = 0x88;
//	write_mileage[3] = 0x99;
//    iap_eeprom_write(0,write_mileage,4);	                                     
//	bsp_delay_ms(50);                     

//	read_mileage[0] = 0;
//	read_mileage[1] = 0;
//	read_mileage[2] = 0;
//	read_mileage[3] = 0;
//	iap_eeprom_read(0,read_mileage,4);	
	

kp_TC = ReadFloat(0x10);
ki_TC = ReadFloat(0x18);
kd_TC = ReadFloat(0x20);
kt_TC = ReadFloat(0x28);

TempSet_Point=ReadFloat(0x60);
Temp_SetHigh=ReadFloat(0x68);
Temp_SetLow=ReadFloat(0x70);
Temp_Disp_Tolerance=ReadFloat(0x78);

ki_TempCal = ReadFloat(0x30);
kp_TempCal = ReadFloat(0x38);
	
         for(i=0;i<20;i++)
					{
					 Buf_tempTC[i]=0x00;
					}
						


	///////////////////////////////////////////////////////////////////////
	
	while (1)
	{
	  //bsp_delay_ms (1000);       //延时后LED2亮
    //SendByte(0x55);
		
		//点亮 p14   led2
		//P0_3 = 1;
		//P1_4 = 0;
		//P1_5 = 0;
		//P1_6 = 1;
		//P1_2 = 1;
		//bsp_delay_ms (1000);       //延时后LED3亮
		
    //SendByte(0xAA);
		
		// 点亮P16 led3
		//P0_3 = 1;
		//P1_4 = 1;
		//P1_5 = 1;
		
		//P1_6 = 0;
		//P1_2 = 1;
		//bsp_delay_ms (100);      //延时后LED4亮
		
				//Value0=0;
				//Value1=0;
				//////////////////////////////////////////////////********  LED  Dispaly
				if(Flag_B_500ms)
				{
					Splinking = 1 - Splinking;
					Flag_B_500ms = 0;
				}

				// if(EDIT_enable == 1 && Splinking == 1 && B_Keypush == 0)
				// {			
				// 	Value0 = 11;
				// 	Value1 = 11;
				// 	Value2 = 11;
				// 	Value4 = 11;
				// 	Value3 = 11;
				// }

				//HC595SendData(0x80);//发送数据		
				
				//HC595SendData(tab[0]);//发送数据		
				HC595SendData(tab[2]);//发送数据	
				//HC595SendData(0xff);
				//HC595SendData(0xff);
				//HC595ShowData();//RCK_595产生一上升沿(输出数据)
				select11();
				
				
				if(DISPLAY_what == NORMAL_DISPLAY)
				{
					HC595SendData(tab[2]&0x7F);
				}
				else
				{
					//HC595SendData(0x80);//发送数据
					//HC595SendData(tab[0]);//发送数据	
					HC595SendData(tab[2]);//发送数据	
				}
				//HC595SendData(tab[10]);//发送数据
				//HC595SendData(tab[1]);//发送数据
				//HC595SendData(0x01);
				//HC595ShowData();//RCK_595产生一上升沿(输出数据)
				select12();
				//bsp_delay_ms (20);      //延时后LED4亮
				
				//HC595SendData(0x80);//发送数据
				HC595SendData(tab[2]);//发送数据
				

				//HC595ShowData();//RCK_595产生一上升沿(输出数据)
				select13();
				//HC595SendData(tab[Value3]&0x7f);//发送数据
				//HC595SendData(0x80);//发送数据
				HC595SendData(tab[2]);//发送数据
				//HC595ShowData();//RCK_595产生一上升沿(输出数据)
				select14();

				// HC595SendData(tab[Value4]);//发送数据
				// HC595ShowData();//RCK_595产生一上升沿(输出数据)
				// select5();
				// HC595SendData(tab[LED_Data]&value_LED_Running);//发送数据
				// //HC595SendData(tab[LED_Data]);//发送数据
				// HC595ShowData();//RCK_595产生一上升沿(输出数据)
				// select6();
				
				HC595SendData(tab[2]);//发送数据
				select21();
                HC595SendData(tab[2]);//发送数据
				select22();
				HC595SendData(tab[2]);//发送数据
				select23();
                HC595SendData(tab[2]);//发送数据
				select24();

		
		    /////////////////////////////////////////////////********  LED  Dispaly
			
			switch(DISPLAY_what)
			{
				case NORMAL_DISPLAY: // display the normal temperature here.
					LED_Data = 17;
					Value = get_set_value(NORMAL_DISPLAY);
					Value4=Value/10000;Value=Value%10000;
					Value3=Value/1000;Value=Value%1000;
					Value2=Value/100;Value=Value%100; 
					Value1=Value/10;Value=Value%10; 
					Value0=Value;	

					if(Value4 == 0) 
					{
						Value4 = 11;
						if(Value3 == 0)
						{
							Value3 = 11;
							if(Value2 == 0)
							{
								Value2 = 11;
							}
						}
					}

					break;
				case ALARM_DISPLAY: // display the normal temperature here.
					LED_Data = 14;
					Value = get_set_value(ALARM_DISPLAY);
					Value4= 19; // 'A'
					Value3=Value/1000;Value=Value%1000;
					Value2=Value/100;Value=Value%100; 
					Value1=Value/10;Value=Value%10; 
					Value0=Value;	
					break;
				case CONTROL_SETTING_ALARM_UPLIMIT:
					LED_Data = 16;
					if(EDIT_enable == 0)
					{
						Value4 = 20; // 'S'
						Value3 = 21; // 'H'
						Value = get_set_value(CONTROL_SETTING_ALARM_UPLIMIT);
						Current_Set_Value = Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;	
					}
					else
					{
						Value4 = 20; // 'S'
						Value3 = 21; // 'H'
						Value = Current_Set_Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;							
					}
					break;
				case CONTROL_SETTING_ALARM_LOWLIMIT:
					LED_Data = 16;
					if(EDIT_enable == 0)
					{
						Value4 = 20; // 'S'
						Value3 = 22; // 'L'
						Value = get_set_value(CONTROL_SETTING_ALARM_LOWLIMIT);
						Current_Set_Value = Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;	
					}
					else
					{
						Value4 = 20; // 'S'
						Value3 = 22; // 'L'
						Value = Current_Set_Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;							
					}
					break;
				case CONTROL_SETTING_SETPOINT:
					LED_Data = 16;
					if(EDIT_enable == 0)
					{
						Value4 = 20; // 'S'
						Value = get_set_value(CONTROL_SETTING_SETPOINT);
						Current_Set_Value = Value;
						Value3 = Value/1000;Value = Value%1000;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;	
					}
					else
					{
						Value4 = 20; // 'S'
						Value = Current_Set_Value;
						Value3 = Value/1000;Value = Value%1000;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;							
					}
					break;
				case PID_SETTING_P:
					LED_Data = 16;
					if(EDIT_enable == 0)
					{
						Value4 = 25; // 'P'
						Value3 = 1;
						Value = get_set_value(PID_SETTING_P);
						Current_Set_Value = Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;	
					}
					else
					{
						Value4 = 25; // 'P'
						Value3 = 1;
						Value = Current_Set_Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;							
					}
					break;
				case PID_SETTING_I:
					LED_Data = 16;
					if(EDIT_enable == 0)
					{
						Value4 = 25; // 'P'
						Value3 = 2;
						Value = get_set_value(PID_SETTING_I);
						Current_Set_Value = Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;	
					}
					else
					{
						Value4 = 25; // 'P'
						Value3 = 2;
						Value = Current_Set_Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;							
					}
					break;
				case PID_SETTING_D:
					LED_Data = 16;
					if(EDIT_enable == 0)
					{
						Value4 = 25; // 'P'
						Value3 = 3;
						Value = get_set_value(PID_SETTING_D);
						Current_Set_Value = Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;	
					}
					else
					{
						Value4 = 25; // 'P'
						Value3 = 3;
						Value = Current_Set_Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;							
					}
					break;
				case PID_SETTING_T:
					LED_Data = 16;
					if(EDIT_enable == 0)
					{
						Value4 = 25; // 'P'
						Value3 = 4;
						Value = get_set_value(PID_SETTING_T);
						Current_Set_Value = Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;	
					}
					else
					{
						Value4 = 25; // 'P'
						Value3 = 4;
						Value = Current_Set_Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;							
					}
					break;
				case CALIBRATION_SETTING_UPLIMIT:
					LED_Data = 12;
					if(EDIT_enable == 0)
					{
						Value4 = 23; // 'C'
						Value3 = 21; // 'H'
						Value = get_set_value(CALIBRATION_SETTING_UPLIMIT);
						Current_Set_Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;	
					}
					else
					{
						Value4 = 23; // 'C'
						Value3 = 21; // 'H'
						Value = Current_Set_Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;							
					}
					break;
				case CALIBRATION_SETTING_LOWLIMIT:
					LED_Data = 12;
					if(EDIT_enable == 0)
					{
						Value4 = 23; // 'C'
						Value3 = 22; // 'L'
						Value = get_set_value(CALIBRATION_SETTING_LOWLIMIT);
						Current_Set_Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;	
					}
					else
					{
						Value4 = 23; // 'C'
						Value3 = 22; // 'L'
						Value = Current_Set_Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;							
					}
					break;
				case CALIBRATION_SETTING_OFFSET:
					LED_Data = 12;
					if(EDIT_enable == 0)
					{
						Value4 = 23; // 'C'
						Value3 = 23; // 'C'
						Value = get_set_value(CALIBRATION_SETTING_OFFSET);
						Current_Set_Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;	
					}
					else
					{
						Value4 = 23; // 'C'
						Value3 = 23; // 'C'
						Value = Current_Set_Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;							
					}
					break;
				case SENSOR_SETTING:
					LED_Data = 15;
					if(EDIT_enable == 0)
					{
						Value4 = 24; // 'U'
						Value3 = 19; // 'A'
						Value = get_sensor_type();
						Current_Set_Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;	
					}
					else
					{
						Value4 = 24; // 'U'
						Value3 = 19; // 'A'
						Value = Current_Set_Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;							
					}
					break;
				case OUTPUTTYPE_SETTING:
					LED_Data = 14;
					if(EDIT_enable == 0)
					{
						Value4 = 21; // 'H'
						Value3 = 19; // 'A'
						Value = get_output_type();
						Current_Set_Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;	
					}
					else
					{
						Value4 = 21; // 'U'
						Value3 = 19; // 'A'
						Value = Current_Set_Value;
						Value2=Value/100;Value=Value%100; 
						Value1=Value/10;Value=Value%10; 
						Value0=Value;							
					}
					break;
				default:
					break;
			}
			

			/////////////////////////////////////////////////********  Key  and   MENU
			if(Key1Flag) // ESC key processing
			{
				Key1Flag=0x00;//LED_Data=13;
				CNT_BackMainMU=0;
				if(EDIT_enable == 1)
				{
					EDIT_enable = 0;
				}
				else
				{
					// back to normal default mode by default.
					if(DISPLAY_what != NORMAL_DISPLAY)
					{
						DISPLAY_what = NORMAL_DISPLAY;
					}
				}
			}

			if(Key2Flag) // Up key processing
			{
				Key2Flag=0x00;
				CNT_BackMainMU=0;			
				 B_Keypush=0x01;
                 CNT_Keypush=0x00;

				if(EDIT_enable == 0)
				{
					if(DISPLAY_what == 1)
					{
						B_BackMainMU=0x01;
						CNT_BackMainMU=0x00;
					}
					DISPLAY_what++;
					if (DISPLAY_what >= DISPLAY_MAX)
					{
						DISPLAY_what = 1;
					}
					Current_Set_Value = get_set_value(DISPLAY_what);
				}
				else // editing
				{
					Current_Set_Value++;
					//Current_Set_Value=Judge_Set_Value(DISPLAY_what);
				}
			}

			if(Key3Flag) // Down key processing
			{
				Key3Flag=0x00;
				B_Keypush=0x01;
                CNT_Keypush=0x00;
				CNT_BackMainMU=0;
				if(EDIT_enable == 0)
				{
					if(DISPLAY_what == 1)
					{
						B_BackMainMU=0x01;
						CNT_BackMainMU=0x00;
					}
					DISPLAY_what--; 
					if(DISPLAY_what == 0)
					{
						DISPLAY_what = DISPLAY_MAX -1;
					}
					
					Current_Set_Value = get_set_value(DISPLAY_what);
				}
				else // editing
				{
					Current_Set_Value--;
					//Current_Set_Value=Judge_Set_Value(DISPAY_what);
				}
			}

			if(Key4Flag) // Enter key process
			{
				Key4Flag=0x00;
				CNT_BackMainMU=0;
				if(EDIT_enable == 1)
				{
					EDIT_enable = 0;
					Save_Set_Value(DISPLAY_what, Current_Set_Value);
				}
				else
				{
					if(DISPLAY_what != NORMAL_DISPLAY)
					{
						EDIT_enable = 1;
					}					
				}			
			}
				
		    /////////////////////////////////////////////////********  Key  and   MENU
				/////////////////////////////////////////////////********  Process
				
				
				if(Flag_B_100ms)
				 {
				   Flag_B_100ms	= 0;

					adTC_value=adc_get_value (21);                 // ADC 值获取函数

					if(List_tempTC>=20)List_tempTC=0;
					Buf_tempTC[List_tempTC++]=adTC_value;;
					DataSum=0;
									
					for(i=0;i<20;i++)
					{
					    DataSum=DataSum+Buf_tempTC[i];
						if(Buf_tempTC[i] > DataMax) DataMax = Buf_tempTC[i];
						if(Buf_tempTC[i] < DataMin) DataMin = Buf_tempTC[i];
					}
					DataSum -= 	DataMax;
					DataSum -= 	DataMin;			
					DataSum=DataSum/18;
									
					tempTC = DataSum;

					tempTC= adTC_value ;

				     NowTC_Data_Value = 	tempTC * ki_TempCal + kp_TempCal;//						 
									
					TempData_Current=NowTC_Data_Value;
				
					// if(++Temp_TC_Ctrl_Cnt > kt_TC)
					// {
					// 	Temp_TC_Ctrl_Flag =1;
					// 	Temp_TC_Ctrl_Cnt = 0;
					// }

					Do_PID_Control();
					

					
				 }

				 if(Flag_B_1000ms)
				 {
				   Flag_B_1000ms	= 0;
					 
					/// K1=!K1;
					// K2=!K2;
				 	 //BackADDataTo_PC();
				// 	 //RS485_EN=1;
				// 	 //SendByte(0xAA);	
				 }


				if (RX1COMOK)
				{
					/* code */
					RX1COMOK = 0;	// 单片机完整接收一条消息

					 ParseDataFrom_PC();


				}
					

		    /////////////////////////////////////////////////********  Process
				
		    
	}
}
/*
系统频率设置为二分频
*/

/*
LED1  P0.3
LED2  P1.4
LED3  P1.6
LED4  P1.2

*/
/******************************************************************************************
** 函数名称: gpio_init
** 函数描述: 将所有IO配置成推挽模式   
** 输入参数: 无
** 输出参数: 无 
*******************************************************************************************/
void gpio_init(void)
{
/////////////////////////////////////////////////////////////////
   
	PORTIDX = PORT3;
	PINMOD32 = PINMOD32 & ~0x0f | PIN_L_Mode_PP;	                    //P32  com1
	P3_2 = 0; 
  PORTIDX = PORT3;
	PINMOD32 = PINMOD32 & ~0xF0 | PIN_H_Mode_PP;	                    //P33  com2
	P3_3 = 0;   

  PORTIDX = PORT2;
	PINMOD32 = PINMOD32 & ~0xf0 | PIN_H_Mode_PP;                      //P23   .com3
	P2_3 = 0;
  PINMOD54 = PINMOD54 & ~0x0f | PIN_L_Mode_PP;	 										//P2.4   com4
	P2_4 = 0;

  PORTIDX = PORT0;
	PINMOD32 = PINMOD32 & ~0x0f | PIN_L_Mode_PP;                      //P02    com5
	P0_2 = 0;
	PINMOD32 = PINMOD32 & ~0xf0 | PIN_H_Mode_PP;                      //P03    com6
	P0_3 = 0;
	PINMOD76= PINMOD32 & ~0x0f | PIN_L_Mode_PP;                       //P06    com7
	P0_6 = 0;	
	PINMOD76= PINMOD32 & ~0xf0 | PIN_H_Mode_PP;                       //P07    com8
	P0_7 = 0;
	
	PORTIDX = PORT3;
	PINMOD10 = PINMOD10 & ~0xf0 | PIN_H_Mode_PP;	                    //P31    com9
	P3_1 = 0; 
	
  PORTIDX = PORT3;
	PINMOD10 = PINMOD10 & ~0x0f | PIN_L_Mode_PP;	                    //P30    K1
	P3_0 = 0; 
	 
	 
	PORTIDX = PORT3;
	PINMOD76 = PINMOD76 & ~0xF0 | PIN_H_Mode_OD_IPU_WAKEUP;    //P3.7 	key1  
  PORTIDX = PORT2;
	PINMOD10 = PINMOD10 & ~0xf0 | PIN_H_Mode_OD_IPU_WAKEUP;    //P2.1  	key2  
	PINMOD10 = PINMOD10 & ~0x0f | PIN_L_Mode_OD_IPU_WAKEUP;    //P2.0   key3  
	PORTIDX = PORT0;
	PINMOD54 = PINMOD54 & ~0x0f | PIN_L_Mode_OD_IPU_WAKEUP;    //P0.4 	key1  
	 
	PORTIDX = PORT1; 
	PINMOD10 = PINMOD10 & ~0x0f | PIN_L_Mode_PP;   						//P1.0  A0  
	PINMOD10 = PINMOD10 & ~0xf0 | PIN_H_Mode_PP;   						//P1.1  B0  
	PINMOD32 = PINMOD32 & ~0x0f | PIN_L_Mode_PP;   						//P1.2  C0 	
  PINMOD32 = PINMOD32 & ~0xF0 | PIN_H_Mode_PP;   						//P1.3  D0  
	
	PINMOD54 = PINMOD54 & ~0x0f | PIN_L_Mode_PP;    					// P1.4  E0
	PINMOD76 = PINMOD76 & ~0x0f| PIN_L_Mode_PP;    					  // P1.6  G0
	PINMOD54 = PINMOD54 & ~0xf0| PIN_H_Mode_PP;    			      // P1.5  F0
	
	PINMOD76 = PINMOD76 & ~0xF0 | PIN_H_Mode_ADC;             ////P1.7  ADC  CH 12
	
	
}
/* 快时钟系统主频为 18.432M/2 = 9.216M
 * 分给定时器的时钟频率为9.216M/2 = 4.608M
 */
/*
系统频率设置为二分频
*/

/******************************************************************************************
** 函数名称: timer0_init
** 函数描述: time0初始化函数   
** 输入参数: 无
** 输出参数: 无 
*******************************************************************************************/
void timer0_init(void)
{
	TMOD = (TMOD & ~ TMOD_TMOD0_MASK) | 1 << TMOD_TMOD0_POS;       // Timer0模式选择  16位定时器                       

	TH0 = (65536 - 461) / 256;             // 100US
	TL0 = (65536 - 461) % 256;

	TR0 = 1;                               // TIMER0 运行
	ET0 = 1;
}
/*
系统频率设置为二分频
*/

/******************************************************************************************
** 函数名称: uart1_timer2_init
** 函数描述: uart初始化函数  9600-8-1 无校验（中断接收）
** 输入参数: 无
** 输出参数: 无
*******************************************************************************************/

void uart1_timer2_init(void)
{
	PCON |= 0X80; 		//双波特率控制位
	
	PORTIDX = PORT3;
	PINMOD32 = PINMOD32 & 0x00 | PIN_L_Mode_OD_IPU | PIN_H_Mode_PP;	 //uart选用 txd p33   rxd p32
	PINMOD = PINMOD & ~0x03 | 0X01;                                  //uart选用 txd p33   rxd p32

//	PORTIDX = PORT3;
//	PINMOD32 = PINMOD32&0x00 | PIN_H_Mode_OD_IPU | PIN_L_Mode_PP;	  //uart选用 txd p32   rxd p33 
//	PINMOD = PINMOD&~0x03|0X03;                                       //uart选用 txd p32   rxd p33
	
	
	SM0 = 0;
	SM1 = 1;  				//模式1
	SM2 = 0;


	//  TMOD |= 0X10;		                //16位自动重装载

	CT2 = 0;                                // 定时器模式，Timer2 的数据以 2 个系统时钟周期速率增加
	TCLK = 1;                               // 模式1 或 3 时使用Timer2 溢出作为串行端口发送时钟
	RCLK = 1;                               // 模式1 或 3 时使用Timer2 溢出作为串行端口接收时钟

	TH2 = (65535 - 30) / 256;   			// 9600   9.216MHz
	TL2 = (65535 - 30) % 256;
	RCP2H = (65535 - 30) / 256;
	RCP2L = (65535 - 30) % 256;

	TR2 = 1;
	REN = 1; 				              	// 允许接收

	ES = 1;

}

void  SendByte(unsigned char DATA)
{
	  unsigned char temp;
	
	  temp=DATA;
	  
	  TI = 0;
	
    SBUF = temp;
	
		//while (TI == 0);
	
		//TI = 0;
}
void ScanKey1(void)
{
	//RSTSTAT = RSTSTAT;
	if(!Key1Flag)
	{
		//Key2ValueBK = KEYVAL_NULL;
		if(P1_3==0)
		{
			//Key2ValueBK = KEY_ON;
			CNT_Key1_On++;
			if(CNT_Key1_On>5)
			{   
				
				//CNT_Key1_On=5;
				//KeyValueBK = KEY_ON;
				
				CNT_Key1_On=0;
				
				Key1Value = 0x01;
				Key1Flag = 1;
				
			}
		}
		else
		{
			//if(KeyValueBK)
			//{
			//	KeyValueBK = 0x00;
			//	KeyValue = 0x01;
			//	KeyFlag = 1;
			//}
			
			CNT_Key1_On=0x00;;
		}
	}
	
	
}
void ScanKey2(void)
{
	//RSTSTAT = RSTSTAT;
	if(!Key2Flag)
	{
		//Key2ValueBK = KEYVAL_NULL;
		//if(!KEY_2_IO)
		if(P1_2==0)
		{
			//Key2ValueBK = KEY_ON;
			CNT_Key2_On++;
			if(CNT_Key2_On>5)
			{   
				CNT_Key2_On=0;
				
				Key2Value = 0x01;
				Key2Flag = 1;
				//Key2ValueBK = KEY_ON;
			}
		}
		else
		{
			//if(Key2ValueBK)
			//{
			//	Key2ValueBK = 0x00;
			//	Key2Value = 0x01;
			//	Key2Flag = 1;
			//}
			
			CNT_Key2_On=0x00;;
		}
	}
	
	
}
void ScanKey3(void)
{
	//RSTSTAT = RSTSTAT;
	if(!Key3Flag)
	{
		//Key2ValueBK = KEYVAL_NULL;
		//if(!KEY_2_IO)
		if(P1_1==0)
		{
			//Key2ValueBK = KEY_ON;
			CNT_Key3_On++;
			if(CNT_Key3_On>5)
			{   
				CNT_Key3_On=0;
				
				Key3Value = 0x01;
				Key3Flag = 1;
				//Key3ValueBK = KEY_ON;
			}
		}
		else
		{
			//if(Key3ValueBK)
			//{
			//	Key3ValueBK = 0x00;
			//	Key3Value = 0x01;
			//	Key3Flag = 1;
			//}
			
			CNT_Key3_On=0x00;;
		}
	}
}
void ScanKey4(void)
{
	//RSTSTAT = RSTSTAT;
	if(!Key4Flag)
	{
		//Key2ValueBK = KEYVAL_NULL;
		//if(!KEY_2_IO)
		if(P1_0==0)
		{
			//Key2ValueBK = KEY_ON;
			CNT_Key4_On++;
			if(CNT_Key4_On>5)
			{   
				CNT_Key4_On=0;
				Key4Value = 0x01;
				Key4Flag = 1;
				//Key4ValueBK = KEY_ON;
			}
		}
		else
		{
			//if(Key4ValueBK)
			//{
			//	Key4ValueBK = 0x00;
			//	Key4Value = 0x01;
			//	Key4Flag = 1;
			//}
			
			CNT_Key4_On=0x00;;
		}
	}
}

void Delay4us(void)
{
	U8 i;
	//for(i=0; i<16; i++);
	for(i=0; i<5; i++);
}

void HC595SendData(unsigned char SendVal)//发送数据
{  
   
	 P1_0 = ((SendVal & 0x01) != 0)?1:0; // A0
	 P1_1 = ((SendVal & 0x02) != 0)?1:0; // B0
	 P1_2 = ((SendVal & 0x04) != 0)?1:0; // C0
	 P1_3 = ((SendVal & 0x08) != 0)?1:0; // D0
	 P1_4 = ((SendVal & 0x10) != 0)?1:0; // E0
	 P1_6 = ((SendVal & 0x40) != 0)?1:0; // G0
	 P1_5 = ((SendVal & 0x20) != 0)?1:0; // F0	
} 

void HC595ShowData()
{
  P1_7=0;		//	RCK1_595=0;
  //_nop_();
  //_nop_();
	Delay4us(); 
	//Delay4us(); 
	
  P1_7=1;		//  RCK1_595=1; 
}

void select11()
{
  P3_2 = 1;  //P3.2 COM1
  P3_3 = 0;  //P3.3 COM2
  P2_3 = 0;  //P2.3 COM3  	
  P2_4 = 0;  //P2.4 COM4
  P0_2 = 0;  //P0.2 COM5
  P0_3 = 0;  //P0.3 COM6
  P0_6 = 0;  //P0.6 COM7
  P0_7 = 0;  //P0.7 COM8
  P3_1 = 0;  //P3.1 COM9
}	
void select12()
{
  P3_2 = 0;  //P3.2 COM1
  P3_3 = 1;  //P3.3 COM2
  P2_3 = 0;  //P2.3 COM3  	
  P2_4 = 0;  //P2.4 COM4
  P0_2 = 0;  //P0.2 COM5
  P0_3 = 0;  //P0.3 COM6
  P0_6 = 0;  //P0.6 COM7
  P0_7 = 0;  //P0.7 COM8
  P3_1 = 0;  //P3.1 COM9
}	
void select13()
{
  P3_2 = 0;  //P3.2 COM1
  P3_3 = 0;  //P3.3 COM2
  P2_3 = 1;  //P2.3 COM3  	
  P2_4 = 0;  //P2.4 COM4
  P0_2 = 0;  //P0.2 COM5
  P0_3 = 0;  //P0.3 COM6
  P0_6 = 0;  //P0.6 COM7
  P0_7 = 0;  //P0.7 COM8
  P3_1 = 0;  //P3.1 COM9
}	
void select14()
{
  P3_2 = 0;  //P3.2 COM1
  P3_3 = 0;  //P3.3 COM2
  P2_3 = 0;  //P2.3 COM3  	
  P2_4 = 1;  //P2.4 COM4
  P0_2 = 0;  //P0.2 COM5
  P0_3 = 0;  //P0.3 COM6
  P0_6 = 0;  //P0.6 COM7
  P0_7 = 0;  //P0.7 COM8
  P3_1 = 0;  //P3.1 COM9
}	
void select21()
{
  P3_2 = 0;  //P3.2 COM1
  P3_3 = 0;  //P3.3 COM2
  P2_3 = 0;  //P2.3 COM3  	
  P2_4 = 0;  //P2.4 COM4
  P0_2 = 1;  //P0.2 COM5
  P0_3 = 0;  //P0.3 COM6
  P0_6 = 0;  //P0.6 COM7
  P0_7 = 0;  //P0.7 COM8
  P3_1 = 0;  //P3.1 COM9
}	
void select22()
{
  P3_2 = 0;  //P3.2 COM1
  P3_3 = 0;  //P3.3 COM2
  P2_3 = 0;  //P2.3 COM3  	
  P2_4 = 0;  //P2.4 COM4
  P0_2 = 0;  //P0.2 COM5
  P0_3 = 1;  //P0.3 COM6
  P0_6 = 0;  //P0.6 COM7
  P0_7 = 0;  //P0.7 COM8
  P3_1 = 0;  //P3.1 COM9
}	
void select23()
{
  P3_2 = 0;  //P3.2 COM1
  P3_3 = 0;  //P3.3 COM2
  P2_3 = 0;  //P2.3 COM3  	
  P2_4 = 0;  //P2.4 COM4
  P0_2 = 0;  //P0.2 COM5
  P0_3 = 0;  //P0.3 COM6
  P0_6 = 1;  //P0.6 COM7
  P0_7 = 0;  //P0.7 COM8
  P3_1 = 0;  //P3.1 COM9
}	
void select24()
{
  P3_2 = 0;  //P3.2 COM1
  P3_3 = 0;  //P3.3 COM2
  P2_3 = 0;  //P2.3 COM3  	
  P2_4 = 0;  //P2.4 COM4
  P0_2 = 0;  //P0.2 COM5
  P0_3 = 0;  //P0.3 COM6
  P0_6 = 0;  //P0.6 COM7
  P0_7 = 1;  //P0.7 COM8
  P3_1 = 0;  //P3.1 COM9
}	
void selectled()
{
  P3_2 = 0;  //P3.2 COM1
  P3_3 = 0;  //P3.3 COM2
  P2_3 = 0;  //P2.3 COM3  	
  P2_4 = 0;  //P2.4 COM4
  P0_2 = 0;  //P0.2 COM5
  P0_3 = 0;  //P0.3 COM6
  P0_6 = 0;  //P0.6 COM7
  P0_7 = 0;  //P0.7 COM8
  P3_1 = 1;  //P3.1 COM9
}

void BackCurrentDataTo_PC(void)
{
		U8 j=0;

        union FtoC{
		float F;
		unsigned char B[4];// ??????????????????4?????
	    }temp;

		//CNT_500ms=0;
		//Timer500msFlg=0;
	    temp.F = TempData_Current;// 将浮点数写入共用体
       
	    

	    Sed_Com1[j++]=0X5A;Sed_Com1[j++]=0XA5;
		Sed_Com1[j++]=0x00;
		Sed_Com1[j++]=0X07;
		Sed_Com1[j++]=0XBA;

		Sed_Com1[j++]=temp.B[3];
		Sed_Com1[j++]=temp.B[2];
		Sed_Com1[j++]=temp.B[1];
		Sed_Com1[j++]=temp.B[0];	

		Sed_Com1[j++]=adTC_value>>8;	Sed_Com1[j++]=adTC_value&0x00FF;

		Sed_Com1[j++] = K1;

		Sed_Com1[j++] = K2;

		Sed_Com1[j++] = Temp_TC_Period_Flag>>8;

		Sed_Com1[j++] = Temp_TC_Period_Flag&0xFF;

		Sed_Com1[j++]=0XAA;Sed_Com1[j++]=0X55;
					
		Sed_Com1[2]=j;
				  
        Write_Com1SBUF(Sed_Com1[0],j);
}

void BackADDataTo_PC(void)
{
		U8 j=0;

		//CNT_500ms=0;
		//Timer500msFlg=0;
	
	    Sed_Com1[j++]=0X5A;Sed_Com1[j++]=0XA5;
		Sed_Com1[j++]=0x00;
		Sed_Com1[j++]=0X01;
		Sed_Com1[j++]=0XD0;Sed_Com1[j++]=0X01;
				
		Sed_Com1[j++]=adTC_value>>8;	Sed_Com1[j++]=adTC_value&0x00FF;
//		Sed_Com1[j++]=DAC0_Data>>8; Sed_Com1[j++]=DAC0_Data&0x00FF;
//		Sed_Com1[j++]=DAC1_Data>>8; Sed_Com1[j++]=DAC1_Data&0x00FF;
//		Sed_Com1[j++]=PWM0_Data>>8; Sed_Com1[j++]=PWM0_Data&0x00FF;
//		Sed_Com1[j++]=PWM1_Data>>8; Sed_Com1[j++]=PWM1_Data&0x00FF;
	
		Sed_Com1[j++]=0XAA;Sed_Com1[j++]=0X55;
					
		Sed_Com1[2]=j;
				  
        Write_Com1SBUF(Sed_Com1[0],j);


}

void SendCommandResponse(U8 Cmd,U8 CmdData)
{
		U8 j=0;

		//CNT_500ms=0;
		//Timer500msFlg=0;
	
	    Sed_Com1[j++]=0X5A;Sed_Com1[j++]=0XA5;
		Sed_Com1[j++]=0x00;
		Sed_Com1[j++]=0X07;
		Sed_Com1[j++]=Cmd;
		Sed_Com1[j++]=CmdData;
		Sed_Com1[j++]=0XAA;Sed_Com1[j++]=0X55;
					
		Sed_Com1[2]=j;
				  
        Write_Com1SBUF(Sed_Com1[0],j);


}
void SendCommandResponse_float(U8 Cmd,float CmdData)
{
		U8 j=0;

       union FtoC{
		float F;
		unsigned char B[4];// ??????????????????4?????
	    }temp;
		//CNT_500ms=0;
		//Timer500msFlg=0;
	     
		 temp.F = CmdData;// 将浮点数写入共用体

	    Sed_Com1[j++]=0X5A;Sed_Com1[j++]=0XA5;
		Sed_Com1[j++]=0x00;
		Sed_Com1[j++]=0X07;
		Sed_Com1[j++]=Cmd;
		Sed_Com1[j++]=temp.B[3];
		Sed_Com1[j++]=temp.B[2];
		Sed_Com1[j++]=temp.B[1];
		Sed_Com1[j++]=temp.B[0];

		Sed_Com1[j++]=0XAA;Sed_Com1[j++]=0X55;
					
		Sed_Com1[2]=j;
				  
        Write_Com1SBUF(Sed_Com1[0],j);


}
void ParseDataFrom_PC(void)
{

	float buf_F; 
	union FtoC{
		float F;
		unsigned char B[4];// ??????????????????4?????
	}temp;
	// unsigned char i;
	// float value;
	
	// for(i = 0; i <=3 ; i++)
	// {
	// 	temp.B[i] = epprom_read_byte(0,addr+i);	
	// }	
	
	switch(Rec_Com1_Data[4])
	{
			case 0xBA:        //上位机请求数据回传 电压，热电偶，PT1000 实	时数据
				BackCurrentDataTo_PC();
				break;
			case 0xB0:        //temp  set point
				SendCommandResponse_float(0xB0, TempSet_Point);
				break;
			case 0xB5:        // TC_Kp
				SendCommandResponse_float(0xB5, kp_TC);
				break;
			case 0xB6:        // TC_Ki
				SendCommandResponse_float(0xB6, ki_TC);
				break;
			case 0xB7:        // TC_Kd
				SendCommandResponse_float(0xB7, kd_TC);
				break;
			case 0xB8:        // TC_Kt
				SendCommandResponse_float(0xB8, kt_TC);
				break;
			case 0xBB:        // TCHighCalibration
				SendCommandResponse_float(0xBB, TCHighCalibration);
				break;
			case 0xBC:        // TCLowCalibration
				SendCommandResponse_float(0xBC, TCLowCalibration);
				break;
			case 0xBD:        // TCOffsetCalibration
				SendCommandResponse_float(0xBD, TCOffsetCalibration);
			case 0xB9:        // TempSetHigh
				SendCommandResponse_float(0xB9, Temp_SetHigh);
				break;
			case 0xBE:        // TempSetLow
				SendCommandResponse_float(0xBE, Temp_SetLow);
				break;
			case 0xBF:        // Temp_Disp_Tolerance
				SendCommandResponse_float(0xBF, Temp_Disp_Tolerance);
				break;
			case 0xC1:        //温度热电偶1高点
				Flag_TCVoltageHighCalibration_OK = 1;
				temp.B[3]=Rec_Com1_Data[5];
			    temp.B[2]=Rec_Com1_Data[6];
			    temp.B[1]=Rec_Com1_Data[7];
			    temp.B[0]=Rec_Com1_Data[8];	
				TCHighCalibration=temp.F;
				AdcTC_H=adTC_value;	
				Save_CalibrationParameter();
				break;
			case 0xC2:        //温度热电偶1低点
				Flag_TCVoltageLowCalibration_OK = 1;
				temp.B[3]=Rec_Com1_Data[5];
			    temp.B[2]=Rec_Com1_Data[6];
			    temp.B[1]=Rec_Com1_Data[7];
			    temp.B[0]=Rec_Com1_Data[8];	
				TCLowCalibration=temp.F;
				AdcTC_L=adTC_value;	
				Save_CalibrationParameter();
				break;		
			case 0xC3:        //温度热电偶1 offset点
			   
					
				break;
		   case 0xD0:        //温度 Setpoint   
			    temp.B[3]=Rec_Com1_Data[5];
			    temp.B[2]=Rec_Com1_Data[6];
			    temp.B[1]=Rec_Com1_Data[7];
			    temp.B[0]=Rec_Com1_Data[8];	
				  TempSet_Point=temp.F;
				  SaveFloat(TempSet_Point, 0x60);
				  SendCommandResponse(Rec_Com1_Data[4],0x01);
				break;	
			case 0xD5:        //温度 Setpoint   
			    temp.B[3]=Rec_Com1_Data[5];
			    temp.B[2]=Rec_Com1_Data[6];
			    temp.B[1]=Rec_Com1_Data[7];
			    temp.B[0]=Rec_Com1_Data[8];	
				  kp_TC=temp.F;
				  SaveFloat(kp_TC, 0x10);
                  buf_F=ReadFloat(0x10);
				  if(buf_F<kp_TC+0.001 && buf_F > kp_TC-0.001)
				  	SendCommandResponse(Rec_Com1_Data[4],0x00);
				  else
				  	SendCommandResponse(Rec_Com1_Data[4],0x01);
				break;		
			case 0xD6:        //温度 Setpoint   
			    temp.B[3]=Rec_Com1_Data[5];
			    temp.B[2]=Rec_Com1_Data[6];
			    temp.B[1]=Rec_Com1_Data[7];
			    temp.B[0]=Rec_Com1_Data[8];	
				  ki_TC=temp.F;
				  SaveFloat(ki_TC, 0x18);
				  //SendCommandResponse(Rec_Com1_Data[4],0x01);
				break;	
			case 0xD7:        //温度 Setpoint   
			    temp.B[3]=Rec_Com1_Data[5];
			    temp.B[2]=Rec_Com1_Data[6];
			    temp.B[1]=Rec_Com1_Data[7];
			    temp.B[0]=Rec_Com1_Data[8];	
				  kd_TC=temp.F;
				  SaveFloat(kd_TC, 0x20);
				  //SendCommandResponse(Rec_Com1_Data[4],0x01);
				break;
			case 0xD8:        //温度 Setpoint   
			    temp.B[3]=Rec_Com1_Data[5];
			    temp.B[2]=Rec_Com1_Data[6];
			    temp.B[1]=Rec_Com1_Data[7];
			    temp.B[0]=Rec_Com1_Data[8];	
				  kt_TC=temp.F;
				  SaveFloat(kt_TC, 0x28);
				 // SendCommandResponse(Rec_Com1_Data[4],0x01);
				break;
			case 0xD9:        //温度 Temp_SetHigh   
			    temp.B[3]=Rec_Com1_Data[5];
			    temp.B[2]=Rec_Com1_Data[6];
			    temp.B[1]=Rec_Com1_Data[7];
			    temp.B[0]=Rec_Com1_Data[8];	
				  Temp_SetHigh=temp.F;
				  SaveFloat(Temp_SetHigh, 0x68);
				  SendCommandResponse(0xD9,0x01);
				break;
			case 0xDE:        //温度 Temp_SetLow 
			    temp.B[3]=Rec_Com1_Data[5];
			    temp.B[2]=Rec_Com1_Data[6];
			    temp.B[1]=Rec_Com1_Data[7];
			    temp.B[0]=Rec_Com1_Data[8];	
				  Temp_SetLow=temp.F;
				  SaveFloat(Temp_SetLow, 0x70);
				  SendCommandResponse(0xDE,0x01);
				break;
			case 0xDF:        //温度 Temp_Disp_Tolerance   
			    temp.B[3]=Rec_Com1_Data[5];
			    temp.B[2]=Rec_Com1_Data[6];
			    temp.B[1]=Rec_Com1_Data[7];
			    temp.B[0]=Rec_Com1_Data[8];	
				  Temp_Disp_Tolerance=temp.F;
				  SaveFloat(Temp_Disp_Tolerance, 0x78);
				  SendCommandResponse(0xDF,0x01);
				break;
			default:
				break;
	}
	
}

void Write_Com1SBUF(U8 Data,U8 length)
{
	//BANK1_SEL;
	//_SWTCH_BANK(1);

    TI=0;
	  //REN1 = 0; 
	
	  RS485_EN =1;
	
	  //COM0_485_EN();
	//COM0_485_EN
    SBUF = Data;     //Start Send Data; Set UART REG
	
	//_SWTCH_BANK(0);
    //BANK0_SEL;
	
	  COM1_Send_Length=length;   								  //??????????
    COM1_Send_Ptr=0x01;
   	  
}
void 	Save_CalibrationParameter(void )
{

    if (Flag_TCVoltageHighCalibration_OK && Flag_TCVoltageLowCalibration_OK)// 电压校准完成，计算新的电压系数
		{	
			Flag_TCVoltageHighCalibration_OK = 0;
			Flag_TCVoltageLowCalibration_OK = 0;
			if(TCHighCalibration != TCLowCalibration)	// 防止未改变设置电压多次校准写入
			{
				
				//GetNew_Vparameter();
				GetNewTC_KiKpParameter();
				
			}
		}
		
		// if( Flag_PTVoltageHighCalibration_OK && Flag_PTVoltageLowCalibration_OK )	
		// {
		// 	Flag_PTVoltageHighCalibration_OK = 0;
		// 	Flag_PTVoltageLowCalibration_OK = 0;
		// 	if(PTHighCalibration != PTLowCalibration)	
		// 	{
		// 		//GetNew_Iparameter();
		// 		GetNewPT_KiKpParameter();
		// 		//Write_Eeprom();
		// 	}			
		// }	


}
void GetNewTC_KiKpParameter( void )// 校准万用表---AD电压采集
{
	float Ki = 0;
	float Kp = 0;
	
	
	Ki = (float) (TCHighCalibration - TCLowCalibration) / (AdcTC_H - AdcTC_L);
	Kp = (float) (TCHighCalibration) - AdcTC_H * Ki;

	
	//ki_TC = ki_TC * Ki;
	//kp_TC = kp_TC * Ki + Kp;// 注意不是减号
	
	ki_TempCal = Ki;
	kp_TempCal = Kp;// 注意不是减号
	
	//Write_Eeprom();
   SaveFloat(ki_TempCal,0x30);
   SaveFloat(kp_TempCal,0x38);

}
void Write_Eeprom( void )
{
	
   U8 buf_H,buf_L;
	 MYUNION_16 myuniondata_16;
	
	
	EA = 0;		
	//Sector_Erase(0);	// 先擦除扇区0	
	
//	SaveFloat(ki_TC,0x04);
//	SaveFloat(kp_TC,0x08);	
//	SaveFloat(ki_TC_v0,0x0C);	
//	SaveFloat(kp_TC_v0,0x10);
//	
//	
//	eeprom_write_byte(0,0x24,P_WKP);	
//	eeprom_write_byte(0,0x25,I_WKP);	
//	eeprom_write_byte(0,0x26,D_WKP);	
//	eeprom_write_byte(0,0x27,T_WKP);

	EA = 1;		
}

/******************************************************************************************/
void Read_Eeprom( void )
{
	
//	0x3F,0x00,0xF8,0x62,	// ki_TC;
//	0x43,0x7B,0xE3,0xD7,	// kp_TC;
//  0x3F,0x00,0xF8,0x62,	// ki_TC_v0;
//	0x43,0x7B,0xE3,0xD7,  // kp_TC_v0;
//			
//	0x43,0x99,0x93,0x33,	// ki_PT;
//	0x3C,0x76,0x16,0x72,	// kp_PT;
//	0x43,0x99,0x93,0x33,	// ki_PT_v0;
//	0x3C,0x76,0x16,0x72,	// kp_PT_v0;
	
	//BOARD_ID = (epprom_read_byte(0,0x00));
	
//	typedef union  
//	{
//		 U8 Data[2];
//		 S16 Data_s16;
//	}MYUNION_16;
	
	 U8 buf_H,buf_L;
	 MYUNION_16 myuniondata_16;
//	

//	
//	ki_TC = ReadFloat(0x04);
//	kp_TC = ReadFloat(0x08);		
//	ki_TC_v0 = ReadFloat(0x0C);
//	kp_TC_v0 = ReadFloat(0x10);
//		
//	P_WKP=epprom_read_byte(0x00,0x24);
//	I_WKP=epprom_read_byte(0x00,0x25);
//	D_WKP=epprom_read_byte(0x00,0x26);
//	T_WKP=epprom_read_byte(0x00,0x27);
	
		
}
float ReadFloat(unsigned char addr)
{
	union FtoC{
		float F;
		unsigned char B[4];// 一个单精度的浮点数占用4个字节
	}temp;
	unsigned char i;
	float value;
	
	//for(i = 0; i <=3 ; i++)
	//{
	//	temp.B[i] = epprom_read_byte(0,addr+i);	
	//}	
	//void iap_eeprom_write(unsigned char addr, unsigned char *buf, unsigned char len);
    //void iap_eeprom_read(unsigned char addr, unsigned char *buf, unsigned char len);
     
	 iap_eeprom_read(addr,read_mileage,4); 

	 temp.B[3]=read_mileage[0] ;
	 temp.B[2]=read_mileage[1] ;
	 temp.B[1]=read_mileage[2] ;
	 temp.B[0]=read_mileage[3] ; 



	value = temp.F;// 读出浮点数
	return value;
}

void SaveFloat(float f,unsigned char addr)
{
	union FtoC{
		float F;
		unsigned char B[4];
	}temp;
	unsigned char i;
	
	temp.F = f;// 将浮点数写入共用体
	//for(i = 0; i <=3 ; i++)
	//{
	//	eeprom_write_byte(0,addr+i,temp.B[i]);
	//}
    write_mileage[0] = temp.B[3];
	write_mileage[1] = temp.B[2];
	write_mileage[2] = temp.B[1];
	write_mileage[3] = temp.B[0];
    iap_eeprom_write(addr,write_mileage,4);	    


}	

/******************************************************************************************
** 函数名称: adc_control_init
** 函数描述: ADC counter脚初始化  
** 输入参数: 无
** 输出参数: 无 
*******************************************************************************************/
void adc_control_init()
{
	
	//PORTIDX = PORT1;
	//PINMOD54 = PINMOD54 & ~0xf0 | PIN_L_Mode_PP;	                    //P14

	//PINMOD76 = PINMOD76 & ~0xf0 | PIN_H_Mode_ADC;		                //P0.2


	PORTIDX = PORT0;
	
	
	PINMOD32 = PINMOD32 & ~0x0f | PIN_L_Mode_ADC;                      ////P0.2  ADC  CH 21
	//P0_3 = 1;
	
}
/******************************************************************************************
** 函数名称: adc_init
** 函数描述: ADC初始化函数   
** 输入参数: 无
** 输出参数: 无 
*******************************************************************************************/
void  adc_init()
{
	unsigned char temp;
	
	temp = OPTION & 0xf3;

	OPTION = temp | ADCKS_sys_8;               //adc分频  选择不同的分频数

	SET_ADVREFS_00;                            //VCC选择基准源
}

/**********************************************************************************************************
**函数名称 ：adc_get_value
**函数描述 ：ADC返回值 adc_temp 
**输    入 ：adc_temp
**输    出 ：adc_sum
**********************************************************************************************************/
unsigned int adc_get_value (unsigned char ch)                 // ADC 值获取函数
{
	unsigned int adc_temp = 0;
	unsigned int  temph = 0;
	unsigned int  templ = 0;

	ADCHS = (ADCHS & ~ADCHS) | ch;                            // ADC 通道选择

	ADSOC = 1;                                                // ADC启动转换
	while (ADSOC);

	templ = ADCDL;
	temph = ADCDH;

	adc_temp  = (temph << 4) & 0xff0;
	adc_temp  |= (templ >> 4);
	return adc_temp ;
	
}
/* eeprom写数据*/
/*
 连续写字节不能太多
 写单个字节的时间根据写的内容的前后不同，时间不等。	以及电源电压相关
 理论上随着写的次数增加，写的时间会相应增加，建议以单个字节1ms-2ms的时间为基准
*/
/******************************************************************************************
** 函数名称: iap_eeprom_write
** 函数描述: iap_EEPROM写数据配置函数  
** 输入参数: 无
** 输出参数: 无 
*******************************************************************************************/
void iap_eeprom_write(unsigned char addr, unsigned char *buf, unsigned char len)       
{
	unsigned char i=0,temp_ea=0;
	
	temp_ea = EA;
	EA = 0;

 	IAPWE_SFR=0XE2;    //使能iap
    LVRPD = 1;   //关闭LVR
	
	for(i = 0;i<len;i++)
	{
		IAPTE_22_MS;        //设置IAP看门狗复位时间
		eeprom_address[addr+i*2] = *buf;
		buf++;
	}
	LVRPD = 0; ;         //打开LVR
    IAPWE_SFR = 0x00;    //关闭IAP
	IAPTE_DISABLE;

	EA = temp_ea;
}
/******************************************************************************************
** 函数名称: iap_eeprom_read
** 函数描述: iap_EEPROM读数据配置函数  
** 输入参数: 无
** 输出参数: 无 
*******************************************************************************************/
void iap_eeprom_read(unsigned char addr, unsigned char *buf, unsigned char len)    //eeprom读
{
	unsigned char i=0,temp_ea=0;
	
	temp_ea = EA;
	EA = 0;
	
	for(i = 0;i<len;i++)
	{
		*buf = eeprom_address[addr+i*2];
		buf++;
	}	
	
	EA = temp_ea;
}

	