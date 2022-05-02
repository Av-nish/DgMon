int x = 0;


void setup() {
  Serial.begin(9600);
  Serial.println("Started");

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

}

void loop() {

  /*digitalWrite(5, LOW);                      // 0  V_R
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  int y = 0;

  for (int i = 0; i < 10000; i ++)
  {
      x = analogRead(A0);  
      if (x > y)
      {
        y = x;
      }
  }
  Serial.print("Channel A : ");
  Serial.println(y*0.243203);
  //Serial.println(y);
  delay(10);
*/


 /*digitalWrite(5, HIGH);
  digitalWrite(6, LOW);                    // 1  V_Y
  digitalWrite(7, LOW);

  int y = 0;
  for (int i = 0; i < 10000; i ++)
  {
      x = analogRead(A0);  
      if (x > y)
      {
        y = x;
      }
  }
  
  Serial.print("Channel B : ");
  //Serial.println(y);
  Serial.println(y * 0.24475);


  delay(10);
*/

  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);                           // 2
  digitalWrite(7, LOW);
  int y = 0;
    for (int i = 0; i < 10000; i ++)
    {
        x = analogRead(A0);  
        if (x > y)
        {
          y = x;
        }
    }
  
  Serial.print("Channel C : ");
  //Serial.println(y);
  Serial.println(y * 0.24475);


  delay(10);


//
//  digitalWrite(5, HIGH);                      //3
//  digitalWrite(6, HIGH);
//  digitalWrite(7, LOW);
//
//  x = analogRead(A0);  
//  Serial.print("Channel D : ");
//  Serial.println(x);
//
// // delay(10);
//
//  digitalWrite(5, LOW);
//  digitalWrite(6, LOW);                    // 4
//  digitalWrite(7, HIGH);
//
//  x = analogRead(A0);  
//  Serial.print("Channel E : ");
//  Serial.println(x);
//
//  //delay(10);
//
//  digitalWrite(5, HIGH);
//  digitalWrite(6, LOW);                           // 5
//  digitalWrite(7, HIGH);
//
//  x = analogRead(A0);  
//  Serial.print("Channel F : ");
//  Serial.println(x);
//
// // delay(10);
//
//  digitalWrite(5, LOW);
//  digitalWrite(6, HIGH);                    // 6
//  digitalWrite(7, HIGH);
//
//  x = analogRead(A0);  
//  Serial.print("Channel G : ");
//  Serial.println(x);
//
//  //delay(10);
//
//  digitalWrite(5, HIGH);
//  digitalWrite(6, HIGH);                           // 7
//  digitalWrite(7, HIGH);
//
//  x = analogRead(A0);  
//  Serial.print("Channel H : ");
//  Serial.println(x);
//
//  //delay(10);
//  
  

 
}
