//#include <SoftwareSerial.h>

#include <Wire.h>
#include <Adafruit_MLX90614.h>

#include "DHT.h"

String a, b, c, d, e, f, g;

// Deployment settings: replace these values during commissioning.
// Do not embed database credentials or server-side secrets in firmware.
const char DEVICE_ID[] = "ASC-CR-0001";
const char TELEMETRY_ENDPOINT[] = "https://telemetry.example.invalid/insertrecordGET.php";
const char MOBILE_APN[] = "internet";

#define DHTPIN1 4
#define DHTPIN2 5
#define DHTPIN3 6
#define DHTPIN4 7
#define DHTPIN5 8
#define DHTPIN6 9
#define DHTPIN7 10
#define DHTPIN8 11
#define DHTPIN9 12
#define DHTPIN10 13

#define DHTTYPE DHT22   

DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);
DHT dht3(DHTPIN3, DHTTYPE);
DHT dht4(DHTPIN4, DHTTYPE);
DHT dht5(DHTPIN5, DHTTYPE);
DHT dht6(DHTPIN6, DHTTYPE);
DHT dht7(DHTPIN7, DHTTYPE);
DHT dht8(DHTPIN8, DHTTYPE);
DHT dht9(DHTPIN9, DHTTYPE);
DHT dht10(DHTPIN10, DHTTYPE);

#define IR1 0x5A
#define IR2 0x5B
#define IR3 0x5C
#define IR4 0x5D
#define IR5 0x5E
#define IR6 0x6A
#define IR7 0x6B
#define IR8 0x6C
#define IR9 0x6D
#define IR10 0x6E

Adafruit_MLX90614 mlx;

//SoftwareSerial Serial3(2, 3);  //SIM900 Tx & Rx is connected to Arduino #7 & #8


  float h1, t1;
  float h2, t2;
  float h3, t3;
  float h4, t4;
  float h5, t5;
  float h6, t6;
  float h7, t7;
  float h8, t8;
  float h9, t9;
  float h10, t10;

  String url;

  







void setup() 
{
  Serial.begin(9600);
  
  Serial.println("Program Did Reset");
  Serial.println("Program Did Reset");
  Serial.println("Program Did Reset");
  Serial.println("Program Did Reset");

  
  dht1.begin();
  dht2.begin();
  dht3.begin();
  dht4.begin();
  dht5.begin();
  dht6.begin();
  dht7.begin();
  dht8.begin();
  dht9.begin();
  dht10.begin(); 

  mlx.begin(); 

  pinMode(A0, OUTPUT);//Relay 1
  pinMode(A1, OUTPUT);//Relay 2
  pinMode(A2, OUTPUT);//Relay 3
  pinMode(A3, OUTPUT);//relay 4
  
  Serial3.begin(9600);
 
  Serial.println("Initializing GSM...");

    //Once the handshake test is successful, it will back to OK
  sendATcommand("AT", "OK", 2000);
  sendATcommand("AT+CMGF=1", "OK", 2000);
  //Serial3.print("AT+CMGR=40\r");
    sendATcommand("AT", "OK", 2000);
  sendATcommand("AT+CREG?","+CREG: ", 1000);
  sendATcommand("AT+CMGF=1", "OK", 2000);
  sendATcommand("AT+CLTS=1", "OK", 2000);
  sendATcommand("AT+CLTS?", "OK", 2000);
  sendATcommand("AT&W", "OK", 2000);
  sendATcommand("AT+CCLK?", "OK", 2000);


  //sendDataToServer();
  
}
void loop() 
{

    while(Serial3.available()){
    //Serial.println(Serial3.readString());
    char c = Serial3.read();
  Serial.write(c);
  }
  while(Serial.available())  {
    char c = Serial.read();
    Serial3.write(c);
  }


//Serial.print("Free RAM: ");
//Serial.println(freeMemory());


  Serial.println("Top");

  h1 = dht1.readHumidity(); t1 = dht1.readTemperature();
  h2 = dht2.readHumidity(); t2 = dht2.readTemperature();
  h3 = dht3.readHumidity(); t3 = dht3.readTemperature();
  h4 = dht4.readHumidity(); t4 = dht4.readTemperature();
  h5 = dht5.readHumidity(); t5 = dht5.readTemperature();
  h6 = dht6.readHumidity(); t6 = dht6.readTemperature();
  h7 = dht7.readHumidity(); t7 = dht7.readTemperature();
  h8 = dht8.readHumidity(); t8 = dht8.readTemperature();
  h9 = dht9.readHumidity(); t9 = dht9.readTemperature();
  h10 = dht10.readHumidity(); t10 = dht10.readTemperature();

//  Serial.println("      New Updated Sensor Readings");
//  Serial.print(F("Humidity1: ")); Serial.print(h1); Serial.print(F("%  Temperature1: ")); Serial.print(t1);  Serial.println(F("°C "));
//  Serial.print(F("Humidity2: ")); Serial.print(h2); Serial.print(F("%  Temperature2: ")); Serial.print(t2);  Serial.println(F("°C "));
//  Serial.print(F("Humidity3: ")); Serial.print(h3); Serial.print(F("%  Temperature3: ")); Serial.print(t3);  Serial.println(F("°C "));
//  Serial.print(F("Humidity4: ")); Serial.print(h4); Serial.print(F("%  Temperature4: ")); Serial.print(t4);  Serial.println(F("°C "));
//  Serial.print(F("Humidity5: ")); Serial.print(h5); Serial.print(F("%  Temperature5: ")); Serial.print(t5);  Serial.println(F("°C "));
//  Serial.print(F("Humidity6: ")); Serial.print(h6); Serial.print(F("%  Temperature6: ")); Serial.print(t6);  Serial.println(F("°C "));
//  Serial.print(F("Humidity7: ")); Serial.print(h7); Serial.print(F("%  Temperature7: ")); Serial.print(t7);  Serial.println(F("°C "));
//  Serial.print(F("Humidity8: ")); Serial.print(h8); Serial.print(F("%  Temperature8: ")); Serial.print(t8);  Serial.println(F("°C "));
//  Serial.print(F("Humidity9: ")); Serial.print(h9); Serial.print(F("%  Temperature9: ")); Serial.print(t9);  Serial.println(F("°C "));
//  Serial.print(F("Humidity10: ")); Serial.print(h10); Serial.print(F("%  Temperature10: ")); Serial.print(t10);  Serial.println(F("°C "));


  //Serial.println(F(""));
  
  mlx.AddrSet(IR1); 
//  Serial.print("IR1: ");
//  Serial.print("Ambient = "); 
//  Serial.print(mlx.readAmbientTempC()); 
//  Serial.print("*C\tObject = "); 
//  Serial.print(mlx.readObjectTempC()); 
//  Serial.println("*C");
  mlx.temp1 = mlx.readObjectTempC();
  mlx.Atemp1 = mlx.readAmbientTempC();
  delay(250);
  
  mlx.AddrSet(IR2); 
//  Serial.print("IR2: ");
//  Serial.print("Ambient = "); 
//  Serial.print(mlx.readAmbientTempC()); 
//  Serial.print("*C\tObject = "); 
//  Serial.print(mlx.readObjectTempC()); 
//  Serial.println("*C");
  mlx.temp2 = mlx.readObjectTempC();
  mlx.Atemp2 = mlx.readAmbientTempC();
  delay(250);
  
  mlx.AddrSet(IR3); 
  //Serial.print("IR3: ");
  //Serial.print("Ambient = "); 
  //Serial.print(mlx.readAmbientTempC()); 
  //Serial.print("*C\tObject = "); 
  //Serial.print(mlx.readObjectTempC()); 
  //Serial.println("*C");
  mlx.temp3 = mlx.readObjectTempC();
  mlx.Atemp3 = mlx.readAmbientTempC();
  delay(250);
  
  mlx.AddrSet(IR4); 
  //Serial.print("IR4: ");
  //Serial.print("Ambient = "); 
  //Serial.print(mlx.readAmbientTempC()); 
  //Serial.print("*C\tObject = "); 
  //Serial.print(mlx.readObjectTempC()); 
  //Serial.println("*C");
  mlx.temp4 = mlx.readObjectTempC();
  mlx.Atemp4 = mlx.readAmbientTempC();
  delay(250);
  
  mlx.AddrSet(IR5); 
  //Serial.print("IR5: ");
  //Serial.print("Ambient = "); 
  //Serial.print(mlx.readAmbientTempC()); 
  //Serial.print("*C\tObject = "); 
  //Serial.print(mlx.readObjectTempC()); 
  //Serial.println("*C");
  mlx.temp5 = mlx.readObjectTempC();
  mlx.Atemp5 = mlx.readAmbientTempC();
  delay(250);
  
  mlx.AddrSet(IR6); 
  //Serial.print("IR6: ");
  //Serial.print("Ambient = "); 
  //Serial.print(mlx.readAmbientTempC()); 
  //Serial.print("*C\tObject = "); 
  //Serial.print(mlx.readObjectTempC()); 
  //Serial.println("*C");
  mlx.temp6 = mlx.readObjectTempC();
  mlx.Atemp6 = mlx.readAmbientTempC();
  delay(250);
  
  mlx.AddrSet(IR7); 
  //Serial.print("IR7: ");
  //Serial.print("Ambient = "); 
  //Serial.print(mlx.readAmbientTempC()); 
  //Serial.print("*C\tObject = "); 
  //Serial.print(mlx.readObjectTempC()); 
  //Serial.println("*C");
  mlx.temp7 = mlx.readObjectTempC();
  mlx.Atemp7 = mlx.readAmbientTempC();
  delay(250);
  
  mlx.AddrSet(IR8); 
  //Serial.print("IR8: ");
  //Serial.print("Ambient = "); 
  //Serial.print(mlx.readAmbientTempC()); 
  //Serial.print("*C\tObject = "); 
  //Serial.print(mlx.readObjectTempC()); 
  //Serial.println("*C");
  mlx.temp8 = mlx.readObjectTempC();
  mlx.Atemp8 = mlx.readAmbientTempC();
  delay(250);
  
  mlx.AddrSet(IR9); 
  //Serial.print("IR9: ");
  //Serial.print("Ambient = "); 
  //Serial.print(mlx.readAmbientTempC()); 
  //Serial.print("*C\tObject = "); 
  //Serial.print(mlx.readObjectTempC()); 
  //Serial.println("*C");
  mlx.temp9 = mlx.readObjectTempC();
  mlx.Atemp9 = mlx.readAmbientTempC();
  delay(250);
  
  mlx.AddrSet(IR10); 
  //Serial.print("IR10: ");
  //Serial.print("Ambient = "); 
  //Serial.print(mlx.readAmbientTempC()); 
  //Serial.print("*C\tObject = "); 
  //Serial.print(mlx.readObjectTempC()); 
  //Serial.println("*C");
  mlx.temp10 = mlx.readObjectTempC();
  mlx.Atemp10 = mlx.readAmbientTempC();
  delay(250);



  
  //Serial.print("\n***********Average Temp:"); 
  float averageTemp = (mlx.temp1+mlx.temp2+mlx.temp3+mlx.temp4+mlx.temp5+mlx.temp6+mlx.temp7+mlx.temp8+mlx.temp9+mlx.temp10)/10;
  mlx.avgF=(mlx.temp1+mlx.temp2+mlx.temp3+mlx.temp4+mlx.temp5+mlx.temp6+mlx.temp7+mlx.temp8+mlx.temp9+mlx.temp10)/10;
  //Serial.print("***********\n");
  //Serial.println();

  //Minimum is 4 Degrees celcius and Maximum is 8 Degrees celcius
  if(averageTemp<=24){
    //4 degrees celcius
    //Serial.println("Turn off Cooler");

    digitalWrite(A0, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(A1, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(A2, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(A3, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);                       // wait for a second
  //delay(1000);                       // wait for a second

    
    }else if(averageTemp>=30){
      //8 degrees celcius
      //Serial.println("Turn On Cooler");
      digitalWrite(A0, HIGH);    // turn the LED off by making the voltage LOW
      digitalWrite(A1, HIGH);    // turn the LED off by making the voltage LOW
      digitalWrite(A2, HIGH);    // turn the LED off by making the voltage LOW
      digitalWrite(A3, HIGH);    // turn the LED off by making the voltage LOW
      
      }else{
        //Leave Else blank to let temperature make cycles between the maximum and minimum so that the relay doesnt do vibration switching on a boundary value
        //Serial.println("Temperature is in Normal Range");
        digitalWrite(A0, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(A1, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(A2, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(A3, LOW);    // turn the LED off by making the voltage LOW
        }

        //Serial.println("Send All Sensor Data to Remote Database");
        //Serial.println();
        //Serial.println();


              // Concatenate h1 to h10 into b
  b = String(h1) + "," + String(h2) + "," + String(h3) + "," + String(h4) + "," + 
      String(h5) + "," + String(h6) + "," + String(h7) + "," + String(h8) + "," + 
      String(h9) + "," + String(h10);

  // Concatenate t1 to t10 into c
  c = String(t1) + "," + String(t2) + "," + String(t3) + "," + String(t4) + "," + 
      String(t5) + "," + String(t6) + "," + String(t7) + "," + String(t8) + "," + 
      String(t9) + "," + String(t10);

  // Concatenate mlx_temp1 to mlx_temp10 into d
  d = String(mlx.temp1) + "," + String(mlx.temp2) + "," + String(mlx.temp3) + "," + 
      String(mlx.temp4) + "," + String(mlx.temp5) + "," + String(mlx.temp6) + "," + 
      String(mlx.temp7) + "," + String(mlx.temp8) + "," + String(mlx.temp9) + "," + 
      String(mlx.temp10);

  // Concatenate mlx_temp1 to mlx_temp10 into e
  e = String(mlx.Atemp1) + "," + String(mlx.Atemp2) + "," + String(mlx.Atemp3) + "," + 
      String(mlx.Atemp4) + "," + String(mlx.Atemp5) + "," + String(mlx.Atemp6) + "," + 
      String(mlx.Atemp7) + "," + String(mlx.Atemp8) + "," + String(mlx.Atemp9) + "," + 
      String(mlx.Atemp10);

      
        
    sendDataToServer(); 

      url = "";
      a = "";
      b = "";
      c = "";
      d = "";
      e = "";
      f = "";
      g = "";
      h1=0, t1=0;
      h2=0, t2=0;
      h3=0, t3=0;
      h4=0, t4=0;
      h5=0, t5=0;
      h6=0, t6=0;
      h7=0, t7=0;
      h8=0, t8=0;
      h9=0, t9=0;
      h10=0, t10=0;
      
      mlx.temp1=0;
      mlx.temp2=0;
      mlx.temp3=0;
      mlx.temp4=0;
      mlx.temp5=0;
      mlx.temp6=0;
      mlx.temp7=0;
      mlx.temp8=0;
      mlx.temp9=0;
      mlx.temp10=0;
      mlx.avgF=0;
  
    Serial.println("Bottom");
    delay(60000);
    //setup();
   
    


    



}

















int sendDataToServer()
{

      Serial.println("Overflow");


   
      
      a = DEVICE_ID;
      //b = h1;//mlx.temp6;//3.0;//val;//String(gps.location.lng(), 6); // Longitude in degrees (double)
      //c = h2;//mlx.temp7;//4.0;//AmbTemp;//String(gps.location.lng(), 6); // Longitude in degrees (double)
      //d = h3;//mlx.avgF;//5.0;//oilTemp;//String(gps.location.lng(), 6); // Longitude in degrees (double)
      //e = h4;//mlx.temp10;//1.0;//oilTemp;//String(gps.location.lng(), 6); // Longitude in degrees (double)
      f = h5/2.7;//mlx.temp9;//2.0;//oilTemp;//String(gps.location.lng(), 6); // Longitude in degrees (double)
      g = h6/9.7;//mlx.temp8;//4.0;//oilTemp;//String(gps.location.lng(), 6); // Longitude in degrees (double)

      //https://uhr.fkb.mybluehost.me/website_6a59e8db/insertrecordGET.php?device_id=CR002&dht_humidity=45.5&dht_room_temp=22.1&mlx_Object_temp=23.3&mlx_room_temp=21.0&voltage=3.6&current=1.1
      
      url = TELEMETRY_ENDPOINT;
      url += "?D_id=";
      url += a;
      url += "&d_h=";
      url += b;
      url += "&d_t=";
      url += c;
      url += "&m_Ot=";
      url += d;
      url += "&m_rt=";
      url += e;
      url += "&v=";
      url += f;
      url += "&c=";
      url += g;

     
      
     

      //url = "http://ahmadssd.000webhostapp.com/gpsdata.php?lat=222&lng=222";

      Serial.println(url);    
      delay(300);

//  Serial3.begin(9600);
//  
//    //Once the handshake test is successful, it will back to OK
//  sendATcommand("AT", "OK", 2000);
//  sendATcommand("AT+CMGF=1", "OK", 2000);
//  //Serial3.print("AT+CMGR=40\r");
//    sendATcommand("AT", "OK", 2000);
//  sendATcommand("AT+CREG?","+CREG: ", 1000);
//  sendATcommand("AT+CMGF=1", "OK", 2000);
//  sendATcommand("AT+CLTS=1", "OK", 2000);
//  sendATcommand("AT+CLTS?", "OK", 2000);
//  sendATcommand("AT&W", "OK", 2000);
//  sendATcommand("AT+CCLK?", "OK", 2000);
  

    sendATcommand("AT", "OK", 2000);
    sendATcommand("AT+CREG?","+CREG: ", 1000);
    sendATcommand("AT+CMGF=1", "OK", 2000);
  
    sendATcommand("AT+CFUN=1", "OK", 2000);
    //AT+CGATT = 1 Connect modem is attached to GPRS to a network. AT+CGATT = 0, modem is not attached to GPRS to a network
    sendATcommand("AT+CGATT=1", "OK", 2000);
    //Connection type: GPRS - bearer profile 1
    sendATcommand("AT+SAPBR=3,1,\"Contype\",\"GPRS\"", "OK", 2000);
    //sets the APN settings for your network provider.
    String apnCommand = String("AT+SAPBR=3,1,\"APN\",\"") + MOBILE_APN + "\"";
    sendATcommand(apnCommand.c_str(), "OK", 2000);
    //enable the GPRS - enable bearer 1
    sendATcommand("AT+SAPBR=1,1", "OK", 2000);
    //Init HTTP service
    sendATcommand("AT+HTTPINIT", "OK", 2000);
    sendATcommand("AT+HTTPPARA=\"CID\",1", "OK", 1000);
    //Set the HTTP URL sim800.print("AT+HTTPPARA="URL","http://ahmadssd.000webhostapp.com/gpsdata.php?lat=222&lng=222"\r");
    Serial3.print("AT+HTTPPARA=\"URL\",\"");
    Serial3.print(url);
    delay(1000);
    sendATcommand("\"", "OK", 5000);
    //Set up the HTTP action
    sendATcommand("AT+HTTPACTION=0", "0,200", 5000);
    //Terminate the HTTP service
    sendATcommand("AT+HTTPTERM", "OK", 1000);
    //shuts down the GPRS connection. This returns "SHUT OK".
    sendATcommand("AT+CIPSHUT", "SHUT OK", 1000);
   
  return 1;    
}

int8_t sendATcommand(const char* ATcommand, const char* expected_answer, unsigned int timeout){

    uint8_t x=0,  answer=0;
    char response[100];
    unsigned long previous;

    //Initialice the string
    memset(response, '\0', 100);
    delay(100);
   
    //Clean the input buffer
    while( Serial3.available() > 0) Serial3.read();
   
    if (ATcommand[0] != '\0'){
      //Send the AT command
      Serial3.println(ATcommand);
    }

    x = 0;
    previous = millis();

    //this loop waits for the answer with time out
    do{
        //if there are data in the UART input buffer, reads it and checks for the asnwer
        if(Serial3.available() != 0 && x < sizeof(response) - 1){
            response[x] = Serial3.read();
            //Serial.print(response[x]);
            x++;
            response[x] = '\0';
            // check if the desired answer (OK) is in the response of the module
            if(strstr(response, expected_answer) != NULL){
                answer = 1;
            }
        }
    }while((answer == 0) && ((millis() - previous) < timeout));

  Serial.println(response);
  return answer;
}



extern int __heap_start, *__brkval;
int freeMemory() {
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
