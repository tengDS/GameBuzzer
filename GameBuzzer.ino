#define RED_LED 7
#define WHITE_LED 8 
#define GREEN_LED 9

void setup() {
  // put LED pins in output mode.
  pinMode(RED_LED, OUTPUT);
  pinMode(WHITE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED_LED, HIGH);
  digitalWrite(WHITE_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);

  delay(3000);

  digitalWrite(RED_LED, LOW);
  digitalWrite(WHITE_LED, LOW);
  digitalWrite(GREEN_LED, LOW);

  delay(3000);
}
