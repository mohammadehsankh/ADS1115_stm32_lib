/*
mohammad ehsan 

mohammadehsankhodaee@gmail.com

2022

*/

#ifndef _ADS1115_
#define _ADS1115_


#include "stm32f1xx_hal.h"


//address
//ADDR Pin Connection and Corresponding Slave Address

#define add_G 0x90 //(default)
#define add_vdd 0x92
#define add_sda 0x94
#define add_scl 0x96

//registers address

#define Conversion_register 0
#define Config_register     1
#define Lo_thresh_register  2
#define Hi_thresh register  3




//OS: Operational status/single-shot conversion start
/*
For a write status:
0 : No effect
1 : Begin a single conversion (when in power-down mode)
For a read status:
0 : Device is currently performing a conversion
1 : Device is not currently performing a conversion
*/
#define  os_read 0
#define  os_write 1


//Input multiplexer configuration
#define p_0_n_1 0    //000 : AINP = AIN0 and AINN = AIN1 
#define p_0_n_3 1    //001 : AINP = AIN0 and AINN = AIN3
#define p_1_n_3 2    //010 : AINP = AIN1 and AINN = AIN3
#define p_2_n_3 3    //011 : AINP = AIN2 and AINN = AIN3

#define p_1_n_G 4    //100 : AINP = AIN0 and AINN = GND
#define p_2_n_G 5    //101 : AINP = AIN1 and AINN = GND
#define p_3_n_G 6   //110 : AINP = AIN2 and AINN = GND
#define p_4_n_G 7   //111 : AINP = AIN3 and AINN = GND

//Programmable gain amplifier configuration (ADS1114 and ADS1115 only)
#define fs_6v144 0  // 000 : FS= ±6.144V
#define fs_4v096 1  //001 : FS = ±4.096V
#define fs_2v048 2  //010 : FS = ±2.048V
#define fs_2v024 3  //011 : FS = ±1.024V
#define fs_0v512 4  //100 : FS = ±0.512V
#define fs_0v256 5  //101 : FS = ±0.256V

//MODE: Device operating mode
#define MODE_CCM 0 //0 : Continuous conversion mode
#define MODE_PDS 1 //1 : Power-down single-shot mode

//Data rate
#define s8 0
#define s16 1
#define s32 2
#define s64 3
#define s128 4
#define s250 5
#define s475 6
#define s860 7

//Comparator mode (ADS1114 and ADS1115 only)
/* This bit controls the comparator mode of operation. It changes whether the comparator is implemented as a
traditional comparator (COMP_MODE = '0') or as a window comparator (COMP_MODE = '1'). It serves no
function on the ADS1113.*/

#define COMP_MODE_0 0 //0 : Traditional comparator with hysteresis 
#define COMP_MODE_1 1 //1 : Window comparator

//COMP_POL: Comparator polarity
/*This bit controls the polarity of the ALERT/RDY pin. When COMP_POL = '0' the comparator output is active
low. When COMP_POL='1' the ALERT/RDY pin is active high. It serves no function on the ADS1113.*/

#define COMP_POL_0 0  //0 : Active low 
#define COMP_POL_1 1  //1 : Active high

//COMP_LAT: Latching comparator (ADS1114 and ADS1115 only)
/*This bit controls whether the ALERT/RDY pin latches once asserted or clears once conversions are within the
margin of the upper and lower threshold values. When COMP_LAT = '0', the ALERT/RDY pin does not latch
when asserted. When COMP_LAT = '1', the asserted ALERT/RDY pin remains latched until conversion data
are read by the master or an appropriate SMBus alert response is sent by the master, the device responds with
its address, and it is the lowest address currently asserting the ALERT/RDY bus line. This bit serves no
function on the ADS1113.*/

#define COMP_LAT_0 0  //0 : Non-latching comparator 
#define COMP_LAT_1 1  //1 : Latching comparator

//COMP_QUE: Comparator queue and disable
/*These bits perform two functions. When set to '11', they disable the comparator function and put the
ALERT/RDY pin into a high state. When set to any other value, they control the number of successive
conversions exceeding the upper or lower thresholds required before asserting the ALERT/RDY pin. They
serve no function on the ADS1113.*/

#define COMP_QUE_0 0 //00 : Assert after one conversion
#define COMP_QUE_1 1 //01 : Assert after two conversions
#define COMP_QUE_2 2 //10 : Assert after four conversions
#define COMP_QUE_3 3 //11 : Disable comparator 




void ADS1115_calib(I2C_HandleTypeDef *hi2c,uint8_t dev_add,uint8_t os,uint8_t input_pin ,uint8_t gain, uint8_t mode , uint8_t data_rate, uint8_t comprator_mode,uint8_t comprator_polarity,uint8_t latching_compratoe, uint8_t comprator_q_d);
uint16_t ADS_read_data(I2C_HandleTypeDef *hi2c,uint8_t dev_add);

#endif // _ADS1115_

