#define PIR_2 A0
#define PIR_1 A1
#define PIR_P2 11
#define PIR_P1 12
#define Relay  7
#define IR_2 A2
#define IR_P2 8
#define IR_1 A3
#define IR_P1 9
int count_1=0;
int count_2=0;
int lightState=0;
void setup(){
  Serial.begin(9600);
  pinMode(PIR_P1,OUTPUT);
  pinMode(PIR_P2,OUTPUT);
  pinMode(PIR_1,INPUT);
  pinMode(PIR_2,INPUT);
  pinMode(Relay,OUTPUT);
  pinMode(IR_1,INPUT);
  pinMode(IR_P1,OUTPUT);
  pinMode(IR_2,INPUT);
  pinMode(IR_P2,OUTPUT);
  digitalWrite(PIR_P1,HIGH);
  digitalWrite(PIR_P2,HIGH);
  digitalWrite(Relay,HIGH);
  digitalWrite(IR_P1,HIGH);
  digitalWrite(IR_P2,HIGH);
 
}
void loop(){
 
  if(digitalRead(IR_1)==0){
    digitalWrite(IR_P2,LOW);
    delay(1500);
    digitalWrite(IR_P2,HIGH);
    count_1++;
    digitalWrite(Relay,LOW);
    Serial.print("Count_1");
    Serial.println(count_1);
    lightState=1;
    
 }
else if(digitalRead(IR_2)==0){
  if(lightState==1){
   delay(1500);
   count_2++;
  Serial.print("Count_2");
  Serial.println(count_2);
  
  }
 
 
 if(count_1==count_2){
    count_1=0;
    count_2=0;
    digitalWrite(Relay,HIGH);
   lightState=0;
   
  
  
   } 
  

 }

}
   
  
  
   
   
   

  
  
      
    


     
    
    
    

  
 

  
  
   
 

  
