// Source: main.h 
// File Name: main.h
// Author: hg
// Date:2018年5月24日

#define MAIN_C_

#include "main.h"

/* define variables */
uint16 count;

void main()
{
	Lcm_Init();
	
	Init_TIME0();
	Init_TIME1();
	
	Init_USART();
	
	Display_Start();
	
	EA=1;//总中断
	
	//请求一次完整包
	SendHeartBeadPacket();
	while(1)
	{
		Display_Menu1_Screen();//主显示界面
		Display_Menu2_Screen();//显示设置界面
	}
}

void Timer0() interrupt 1
{
	Interrupt_Init0();
	if (count-- == 0)               //1ms * 1000 -> 1s
  {
    count = 1000;               //reset counter
		Led_Change();
  }
}
void Usart() interrupt 4
{
		if(RI)
    {
        Interrupt_Queue(SBUF);
        RI=0;       
    }
}
