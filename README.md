**Library created from Non-Volatile Storage of ESP-IDF Webpage**

### How to use it:

**Declare:** in *app_main*() function

- char \*store: place to set/get value 32 bit.
- uint32_t dataIn: write data to store.
- uint32_t dataOut: read data from store.

**Write data to store:** *writeData*(store, dataIn)

**Read data from store**: *readData*(store, &dataOut)

*Note:* One store just used for only one data to get it.
