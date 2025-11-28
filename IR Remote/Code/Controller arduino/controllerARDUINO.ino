#define IR_SEND_PIN 3        // Pin connected to IR LED driver (transistor base via 1k)
#include <IRremote.hpp>

void setup() {
  Serial.begin(115200);
  Serial.println(F("IR Sender ready"));

  // IMPORTANT: use the 1-argument version, works with current IRremote
  IrSender.begin(IR_SEND_PIN);  
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();

    switch (c) {
      case 'p': // POWER
        IrSender.sendNEC(0x2, 0x1D, 1);
        Serial.println("Sent: POWER");
        break;

      case 'o': // OK
        IrSender.sendNEC(0x2, 0x0B, 1);
        Serial.println("Sent: OK");
        break;

      case 'w': // UP
        IrSender.sendNEC(0x2, 0x09, 1);
        Serial.println("Sent: UP");
        break;

      case 's': // DOWN
        IrSender.sendNEC(0x2, 0x01, 1);
        Serial.println("Sent: DOWN");
        break;

      case 'd': // RIGHT
        IrSender.sendNEC(0x2, 0x08, 1);
        Serial.println("Sent: RIGHT");
        break;

      case 'a': // LEFT
        IrSender.sendNEC(0x2, 0x0A, 1);
        Serial.println("Sent: LEFT");
        break;

      case '+': // VOL UP
        IrSender.sendNEC(0x2, 0x11, 1);
        Serial.println("Sent: VOL+");
        break;

      case '-': // VOL DOWN
        IrSender.sendNEC(0x2, 0x15, 1);
        Serial.println("Sent: VOL-");
        break;

      case 'm': // MENU
        IrSender.sendNEC(0x2, 0x1F, 1);
        Serial.println("Sent: MENU");
        break;

      case 'h': // HOME
        IrSender.sendNEC(0x2, 0x1A, 1);
        Serial.println("Sent: HOME");
        break;

      case 'r': // RETURN
        IrSender.sendNEC(0x2, 0x1B, 1);
        Serial.println("Sent: RETURN");
        break;

      case 'i': // SOURCE
        IrSender.sendNEC(0x2, 0x1E, 1);
        Serial.println("Sent: SOURCE");
        break;
    }
  }
}