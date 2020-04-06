//button states are 0 in the start
int button1=0;
int button2=0;
//initial time counter is also 0
int time_sec=0;

void setup() {

//pins 2-7 are for LEDs
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);

//pin8 for relay control
pinMode(8, OUTPUT);
//pin11 for counting presses and time input
pinMode(11, INPUT);
//pin 12 for starting relay
pinMode(12, OUTPUT);
//pin10 for indicator LED
pinMode(10, OUTPUT);



Serial.begin(9600);


  
}
void loop() {
  button2=digitalRead(11);
  if (button2 == HIGH){
    time_sec++;   // increment buttonPresses count
    delay(250);  // debounce switch
  }

  //code for making binary number from decimal and turning on specific LEDs
  if((time_sec % 2) > 0) { digitalWrite(2, HIGH); } else { digitalWrite(2, LOW); }
  if((time_sec % 4) > 1) { digitalWrite(3, HIGH); } else { digitalWrite(3, LOW); }
  if((time_sec % 8) > 3) { digitalWrite(4, HIGH); } else { digitalWrite(4, LOW); }
  if((time_sec % 16) > 7) { digitalWrite(5, HIGH); } else { digitalWrite(5, LOW); }
  if((time_sec % 32) > 15) { digitalWrite(6, HIGH); } else { digitalWrite(6, LOW); }
  if((time_sec % 64) > 31) { digitalWrite(7, HIGH); } else { digitalWrite(7, LOW); }
  
  //delay time must be converted to ms
  int time_msec=time_sec*1000;

//pressed button triggers relay. this is for the test, some relays are open when pins are LOW
  button1=digitalRead(9);
  if (button1==HIGH){ 
    digitalWrite(8, HIGH);
    digitalWrite(10, HIGH);
    delay(time_msec);
    digitalWrite(8, LOW);
    digitalWrite(10,LOW);
  }
  
  }
 
  
  
  
  


 

  

  
