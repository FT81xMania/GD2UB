void Leds()
{
  unsigned long currentMillisLED = millis(); 
  if(currentMillisLED - previousMillisLED > intervalLED)
  {
    previousMillisLED = currentMillisLED; 
    digitalWrite(LEDP2,!digitalRead(LEDP2)); //pinMode(LEDP2, OUTPUT); 
    digitalWrite(LEDP1,!digitalRead(LEDP1)); //pinMode(LEDP2, OUTPUT); 
  }
}

void Led1()
{
  digitalWrite(LEDP2,LOW);
  unsigned long currentMillisLED = millis(); 
  if(currentMillisLED - previousMillisLED > 50)
  {
    previousMillisLED = currentMillisLED; 
    //digitalWrite(LEDP2,!digitalRead(LEDP2)); //pinMode(LEDP2, OUTPUT); 
    digitalWrite(LEDP1,!digitalRead(LEDP1)); //pinMode(LEDP2, OUTPUT); 
  }
}

void Led2()
{
  unsigned long currentMillisLED = millis(); 
  if(currentMillisLED - previousMillisLED > 250)
  {
    previousMillisLED = currentMillisLED; 
    options=HIGH;
  }
  else{options=LOW;}
  
  digitalWrite(PG14, options);    
}

