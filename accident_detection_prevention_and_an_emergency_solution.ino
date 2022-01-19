#include <SoftwareSerial.h>

//Gps
#include <TinyGPS++.h>
SoftwareSerial ss(10,11);
TinyGPSPlus gps;
String lng = "", lat = "";

//Sim module ---------------------------------------------------
SoftwareSerial sim800l(8, 9);

// L298N motor drive
#define in1 2 
#define in2 3
#define in3 4
#define in4 5

int command; //Int to store app command state.
int Speed = 204; // 0 - 255.
int Speedsec;
int buttonState = 0;
int lastButtonState = 0;
int Turnradius = 0; //Set the radius of a turn, 0 - 255 Note:the robot will malfunction if this is higher than int Speed.
int brakeTime = 45;
int brkonoff = 1; //1 for the electronic braking system, 0 for normal.

// Ultra sonic start ----------------------------------------------------
#define echoPin 6
#define trigPin 7
long duration;
int distance; 
// Ultra sonic end   ----------------------------------------------------

// MQ3 sensor start ----------------------------------------------------
int alcholValue = 0;
// MQ3 sensor end   ----------------------------------------------------

//Vibrator sensor -------------------------------------
#define vibratorPin 13
int vibratorValue=0;

void setup() {
  Serial.begin(9600); 
  sim800l.begin(9600);
  ss.begin(9600); 
  
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Ultra sonic start ----------------------------------------------
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // Ultra sonic end ----------------------------------------------

  //Vibrator --------------------------------
  pinMode(vibratorPin,INPUT);

  //Sim800l ----------------------------------------------------
  
  
  //callNumber(sendto);
}

void loop() {

  if (sim800l.available()) {
    Serial.write(sim800l.read());
  }
  if (Serial.available()) {
    sim800l.write(Serial.read());
  }

  ultraSonic();
  mq3Gas();
  bluetoothSerial();
  gpsNeo6m();

  vibratorValue = digitalRead(vibratorPin);
  //Serial.println(vibratorValue);
  if(vibratorValue==0) {
    Serial.println(F("Vribrated"));
    SendSMS();
    //vibratorValue = 0;

    Stop();
  }

//  if (sim800l.available()){
//    Serial.write(sim800l.read()); 
//  }
  
}

void bluetoothSerial() {
  if (Serial.available() > 0 && alcholValue < 400) {
    command = Serial.read();
    Stop(); //Initialize with motors stoped.
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'G':
        forwardleft();
        break;
      case 'I':
        forwardright();
        break;
      case 'H':
        backleft();
        break;
      case 'J':
        backright();
        break;
      case '0':
        Speed = 100;
        break;
      case '1':
        Speed = 140;
        break;
      case '2':
        Speed = 153;
        break;
      case '3':
        Speed = 165;
        break;
      case '4':
        Speed = 178;
        break;
      case '5':
        Speed = 191;
        break;
      case '6':
        Speed = 204;
        break;
      case '7':
        Speed = 216;
        break;
      case '8':
        Speed = 229;
        break;
      case '9':
        Speed = 242;
        break;
      case 'q':
        Speed = 255;
        break;
    }
    Speedsec = Turnradius;
    if (brkonoff == 1) {
      brakeOn();
    } else {
      brakeOff();
    }
  }else if (alcholValue > 400) {
    Stop();
  }
}

void forward() {
  if(distance >= 30) {
     analogWrite(in1, Speed);
     analogWrite(in3, Speed); 
  }
}

void back() {
  analogWrite(in2, Speed);
  analogWrite(in4, Speed);
}

void left() {
  analogWrite(in3, Speed);
  analogWrite(in2, Speed);
}

void right() {
  analogWrite(in4, Speed);
  analogWrite(in1, Speed);
}
void forwardleft() {
  analogWrite(in1, Speedsec);
  analogWrite(in3, Speed);
}
void forwardright() {
  analogWrite(in1, Speed);
  analogWrite(in3, Speedsec);
}
void backright() {
  analogWrite(in2, Speed);
  analogWrite(in4, Speedsec);
}
void backleft() {
  analogWrite(in2, Speedsec);
  analogWrite(in4, Speed);
}

void Stop() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
}

void brakeOn() {
  //Here's the future use: an electronic braking system!
  // read the pushbutton input pin:
  buttonState = command;
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == 'S') {
      if (lastButtonState != buttonState) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, HIGH);
        delay(brakeTime);
        Stop();
      }
    }
    // save the current state as the last state,
    //for next time through the loop
    lastButtonState = buttonState;
  }
}

void brakeOff() {}

void ultraSonic() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
//  Serial.print("UltraSonic: ");
// Serial.print(distance);
// Serial.println(" cm");
}

void mq3Gas() {
  alcholValue = analogRead(A1);
//  Serial.print("MQ3: ");
  //Serial.println(alcholValue);
  // MQ3 sensor end
}

float gpslat, gpslon;

void gpsNeo6m() {
  while (ss.available() > 0){
    //Serial.write(ss.read());
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      Serial.write("Latitude= "); 
      lat = String(gps.location.lat(), 6);
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= "); 
      lng = String(gps.location.lng(), 6);
      Serial.println(gps.location.lng(), 6);
    }
    //Serial.println(gps.location.lng(), 6);
  }
//  ss.listen();
//  while (ss.available()) {
//    int c = ss.read();
//    if (gps.encode(c)) {
//      gps.f_get_position(&gpslat, &gpslon);
//    }
//  }
}

void SendSMS()
{

  String arr[1];
  arr[0] = "AT+CMGS=\"+8801726920703\"\r";
//  arr[1] = "AT+CMGS=\"+8801749651289\"\r";
//  arr[2] = "AT+CMGS=\"+8801883903436\"\r";
//  arr[3] = "AT+CMGS=\"+8801637580263\"\r";

  String number = arr[random(0, 1)];

  
  Serial.println("Sending SMS...");     
  sim800l.print("AT+CMGF=1\r");  
  delay(100);
  sim800l.print(number); 
  delay(500);

  sim800l.print("An accident occured at location ");
  sim800l.print("https://www.google.com/maps/?q=");
  sim800l.print(lat);
  sim800l.print(",");
  sim800l.print(lng);
  sim800l.print("Please rescue!!");
  delay(500);
  sim800l.print((char)26);// (required according to the datasheet)
  delay(500);
  sim800l.println();
  Serial.println("Text Sent.");
  delay(500);
}




//#include <SoftwareSerial.h>
//
//SoftwareSerial mySerial(8, 9); // RX, TX
//
//void setup() {
//  // put your setup code here, to run once:
//  Serial.begin(9600);
//  mySerial.begin(9600);
//  //pinMode(13, OUTPUT);
//  
//}
//
//void loop() {
//
//  mySerial.print("AT+SAPBR=3,1,\"Contype\",\"GPRS\"﻿\r"); 
//  mySerial.print("AT+CSTT=\"internet\",\"internet\",\"internet\"﻿\r"); 
//  mySerial.print("AAT+SAPBR=1,1﻿﻿\r"); 
//  mySerial.print("AT+SAPBR=2,1﻿﻿\r"); 
//  mySerial.print("AT+HTTPINIT﻿\r"); 
//  mySerial.print("AT+HTTPSSL=1﻿﻿\r"); 
//  mySerial.print("AT+HTTPPARA=\"CID\",1﻿﻿\r"); 
//  mySerial.print("AT+HTTPPARA=\"URL\",\"https://find-nearest-hospital-bd.herokuapp.com/main/v1/loc?lat=23.7869245&lng=90.3774381\"\r"); 
//  mySerial.print("AT+HTTPACTION=0﻿\r"); 
//  mySerial.print("AT+HTTPREAD");
//  mySerial.print("AT+HTTPTERM"); 
//  
//
//
////  mySerial.print("AT+SAPBR=3,1\"APN\",\"CMNET\"\r"); 
////  mySerial.print("AT+SAPBR=1,1\r"); 
////  mySerial.print("AT+SAPBR=2,1\r"); 
////  mySerial.print("AT+HTTPINIT\r"); 
////  mySerial.print("AT+HTTPPARA=\"CID\",1\r"); 
////  mySerial.print("AT+HTTPPARA=\"https://find-nearest-hospital-bd.herokuapp.com/main/v1/loc?lat=23.7869245&lng=90.3774381\"\r"); 
////  mySerial.print("AT+HTTPACTION=0\r"); 
////  mySerial.print("AT+HTTPREAD\r"); 
////  mySerial.print("AT+HTTPTERM\r"); 
////  mySerial.print("AT+SAPBR=0,1\r"); 
//  
//}
