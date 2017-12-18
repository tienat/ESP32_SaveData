#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "include/SaveData.h"
#include "esp_system.h"

#define STORAGE_NAMESPACE "storage"

esp_err_t writeData(char *str, uint32_t data)
{
  char *temp = str;
  nvs_handle my_handle;
  esp_err_t err;

  // Open
  err = nvs_open(STORAGE_NAMESPACE, NVS_READWRITE, &my_handle);
  if (err != ESP_OK) return err;

  // Write
  err = nvs_set_i32(my_handle, temp, data);
  if (err != ESP_OK) return err;

  err = nvs_commit(my_handle);
  if (err != ESP_OK) return err;

  // Close
  nvs_close(my_handle);
  return ESP_OK;
}

esp_err_t readData(char *str, uint32_t *data)
{
  char *temp = str;
  nvs_handle my_handle;
  esp_err_t err;

  // Open
  err = nvs_open(STORAGE_NAMESPACE, NVS_READWRITE, &my_handle);
  if (err != ESP_OK) return err;

  // Read restart counter
  int32_t dataRead = 0;
  err = nvs_get_i32(my_handle, temp, &dataRead);
  if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND) return err;
  *data = dataRead;

  // Close
  nvs_close(my_handle);
  return ESP_OK;
}
