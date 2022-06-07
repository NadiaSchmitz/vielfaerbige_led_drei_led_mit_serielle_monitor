String farben[] = {"R", "G", "B"};
int leds[] = {3,5,6};
String value_s_monitor[3];
int value[3];

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Bitte gewünschte Kombination eingeben:");
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i],OUTPUT);
  }
  
}

void loop() {

  
  for (int i = 0; i < 3; i++) {
    if (Serial.available()) {
      while (Serial.available()) {  
        value_s_monitor[i] = Serial.readStringUntil('\n');
        value[i] = value_s_monitor[i].toInt();
        analogWrite(leds[i], value[i]);
        Serial.println(farben[i]);
        Serial.println(value[i]);
        delay(1000);
      }
    }
  }
  
}
  
