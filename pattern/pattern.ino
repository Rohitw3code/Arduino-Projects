
const int num_led = 3l;
const int pinLeds[num_led] = {1,4,7};

void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<3;i++){
    pinMode(pinLeds[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<3;i++){
    digitalWrite(pinLeds[i],HIGH);
    delay(300); 
    digitalWrite(pinLeds[i],LOW);
    delay(300); 
   }  
}
