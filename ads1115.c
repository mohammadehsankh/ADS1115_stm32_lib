#include "ads1115.h"

void ADS1115_calib(I2C_HandleTypeDef *hi2c,uint8_t dev_add,uint8_t os,uint8_t input_pin ,uint8_t gain, uint8_t mode , uint8_t data_rate, uint8_t comprator_mode,uint8_t comprator_polarity,uint8_t latching_compratoe, uint8_t comprator_q_d)

{

uint8_t end_point[2]={0};

end_point[0]|=os<<7;
end_point[0]|=input_pin<<4;
end_point[0]|=gain<<1;
end_point[0]|=mode<<0;
end_point[1]|=data_rate<<5;
end_point[1]|=comprator_mode<<4;
end_point[1]|=comprator_polarity<<3;
end_point[1]|=latching_compratoe<<2;
end_point[1]|=comprator_q_d<<0;

HAL_I2C_Mem_Write(hi2c,dev_add,Config_register,1,end_point,2,100);


}


uint16_t ADS_read_data(I2C_HandleTypeDef *hi2c,uint8_t dev_add)
{
uint8_t data[2]={0};
HAL_I2C_Mem_Read(hi2c,dev_add,Conversion_register,1,data,2,100);	
return data[0]<<8|data[1];
}


