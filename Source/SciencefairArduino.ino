// intiailize variables
  #define StringF 5
  #define StringB 6
  int turning; // stores the number for the string that needs to be turned at which way


  /*
  setup function
  */
  void setup()
  {
    // intialize pins for E string
    pinMode(StringF,OUTPUT); 
    pinMode(StringB,OUTPUT);
      Serial.begin(9600);
  }

  /*
  fucntion that turns the motor clockwise for .05 seconds
  parameter= string that will be turned 
  */
  void clockwise(int string)
  {
    analogWrite(string, 120);
    delay(10);
    analogWrite(string,0); 
  }

  /*
  fucntion that turns the motor counter-clockwise for .05 seconds
  parameter= string that will be turned 
  */
  void counterclockwise(int string)
  {
    analogWrite(string,120); 
    delay(10);
    analogWrite(string,0);  
  }

  /*
  loop function
  */
  void loop()
  {
    int temp=0;
    flush_rx();
    delay(1);
if(Serial.available() > 0)
  {
   temp=Serial.read(); 
  }
  turning=(int)temp;
  turning=turning-48;
  
    if(turning==1)
    {
      counterclockwise(StringB);         // turns E string counter-clockwise
    }
    if(turning==2)
    {
      clockwise(StringF);                // turns E string clockwise
    }
  
  }// end of loop function
