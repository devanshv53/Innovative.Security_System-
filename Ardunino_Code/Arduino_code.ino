void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(7, INPUT); 
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  
   int val =  digitalRead(7); 
   Serial.println(val);
   if(val){
     digitalWrite(8, HIGH); 
   }
   else{
     
     digitalWrite(8, LOW); 
   }

}
