#include <REGtenxTM52F086B.h>
#include <intrins.h>
#include "TM52F086B_bsp.h"







/* ��ʱ��ϵͳ��ƵΪ 18.432/2M   Ĭ�϶���Ƶ
 */
void bsp_clock_init()	     
{
	SELFCK = 0;	         //�л�����ʱ��
		
	CLKCON = 0x02;       //ʱ�Ӷ���Ƶ
//	CLKCON = 0x03;       //ʱ��һ��Ƶ
	
	delay_10nop();
	STPPCK = 0;			 //��������ģ��ʹ�ÿ�ʱ��
	delay_10nop();
	STPFCK = 0;			 //������ʱ��
	delay_10nop();
	SELFCK = 1;			 //�л�����ʱ��
	delay_10nop(); 	 
}

/* ��ʱ��ϵͳ��ƵΪ��ӿ���FXT    Ĭ�϶���Ƶ
 */
void bsp_FXT_clock_init()	     
{
	SELFCK = 0;	         //�л�����ʱ��

	CLKCON = 0x02;       //ʱ�Ӷ���Ƶ
//	CLKCON = 0x03;       //ʱ��һ��Ƶ

	FCKTYPE = 1;         //FXT
	delay_10nop();
	STPPCK = 0;			 //������ʱ��
	delay_10nop();
	STPFCK = 0;			 //��������ģ��ʹ�ÿ�ʱ��
	delay_10nop();
	SELFCK = 1;			 //�л�����ʱ��
	delay_10nop(); 	 
}


/* ʱ��ϵͳ��ƵΪ�������SXT   Ĭ�϶���Ƶ
 */
void bsp_SXT_clock_init()	     
{
	SELFCK = 0;	         //�л�����ʱ��
	
	CLKCON = 0x02;       //ʱ�Ӷ���Ƶ 
//	CLKCON = 0x03;       //ʱ��һ��Ƶ

	delay_10nop();
	STPPCK = 0;			 //������ʱ��
	delay_10nop();
	STPFCK = 0;			 //��������ģ��ʹ�ÿ�ʱ��
	delay_10nop();
	SELFCK = 1;			 //�л�����ʱ��
	delay_10nop(); 	 
    SCKTYPE = 1;         //SXT
	delay_10nop();
	SELFCK = 0;	         //�л�����ʱ��
}



void bsp_delay_100us(unsigned int cnt)   //�ú������Ǿ�ȷ��ʱ�������ڲ�ʱ�Ӷ���Ƶ���������
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


void bsp_delay_ms(unsigned int ms)      //�ú������Ǿ�ȷ��ʱ�������ڲ�ʱ�Ӷ���Ƶ���������
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













