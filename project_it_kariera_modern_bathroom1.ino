int infraredSensor=3;
int tissueDispenser = 11;
int dcFan = 10;
int slideSwitch= 13;
int slideSwitchOn=1;
int lightbulb = 9;


void setup()
{
  pinMode(infraredSensor, INPUT);
  pinMode(tissueDispenser, OUTPUT);
  pinMode(dcFan, OUTPUT);  
  pinMode(slideSwitch,INPUT);
  pinMode(lightbulb, OUTPUT);
}

void loop()
{ 
	slideSwitchFunc();  
  
  	paperDispenser();
}


void slideSwitchFunc(){
  
int read= digitalRead(slideSwitch);
  if(read==1){
    analogWrite(dcFan,1020);
    analogWrite(lightbulb,1020);
  }else
  {
  	analogWrite(dcFan,0);
    analogWrite(lightbulb,0);
  }
}


void paperDispenser(){
if(digitalRead(infraredSensor)){
   analogWrite(tissueDispenser,20);
   delay(1500);
   analogWrite(tissueDispenser,0);
   delay(3500);//delay mejdu sledvashtoto puskane na hartiqta
  }else{
  analogWrite(tissueDispenser,0);
  }
}
