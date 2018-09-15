#define NOTE_C  262 //Hz
#define NOTE_D  294 //Hz
#define NOTE_E  330 //Hz
#define NOTE_G  392 //Hz
#define NOTE_A  440 //Hz

const int LED1 = 12;
const int LED2 = 8;
const int LED3 = 9;
const int LED4 = 10;
const int LED5 = 11;


const int button_C = 1;
const int button_D = 2;
const int button_E = 3;
const int button_G = 4;
const int button_A = 5;

const int buzzer = 6;

int value;

void setup() 
{
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  /*pinMode(button_C, INPUT);
  pinMode(button_D, INPUT);
  pinMode(button_E, INPUT);
  pinMode(button_G, INPUT);
  pinMode(button_A, INPUT);
  Serial.begin(9600);
  */
}

void loop()
{
  /*value = digitalRead(button_C);
  Serial.println(value);
  delay(250);
  
  if (value != 1)
  {
    tone(buzzer, NOTE_C, 100);
    digitalWrite(LED1, HIGH);
  }

    else 
  {
    tone(buzzer, NOTE_D, 100);
    digitalWrite(LED2, HIGH);
  }*/
  while (digitalRead(button_C))
    tone(buzzer, NOTE_C);
    digitalWrite(LED2, HIGH);
  while (digitalRead(button_D))
    tone(buzzer, NOTE_D);
    digitalWrite(LED2, HIGH);
  while (digitalRead(button_E))
    tone(buzzer, NOTE_E);
    digitalWrite(LED3, HIGH);
  while (digitalRead(button_G))
    tone(buzzer, NOTE_G);
    digitalWrite(LED4, HIGH);
  while (digitalRead(button_A))
    tone(buzzer, NOTE_A);
    digitalWrite(LED5, HIGH);

  noTone(buzzer);
}
