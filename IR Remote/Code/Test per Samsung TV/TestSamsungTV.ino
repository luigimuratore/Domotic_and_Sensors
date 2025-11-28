int irPin = 3;

void burst(int us) {
  unsigned long endMicros = micros() + us;
  while (micros() < endMicros) {
    digitalWrite(irPin, HIGH);
    delayMicroseconds(13);   // ~38 kHz
    digitalWrite(irPin, LOW);
    delayMicroseconds(13);
  }
}

void sendSamsung(unsigned long data) {
  // header
  burst(5000);
  delayMicroseconds(4500);

  // 32 bit
  for (int i = 0; i < 32; i++) {
    burst(560);  // burst per il bit
    if (data & (1UL << (31 - i))) {
      delayMicroseconds(1690); // bit = 1
    } else {
      delayMicroseconds(560);  // bit = 0
    }
  }

  // stop bit
  burst(560);
}

void setup() {
  pinMode(irPin, OUTPUT);
}

void loop() {
  // Codice CH+ Samsung: E0E048B7
  sendSamsung(0xE0E048B7);
  delay(2000);   // ogni 2 secondi cambia canale
}