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
int fadeRate2 = 0;
int currentFadeStep = 0;
int totalFadeSteps = 100;

unsigned long lastSparkleTime = 0;
int currentSparkleStep = 0;
int totalSparkleStep = 100;

unsigned long lastSparkleTime2 = 0;
int currentSparkleStep2 = 0;
int totalSparkleStep2 = 100;

int f = 100;   //fade variable
int sf = 100;  //sparkle fade variable
int sf1 = 100; //second sparkle fade variable
// int i = 0;

bool orange = false;
bool lightBlue = false;
bool white = false;

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

long randNumber17;
long randNumber18;
long randNumber19;
long randNumber20;
long randNumber21;
long randNumber22;
long randNumber23;
long randNumber24;
long randNumber25;
long randNumber26;
long randNumber27;
long randNumber28;
long randNumber29;
long randNumber30;
long randNumber31;
long randNumber32;


int randNumberArray[33][1] = {
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
  { randNumber17 = random(64) },
  { randNumber18 = random(64) },
  { randNumber19 = random(64) },
  { randNumber20 = random(64) },
  { randNumber21 = random(64) },
  { randNumber22 = random(64) },
  { randNumber23 = random(64) },
  { randNumber24 = random(64) },
  { randNumber25 = random(64) },
  { randNumber26 = random(64) },
  { randNumber27 = random(64) },
  { randNumber28 = random(64) },
  { randNumber29 = random(64) },
  { randNumber30 = random(64) },
  { randNumber31 = random(64) },
  { randNumber32 = random(64) },
};

void setup() {
  Serial.begin(9600);
  randomSeed(digitalRead(0));

  strip.begin();
  strip.clear();
  strip.setBrightness(100);  //eventually this will be variable with slider/expression pedal
  strip.show();
}

void loop() {
  verseSatellite();  //still makes both orange
}


void verseSatellite() {
  fadeMillis(orange, 200);
  sparkleOverFill(orange, 50);
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


void colorRecall(int color) {  //not working properly
  if (orange == color) {
    RED = 2.55;
    GREEN = 1.00;
    BLUE = 0;
  }
  if (lightBlue == color) {
    RED = 0.6;
    GREEN = 1.27;
    BLUE = 2.55;
  }
  if (white == color) {
    RED = 1.27;
    GREEN = 1.27;
    BLUE = 1.27;
  } else {
    RED = 0;
    GREEN = 0;
    BLUE = 0;
  }
  Serial.println(orange);
}

void colorRecall2(int color2) {  //tried this as a solution, but still not changing anything
  if (color2 == orange) {
    RED = 2.55;
    GREEN = 1.00;
    BLUE = 0;
  } if (color2 == lightBlue) {
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
    // strip.show();
    Serial.println(f);
    nextFade();
  }
}

void sparkleOverFill(int color, int fadeRate) {
  colorRecall(color);
  if (millis() > lastSparkleTime + fadeRate) {
    lastSparkleTime = millis();
    for (int i = 0; i < 33; i++) {
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


void nextSparkle() {
  currentSparkleStep = currentSparkleStep + 1;
  if (currentSparkleStep >= totalSparkleStep) {
    sf = 100;
    currentSparkleStep = 0;
  }
}

