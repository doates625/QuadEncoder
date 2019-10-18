# QuadEncoder
Quadrature encoder interface for Arduino and Mbed platforms  
Written by Dan Oates (WPI Class of 2020)

### Description
This class provides the methods interrupt_A and interrupt_B for each encoder, which must be called on both rising and falling edges for channels A and B (respectively). Because interrupt implementation is very device-specific, it is the responsibility of the user to configure ISRs and call these methods.

### Dependencies
- [CppUtil](https://github.com/doates625/CppUtil.git)
- [Platform](https://github.com/doates625/Platform.git)
- [DigitalIn](https://github.com/doates625/DigitalIn.git)