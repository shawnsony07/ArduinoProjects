#define R_A 7
#define R_B 8
#define L_A 9
#define L_B 10
#define ENA 6
#define ENB 11
int pin;
int i;
char data;
int duration;
int distance;
void forward(){
 digitalWrite(R_A,HIGH);
 digitalWrite(R_B,LOW);
 digitalWrite(L_A,HIGH);
 digitalWrite(L_B,LOW);
 analogWrite(ENA,1023);
 analogWrite(ENB,1023);
 }
 void backward(){
 digitalWrite(R_A,LOW);
 digitalWrite(R_B,HIGH);
 digitalWrite(L_A,LOW);
 digitalWrite(L_B,HIGH);
 analogWrite(ENA,1023);
 analogWrite(ENB,1023);
 }
 void brakes(){
 digitalWrite(R_A,LOW);
 digitalWrite(R_B,LOW);
 digitalWrite(L_A,LOW);
 digitalWrite(L_B,LOW);
 analogWrite(ENA,0);
 analogWrite(ENB,0);
 
 } 
 void Right(){
 digitalWrite(R_A,LOW);
 digitalWrite(R_B,HIGH);
 digitalWrite(L_A,HIGH);
 digitalWrite(L_B,LOW);
 analogWrite(ENA,1023);
 analogWrite(ENB,1023);
 
 
 }
 void Left(){
 digitalWrite(R_A,HIGH);
 digitalWrite(R_B,LOW);
 digitalWrite(L_A,LOW);
 digitalWrite(L_B,HIGH);
 analogWrite(ENA,1023);
 analogWrite(ENB,1023);
 
 }
 


void setup() {
 Serial.begin(9600);
 pinMode(R_A,OUTPUT);
 pinMode(R_B,OUTPUT);
 pinMode(ENA,OUTPUT);
 pinMode(L_A,OUTPUT);
 pinMode(L_B,OUTPUT);
 pinMode(ENB,OUTPUT);
 analogWrite(ENA,0);
 analogWrite(ENB,0);
 
 
 brakes();

}

void loop() {
  if (Serial.available()){
    data = Serial.read();
  

  switch(data){
    case 'F':forward();
    break;

    case 'B':backward();
    break;

    case 'S':brakes();
    break;

    case 'R':Right();
    break;

    case 'L':Left();
    break;

    
    

    

  default :break;
  }
 
 }
}

 
