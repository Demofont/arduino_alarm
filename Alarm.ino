const int trigPin = 2;
const int echoPin = 3;
const int buzzer = 11;
const int ledPin = 13;

long duration, cm;

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop(){
 digitalWrite(trigPin, LOW);
 delayMicroseconds(5);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);

 pinMode(echoPin, INPUT);
 duration = pulseIn(echoPin, HIGH);

 cm = (duration/2) * 0.0343;

if (cm < 50){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}

 Serial.print(cm);
 Serial.print("cm");
 Serial.println();

 delay(250);
}
