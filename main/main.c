#include <esp_log.h>
#include <inttypes.h>
#include "rc522.h"




rc522_config_t config = {
    .spi.host = VSPI_HOST,
    .spi.miso_gpio = 21,
    .spi.mosi_gpio = 23, 
    .spi.sck_gpio = 19,
    .spi.sda_gpio = 22,
    .spi.device_flags= SPI_DEVICE_HALFDUPLEX
};



void get_rfid(uint64_t rfid){
    printf("El id es:%llu\n",rfid);
}








int app_main()
{
     rc522_init(&config,get_rfid);

    while(1){
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }

   
    return 0;
}