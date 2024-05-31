#include <esp_log.h>
#include <inttypes.h>
#include "rc522.h"

static const char* TAG = "rc522-demo";


static rc522_handle_t scanner;


rc522_config_t config = {
    .spi.host = VSPI_HOST,
    .spi.miso_gpio = 21,
    .spi.mosi_gpio = 23, 
    .spi.sck_gpio = 19,
    .spi.sda_gpio = 22,
    .spi.device_flags= SPI_DEVICE_HALFDUPLEX
};




// Cuando detecto una tarjeta genero un evento que se procesa aqui
// Es algo parecido a una interrupción por software (basado en eventos de FreeRTOS)
static void rc522_handler(void* arg, esp_event_base_t base, int32_t event_id, void* event_data)
{
    rc522_event_data_t* data = (rc522_event_data_t*) event_data;

    switch(event_id) {
        case RC522_EVENT_TAG_SCANNED: {
                rc522_tag_t* tag = (rc522_tag_t*) data->ptr;
                ESP_LOGI(TAG, "Tag scanned (sn: %" PRIu64 ")", tag->serial_number);
            }
            break;
    }
}


static void RFID_reader_init(){
 rc522_create(&config, &scanner);
 rc522_register_events(scanner, RC522_EVENT_ANY, rc522_handler, NULL);
 rc522_start(scanner);
}



int app_main()
{
    RFID_reader_init();

    while(1){
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }

   
    return 0;
}