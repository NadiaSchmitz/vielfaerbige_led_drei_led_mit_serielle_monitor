int leds[] = {3,5,6};
int leds_value[3];

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i],OUTPUT);
  }
  Serial.begin(9600);
  randomSeed(analogRead(0));
  delay(1000);
  Serial.println("Bitte ein Zahl zwischen 1 und 10");
}

void loop() {
  if (Serial.available()) {
      while (Serial.available()) {  
        int control_sum;
        int value = Serial.parseInt();
        delay(30);
        Serial.println(value);
        
        for (int i = 0; i < 3; i++) {
          
          control_sum = random(200);
          Serial.println(control_sum);
          leds_value[i] = value * control_sum;
          if (leds_value[i] > 255) {
            leds_value[i] = 255;
          }
          Serial.println(leds_value[i]);
          analogWrite(leds[i], leds_value[i]);
          
        }
        delay(100000);
    }
    
  }
  
}
  
