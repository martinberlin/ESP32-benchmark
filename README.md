# ESP32-benchmark
Collection on benchmarks found on the web. FreeRTOS mainly, can have Arduino framework for ESP32 parts

## Mission

Is to adapt Benchmarks found in the Web, perform tests in different ESP32's but also on the new ESP32S2

Note that ESP32S2 should be compiled for now [only with the ESP-IDF](https://esp32.com/viewtopic.php?p=49147#p49147) Toolchain

### Current results 

On a Lolin 32 board are this:

    Speed test
    ----------

    digitalRead               : 0.145 us
    digitalWrite              : 0.110 us
    pinMode                   : 2.767 us
    multiply byte             : 0.000 us
    divide byte               : 0.000 us
    add byte                  : 0.000 us
    multiply integer          : 0.055 us
    divide integer            : 0.060 us
    add integer               : 0.055 us
    multiply long             : 0.000 us
    divide long               : 0.000 us
    add long                  : 0.000 us
    multiply float            : 0.000 us
    divide float              : 0.000 us
    add float                 : 0.000 us
    itoa()                    : 0.705 us
    ltoa()                    : 0.800 us
    dtostrf()                 : 11.450 us
    random()                  : 0.725 us
    y |= (1<<x)               : 0.046 us
    bitSet()                  : 0.046 us
    analogRead()              : 5.950 us
    digitalWrite() PWM         : 0.110 us
    delay(1)                  : 1000.000 us
    delay(100)                : 100000.000 us
    delayMicroseconds(2)      : 2.716 us
    delayMicroseconds(5)      : 5.918 us
    delayMicroseconds(100)    : 100.450 us
    -----------

### Compile this 

Using Platformio or Arduino in your ESP32

ESP-IDF FreeRTOS version comming soon
