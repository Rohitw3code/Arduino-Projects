const int micPin = A0;
const int bpin = 3;
const int gpin = 7;
const int rpin = 9;
 
void setup() {
    Serial.begin(9600); 
    pinMode(gpin, OUTPUT);
    pinMode(bpin, OUTPUT);
    pinMode(rpin, OUTPUT);
}
 
void loop() {   
    int mvolts = analogRead(micPin) * 5.0 / 1024.0 * 1000.0; // values in millivolts
     Serial.println(mvolts); // output to the port

     if(mvolts <101){
      digitalWrite(rpin,HIGH);
      digitalWrite(bpin,LOW);
      digitalWrite(gpin,LOW);
      }
     else if(100 < mvolts && mvolts <300){
      digitalWrite(bpin,HIGH);
      digitalWrite(rpin,LOW);
      digitalWrite(gpin,LOW);
      }
      else{
      digitalWrite(gpin,HIGH);
      digitalWrite(rpin,LOW);
      digitalWrite(bpin,LOW);
      }


     
}
