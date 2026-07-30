int led1 = 3;
int led2 = 5;
int led3 = 6;

int ldr = 7;           // LDR digital pin
int ir1 = 9;
int ir2 = 12;
int ir3 = 11;

void setup()
{
  // set LED pins as output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // set sensor pins as input
  pinMode(ldr, INPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);

  // start Serial Monitor
  Serial.begin(9600);
}

void loop()
{
  int ldrValue = digitalRead(ldr);   // read LDR (0 = dark, 1 = light)
  int irValue1 = digitalRead(ir1);
  int irValue2 = digitalRead(ir2);
  int irValue3 = digitalRead(ir3);

  // print LDR value for testing
  Serial.println(ldrValue);

  if (ldrValue == HIGH)
  {
    // check each IR sensor

    if (irValue1 == LOW)   // object detected
      digitalWrite(led1, HIGH);
    else
      digitalWrite(led1, LOW);

    if (irValue2 == HIGH)
      digitalWrite(led2, HIGH);
    else
      digitalWrite(led2, LOW);

    if (irValue3 == HIGH)
      digitalWrite(led3, HIGH);
    else
      digitalWrite(led3, LOW);
  }
  else
  {
    // turn off all LEDs
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }

  // small delay to make readings and LED behaviour stable
  delay(100);
}
