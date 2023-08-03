#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "IIC.h"

int main(void)
{
	OLED_Init();
	IIC_Init();
	OLED_ShowString(1, 1, "HelloWorld!");
	IIC_Start();
	IIC_SendByte(0xA0);//1101000 0
	uint8_t ack = IIC_ReceiveACK();
	IIC_Stop();
	OLED_ShowNum(2, 1, ack, 3);
	while (1)
	{
		
	}
}
