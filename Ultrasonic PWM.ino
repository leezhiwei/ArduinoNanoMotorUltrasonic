//define pins for ultrasonic sensor
const int trigPin = 12;
const int echoPin = 11;

//defines pins for PWM signal output
const int PWMOutput = 7;

//defines other variables
long duration;
int distance;
int pwmnum;
void setup() {
  // put your setup code here, to run once:
  pinMode(PWMOutput, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Clears TrigPin
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  
  //Sets trigpin on high state for 10 microseconds
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //Reads Echopin for timing for feedback
  duration = pulseIn(echoPin, HIGH);

  //Calculating Distance
  distance= duration*0.034/2;

  //Calculating PWM signal timing
  pwmnum= distance*5;

  //Driving PWM signal
  analogWrite(PWMOutput , pwmnum);

  //Printing distance and PWM values
  Serial.print("Distance:");
  Serial.println(distance);
  Serial.print("PWM Timing");
  Serial.println(pwmnum);
}
