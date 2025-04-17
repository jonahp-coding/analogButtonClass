

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
    uint16_t buttonLowThreshold = 40; // CHANGE THIS

};

void setup() {

  Serial.begin(115200);

}

void loop() {

  analogButton startButton(A0);
  analogButton RunButton(A1);
  analogButton threeButton(A2);
  analogButton fourButton(A3);
  analogButton fiveButton(A4);
  analogButton sixButton(A5);
  analogButton sevenButton(A6);
  analogButton eightButton(A7);

  Serial.print("startButton: ");
  Serial.println(startButton.checkButton());

  Serial.print("RunButton: ");
  Serial.println(RunButton.checkButton());

  Serial.print("threeButton: ");
  Serial.println(threeButton.checkButton());

  Serial.print("fourButton: ");
  Serial.println(fourButton.checkButton());

  Serial.print("fiveButton: ");
  Serial.println(fiveButton.checkButton());

  Serial.print("sixButton: ");
  Serial.println(sixButton.checkButton());

  Serial.print("sevenButton: ");
  Serial.println(sevenButton.checkButton());

  Serial.print("eightButton: ");
  Serial.println(eightButton.checkButton());

  Serial.println("=========================");

  delay(100);

}
