#ifndef _BASE_H
#define _BASE_H

#include "esp_err.h"
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include "esp_event.h"
#include <esp_log.h>
#include <inttypes.h>



typedef void (*callback_RFID_t)(uint64_t rfid);



/**
 * @brief Callback de recepción de datos con parámetros.
 * 
 */
typedef void (*callback_data_t)(char* data, char* topic);


/**
 * @brief Callback sin parámetros.
 * 
 */
typedef void (*esp_callback_t)(void);


#define CHECK_RUN_F(f)            if(f)f()     // si f es distinta de NULL, llamar

// printf solo compila cuando se define EN_DEBUG_MESSAGE
#define EN_DEBUG_MESSAGE             

#ifdef EN_DEBUG_MESSAGE
    #define DEBUG_FORMAT                        "[DEBUG] %s"
    #define DEBUG_PRINT(message)                printf(DEBUG_FORMAT,message)
#else
    #define DEBUG_PRINT(message) 
#endif




#endif