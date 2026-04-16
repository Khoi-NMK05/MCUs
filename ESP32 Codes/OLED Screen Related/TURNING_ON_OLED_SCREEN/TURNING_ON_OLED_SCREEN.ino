/*
 * Project: OLED SH110x Display Test
 * Board: MKE-K01 ESP32-S3
 * Screen: 1.3" OLED (SH1106)
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

// SH1106 OLEDs are usually 128x64 pixels
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1   // Set to -1 if your OLED doesn't have a reset pin

// Initialize the display using the I2C address (usually 0x3C)
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  // Initialize I2C on the correct pins for MKE-K01 (SDA: 41, SCL: 42)
  Wire.begin(41, 42);

  // Start the OLED display
  // 0x3C is the standard I2C address for these screens
  if (!display.begin(0x3C, true)) {
    Serial.println(F("SH1106 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  display.display();
  delay(1000); // Pause for 1 second

  // Clear the buffer
  display.clearDisplay();

  // Draw some text
  display.setTextSize(1);              // Normal 1:1 pixel scale
  display.setTextColor(SH110X_WHITE);  // Draw white text
  display.setCursor(0, 0);             // Start at top-left corner
  display.println(F("ESP32-S3 MKE-K01"));
  display.println(F("SH1106 1.3 inch"));
  display.println(F("-------------------"));
  display.setTextSize(2);              // Larger text size
  display.println(F("HELLO!"));
  
  display.display(); // Actually push the data to the screen
}

void loop() {
  // You can update the screen here based on your button toggle
}