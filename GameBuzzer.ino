#define RED_LED 7
#define WHITE_LED 8 
#define GREEN_LED 9

#define RED_BUTTON 2
#define WHITE_BUTTON 3
#define GREEN_BUTTON 4

enum ButtonState {
  UNPRESSED,
  PRESSED
};

ButtonState prevGreen;

enum SystemState {
  ARMED=0,
  RED_WON=1,
  WHITE_WON=2
};

SystemState currState;

void setup() {
  Serial.begin(115200);

  // put LED pins in output mode.
  pinMode(RED_LED, OUTPUT);
  pinMode(WHITE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // put button pins into pullup input mode.
  pinMode(RED_BUTTON, INPUT_PULLUP);
  pinMode(WHITE_BUTTON, INPUT_PULLUP);
  pinMode(GREEN_BUTTON, INPUT_PULLUP);

  // set button states.
  prevGreen = UNPRESSED;

  // set system state.
  resetSystem();
}

void enableLED(byte pin) {
  if(pin == RED_LED) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(WHITE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
  } else if (pin == WHITE_LED) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(WHITE_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  } else if (pin == GREEN_LED) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(WHITE_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }
}

void resetSystem() {
  enableLED(GREEN_LED);
  currState = ARMED;
}

void checkButtons() {
  bool isPressed;

  // green button always resets system and puts it back in ARMED state.
  // check green button.
  isPressed = !digitalRead(GREEN_BUTTON);
  if (isPressed && prevGreen == UNPRESSED) {
    // user just pressed the green button.
    prevGreen = PRESSED;
    resetSystem();
  } else if (isPressed == false && prevGreen == PRESSED) {
    // user just released the green button.
    prevGreen = UNPRESSED;
  }

  // check red button.
  // note we could use an interrupt to check the states of the red and white buttons but it should be fine to just poll instead.
  isPressed = !digitalRead(RED_BUTTON);
  if (isPressed && currState == ARMED) {
    // red only wins if system was in armed state and red button is pressed.
    currState = RED_WON;
    enableLED(RED_LED);
  }

  // check white button.
  isPressed = !digitalRead(WHITE_BUTTON);
  if (isPressed && currState == ARMED) {
    // white only wins if the system was in armed state and white button is pressed.
    currState = WHITE_WON;
    enableLED(WHITE_LED);
  }
}

void loop() {
  // check buttons
  checkButtons();

  Serial.println(currState);
}
