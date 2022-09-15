#include <intrins.h>

#include "REGtenxTM52F1376.h"

#include "TM52F1376_bsp_lcd.h"


unsigned char code BIT_MAP[8] = {0x01,0x02,0x04,0x08,0x01,0x02,0x04,0x08};

unsigned char com_seg_buf[SEG_MAX];

/* LCD seg 0-3周期刷新驱动*/
void lcd_set_seg1(unsigned char com_idx)
{
	unsigned char bit_seat = BIT_MAP[com_idx];
	
	if(com_seg_buf[0]&bit_seat)   //seg0口电平判断
		SEG0 = 1;
	else
		SEG0 = 0;

	if(com_seg_buf[1]&bit_seat)   //seg1口电平判断
		SEG1 = 1;
	else
		SEG1 = 0;
	
	if(com_seg_buf[2]&bit_seat)     //seg2口电平判断
		SEG2 = 1;
	else
		SEG2 = 0;

	if(com_seg_buf[3]&bit_seat)
		SEG3 = 1;
	else
		SEG3 = 0;

	if(com_seg_buf[4]&bit_seat)
		SEG4 = 1;
	else
		SEG4 = 0;

	if(com_seg_buf[5]&bit_seat)    //seg5口电平判断
		SEG5 = 1;
	else
		SEG5 = 0;
}

/* LED seg4-7周期刷新驱动*/
void lcd_set_seg2(unsigned char com_idx)
{
	unsigned char bit_seat = BIT_MAP[com_idx];
	
	if(com_seg_buf[0]&bit_seat)       //seg0口电平判断
		SEG0 = 0;
	else
		SEG0 = 1;

	if(com_seg_buf[1]&bit_seat)
		SEG1 = 0;
	else
		SEG1 = 1;
	
	if(com_seg_buf[2]&bit_seat)
		SEG2 = 0;
	else
		SEG2 = 1;

	if(com_seg_buf[3]&bit_seat)
		SEG3 = 0;
	else
		SEG3 = 1;

	if(com_seg_buf[4]&bit_seat)
		SEG4 = 0;
	else
		SEG4 = 1;

	if(com_seg_buf[5]&bit_seat)       //seg5口电平判断
		SEG5 = 0;
	else
		SEG5 = 1;
}

/* LCD com口刷新*/
void lcd_set_com(unsigned char com)   
{
	switch(com)               //选择刷新周期0-7
	{ 
		
		case 0:
			P0_0 = 0;
			P0_1 = 1;
			P0_2 = 1;
			P0_3 = 1;   
		
			PORTIDX = 0;	
			PINMOD10 = (PINMOD10&~0x0f)|6<<0;	  	//P00
			PINMOD10 = (PINMOD10&~0xf0)|15<<4;		//P01
			PINMOD32 = (PINMOD32&~0x0f)|15<<0;		//P02
			PINMOD32 = (PINMOD32&~0xf0)|15<<4;		//P03           
			break;
		
		case 1:
			P0_0 = 1;
			P0_1 = 0;
			P0_2 = 1;
			P0_3 = 1;

			PORTIDX = 0;	
			PINMOD10 = (PINMOD10&~0x0f)|15<<0;	   //P00
			PINMOD10 = (PINMOD10&~0xf0)|6<<4;		   //P01
			PINMOD32 = (PINMOD32&~0x0f)|15<<0;		 //P02
			PINMOD32 = (PINMOD32&~0xf0)|15<<4;		 //P03
			break;
		
		case 2:
	  	P0_0 = 1;
			P0_1 = 1;
			P0_2 = 0;
			P0_3 = 1;
		
			PORTIDX = 0;	
			PINMOD10 = (PINMOD10&~0x0f)|15<<0;	  	//P00
			PINMOD10 = (PINMOD10&~0xf0)|15<<4;	    //P01
			PINMOD32 = (PINMOD32&~0x0f)|6<<0;		    //P02
			PINMOD32 = (PINMOD32&~0xf0)|15<<4;		  //P03
			break; 
		
		case 3:
		  P0_0 = 1;
			P0_1 = 1;
			P0_2 = 1;
			P0_3 = 0;
		
			PORTIDX = 0;	
			PINMOD10 = (PINMOD10&~0x0f)|15<<0;	  	//P00
			PINMOD10 = (PINMOD10&~0xf0)|15<<4;		  //P01
			PINMOD32 = (PINMOD32&~0x0f)|15<<0;		  //P02
			PINMOD32 = (PINMOD32&~0xf0)|6<<4;		    //P03
			break;
	
		case 4:
		  P0_0 = 1;
			P0_1 = 1;
			P0_2 = 1;
			P0_3 = 1;

			PORTIDX = 0;	
			PINMOD10 = (PINMOD10&~0x0f)|6<<0;	  	//P00
			PINMOD10 = (PINMOD10&~0xf0)|15<<4;		//P01
			PINMOD32 = (PINMOD32&~0x0f)|15<<0;		//P02
			PINMOD32 = (PINMOD32&~0xf0)|15<<4;		//P03  
			break;
		
		case 5:
	  	P0_0 = 1;
			P0_1 = 1;
			P0_2 = 1;
			P0_3 = 1;

			PORTIDX = 0;	
			PINMOD10 = (PINMOD10&~0x0f)|15<<0;	   //P00
			PINMOD10 = (PINMOD10&~0xf0)|6<<4;		   //P01
			PINMOD32 = (PINMOD32&~0x0f)|15<<0;		 //P02
			PINMOD32 = (PINMOD32&~0xf0)|15<<4;		 //P03
			break; 
		
		case 6:
  	  P0_0 = 1;
			P0_1 = 1;
			P0_2 = 1;
			P0_3 = 1;

			PORTIDX = 0;	
			PINMOD10 = (PINMOD10&~0x0f)|15<<0;	  	//P00
			PINMOD10 = (PINMOD10&~0xf0)|15<<4;		//P01
			PINMOD32 = (PINMOD32&~0x0f)|6<<0;		  //P02
			PINMOD32 = (PINMOD32&~0xf0)|15<<4;		//P03
			break;
		
		case 7:
	  	P0_0 = 1;
			P0_1 = 1;
			P0_2 = 1;
			P0_3 = 1;

			PORTIDX = 0;	
			PINMOD10 = (PINMOD10&~0x0f)|15<<0;	  	//P00
			PINMOD10 = (PINMOD10&~0xf0)|15<<4;		 //P01
			PINMOD32 = (PINMOD32&~0x0f)|15<<0;		 //P02
			PINMOD32 = (PINMOD32&~0xf0)|6<<4;		   //P03
			break;
		
		default:
		break;			
			
	}
}

/*LCD刷新函数*/
void lcd_reflush(unsigned char com_idx)
{
	lcd_set_com(com_idx);
	if(com_idx <4)
	{
		lcd_set_seg1(com_idx);
	}
	else
	{
		lcd_set_seg2(com_idx);
	}
}

void lcd_wirte_seg(unsigned char seg_idx,unsigned char content_mask,unsigned char content)
{
	unsigned char temp_contenx;

	temp_contenx = com_seg_buf[seg_idx]&(~content_mask);
	content = content&content_mask;
	com_seg_buf[seg_idx] = temp_contenx|content;	
}

/*LCD display*/
void lcd_display_special(unsigned char contenx)
{
	lcd_wirte_seg(0,0xff,contenx);
	lcd_wirte_seg(1,0xff,contenx);
	lcd_wirte_seg(2,0xff,contenx);
	lcd_wirte_seg(3,0xff,contenx);
	lcd_wirte_seg(4,0xff,contenx);
	lcd_wirte_seg(5,0xff,contenx);
}

