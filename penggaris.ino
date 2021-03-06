#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

const int lebar=128;
const int tinggi=64;
const int reset=4;
#define trigPin 9
#define echoPin 8

Adafruit_SSD1306 oled(lebar,tinggi,&Wire,reset);


void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, OUTPUT);

  oled.begin(SSD1306_SWITCHCAPVCC,0x3C);
  oled.clearDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  Serial.println(distance);
  delay(100);

  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(WHITE);
  oled.setCursor(20,20);
  oled.println(distance);
  delay(500);
  oled.setCursor(60,20);
  oled.println("CM");
  oled.display();
}
