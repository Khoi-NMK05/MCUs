/*
 * Project: Toggle LED Blink with Button
 * Board: MKE-K01 ESP32-S3 (N16R8)
 * LED Pins: IO1, IO2 | Button Pin: IO42
 */

const int BUTTON_PIN = 42; // Button connected to IO42
const int LED_PIN = 1;     // First LED connected to IO1
const int LED_PIN2 = 2;    // Second LED connected to IO2

bool isBlinking = false;      // Variable to store the system state (On/Off)
int lastButtonState = HIGH;   // Store the previous state of the button

void setup() {
  // Configure LED pins as outputs
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  
  // Configure button with internal pull-up resistor
  // Idle = HIGH, Pressed = LOW
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  // Initialize LEDs to be OFF
  digitalWrite(LED_PIN, LOW);
  digitalWrite(LED_PIN2, LOW);
}

void loop() {
  // Read the current physical state of the button
  int currentButtonState = digitalRead(BUTTON_PIN);

  // DETECT FALLING EDGE: If the button was just pressed (transition from HIGH to LOW)
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    isBlinking = !isBlinking; // Flip the state (True becomes False, False becomes True)
    delay(50);                // Software Debounce: ignore mechanical vibrations
  }
  
  // Save the current state for comparison in the next loop cycle
  lastButtonState = currentButtonState;

  // EXECUTE ACTIONS BASED ON STATE
  if (isBlinking) {
    // If system is ON: Perform alternating blink
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, LOW);
    delay(200);
    
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, HIGH);
    delay(200);
  } 
  else {
    // If system is OFF: Ensure both LEDs are turned off
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);
  }
}
