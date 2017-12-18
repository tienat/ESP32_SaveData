#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "../components/SaveData/include/SaveData.h"

void app_main()
{
  char *store = "store";
  uint32_t dataIn = 0x00FFA25F;
  uint32_t dataOut;

  esp_err_t err = nvs_flash_init();
  if (err == ESP_ERR_NVS_NO_FREE_PAGES)
  {
    ESP_ERROR_CHECK(nvs_flash_erase());
    err = nvs_flash_init();
  }
  ESP_ERROR_CHECK( err );

  err = writeData(store, dataIn);
  if (err != ESP_OK) printf("Error (%d) saving restart counter to NVS!\n", err);

  err = readData(store, &dataOut);
  if (err != ESP_OK) printf("Error (%d) reading data from NVS!\n", err);

  printf("%d\n", dataOut);
}
