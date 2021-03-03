#include <iostream>
#include <string>
#include "tiny_serial.h"

using namespace std;


int main(void){
    uint8_t message[] = "Hello From PC";
    tiny_serial_config arduino_config;
    arduino_config.port = string("COM11").c_str();
    arduino_config.baudrate = 115200;
    arduino_config.data_bits = Data_bits::EIGHT;
    arduino_config.stop_bits = Stop_bits::ONE;
    arduino_config.parity = Parity::NONE;

    tiny_serial serial(&arduino_config);
    if(serial.open() == TinySerialStatus::Error){
        cout << "There's Something Error\n";
    }
    if(serial.write(message, sizeof(message)) == TinySerialStatus::Error){
        cout << "Couldn't send the messag, sorry";
    }
    return 0;
};