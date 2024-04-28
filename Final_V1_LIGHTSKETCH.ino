#include <Adafruit_NeoPixel.h>

#define LED_PIN 32
#define LED_COUNT 64

Adafruit_NeoPixel strip(64, 32, NEO_GRB);  //panels 1 & 2

uint32_t lightBlue = strip.Color(60, 127, 255);
uint32_t softYellow = strip.Color(255, 164, 0);
uint32_t orange = strip.Color(255, 100, 0);
uint32_t white = strip.Color(127, 127, 127);
uint32_t blue = strip.Color(64, 32, 255);

// int[30][3] = {
//   [255, 0, 0],
//   [255, 255, 0],
// }

long randNumber;
long randNumber1;
long randNumber2;
long randNumber3;

unsigned long lastStepTime = 0;
int stepLength = 1000;
int currentStep = 0;
int totalSteps = 6;


unsigned long lastFadeTime = 0;
int fadeRate = 0;  //in milliseconds
int currentFadeStep = 0;
int totalFadeSteps = 100;

int f = 100;
int i = 0;

int orange = 0;
int lightBlue = 0;

float RED = 0;
float BLUE = 0;
float GREEN = 0;


void setup() {

  randomSeed(digitalRead(0));

  strip.begin();
  strip.clear();
  strip.setBrightness(100);  //eventually this will be variable with slider/expression pedal
  strip.show();
}

void loop() {
  strip.clear();

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


void colorRecall(int color) {
  if (color == orange) {
    RED = 2.55;
    GREEN = 1.00;
    BLUE = 0;
  }
}

void fadeMillis(int color, int fadeRate) {
  colorRecall(color);
  if (millis() > lastFadeTime + fadeRate) {
    lastFadeTime = millis();
    for (int i = 0; i < 65; i++) {
      strip.setPixelColor(i, (RED * f), (GREEN * f), (BLUE * f));
      Serial.println(RED);
    }
    f = f - 1;
    strip.show();
    Serial.println(f);
    nextFade();
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


void nextFade() {
  currentFadeStep = currentFadeStep + 1;
  if (currentFadeStep >= totalFadeSteps) {
    currentFadeStep = 0;
    f = 100;
  }
}


void nextStep() {
  currentStep = currentStep + 1;
  if (currentStep >= totalSteps) {
    currentStep = 0;
  }
}
