#ifndef __TM52F1376_BSP_LCD_H__
#define __TM52F1376_BSP_LCD_H__

#define COM_MAX	4
#define SEG_MAX 6



#define SEG5		P2_2
#define SEG4		P1_2
#define SEG3		P0_7
#define SEG2		P0_6
#define SEG1		P2_5
#define SEG0    P2_3



void lcd_reflush(unsigned char com_idx);

void lcd_wirte_seg(unsigned char seg_idx,unsigned char content_mask,unsigned char content);

void lcd_display_special(unsigned char contenx);
#endif
