#ifndef MPU6050_H_
#define MPU6050_H_
uint8_t MPU6050_ReadReg(uint8_t reg);
void MPU6050_WriteReg(uint8_t reg, uint8_t data);
void MPU6050_Init(void);
#endif