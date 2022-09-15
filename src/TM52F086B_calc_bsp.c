#include <REGtenxTM52F1376.h>
#include <intrins.h>
#include "TM52F1376_calc_bsp.h"


/* �м�ֵ�����ȫ�ֱ��������ö���ֲ�������ʡʱ�� 
 * ʹ��ʱ���ú����ǲ������غ�������Ҫ�ر�ע�ⲻ�����жϺ���������ͬʱʹ��
 * ����ʹ�øú���ǰ�ر��ж� 
 */
calc_mid_t clac_mid;
unsigned char mid_1,mid_2;

/* 16bit�޷�����  ���� 16bit �޷�����
 * ���ؽ��Ϊ32bit �޷�����
 */
 /******************************************************************************************
** ��������: mul_32
** ��������: �˷�ģʽ   
** �������: ��
** �������: �� 
*******************************************************************************************/
unsigned long mul_32(unsigned int a,unsigned int b)
{
	clac_mid.us16[0] = a;			   
	mid_1 = clac_mid.us8[1];	  
	EXA = clac_mid.us8[0];
	clac_mid.us16[0] = b;			   
	mid_2 = clac_mid.us8[1];	  
	EXB = clac_mid.us8[0];
	AUX2 = (AUX2&0xf6)|0x1;

	clac_mid.tt.us12 = mid_1*mid_2;
	clac_mid.tt.us3 = EXA;
	clac_mid.tt.us0 = EXB;
	AUX2 = (AUX2&0xf6);
	return clac_mid.us32;
}
 /******************************************************************************************
** ��������: div_32
** ��������: ����ģʽ   
** �������: ��
** �������: �� 
*******************************************************************************************/
unsigned long div_32(unsigned long a,unsigned int b)
{
//	calc_mid_t clac_mid;
//	unsigned char mid_1,mid_2;

	clac_mid.us32 = a;		   
 	mid_1 = clac_mid.us8[3];		   
	EXA = clac_mid.us8[2];		   		   
	EXA2 = clac_mid.us8[1];		   	   
	EXA3 = clac_mid.us8[0];		   	
	clac_mid.us16[0] = b;	   			   
	mid_2 = clac_mid.us8[1];		   	  
	EXB = clac_mid.us8[0];		   
	AUX2 = (AUX2&0xf6)|0x9;	
		   			   
	clac_mid.us8[0] = mid_1/mid_2;
  
	clac_mid.us8[1] = EXA;		   
	clac_mid.us8[2] = EXA2;		   
	clac_mid.us8[3] = EXA3;		   		   
	AUX2 = (AUX2&0xf6);	
	return clac_mid.us32;		   
}
/******************************************************************************************
** ��������: mod_32
** ��������: modģʽ   
** �������: ��
** �������: �� 
*******************************************************************************************/
unsigned int mod_32(unsigned long a,unsigned int b)
{
	clac_mid.us32 = a;		   
 	mid_1 = clac_mid.us8[3];		   
	EXA = clac_mid.us8[2];		   		   
	EXA2 = clac_mid.us8[1];		   	   
	EXA3 = clac_mid.us8[0];		   	
	clac_mid.us16[0] = b;	   			   
	mid_2 = clac_mid.us8[1];		   	  
	EXB = clac_mid.us8[0];		   
	AUX2 = (AUX2&0xf6)|0x9;	
		   			   
	clac_mid.us8[0] = mid_1%mid_2;  
	clac_mid.us8[1] = EXB;		   
//	clac_mid.us8[2] = EXA2;		   
//	clac_mid.us8[3] = EXA3;		   		   
	AUX2 = (AUX2&0xf6);	
	return clac_mid.us16[0];		   
}














