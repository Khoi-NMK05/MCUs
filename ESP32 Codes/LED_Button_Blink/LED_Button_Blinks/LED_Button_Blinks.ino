/*
 * Project: Button controlled LED Blink
 * Board: MKE-K01 ESP32-S3 (N16R8)
 * LED: IO1 | Button: IO42
 */

const int BUTTON_PIN = 42; // Chân nút nhấn
const int LED_PIN = 1;
const int LED_PIN2 = 2;     // Chân LED

void setup() {
  // Cấu hình LED là đầu ra
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  
  // Cấu hình nút nhấn với điện trở kéo lên nội bộ
  // Khi không nhấn = HIGH, khi nhấn = LOW
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  // Khởi tạo trạng thái ban đầu
  digitalWrite(LED_PIN, LOW);
  digitalWrite(LED_PIN2, LOW);
}

void loop() {
  // Đọc trạng thái nút nhấn
  int buttonState = digitalRead(BUTTON_PIN);

  // Nếu nút được nhấn (tín hiệu LOW)
  if (buttonState == LOW) {
    // Chớp tắt LED
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, LOW);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, HIGH);
    delay(200);
  } 
  else {
    // Nếu không nhấn thì tắt LED
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);
  }
}