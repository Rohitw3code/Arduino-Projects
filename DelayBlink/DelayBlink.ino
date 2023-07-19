
const int kPinLED = 13;


void setup() {
  // put your setup code here, to run once:
  pinMode(kPinLED,OUTPUT);
  pinMode()
}

int delayTime = 1000;

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<=4;i++){
    digitalWrite(kPinLED,HIGH);
    delay(200);  
    digitalWrite(kPinLED,LOW);
    delay(200);
  }

  delay(1000);
  

}
