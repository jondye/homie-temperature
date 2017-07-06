Homie temperature module
========================

I built this temperature sensor to monitor the temperature in our office. It
posts the temperature to an [mqtt] server and then the temperature is displayed
on a TV screen using a dashboard created with the [smashing] framework.


Hardware
--------

The module uses a [WEMOS] [D1 mini] ESP8266 development board and a [ds18b20] 
1-Wire temperature sensor connected to pin D4.

The WEMOS can be bought from 
WEMOS' official [AliExpress shop](https://wemoscc.aliexpress.com/store/1331105).
There are also clones available from AliExpress and other places such as eBay.
The ds18b20 sensor can be bought from 
[Adafruit](https://www.adafruit.com/product/381), 
[Sparkfun](https://www.sparkfun.com/products/245), eBay or a range of other
electronics retailers.


Software
--------

The software uses the [Homie] framework for ESP8266 for the basic mqtt sensor 
functionality. It is built using the [platformio] development platform.


Building
--------

The code can be built and uploaded using either the platformio 
[cli](http://platformio.org/get-started/cli) or 
[ide](http://platformio.org/get-started/ide)


[smashing]:   https://github.com/Smashing/smashing
[mqtt]:       https://mosquitto.org/
[WEMOS]:      https://www.wemos.cc/
[D1 mini]:    https://wiki.wemos.cc/products:d1:d1_mini
[ds18b20]:    https://www.maximintegrated.com/en/products/analog/sensors-and-sensor-interface/DS18B20.html
[Homie]:      https://github.com/marvinroger/homie-esp8266
[platformio]: http://platformio.org/
