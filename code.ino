#include <Servo.h>

// -------------------- Pin Definitions --------------------
#define trigPin 7         // Ultrasonic sensor trigger pin
#define echoPin 6         // Ultrasonic sensor echo pin
#define motor1Pin1 22     // L293D Motor1 pin1
#define motor1Pin2 23     // L293D Motor1 pin2
#define motor2Pin1 24     // L293D Motor2 pin1
#define motor2Pin2 25     // L293D Motor2 pin2
#define enableMotor1 3    // L293D Motor1 enable pin (PWM)
#define enableMotor2 5    // L293D Motor2 enable pin (PWM)
#define bluetoothRx 19    // HC-05 RX
#define bluetoothTx 18    // HC-05 TX

// -------------------- Servo Objects --------------------
Servo leftArmServo;
Servo rightArmServo;
#define leftArmPin 9
#define rightArmPin 10

// -------------------- Variables --------------------
long duration;
int distance;
char btCommand;

// -------------------- Setup --------------------
void setup() {
  Serial.begin(9600);       // Serial monitor
  Serial1.begin(9600);      // HC-05 Bluetooth
  
  // Motor pins setup
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enableMotor1, OUTPUT);
  pinMode(enableMotor2, OUTPUT);
  
  // Ultrasonic pins setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Servo setup
  leftArmServo.attach(leftArmPin);
  rightArmServo.attach(rightArmPin);

  // Initialize servos
  leftArmServo.write(90);   // neutral position
  rightArmServo.write(90);  // neutral position
}

// -------------------- Main Loop --------------------
void loop() {
  // 1. Check for Bluetooth command
  if (Serial1.available()) {
    btCommand = Serial1.read();
    handleBluetoothCommand(btCommand);
  }

  // 2. Obstacle detection
  distance = readUltrasonic();
  if (distance < 20) { // obstacle closer than 20 cm
    stopMotors();
    Serial.println("Obstacle detected! Stopping.");
  }
}

// -------------------- Functions --------------------

// Function to read ultrasonic distance
int readUltrasonic() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2; // distance in cm
}

// Function to control motors based on Bluetooth command
void handleBluetoothCommand(char cmd) {
  switch (cmd) {
    case 'F': // Forward
      moveForward();
      break;
    case 'B': // Backward
      moveBackward();
      break;
    case 'L': // Left
      turnLeft();
      break;
    case 'R': // Right
      turnRight();
      break;
    case 'S': // Stop
      stopMotors();
      break;
    case 'A': // Move left arm
      leftArmServo.write(0);
      break;
    case 'a': // Reset left arm
      leftArmServo.write(90);
      break;
    case 'D': // Move right arm
      rightArmServo.write(180);
      break;
    case 'd': // Reset right arm
      rightArmServo.write(90);
      break;
  }
}

// Motor movement functions
void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(enableMotor1, 200);
  analogWrite(enableMotor2, 200);
}

void moveBackward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  analogWrite(enableMotor1, 200);
  analogWrite(enableMotor2, 200);
}

void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(enableMotor1, 200);
  analogWrite(enableMotor2, 200);
}

void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  analogWrite(enableMotor1, 200);
  analogWrite(enableMotor2, 200);
}

void stopMotors() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
