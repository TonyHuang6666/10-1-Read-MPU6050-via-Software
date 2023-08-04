#include "stm32f10x.h"
#include "IIC.h"//建立在此模块上
#define SlaveAddress 0xD2 //MPU6050的从机地址

//封装指定地址的写操作
void MPU6050_WriteReg(uint8_t reg, uint8_t data)
{
    IIC_Start();
    IIC_SendByte(SlaveAddress);
    IIC_ReceiveACK();
    IIC_SendByte(reg);
    IIC_ReceiveACK();
    IIC_SendByte(data);
    IIC_ReceiveACK();
    IIC_Pause();
}

//封装指定地址的读操作
uint8_t MPU6050_ReadReg(uint8_t reg)
{
    uint8_t data;
    //设置MPU6050当前地址指针
    IIC_Start();
    IIC_SendByte(SlaveAddress);
    IIC_ReceiveACK();
    IIC_SendByte(reg);
    IIC_ReceiveACK();
    //重新寻址
    IIC_Start();
    IIC_SendByte(SlaveAddress|0x01);//读操作
    //接收数据
    data = IIC_ReceiveByte();
    IIC_SendACK(1);//只读取一个字节，所以最后一个字节需要发送NACK
    IIC_Pause();
    return data;
}

void MPU6050_Init(void)
{
    IIC_Init();
}