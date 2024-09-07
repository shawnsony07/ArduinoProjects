# define trigpin 3
# define echopin 5
# define led_1  A0
# define led_2  A1
# define led_3  A2
# define led_4  A3
int duration;
int distance;
void setup() {
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(led_1,OUTPUT);
  pinMode(led_2,OUTPUT);
  pinMode(led_3,OUTPUT);
  pinMode(led_4,OUTPUT);
  digitalWrite(led_1,LOW);
  digitalWrite(led_2,LOW);
  digitalWrite(led_3,LOW);
  digitalWrite(led_4,LOW);
   
 }

void loop() {
digitalWrite(trigpin,HIGH);
delay(10);
digitalWrite(trigpin,LOW);
duration=pulseIn(echopin,HIGH);
distance=(duration/2)*0.034;
Serial.print( distance);
Serial.println("  cm");
if(distance<15)
{
  digitalWrite(led_1,LOW);
  digitalWrite(led_2,LOW);
  digitalWrite(led_3,LOW);
  digitalWrite(led_4,LOW);
}
else if(distance==15)
{
  digitalWrite(led_1,HIGH);
  digitalWrite(led_2,LOW);
  digitalWrite(led_3,LOW);
  digitalWrite(led_4,LOW);
}
else if(distance==16)
{
  digitalWrite(led_1,HIGH);
  digitalWrite(led_2,HIGH);
  digitalWrite(led_3,LOW);
  digitalWrite(led_4,LOW);
  
}
else if(distance==17)
{
  digitalWrite(led_1,HIGH);
  digitalWrite(led_2,HIGH);
  digitalWrite(led_3,HIGH);
  digitalWrite(led_4,LOW);
  
}
else if(distance==18)
{
  digitalWrite(led_1,HIGH);
  digitalWrite(led_2,HIGH);
  digitalWrite(led_3,HIGH);
  digitalWrite(led_4,HIGH);
}

}
