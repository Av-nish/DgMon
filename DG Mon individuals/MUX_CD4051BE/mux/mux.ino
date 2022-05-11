int x = 0;


void setup() {
  Serial.begin(9600);
  Serial.println("Started");

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

}

void loop() {

  digitalWrite(5, LOW);                      // 0
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);

  x = analogRead(A0);  
  Serial.print("Channel A : ");
  Serial.println(x);

  //delay(10);

  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);                    // 1
  digitalWrite(7, LOW);

  x = analogRead(A0);  
  Serial.print("Channel B : ");
  Serial.println(x);

  //delay(10);

  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);                           // 2
  digitalWrite(7, LOW);
  x = analogRead(A0);  
  Serial.print("Channel C : ");
  Serial.println(x);

  //delay(10);


  digitalWrite(5, HIGH);                      //3
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);

  x = analogRead(A0);  
  Serial.print("Channel D : ");
  Serial.println(x);

 // delay(10);

  digitalWrite(5, LOW);
  digitalWrite(6, LOW);                    // 4
  digitalWrite(7, HIGH);

  x = analogRead(A0);  
  Serial.print("Channel E : ");
  Serial.println(x);

  //delay(10);

  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);                           // 5
  digitalWrite(7, HIGH);

  x = analogRead(A0);  
  Serial.print("Channel F : ");
  Serial.println(x);

 // delay(10);

  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);                    // 6
  digitalWrite(7, HIGH);

  x = analogRead(A0);  
  Serial.print("Channel G : ");
  Serial.println(x);

  //delay(10);

  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);                           // 7
  digitalWrite(7, HIGH);

  x = analogRead(A0);  
  Serial.print("Channel H : ");
  Serial.println(x);

  //delay(10);
  
  

 
}
