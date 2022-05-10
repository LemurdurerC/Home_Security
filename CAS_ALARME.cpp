int incomingByte = 0;   // for incoming serial data
String content = "";
char character;

void setup() {
        Serial.begin(9600);    
    pinMode(3, OUTPUT);
  // opens serial port, sets data rate to 9600 bps
}

void loop() {

        String content = "";
char character;
    
while(Serial.available()) {
     character = Serial.read();
     content.concat(character);
}
      
if (content == "1") {
     Serial.println(content);
  digitalWrite(3, HIGH);
  delay(1200);
}
  
  else{
    Serial.println("Rien à signaler");
    digitalWrite(3, LOW);
    delay(1200);
  }
  
 
}
 