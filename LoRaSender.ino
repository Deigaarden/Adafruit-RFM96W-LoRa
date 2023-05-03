#include <SPI.h>
#include <LoRa.h>

int counter = 0;

int LED = 5;
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

  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    digitalWrite(LED, LOW);
    while (1);
  }
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;
  blinkk();
  delay(2000);
}
