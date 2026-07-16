#include <Servo.h>

Servo esc1;
Servo esc2;
Servo esc3;

const int potPin = A0;

const int escPin1 = 3;
const int escPin2 = 5;
const int escPin3 = 6;

// Chỉnh 3 giá trị này theo ESC/motor của bạn
const int stopSignal  = 1000;  // dừng
const int startSignal = 1250;  // mức bắt đầu quay
const int maxSignal   = 1800;  // tốc độ tối đa khi test

const int deadZone = 40;       // vùng thấp nhất để dừng

void setup() {
  esc1.attach(escPin1);
  esc2.attach(escPin2);
  esc3.attach(escPin3);

  setEsc(stopSignal);
  delay(3000);
}

void loop() {
  int potValue = analogRead(potPin);

  int signal;

  if (potValue <= deadZone) {
    signal = stopSignal;       // thấp nhất: dừng
  } else {
    // Mỗi vị trí biến trở tạo một mức tốc độ khác nhau
    signal = map(potValue, deadZone + 1, 1023, startSignal, maxSignal);
  }

  setEsc(signal);
  delay(20);
}

void setEsc(int signal) {
  esc1.writeMicroseconds(signal);
  esc2.writeMicroseconds(signal);
  esc3.writeMicroseconds(signal);
}
