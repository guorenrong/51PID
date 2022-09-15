#include <REGtenxTM52F086B.h>
#include <intrins.h>
#include "TM52F086B_bsp.h"







/* 快时钟系统主频为 18.432/2M   默认二分频
 */
void bsp_clock_init()	     
{
	SELFCK = 0;	         //切换到慢时钟
		
	CLKCON = 0x02;       //时钟二分频
//	CLKCON = 0x03;       //时钟一分频
	
	delay_10nop();
	STPPCK = 0;			 //开启部分模块使用快时钟
	delay_10nop();
	STPFCK = 0;			 //开启快时钟
	delay_10nop();
	SELFCK = 1;			 //切换到快时钟
	delay_10nop(); 	 
}

/* 快时钟系统主频为外接快钟FXT    默认二分频
 */
void bsp_FXT_clock_init()	     
{
	SELFCK = 0;	         //切换到慢时钟

	CLKCON = 0x02;       //时钟二分频
//	CLKCON = 0x03;       //时钟一分频

	FCKTYPE = 1;         //FXT
	delay_10nop();
	STPPCK = 0;			 //开启快时钟
	delay_10nop();
	STPFCK = 0;			 //开启部分模块使用快时钟
	delay_10nop();
	SELFCK = 1;			 //切换到快时钟
	delay_10nop(); 	 
}


/* 时钟系统主频为外接慢钟SXT   默认二分频
 */
void bsp_SXT_clock_init()	     
{
	SELFCK = 0;	         //切换到慢时钟
	
	CLKCON = 0x02;       //时钟二分频 
//	CLKCON = 0x03;       //时钟一分频

	delay_10nop();
	STPPCK = 0;			 //开启快时钟
	delay_10nop();
	STPFCK = 0;			 //开启部分模块使用快时钟
	delay_10nop();
	SELFCK = 1;			 //切换到快时钟
	delay_10nop(); 	 
    SCKTYPE = 1;         //SXT
	delay_10nop();
	SELFCK = 0;	         //切换到慢时钟
}



void bsp_delay_100us(unsigned int cnt)   //该函数不是精确延时，根据内部时钟二分频计算得来的
{
	unsigned int i;
	unsigned char delay_cnt;
	for(i = 0;i<cnt;i++)
	{
		delay_cnt = 23;
		while(delay_cnt--)
		{
			delay_10nop();
		}
	}

}


void bsp_delay_ms(unsigned int ms)      //该函数不是精确延时，根据内部时钟二分频计算得来的
{
	unsigned int i;
	unsigned char delay_cnt;
		for(i = 0;i<ms;i++)
	{
		delay_cnt =95;
		while(delay_cnt--)
		{
			delay_10nop();
			delay_10nop();
			delay_10nop();
			delay_10nop();
		}
	}
}













