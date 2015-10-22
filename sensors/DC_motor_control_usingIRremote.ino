#include <IRremote.h>

int RECV_PIN = 13;
int before_led;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  //Enable pin
  pinMode(3, OUTPUT);
  //Input 1 of IC
  pinMode(4, OUTPUT);
  //Input 2 of IC
  pinMode(5, OUTPUT);
}

void loop(){
  //Decode recieved Hex values from TSOP
  if(irrecv.decode(&results)){
    //Printing to Serial Monitor for monitoring/debugging
    Serial.println(results.value, HEX);
    
    //If recieved value == defined value then do this
    if(results.value == 0xC0005A){
     digitalWrite(3, HIGH); 
     digitalWrite(4, HIGH);
     digitalWrite(5, LOW);
    }
    
    
    if(results.value == 0xC0005B){
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
    }
   
    
    else{
      //Else switch on an LED to represent no signal
      //connected to an LED 
      digitalWrite(6,HIGH);
    }
    //resume recieving signal -- works like refresh
    irrecv.resume();
  }
  
}
      
      
      
      
