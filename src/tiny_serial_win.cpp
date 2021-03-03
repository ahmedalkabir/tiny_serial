#if defined(_WIN32)

#include <cstdio>
#include "tiny_serial.h"
// #include "windows.h"

tiny_serial::tiny_serial(tiny_serial_config *config)
{
    _config = config;
}

TinySerialStatus tiny_serial::open()
{
    
    char _port[30];
    sprintf(_port, "\\\\.\\%s", _config->port);

    handler = CreateFileA(_port,
                          GENERIC_READ | GENERIC_WRITE,
                          0,
                          NULL,
                          OPEN_EXISTING,
                          0,
                          NULL);
    if(handler == INVALID_HANDLE_VALUE){
        return TinySerialStatus::Error;
    } else {
        return TinySerialStatus::OK;
    }
}

TinySerialStatus tiny_serial::write(uint8_t *buffer, uint32_t lenght, uint32_t timeout)
{
    return TinySerialStatus::Error;
}

uint32_t tiny_serial::read(uint32_t timeout)
{
    return 0;
}

#endif