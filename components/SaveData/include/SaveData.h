#ifndef SAVEDATA_H_
#define SAVEDATA_H_

#include <stdint.h>
#include "nvs_flash.h"
#include "nvs.h"

esp_err_t writeData(char *str, uint32_t data);
esp_err_t readData(char *str, uint32_t *data);

#endif
