/ C++ code
// Dual Button Gate Indicator System
//

// Pin Assignments
const int closeButtonPin = 10; // Button para Close
const int openButtonPin  = 11; // Button para Open

const int redLedPin   = 12; // LED para Closed status
const int greenLedPin = 13; // LED para Open status

// Variables para basahon ang button states
int closeButtonState = 0;
int openButtonState  = 0;

void setup()
{
  // Set Pin Modes
  pinMode(closeButtonPin, INPUT);
  pinMode(openButtonPin, INPUT);
  
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  // Sugdan ang Serial Communication (9600 baud rate)
  Serial.begin(9600);
}

void loop()
{
  // Basahon ang duha ka buttons
  closeButtonState = digitalRead(closeButtonPin);
  openButtonState  = digitalRead(openButtonPin);

  // KUNG GI-PRESS ANG CLOSE BUTTON (Pin 10)
  if (closeButtonState == HIGH) {
    digitalWrite(redLedPin, HIGH);   // Mosiga ang Red LED
    digitalWrite(greenLedPin, LOW);  // Mapalong ang Green LED
    Serial.println("Gate is Closed");
    delay(250); // Delay gamay para dili mag-sige ug spam ang Serial Monitor
  }
  
  // KUNG GI-PRESS ANG OPEN BUTTON (Pin 11)
  else if (openButtonState == HIGH) {
    digitalWrite(redLedPin, LOW);    // Mapalong ang Red LED
    digitalWrite(greenLedPin, HIGH); // Mosiga ang Green LED
    Serial.println("Gate is Open");
    delay(250); // Delay gamay para sa stability
  }

  delay(10); // Simulation stability
}