// C++ code
// Toggle Christmas Light & Buzzer System
//

const int buttonPin = 2;   // Push Button
const int led1 = 11;       // LED 1
const int led2 = 12;       // LED 2
const int led3 = 13;       // LED 3
const int buzzerPin = 8;   // Buzzer

bool systemOn = false;     // Mutrack kung NAKASIGA (true) o NAKAPALONG (false)
int lastButtonState = LOW;

void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  int reading = digitalRead(buttonPin);

  // Mopukaw lang kung bag-ong pisa/click sa button (Button Press Edge Detection)
  if (reading == HIGH && lastButtonState == LOW) {
    systemOn = !systemOn; // I-toggle ang state (ON maging OFF, OFF maging ON)
    delay(200);           // Debounce delay para dili mag-double press
  }
  lastButtonState = reading;

  // KUNG NAKA-ON ANG SYSTEM:
  if (systemOn) {
    Serial.println("Merry Christmas!");

    // Step 1: Siga LED 1 & LED 3, Sound Tone 1
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    tone(buzzerPin, 659, 150); // Tone E5
    delay(200);

    if (!checkOff()) return; // Fast check kung gi-pisa ba ang button ring ikalampag

    // Step 2: Siga LED 2, Sound Tone 2
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    tone(buzzerPin, 523, 150); // Tone C5
    delay(200);
  } 
  // KUNG NAKA-OFF ANG SYSTEM:
  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    noTone(buzzerPin); // Palungon ang sound sa buzzer
  }
}

// Function para dali ra ma-detect ang pagpalong maskin nag-delay
bool checkOff() {
  if (digitalRead(buttonPin) == HIGH) {
    systemOn = false;
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    noTone(buzzerPin);
    delay(300);
    return false;
  }
  return true;
}