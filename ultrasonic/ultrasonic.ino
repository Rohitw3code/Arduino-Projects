const int pingPin = 5; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
const int gled = 12;
const int rled = 13;

void setup() {
   pinMode(pingPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(rled,OUTPUT);
   pinMode(gled,OUTPUT);
   Serial.begin(600); // Starting Serial Terminal
}

int distance = 20;
void loop() {

//  digitalWrite(led,HIGH);
//  delay(500);
//  digitalWrite(led,LOW);
//  delay(500);
  
   long duration, inches, cm;
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);

   if(cm < distance){
      digitalWrite(rled,HIGH);
      digitalWrite(gled,LOW);      
    }
    else{
      digitalWrite(rled,LOW);
      digitalWrite(gled,HIGH);
    }
   
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println("hello");
   delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
