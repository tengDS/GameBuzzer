#define RED_LED 7
#define WHITE_LED 8 
#define GREEN_LED 9

#define RED_BUTTON 2
#define WHITE_BUTTON 3
#define GREEN_BUTTON 4

void setup() {
  // put LED pins in output mode.
  pinMode(RED_LED, OUTPUT);
  pinMode(WHITE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // put button pins into pullup input mode.
  pinMode(RED_BUTTON, INPUT_PULLUP);
  pinMode(WHITE_BUTTON, INPUT_PULLUP);
  pinMode(GREEN_BUTTON, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(RED_BUTTON)) {
    digitalWrite(RED_LED, LOW);
  } else {
    digitalWrite(RED_LED, HIGH);
  }

  if(digitalRead(WHITE_BUTTON)) {
    digitalWrite(WHITE_LED, LOW);
  } else {
    digitalWrite(WHITE_LED, HIGH);
  }

  if(digitalRead(GREEN_BUTTON)) {
    digitalWrite(GREEN_LED, LOW);
  } else {
    digitalWrite(GREEN_LED, HIGH);
  }
}
