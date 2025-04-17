

class analogButton {

  public:

    uint8_t analogPin;

    analogButton(int x) {
      analogPin = x;
    }

    bool check() {
      uint16_t analogValue = analogRead(analogPin);

      prevState = state;

      if (analogValue < buttonLowThreshold) {
        // if the Button has been pressed
        state = 1;
      } else {
        state = 0;
      }

      return returnState();
    }

    uint16_t returnAnalog() {
      return analogRead(analogPin);
    }

    bool returnState() {
      return state;
    }

    bool returnPrevState() {
      return prevState;
    }

  protected:
    bool state=1;
    bool prevState=1;
  
  private:
    uint16_t buttonHighThreshold = 1000; // CHANGE THIS
    uint16_t buttonLowThreshold = 100; // CHANGE THIS

};

analogButton buttonOne(A0);
analogButton buttonTwo(A1);
analogButton buttonThree(A2);
analogButton buttonFour(A3);
analogButton buttonFive(A4);
analogButton buttonSix(A5);
analogButton buttonSeven(A6);
analogButton buttonEight(A7);

void setup() {

  Serial.begin(115200);

}

void loop() {

  if (buttonOne.check() == 1) {
    // button has been pressed

    Serial.println("ButtonOne: Pressed!!");
  }

  Serial.println("=========================");

  delay(100);

}
