
void setup()
{
  pinMode(5, INPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void optimizeLight(){
  int pir = digitalRead(5);

  if(pir == 1){
    digitalWrite(2, HIGH);
    Serial.print("PIR reading:");
    Serial.println(pir);
    delay(100);
  } else {
    digitalWrite(2, LOW);
    Serial.print("PIR reading:");
    Serial.println(pir);
    delay(100);
  }
}


void loop()
{
  optimizeLight();
}
