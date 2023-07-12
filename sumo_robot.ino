// Variables to control Motor A on H-bridge L298N
#define IN1 8
#define IN2 7
#define ENA 9

// Variables to control Motor B on H-bridge L298N
#define IN3 5
#define IN4 4
#define ENB 3

// Variables for the Ultrasonic Sensor HCSR04
#define trig1 A0
#define echo1 A1

// Variables for the IR Sensors TCRT5000
#define R_Sensor A5
#define L_Sensor A4

// Global Variables
float distance, duration; // Variables for calculating distance
int searchcycle = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(9600); // To monitor the results
  pinMode(trig1, OUTPUT); // Trigger as output
  pinMode(echo1, INPUT); // Echo as input
  pinMode(R_Sensor, INPUT);
  pinMode(L_Sensor, INPUT);
}

void loop() {
  // Calculate distance from HCSR04
  digitalWrite(trig1, LOW); // Write a pulse to the trigger pin
  delayMicroseconds(2); // LOW state for 2 microseconds
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10); // HIGH state for 10 microseconds
  digitalWrite(trig1, LOW); // LOW state again
  duration = pulseIn(echo1, HIGH); // Measure response from Echo pin
  
  // Determine distance from the duration and use 343m/s as the speed of sound
  distance = (duration / 2) * 0.0343; // Use half duration as it calculates to the 'object' and back to the sensor

  // Show results on the serial monitor
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 30) { // If distance from front sensor is less than 30, go FORWARD
    analogWrite(ENA, 255); // Sets speed for Motor A
    analogWrite(ENB, 255); // Sets speed for Motor B
    // Sets Motor A to go forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    // Sets Motor B to go forward
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    
    if ((digitalRead(L_Sensor) == HIGH || digitalRead(R_Sensor) == HIGH) && (distance < 30)) {
      analogWrite(ENA, 255);
      analogWrite(ENB, 255);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(1000);
    }
  } else if (digitalRead(L_Sensor) == HIGH || digitalRead(R_Sensor) == HIGH) {
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(1000);
  } else {
    // SEARCH
    if (searchcycle < 15) { // Go forward 15 cycles (around 20 cycles in a sec)
      analogWrite(ENA, 255);
      analogWrite(ENB, 255);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    } else if ((searchcycle <= 20) && (searchcycle > 15)) { // Rotate right 5 cycles
      analogWrite(ENA, 255);
      analogWrite(ENB, 255);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    if (searchcycle < 20) {
      searchcycle += 1;
    } else if (searchcycle == 20) {
      searchcycle = 0;
    }
  }
}