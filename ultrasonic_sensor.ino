const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
int led_us=13;
int buz=12;
void setup() {
  pinMode(led_us,OUTPUT);
  pinMode(buz,OUTPUT);
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   
   if(cm >= 15){
    Serial.print("****NO VECHILE DETECTED******");
   //Serial.print(inches);
  // Serial.print("in, ");
  // Serial.print(cm);
   //Serial.print("cm");
   Serial.println();
    delay(1000);
   }
   else{
     Serial.print("*************DANGER ALERT*******");
     Serial.println();                                                                          
     digitalWrite(led_us, HIGH);
     digitalWrite(buz,HIGH);
     delay(100);
     digitalWrite(led_us,LOW);
     digitalWrite(buz,LOW);
     delay(100);
   }
   
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
