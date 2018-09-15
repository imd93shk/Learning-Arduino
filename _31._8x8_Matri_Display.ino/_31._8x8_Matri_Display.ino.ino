// {0,0,0,0,0,0,0,0},
// {1,1,1,1,1,1,1,1},
#define POT A5

int val = 0;
int displayVal = 0;

// Enter the desired shape here
int data[][8] = {
  {0,0,1,0,0,1,0,0},
  {0,0,1,0,0,1,0,0},
  {1,1,1,1,1,1,1,1},
  {0,0,1,0,0,1,0,0},
  {0,0,1,0,0,1,0,0},
  {1,1,1,1,1,1,1,1},
  {0,0,1,0,0,1,0,0},
  {0,0,1,0,0,1,0,0}
};

void setup() 
{
  Serial.begin(9600);
  
  for (int i=2; i<=9; i++) 
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
        
  }
   for (int j=10; j<=17; j++) 
  {
    pinMode(j, OUTPUT);
    digitalWrite(j, HIGH);
        
  }
}

void loop() 
{
  display();             // Calling Dispaly Function
  
}
  
  
  

  
  
void display()          // Display Function
{
  for (int i=0; i<8; i++) 
  {
    if (i==0) 
    {
      digitalWrite(9, LOW);    
    }
    else 
    {
      digitalWrite(i+1, LOW);
    }

    for (int j=0; j<8; j++) 
    {
      if (data[i][j] == 1) 
      {
        digitalWrite(j+10, LOW);
      }
      else 
      {
        digitalWrite(j+10, HIGH);
      }
    }
    digitalWrite(i+2, HIGH);
  }
}    

/*void pot()  
{
  val = analogRead(POT);
  if (val < 341)
  {
    displayVal = 1;
  }
  // BLUE
  else if (val > 679)
  {
    displayVal = 3;
  }
  // GREEN
  else
  {
    displayVal = 2;
  }
  Serial.println(displayVal); // Print value of val using Arduino serial print option
  delay(500);
  
}*/

