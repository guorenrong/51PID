#ifndef __TM52F1376_BSP_H__
#define __TM52F1376_BSP_H__

#include "TM52F086B_sfr_config.h"

#define delay_10nop() \
	do{												\
		_nop_();_nop_();_nop_();_nop_();_nop_();	 \
		_nop_();_nop_();_nop_();_nop_();_nop_();	\
	}while(0)

	
/* ϵͳʱ��ʹ�ÿ�ʱ�ӣ�Ƶ��Ϊ2��Ƶ 8.294M  */
void bsp_clock_init();
void bsp_FXT_clock_init();
void bsp_SXT_clock_init();
void bsp_SXT_clock_init();	     
void bsp_delay_ms(unsigned int ms);
void bsp_delay_100us(unsigned int cnt);	
	
#endif
