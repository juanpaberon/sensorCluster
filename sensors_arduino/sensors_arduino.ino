unsigned long lastTime = 0;
unsigned long timerDelay = 5000;
String message = "";
int i = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  if ((millis() - lastTime) > timerDelay) {

    switch (i) {
      case 0:
        message = "Hallo Welt!";
        i++;
        break;
      case 1:
        message = "Hello World!";
        i++;
        break;
      default:
        message = "Hola Mundo!";
        i = 0;
    }
    Serial.println(message);

    lastTime = millis();
  }
}
