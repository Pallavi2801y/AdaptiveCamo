#include <Adafruit_NeoPixel.h>

// --- TCS3200 Sensor Pins ---
int S0 = 19;
int S1 = 18;
int S2 = 2;
int S3 = 4;
int OUT = 15;

// --- LED Matrix Setup ---
#define LED_PIN   5
#define NUM_LEDS  64
Adafruit_NeoPixel matrix(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// --- Hardcoded Calibration Values ---
int redMin = 30,   redMax = 150;
int greenMin = 20, greenMax = 160;
int blueMin = 25,  blueMax = 140;

int redRaw, greenRaw, blueRaw;
int redMapped, greenMapped, blueMapped;

void setup() {
  Serial.begin(115200);
  Serial.println("TCS3200 Color -> LED Matrix (RGB display)");

  // Sensor setup
  pinMode(S0, OUTPUT); digitalWrite(S0, HIGH);
  pinMode(S1, OUTPUT); digitalWrite(S1, HIGH);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);

  // LED matrix setup
  matrix.begin();
  matrix.clear();
  matrix.show();
}

void loop() {
  // Read raw RGB values from TCS3200
  redRaw   = readColor(HIGH, HIGH);   // Red filter
  greenRaw = readColor(LOW, HIGH);    // Green filter
  blueRaw  = readColor(LOW, LOW);     // Blue filter

  // Map raw values to 0–255 using calibration ranges
  redMapped   = map(constrain(redRaw, redMin, redMax), redMin, redMax, 0, 255);
  greenMapped = map(constrain(greenRaw, greenMin, greenMax), greenMin, greenMax, 0, 255);
  blueMapped  = map(constrain(blueRaw, blueMin, blueMax), blueMin, blueMax, 0, 255);

  // Debug output
  Serial.print("Raw: R="); Serial.print(redRaw);
  Serial.print(" G="); Serial.print(greenRaw);
  Serial.print(" B="); Serial.println(blueRaw);

  Serial.print("Mapped: R="); Serial.print(redMapped);
  Serial.print(" G="); Serial.print(greenMapped);
  Serial.print(" B="); Serial.println(blueMapped);

  // --- Enhance dominant color ---
  int maxVal = max(redMapped, max(greenMapped, blueMapped));

  if (maxVal == redMapped) {
    greenMapped = 0;
    blueMapped = 0;
  } else if (maxVal == greenMapped) {
    redMapped = 0;
    blueMapped = 0;
  } else if (maxVal == blueMapped) {
    redMapped = 0;
    greenMapped = 0;
  }

  // Set LED color using enhanced RGB values
  uint32_t colorValue = matrix.Color(redMapped, greenMapped, blueMapped);

  for (int i = 0; i < NUM_LEDS; i++) {
    matrix.setPixelColor(i, colorValue);
  }

  matrix.show();

  delay(300);  // Wait a bit before next reading
}

// Read sensor value for given filter selection
int readColor(int s2, int s3) {
  digitalWrite(S2, s2);
  digitalWrite(S3, s3);
  delay(10);
  return pulseIn(OUT, LOW, 25000);
}