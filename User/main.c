#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "IIC.h"

int main(void)
{
	OLED_Init();
	IIC_Init();
	OLED_ShowString(1, 1, "HelloWorld!");
	/*
	以下三行相当于一个点名的时序，可以结合for循环遍历所有从机地址，
	即前7位，把应答位为0的地址打印出来，实现扫描总线上设备的功能
	*/
	IIC_Start();
	IIC_SendByte(0xD2);//1101001 0
	uint8_t ack = IIC_ReceiveACK();

	IIC_Stop();
	OLED_ShowNum(2, 1, ack, 3);
	while (1)
	{
		
	}
}
