//declaramos el potenciometro, y los pines de los led
const int POTENCIOMETRO = 0;
const int led1=2;
const int led2=3;
const int led3=4;
const int led4=5;
const int led5=6;
const int led6=7;
const int led7=8;
const int led8=9;

const int PushButton=A2;
int val = 0; // almacenar el estado del boton
int state = 0; 
int old_val = 0; 
int intensidad;
int input;
int i=0;


void setup(){
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(led5,OUTPUT);
pinMode(led6,OUTPUT);
pinMode(led7,OUTPUT);
pinMode(led8,OUTPUT);
pinMode(PushButton,INPUT);
Serial.begin(9600);
}


void loop(){
pinMode(led1,HIGH);
pinMode(led2,HIGH);
pinMode(led3,HIGH);
pinMode(led4,HIGH);
pinMode(led5,HIGH);
pinMode(led6,HIGH);
pinMode(led7,HIGH);
pinMode(led8,HIGH);
    
val=digitalRead(PushButton);
if(val ==LOW){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    digitalWrite(led5,HIGH);
    digitalWrite(led6,HIGH);
    digitalWrite(led7,HIGH);
    digitalWrite(led8,HIGH);
}
    
if ((val == HIGH) && (old_val == LOW)){
  
state=1-state;
delay(10);
}

if  (state==1){
  
  int valorport=0;
  valorport= analogRead(POTENCIOMETRO);
  intensidad = map(valorport,0,1023,0,255);
  for(i=2; i<10;i++){
        analogWrite(i,intensidad);
      }
    
    delay(25);
    
}
if (Serial.available()>0){
 
    input=Serial.read();
 
    if (input=='2'){
      for(i=2; i<10;i++){
        digitalWrite(i,HIGH);
      }
      delay(2000);
     for(i=2; i<10;i++){
        digitalWrite(i,LOW);
      }
      delay(2000);
    }
}
}