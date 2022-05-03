#include "DgMon.h"

DgMon::DgMon() // parameters int _ir, int _iy, int _ib, int _vr, int _vy, int _vb, int _t, int _dc1, int _dc2 , int _lvlEcho, int _lvlTrig, int _rpm, int _vib, int _pressure, int _aCo, int _dCo
{
    // Declare Pin Numbers and constants for DG-Mon sensors.

    int vibr_Pin = 2;            //   Vibration sensor

    // For DC Voltage
    int DcV_1 = A2;              // DC1 
    int DcV_2 = A3;              // DC2  
    float adc_voltage = 0.0;
    float in_voltage = 0.0;

    // For DC Voltage

    float R1 = 30000.0;         
    float R2 = 7500.0; 

    float ref_voltage = 5.0;
    int adc_value = 0;

    // For Fuel Level
    #define trigPin 3
    #define echoPin 9

    long duration;
    int distance;

    //For Temperature
    #define ONE_WIRE_BUS 4
    OneWire oneWire(ONE_WIRE_BUS);          // Setup a oneWire instance to communicate with any OneWire devices  
    DallasTemperature sensors(&oneWire);
    float myTemperature;

    //For AC Current
    int mVperAmp = 185;           // this the 5A version of the ACS712 -use 100 for 20A Module and 66 for 30A Module
    int Watt = 0;
    double Voltage = 0;
    double VRMS = 0;
    double AmpsRMS = 0;


    // size of buffer used to capture HTTP requests
    #define REQ_BUF_SZ   50

    // MAC address from Ethernet shield sticker under board
    byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

    //IPAddress ip(10, 10, 28, 9); // final on call - 20 April 2022
    //255.255.252.0  subnet use if not working - 20 April 2022
    IPAddress ip(169, 254, 179, 115); // My PC
    //IPAddress ip(10, 10, 76, 9); // C3I Office


    EthernetServer server(80);  // create a server at port 80
    File webFile;               // the web page file on the SD card
    char HTTP_req[REQ_BUF_SZ] = {0}; // buffered HTTP request stored as null terminated string
    char req_index = 0;              // index into HTTP_req buffer


    // declare the  I/O pinMode here.
    pinMode(notSure, OUTPUT);
    pinMode(notSure, INPUT);    

    // initialize variables 
    ir = _ir, iy = _iy, ib = _ib, vr = _vr, vy = _vy, vb = _vb, t = _t, dc1 = _dc1, dc2 = _dc2 , lvlEcho = _lvlEcho, lvlTrig = _lvlTrig, rpm = _rpm, vib = _vib, pressure = _pressure, _aCo = _aCo, dCo = _dCo;
}

void DgMon::init()
{
    // disable Ethernet chip
    pinMode(10, OUTPUT);
    digitalWrite(10, HIGH);

    Serial.begin(9600);       // for debugging
        
        //initialize SD card
    Serial.println("Initializing SD card...");
    if (!SD.begin(4)) {
        Serial.println("ERROR - SD card initialization failed!");
        return;    // init failed
        }
    Serial.println("SUCCESS - SD card initialized.");
    // check for index.htm file
    if (!SD.exists("index.htm")) {
        Serial.println("ERROR - Can't find index.htm file!");
        return;  // can't find index file
        }
    Serial.println("SUCCESS - Found index.htm file.");
    
    Ethernet.begin(mac, ip ); // start the Ethernet connection and the server:
    
    if (Ethernet.hardwareStatus() == EthernetNoHardware)    // Check for Ethernet hardware present
    {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
        delay(1); // do nothing, no point running without Ethernet hardware
        }
    }
    if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
        }

    // start the server
    server.begin();
    Serial.print("server is at ");
    Serial.println(Ethernet.localIP());          // start to listen for clients

        //Temperature
    sensors.begin();
    pinMode(vibr_Pin, INPUT); //set vibr_Pin input for measurment


    //Fuel Level
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void DgMon::getCurrent()
{
     
}


void DgMon::getVoltage()
{
    
}


void DgMon::getTemperature()
{

}


void DgMon::getDcVoltage
{
    
}


void DgMon::getFuelLevel()
{
    
}


void DgMon::getRPM()
{

}


void DgMon::getVib()
{
    
}


void DgMon::getPressure()
{

}


void DgMon::getCOlevel()
{
    
}

// send the XML file containing analog value
void XML_response(EthernetClient cl)
{
    int analog_val1;
    int analog_val0;
    
    cl.print("<?xml version = \"1.0\" ?>");
    cl.print("<inputs>");
    // read analog pin A1 and A0
    analog_val1 = analogRead(1);
    analog_val0 = analogRead(0);
    cl.print("<analog1>");
    cl.print(analog_val1);
    cl.print("</analog1>"); 
    cl.print("<analog0>");
    cl.print(analog_val0);
    cl.print("</analog0>"); 
    cl.print("</inputs>");
}

// sets every element of str to 0 (clears array)
void StrClear(char *str, char length)
{
    for (int i = 0; i < length; i++) {
        str[i] = 0;
    }
}

// searches for the string sfind in the string str
// returns 1 if string found
// returns 0 if string not found
char StrContains(char *str, char *sfind)
{
    char found = 0;
    char index = 0;
    char len;

    len = strlen(str);
    
    if (strlen(sfind) > len) {
        return 0;
    }
    while (index < len) {
        if (str[index] == sfind[found]) {
            found++;
            if (strlen(sfind) == found) {
                return 1;
            }
        }
        else {
            found = 0;
        }
        index++;
    }

    return 0;
}

float getTemperature(int tempIndex)
{
 sensors.requestTemperatures(); 
 myTemperature = sensors.getTempCByIndex(tempIndex); 
 Serial.println(myTemperature);
 
 // Why "byIndex"?  
 // You can have more than one DS18B20 on the same bus.  
 // 0 refers to the first sensor on the wire 
   delay(1000); 
   return myTemperature; 
} 

int mux(int mux_out)
{
  switch (mux_out)
  {
    int x;
    case 0:
      digitalWrite(5, LOW);                      // 0
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      //delay(10);
      x = analogRead(A0); 
      return x;
      break;

      case 1:
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);                    // 1
      digitalWrite(7, LOW);
      //delay(10);
      x = analogRead(A0);  
      return x;
      break;

      case 2:
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);                           // 2
      digitalWrite(7, LOW);
      //delay(10);
      x = analogRead(A0);  
      return x;
      break;

      case 3:
      digitalWrite(5, HIGH);                      //3
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      //delay(10);
      x = analogRead(A0);  
      return x;
      break;

      case 4:
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);                    // 4
      digitalWrite(7, HIGH);
      //delay(10);
      x = analogRead(A0);  
      return x;
      break;

      case 5:
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);                           // 5
      digitalWrite(7, HIGH);
      //delay(10);
      x = analogRead(A0);  
      return x;
      break;

      case 6:
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);                    // 6
      digitalWrite(7, HIGH);   
      //delay(10); 
      x = analogRead(A0);  
      return x;
      break;
  }
} 

float getVoltage(char c)
{
  float voltage;
  int z = 0;
  int y = 0;

  if (c == 'r')
  {
      for (int i = 0; i < 10000; i ++)
        {
            z = mux(0);  
            if (z > y)
            {
                y = z;
            }
        }
        Serial.print("Channel A : ");
        voltage = y*0.243203;
        Serial.println(voltage);
  delay(10);
  }

  if (c == 'y')
  {
      for (int i = 0; i < 10000; i ++)
        {
            z = mux(1);  
            if (z > y)
            {
                y = z;
            }
        }

        Serial.print("Channel B : ");
        voltage = y / 4.380178;
        Serial.println(voltage);
  }

    if (c == 'b')
  {
      for (int i = 0; i < 10000; i ++)
        {
            z = mux(2);  
            if (z > y)
            {
                y = z;
            }
        }
        Serial.print("Channel C : ");
        voltage = y /4.4295336;
        Serial.println(voltage);
  }

    return voltage;
  
}


long getVibration(){
  delay(10);
  long measurement=pulseIn (vibr_Pin, HIGH);  //wait for the pin to get HIGH and returns measurement
  Serial.println(measurement);
  return measurement;
}


float getDcVoltage(int x)
{
    if (x = 1)
    {
        adc_value = analogRead(DcV_1);
    }
    else
    {
        adc_value = analogRead(DcV_2);
    }
    
   // Determine voltage at ADC input
   adc_voltage  = (adc_value * ref_voltage) / 1024.0; 
   
   // Calculate voltage at divider input
   in_voltage = adc_voltage / (R2/(R1+R2)) ; 
   
   // Print results to Serial Monitor to 2 decimal places
  Serial.print("Input Voltage = ");
  Serial.println(in_voltage, 2);

  return in_voltage;
}


int getFuelHeight()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);

    // Trigger the sensor by setting the trigPin high for 10 microseconds:
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Read the echoPin. pulseIn() returns the duration (length of the pulse) in microseconds:
    duration = pulseIn(echoPin, HIGH);
  
    // Calculate the distance:
    distance = duration*0.0343/2;
  
    // Print the distance on the Serial Monitor (Ctrl+Shift+M):
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(100);
    return distance;
}


double getCurrent(char c)
{

  Voltage = getVPP(c);
  VRMS = (Voltage/2.0) *0.707;   //root 2 is 0.707
  AmpsRMS = (VRMS * 1000)/mVperAmp;
 
  Serial.print(AmpsRMS);
  Serial.print(" Amps RMS  ---  ");
  Watt = (AmpsRMS*240/1.3);      // 1.3 is an empirical calibration factor
  Serial.print(Watt);
  Serial.println(" W");

  return AmpsRMS;
}


float getVPP(char c)
{
  
  float result;
  int readValue;                // value read from the sensor
  int maxValue = 0;             // store max value here
  int minValue = 1024;          // store min value here
  
   uint32_t start_time = millis();
   while((millis()-start_time) < 1000) //sample for 1 Sec
   {
    //    readValue = analogRead(sensorIn);
       if (c == 'r')
        {
            readValue = mux(3);                  // enter channel no
        }  
        if (c == 'y')
        {
            readValue = mux(4);                  // enter channel no
        }  
        if (c == 'b')
        {
            readValue = mux(5);                  // enter channel no
        }  
       // see if you have a new maxValue
       if (readValue > maxValue) 
       {
           /*record the maximum sensor value*/
           maxValue = readValue;
       }
       if (readValue < minValue) 
       {
           /*record the minimum sensor value*/
           minValue = readValue;
       }
   }
   
   // Subtract min from max
   result = ((maxValue - minValue) * 5.0)/1024.0;
      
   return result;
 }