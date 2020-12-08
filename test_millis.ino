
#define LED_PIN 2
#define TIMER 1000


void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  while (!Serial) {};
  Serial.println("ok");

}



////TEST 1  - 1sec led blinking
//
//void loop() {
//
//  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
//  Serial.println(digitalRead(LED_PIN));
//  delay(TIMER);
//
//}




////TEST 2  - 1sec led blinking using next_time
//
//unsigned long next_time = 0;
//
//void loop() {
//
//  if (millis()>=next_time) {
//    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
//    next_time=millis()+TIMER;
//    Serial.print(millis());
//    Serial.print(" - ");
//    Serial.println(next_time);
//  };
//
//}





////TEST 3  - verify millis() reset  - reset at 4294967295
//
//extern volatile unsigned long timer0_millis;
//// refer to wiring.c
//
//void loop() {
//
//  Serial.println(millis());
//
//  if ((millis()>=100) && (millis()<4000000000)) {
//    noInterrupts ();
//    timer0_millis = 4294967000;
//    interrupts ();
//  }
//
//}




////TEST 4  - millis close to reset using next_time - reset at 4294967295
//
//unsigned long next_time = 0;
//extern volatile unsigned long timer0_millis;
//// refer to wiring.c
//
//
//void loop() {
//  unsigned long new_millis=4294961500;
//
//  if ((millis()>=6000) && (millis()<new_millis)) {
//    next_time = next_time-millis()+new_millis;   //do not change the blinking period
//    noInterrupts ();
//    timer0_millis = new_millis;
//    interrupts ();
//  }
//
//  if (millis()>=next_time) {
//    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
//    next_time=millis()+TIMER;
//    Serial.print(millis());
//    Serial.print(" - ");
//    Serial.print(next_time);
//    Serial.print(" - ");
//    Serial.println(digitalRead(LED_PIN));
//  }
//
//}



////TEST 5  - millis close to reset using next_time. SLOW LOOP  - (reset at 4294967295)
//
//unsigned long next_time = 0;
//extern volatile unsigned long timer0_millis;
//// refer to wiring.c
//
//
//void loop() {
//  unsigned long new_millis=4294962000;
//
//  if ((millis()>=4200) && (millis()<new_millis)) {
//    noInterrupts ();
//    timer0_millis = new_millis;
//    interrupts ();
//  }
//
//  if (millis() >= next_time) {
//    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
//    next_time = millis() + TIMER;
//  }
//
//  delay(70);
//
//  Serial.print(millis());
//  Serial.print(" - ");
//  Serial.println(next_time);
//
//}





//TEST 6  - millis close to reset using prev_time. SLOW LOOP  - (reset at 4294967295)
unsigned long prev_time = 0;
extern volatile unsigned long timer0_millis; // refer to wiring.c

void loop() {
  unsigned long new_millis=4294962000;
  if ((millis()>=7000) && (millis()<new_millis)) {
    prev_time = prev_time-millis()+new_millis;   //do not change the blinking period
    noInterrupts ();
    timer0_millis = new_millis;
    interrupts ();
  }
  if ((millis()- prev_time) >= TIMER) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    prev_time = millis();
  }
  delay(70);
  Serial.print(millis());
  Serial.print(" - ");
  Serial.print(prev_time);
  Serial.print(" = ");
  Serial.println(millis() - prev_time);
}





















////TEST x - null mode
//
//void loop() {
//
//
//  delay(70);
//
//}
