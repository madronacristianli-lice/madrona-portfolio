// C++ code
// Automatic Night Light / LDR Sensor Control
//

int lightLevel = 0;
int threshold = 500; // Adjusted value: Mas ubos sa 500 = Ngitngit (Gabi-i)

void setup()
{
  pinMode(A0, INPUT);
  pinMode(LED_BUILTIN, OUTPUT); // O i-change sa laing pin, e.g., pinMode(13, OUTPUT);
  Serial.begin(9600);           // Para makita ang reading sa Serial Monitor
}

void loop()
{
  lightLevel = analogRead(A0); // Basahon ang lebel sa suga
  Serial.println(lightLevel);  // I-print ang lebel sa suga

  // KUNG NGITNGIT (ubos sa threshold) -> MOSIGA ANG LED
  if (lightLevel < threshold) {
    digitalWrite(LED_BUILTIN, HIGH);
  } 
  // KUNG HAYAG (labaw sa threshold) -> MAPALONG ANG LED
  else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(100); // Gamay nga pause para sa stability
}