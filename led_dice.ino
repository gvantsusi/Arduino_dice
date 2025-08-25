//delay time variable
#define d 200

//led pins:
int leds[] = {3, 4, 5, 6, 7, 8};  // array of LED pins
const int ledCount = 6;

//button pin:
int button = 2;

//variable of the result:
int result;

void setup() {
  //leds as OUTPUT
  for (int i = 0; i < ledCount; i++) {
    pinMode(leds[i], OUTPUT);
  }
  //button as INPUT_PULLUP (sends LOW when pressed)
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(button) == LOW) {  
    result = random(1, 7); // generates 1–6
  }

  // turn off all LEDs first
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(leds[i], LOW);
  }

  // turn on "result" number of LEDs
  for (int i = 0; i < result; i++) {
    digitalWrite(leds[ledCount - 1 - i], HIGH); 
    // lights from led6 backwards to led1
  }

  delay(d);
}

