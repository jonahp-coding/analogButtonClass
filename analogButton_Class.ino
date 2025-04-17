

class analogButton {

  public:

    uint8_t analogPin;

    analogButton(int x) {
      analogPin = x;
    }

    bool checkButton() {
      uint16_t analogValue = analogRead(analogPin);

      prevState = state;

      if (analogValue < buttonLowThreshold) {
        // if the Button has been pressed
        state = 1;
      } else {
        state = 0;
      }
    }

    uint16_t stateRawReturn() {
      return analogRead(analogPin);
    }

    bool stateReturn() {
      return state;
    }

    bool prevStateReturn() {
      return prevState;
    }

  protected:
    bool state=1;
    bool prevState=1;
  
  private:
    uint16_t buttonHighThreshold = 1000; // CHANGE THIS
    uint16_t buttonLowThreshold = 40; // CHANGE THIS

};

void setup() {

  Serial.begin(115200);

}

void loop() {

  analogButton buttonOne(A0);

  buttonOne.checkButton();

  Serial.println(buttonOne.stateRawReturn());

  /*Serial.print("buttonOne: ");
  Serial.println(buttonOne);

  Serial.print("buttonTwo: ");
  Serial.println(buttonTwo);

  Serial.println("=========================");
  */

  delay(100);

}
