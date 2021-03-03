#ifndef TINY_SERIAL
#define TINY_SERIAL

#include <cstdint>

#if defined(_WIN32)
#include <Windows.h>
#endif

enum class Parity {
    EVEN,
    ODD,
    NONE
};

enum class Data_bits {
    EIGHT
};

enum class Stop_bits {
    ONE,
    TWO
};

enum class TinySerialStatus {
    OK,
    Error
};

struct tiny_serial_config {
    const char *port;
    uint32_t baudrate;
    Parity parity;
    Data_bits data_bits;
    Stop_bits stop_bits;
};

class tiny_serial
{
private:
    tiny_serial_config *_config;
    #if defined(_WIN32)
    HANDLE handler;
    #endif
public:
    tiny_serial(tiny_serial_config *);
    ~tiny_serial(){
        CloseHandle(handler);
    };
    
    TinySerialStatus open();
    TinySerialStatus write(uint8_t *, uint32_t, uint32_t timeout = 2);
    uint32_t read(uint32_t timeout = 2);
};


#endif