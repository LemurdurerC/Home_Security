
const byte TRIGGER_PIN = 2; 
const byte ECHO_PIN = 3;    

 

const unsigned long MEASURE_TIMEOUT = 25000UL; 


const float SOUND_SPEED = 340.0 / 1000;

void setup() {
   

  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
   

  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); 
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  
 
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  

  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
   
 
  float distance_mm = measure / 2.0 * SOUND_SPEED;
   

  Serial.print(F("Distance: "));
  Serial.print(distance_mm);
  Serial.print(F("mm ("));
  Serial.print(distance_mm / 10.0, 2);
  Serial.print(F("cm, "));
  Serial.print(distance_mm / 1000.0, 2);
  Serial.println(F("m)"));
   

  delay(500);
  
  if (distance_mm < 3320.00){
    Serial.print("dedans");
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    Serial.print("out");
    digitalWrite(LED_BUILTIN, LOW);
  }
}




