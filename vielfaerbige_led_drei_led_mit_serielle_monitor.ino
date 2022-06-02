int drei_led_rot = 3;
int drei_led_gruen = 5;
int drei_led_blau = 6;
int value[3];
int value_rot; 
int value_gruen;
int value_blau;

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Bitte gewünschte Kombination eingeben: rot, grün, blau");
  pinMode(drei_led_rot,OUTPUT);
  pinMode(drei_led_gruen,OUTPUT);
  pinMode(drei_led_blau, OUTPUT);
}

void loop() {
  analogWrite(drei_led_blau, 200);
    if (Serial.available()) {
      while (Serial.available()) {
        
        value[0] = Serial.parseInt();
        Serial.println("Rot");
        Serial.println(value[0]);
        analogWrite(drei_led_rot, value[0]);
        delay(2000);
        
        value[1] = Serial.parseInt();
        Serial.println("Gruen");
        Serial.println(value[1]);
        analogWrite(drei_led_gruen, value[1]);
        delay(2000);
  
        value[2] = Serial.parseInt();
        Serial.println("Blau");
        Serial.println(value[2]);
        analogWrite(drei_led_blau, value[2]);
        delay(2000);
        
        delay(10000);
      }
    }
  }
  
