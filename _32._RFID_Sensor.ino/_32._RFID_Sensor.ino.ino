//Viral Science
//RFID
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance (SDA, SCK, MOSI, MISO, RST :: 10, 13, 11, 12, 9)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Put your card to the reader...");
  Serial.println();
  lcd.begin(16, 2);
}
void loop() 
{
  // Print SCAN YOUR CARD in LCD
  lcd.display();
  delay(500);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.write("SCAN YOUR CARD");
    
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.write("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "D3 DF B1 1C") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Access Granted");
    lcd.setCursor(0,1);
    lcd.write("ACCESS GRANTED");
    delay(1000);
  }
 
 else   
 {
    Serial.println(" Access denied");
    lcd.setCursor(0,1);
    lcd.write("ACCESS DENIED");
    delay(1000);
  }
} 
