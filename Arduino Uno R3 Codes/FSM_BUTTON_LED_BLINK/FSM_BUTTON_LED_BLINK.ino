#define RED 13
#define YELLOW 12
#define BLUE 11
#define BUTTON 10

int clickCount = 0;
bool buttonWasPressed = false; // The "Lock" to prevent holding-down bugs
unsigned long lastClickTime = 0;
const int clickWindow = 500; // 0.5 seconds to finish clicking

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);
  
  // Internal pull-up: Button connects Pin 12 to GND
  pinMode(BUTTON, INPUT_PULLUP); 
}

void loop() {
  // Read button: LOW means it is being pressed down
  digitalRead(BUTTON)
}