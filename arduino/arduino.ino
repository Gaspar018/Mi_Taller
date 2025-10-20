int rele1Pin = 7; 
int rele2Pin = 8; 

void setup() {
  Serial.begin(9600);
  pinMode(rele1Pin, OUTPUT);
  pinMode(rele2Pin, OUTPUT);
  digitalWrite(rele1Pin, LOW);
  digitalWrite(rele2Pin, LOW);
}

void loop() {
  if (Serial.available()) {
    String comando = Serial.readStringUntil('\n');
    comando.trim(); 

    if (comando == "ON1") digitalWrite(rele1Pin, HIGH);
    else if (comando == "OFF1") digitalWrite(rele1Pin, LOW);
    else if (comando == "ON2") digitalWrite(rele2Pin, HIGH);
    else if (comando == "OFF2") digitalWrite(rele2Pin, LOW);
  }
}
