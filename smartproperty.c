const int ledPin = 13;
const int buzzerPin = 12;
int cm = 0;
 
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void activateAlarm () {
	tone(buzzerPin, 100);
    digitalWrite(ledPin, HIGH);
    delay(100);
 
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
    delay(100);
 
    Serial.println("---- ALARM ACTIVATED ----"); 
}

void deactivateAlarm () {
  	noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
 
    Serial.println("ALARM DEACTIVATED");
}

void activateBuzzerSystem() {
    cm = 0.01723 * readUltrasonicDistance(7, 7);
    Serial.print(cm);
    Serial.println("cm");
    if (cm < 332) {
        activateAlarm();
    }
    else {
        deactivateAlarm();
    }
    delay(100);
}


void setup () {
 
  Serial.begin(9600);
 
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  activateBuzzerSystem();
}