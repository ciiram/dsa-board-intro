#include "select_program.h"

#if PROGRAM == TEST_TEMP

#include "mbed.h"
#include "HTS221Sensor.h"

static DevI2C devI2c(PB_9, PB_8);

static HTS221Sensor temp_hum(&devI2c);  // temperature and humidity sensor



int main() {
    printf("\r\nHTS221 Test program");
    printf("\r\n******************\r\n");

    float current_temp;
    float current_humidity;

    temp_hum.init(NULL);  // initialize with default parameters
    temp_hum.enable();  // enable the sensors

    while (1) {
      temp_hum.get_temperature(&current_temp);
      temp_hum.get_humidity(&current_humidity);
      printf("Temperature is %4.2f C \r\n", current_temp);
      printf("Humidity is %4.2f \r\n", current_humidity);
      wait(5);
    }
}


#endif
