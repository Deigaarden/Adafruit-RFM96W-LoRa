#include <SPI.h>
#include <LoRa.h>


int LED = 4;
int t = 200;

void blinkk() {
  digitalWrite(LED, HIGH);
  delay(t);
  digitalWrite(LED, LOW);
  delay(t);
  digitalWrite(LED, HIGH);
  delay(t);
  digitalWrite(LED, LOW);
  delay(t);
  digitalWrite(LED, HIGH);
}


void setup() {

  pinMode(LED, OUTPUT);

  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    blinkk();

    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
