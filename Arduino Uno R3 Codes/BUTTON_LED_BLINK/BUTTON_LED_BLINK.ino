#define LED_PIN 13
#define BUTTON_PIN 12

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(BUTTON_PIN) == LOW)
  {
    digitalWrite(LED_PIN, HIGH);
  }
else 
  {
    digitalWrite(LED_PIN, LOW);
  }
}