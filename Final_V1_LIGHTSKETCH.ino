#include <Adafruit_NeoPixel.h>

#define LED_PIN 32
#define LED_COUNT 56

Adafruit_NeoPixel strip(56, 32, NEO_GRB);  //panel 1

uint32_t lightBlue = strip.Color(60, 127, 255);
uint32_t softYellow = strip.Color(255, 164, 0);
uint32_t orange = strip.Color(255, 100, 0);
uint32_t white = strip.Color(127, 127, 127);
uint32_t blue = strip.Color(64, 32, 255);

long randNumber;
long randNumber1;
long randNumber2;
long randNumber3;

void setup() {

  randomSeed(digitalRead(0));

  strip.begin();
  strip.clear();
  strip.setBrightness(80);
  strip.show();
}

void loop() {
  strip.clear();
  // // stripPulseOrange(25);
  // strip.fill(orange);
  sparkleOverFill(25);
  strip.show();

  randNumber = random(56);
  randNumber1 = random(56);
  randNumber2 = random(56);
  randNumber3 = random(56);
}


void verseSatellite() {
}

void verse2Satellite() {
}

void preSatellite() {
}

void chorusSatellite() {
}

void bridgeSatellite() {
}

void bridge2Satellite() {
}

void stripPulseWhite(int wait) {
  for (int i = 127; i > 1; i--) {
    strip.setPixelColor(0, i, i, i);
    strip.setPixelColor(1, i, i, i);
    strip.setPixelColor(2, i, i, i);
    strip.setPixelColor(3, i, i, i);
    delay(wait);
    strip.show();
    if (i == 2) {
      for (int j = 1; j < 127; j++) {
        strip.setPixelColor(0, j, j, j);
        strip.setPixelColor(1, j, j, j);
        strip.setPixelColor(2, j, j, j);
        strip.setPixelColor(3, j, j, j);
        delay(wait);
        strip.show();
      }
    }
  }
}


void stripPulseOrange(int wait) {
  for (int i = 100; i > 0; i--) {
    strip.setPixelColor(0, (i * 2.55), i, 0);
    strip.setPixelColor(1, (i * 2.55), i, 0);
    strip.setPixelColor(2, (i * 2.55), i, 0);
    strip.setPixelColor(3, (i * 2.55), i, 0);
    delay(wait);
    strip.show();
    if (i == 1) {
      for (int j = 1; j < 100; j++) {
        strip.setPixelColor(0, (j * 2.55), j, 0);
        strip.setPixelColor(1, (j * 2.55), j, 0);
        strip.setPixelColor(2, (j * 2.55), j, 0);
        strip.setPixelColor(3, (j * 2.55), j, 0);
        delay(wait);
        strip.show();
      }
    }
  }
}

void stripPulseLightBlue(int wait) {
  for (int i = 100; i > 0; i--) {
    strip.setPixelColor(0, (i * 0.6), (i * 1.27), (i * 2.55));
    strip.setPixelColor(1, (i * 0.6), (i * 1.27), (i * 2.55));
    strip.setPixelColor(2, (i * 0.6), (i * 1.27), (i * 2.55));
    strip.setPixelColor(3, (i * 0.6), (i * 1.27), (i * 2.55));
    delay(wait);
    strip.show();
    if (i == 1) {
      for (int j = 1; j < 100; j++) {
        strip.setPixelColor(0, (j * 0.6), (j * 1.27), (j * 2.55));
        strip.setPixelColor(1, (j * 0.6), (j * 1.27), (j * 2.55));
        strip.setPixelColor(2, (j * 0.6), (j * 1.27), (j * 2.55));
        strip.setPixelColor(3, (j * 0.6), (j * 1.27), (j * 2.55));
        delay(wait);
        strip.show();
      }
    }
  }
}

void sparkleOverFill(int wait) {
  for (int i = 100; i > 0; i--) {
    strip.setPixelColor(randNumber, (i * 0.6), (i * 1.27), (i * 2.55));
    strip.setPixelColor(randNumber1, (i * 0.6), (i * 1.27), (i * 2.55));
    strip.setPixelColor(randNumber2, (i * 0.6), (i * 1.27), (i * 2.55));
    strip.setPixelColor(randNumber3, (i * 0.6), (i * 1.27), (i * 2.55));
    delay(wait);
    strip.show();
  }
}