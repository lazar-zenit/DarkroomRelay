int dugme=0;
int dugme2=0;
int brojac=0;
int vreme_sek=0;
int potenc;
int count;
void setup() {
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);

pinMode(8, OUTPUT);

pinMode(11, INPUT);

pinMode(12, OUTPUT);



Serial.begin(9600);


  
}
void loop() {
  dugme2=digitalRead(11);
  if (dugme2 == HIGH){
    vreme_sek++;                  // increment buttonPresses count
    delay(250);  // debounce switch
  }
  Serial.println(vreme_sek);
  if((vreme_sek % 2) > 0) { digitalWrite(2, HIGH); } else { digitalWrite(2, LOW); }
  if((vreme_sek % 4) > 1) { digitalWrite(3, HIGH); } else { digitalWrite(3, LOW); }
  if((vreme_sek % 8) > 3) { digitalWrite(4, HIGH); } else { digitalWrite(4, LOW); }
  if((vreme_sek % 16) > 7) { digitalWrite(5, HIGH); } else { digitalWrite(5, LOW); }
  if((vreme_sek % 32) > 15) { digitalWrite(6, HIGH); } else { digitalWrite(6, LOW); }
  if((vreme_sek % 64) > 31) { digitalWrite(7, HIGH); } else { digitalWrite(7, LOW); }
  
  int vreme_msek=vreme_sek*1000;

  dugme=digitalRead(9);
  count=vreme_sek;

  
  if (dugme==HIGH){ 
    digitalWrite(8, HIGH);
    delay(vreme_msek);
    digitalWrite(8, LOW);
  }
  
  }
 
  
  
  
  


 

  

  
