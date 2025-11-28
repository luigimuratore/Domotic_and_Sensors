#include <IRremote.hpp>

#define IR_PIN 2   // Pin connected to OUT of receiver

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("IR Decoder Ready...");
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.println();
    Serial.println("========== IR SIGNAL ==========");

    Serial.print("Protocol: ");
    Serial.println(IrReceiver.decodedIRData.protocol);

    Serial.print("Address: 0x");
    Serial.println(IrReceiver.decodedIRData.address, HEX);

    Serial.print("Command: 0x");
    Serial.println(IrReceiver.decodedIRData.command, HEX);

    Serial.print("Raw Data: 0x");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    Serial.println("================================");
    Serial.println();

    IrReceiver.resume();  // Ready for next code
  }
}