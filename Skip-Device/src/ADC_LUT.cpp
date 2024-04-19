#include "ADC_LUT.h"

double getCalibratedADCVoltage(uint16_t index){
return ADC_LUT[index];
}