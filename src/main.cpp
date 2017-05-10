#include <Arduino.h>
#include <DallasTemperature.h>
#include <Homie.h>
#include <OneWire.h>

const auto ONE_WIRE_BUS = D4;
const auto TEMPERATURE_INTERVAL = 300ul;
auto lastTemperatureSent = 0ul;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

HomieNode temperatureNode("temperature", "temperature");

void setupHandler() {
  Homie.setNodeProperty(temperatureNode, "unit", "C", true);
  sensors.begin();
}

void loopHandler() {
  if (millis() - lastTemperatureSent >= TEMPERATURE_INTERVAL * 1000UL || lastTemperatureSent == 0) {
    sensors.requestTemperatures();
    float temperature = sensors.getTempCByIndex(0);
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
    if (Homie.setNodeProperty(temperatureNode, "degrees", String(temperature), true)) {
      lastTemperatureSent = millis();
    } else {
      Serial.println("Temperature sending failed");
    }
  }
}

void setup() {
  Homie.setFirmware("homie-temperature", "1.0.0");
  Homie.registerNode(temperatureNode);
  Homie.setSetupFunction(setupHandler);
  Homie.setLoopFunction(loopHandler);
  Homie.setup();
}

void loop() {
  Homie.loop();
}
