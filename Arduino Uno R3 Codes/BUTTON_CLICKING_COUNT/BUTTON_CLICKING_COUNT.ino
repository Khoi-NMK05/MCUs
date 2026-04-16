#define BUTTON 10
#define RED 13
#define GREEN 12
#define BLUE 11

int count = 0;
bool lastButtonState = HIGH;

// Variables for the "Stopwatch" logic
unsigned long lastTime = 0;
int step = 0; // Used to track which LED is on in a sequence
bool ledState = LOW;

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);
  Serial.println("System Ready. Start pressing!");
}

void loop() {
  // 1. INPUT HANDLING (Always happens instantly)
  bool currentButtonState = digitalRead(BUTTON);
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    count++;
    // Reset animation variables whenever we change modes
    lastTime = millis(); 
    step = 0;
    ledState = LOW;
    // Turn off all LEDs immediately on click to prevent "ghosting"
    digitalWrite(RED, LOW); digitalWrite(GREEN, LOW); digitalWrite(BLUE, LOW);
    
    Serial.print("Count changed to: ");
    Serial.println(count);
    delay(50); // Small debounce is the only delay allowed!
  }
  lastButtonState = currentButtonState;

  // 2. ANIMATION LOGIC (No delays here!)
  unsigned long currentTime = millis();

  switch (count) {
    case 0:
      digitalWrite(BLUE, HIGH);
      break;

    case 1: // Red Blinking
      if (currentTime - lastTime >= 500) {
        ledState = !ledState; // Flip the state (HIGH to LOW or vice versa)
        digitalWrite(RED, ledState);
        lastTime = currentTime; // Reset the stopwatch
      }
      break;

    case 2: // Sequence Blinking (Red -> Green -> Blue)
      if (currentTime - lastTime >= 250) {
        // Turn off whatever was on in the last step
        digitalWrite(RED, LOW); digitalWrite(GREEN, LOW); digitalWrite(BLUE, LOW);
        
        if (step == 0) digitalWrite(RED, HIGH);
        else if (step == 1) digitalWrite(GREEN, HIGH);
        else if (step == 2) digitalWrite(BLUE, HIGH);
        
        step = (step + 1) % 3; // Move to next LED (0, 1, 2, then back to 0)
        lastTime = currentTime;
      }
      break;

    case 3: // All Blinking
      if (currentTime - lastTime >= 500) {
        ledState = !ledState;
        digitalWrite(RED, ledState);
        digitalWrite(GREEN, ledState);
        digitalWrite(BLUE, ledState);
        lastTime = currentTime;
      }
      break;

    default: // Reset State
      Serial.println("Resetting...!");
      count = 0;
      break;
  }
}