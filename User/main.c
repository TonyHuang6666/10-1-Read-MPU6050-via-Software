#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "IIC.h"
#include "MPU6050.h"
int main(void)
{
	OLED_Init();
	MPU6050_Init();
	OLED_ShowString(4, 16, "T");
	MPU6050_WriteReg(0x6B, 0x00);//解除休眠状态
	MPU6050_WriteReg(0x19, 0x66);
	uint8_t ID=MPU6050_ReadReg(0x19);
	OLED_ShowHexNum(1, 1, ID, 2);
	while (1)
	{
		
	}
}
