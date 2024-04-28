#include <Adafruit_NeoPixel.h>

#define LED_PIN 32
#define LED_COUNT 64

Adafruit_NeoPixel strip(64, 32, NEO_GRB);  //panels 1 & 2

// uint32_t lightBlue = strip.Color(60, 127, 255);
// uint32_t softYellow = strip.Color(255, 164, 0);
// uint32_t orange = strip.Color(255, 100, 0);
// uint32_t white = strip.Color(127, 127, 127);
// uint32_t blue = strip.Color(64, 32, 255);

// int[30][3] = {
//   [255, 0, 0],
//   [255, 255, 0],
// }

unsigned long lastStepTime = 0;
int stepLength = 1000;
int currentStep = 0;
int totalSteps = 6;

unsigned long lastFadeTime = 0;
int fadeRate = 0;  //in milliseconds
int currentFadeStep = 0;
int totalFadeSteps = 100;

unsigned long lastSparkleTime = 0;
int currentSparkleStep = 0;
int totalSparkleStep = 100;

int f = 100; //fade variable
int sf = 100; //sparkle fade variable
// int i = 0;

int orange = 0;
int lightBlue = 0;

float RED = 0;
float BLUE = 0;
float GREEN = 0;

long randNumber;
long randNumber1;
long randNumber2;
long randNumber3;
long randNumber4;
long randNumber5;
long randNumber6;
long randNumber7;
long randNumber8;
long randNumber9;
long randNumber10;
long randNumber11;
long randNumber12;
long randNumber13;
long randNumber14;
long randNumber15;
long randNumber16;

int randNumberArray[17][1] = {
  { randNumber = random(64) },
  { randNumber1 = random(64) },
  { randNumber2 = random(64) },
  { randNumber3 = random(64) },
  { randNumber4 = random(64) },
  { randNumber5 = random(64) },
  { randNumber6 = random(64) },
  { randNumber7 = random(64) },
  { randNumber8 = random(64) },
  { randNumber9 = random(64) },
  { randNumber10 = random(64) },
  { randNumber11 = random(64) },
  { randNumber12 = random(64) },
  { randNumber13 = random(64) },
  { randNumber14 = random(64) },
  { randNumber15 = random(64) },
  { randNumber16 = random(64) },
};

void setup() {

  randomSeed(digitalRead(0));

  strip.begin();
  strip.clear();
  strip.setBrightness(100);  //eventually this will be variable with slider/expression pedal
  strip.show();
}

void loop() {
  verseSatellite();
  // strip.show();
}


void verseSatellite() {
  fadeMillis(orange, 25);
  sparkleOverFill(lightBlue, 10);
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
  }else if(color == lightBlue){
    RED = 0.6;
    GREEN = 1.27;
    BLUE = 2.55;
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

void sparkleOverFill(int color, int fadeRate) {
  colorRecall(color);
  if (millis() > lastSparkleTime + fadeRate) {
    lastSparkleTime = millis();
    for (int i = 0; i < 17; i++) {
      strip.setPixelColor(randNumberArray[i][1], (RED * sf), (GREEN * sf), (BLUE * sf));
    }
    sf = sf - 1;
    strip.show();
    nextSparkle();
  }
}


void nextFade() {
  currentFadeStep = currentFadeStep + 1;
  if (currentFadeStep >= totalFadeSteps) {
    currentFadeStep = 0;
    f = 100;
  }
}

// void nextStep() {
//   currentStep = currentStep + 1;
//   if (currentStep >= totalSteps) {
//     currentStep = 0;
//   }
// }

void nextSparkle(){
  currentSparkleStep = currentSparkleStep + 1;
  if(currentSparkleStep >= totalSparkleStep){
    sf = 100;
    currentSparkleStep = 0;
  }
}
