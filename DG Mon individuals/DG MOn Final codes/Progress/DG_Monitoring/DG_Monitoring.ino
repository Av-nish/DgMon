#define VIN 34 

float getVPP()
{
  float result;
  int readValue;            
  int maxValue = 0;          
  int minValue = 1024;          
  
   uint32_t start_time = millis();
   while((millis()-start_time) < 25)  //sample for 25ms
   {
       readValue = analogRead(VIN);
       
       if (readValue > maxValue) 
       {
           
           maxValue = readValue;
       }
       if (readValue < minValue) 
       {
           
           minValue = readValue;
       }
   }
   
   
   result = (maxValue - minValue)/2;
      
   return result;
 }

void setup() {
    Serial.begin(9600);
    Serial.println("Started");
    Serial.println();
}

void loop() {

  int i = 0;
  float x = 0;
  while (i < 50)
  {
      x += getVPP();
      i++;
  }
x /= 50;

//Serial.println(getVPP());
x -= 980.52;
Serial.print(x);
Serial.print("  , I = ");
Serial.println(((x +13.177)/0.0758)/1000);
 
}
