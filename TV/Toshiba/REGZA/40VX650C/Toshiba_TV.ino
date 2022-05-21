


//https://github.com/xiaolaba/arduino_lcd_keypad_shield_testing/blob/main/LCDKeypad_Shield_keypad_ADC0_testing/LCDKeypad_Shield_keypad_ADC0_testing.ino
/*
  Blink backlight
  lcd keypad shield testing
  Turns an backlight of LED on for one second, then off for one second, repeatedly.
  xiaolaba, 2020-NOV-10
*/

#include <Arduino.h>

#include <LiquidCrystal.h>
//LCD pin to Arduino
const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 
LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);

const int pin_BL = 10;  // control pin for backlight LED LED+ = 5V, LED- = NPN switch


//https://gist.github.com/sukedai/1759605


//
//  Toshiba TV(REGZA serise) IR remote controller sketch for SUWANO Startup Set
//
//  使い方:
//    (0) SUWANOスタートアップシールドのLED4を赤外線LEDに付け替えます
//    (1) Arduino-0023を用意します。1.0だと動きません；
//    (2) Arduino-0023にIRremoteライブラリをインストール
//    (3) IRremoteライブラリに次のパッチをあてます -> https://gist.github.com/1759596
//    (4) スケッチをコンパイル後、SUWANOに書き込みます
//    (5) ボタンに次の機能をアサインしています
//        ボタン1 : ボリュームを上げる
//        ボタン2 : ボリュームを下げる
//        ボタン3 : チャンネル1を選択
//        ボタン4 : 電源ON/OFF
//


/*
 * Define macros for input and output pin etc.
 */
#include "PinDefinitionsAndMore.h"

#define SEND_PWM_BY_TIMER
//#define USE_NO_SEND_PWM
#define NO_LED_FEEDBACK_CODE // saves 418 bytes program space

#include <IRremote.hpp>


// IR LED pin default pin3 PWM output
//#include <IRremote.h>

//IRsend irsend;

#define CODE_ON       0x02FD48B7
#define CODE_CH_NEXT  0x02FDD827
#define CODE_CH_PREV  0x02FDF807

#define CODE_VOL_UP   0x02FD58A7
#define CODE_VOL_DOWN 0x02FD7887
#define CODE_SOURCE_CHANGE 0x02FDF00F

#define CODE_CH_1     0x02FD807F
#define CODE_MUTE     0x02FD0800 + (~0x08)
#define CODE_0        0x02FD0000 + (b000000000 <<8 + ~0b00000000)
#define CODE_1        0x02FD8000 + (0b10000000 <<8 + ~0b10000000)
#define CODE_2        0x02FD4000 + (0b01000000 <<8 + ~0b01000000)
#define CODE_3        0x02FD2000 + (0b00100000 <<8 + ~0b01000000)
#define CODE_4        0x02FD1000 + (0b10100000 <<8 + ~0b10100000)
#define CODE_5        0x02FD0400 + (0b01100000 <<8 + ~0b01100000)
#define CODE_6        0x02FD0200 + (0b11100000 <<8 + ~0b11100000)
#define CODE_7        0x02FD0100 + (0b10010000 <<8 + ~0b10010000)
#define CODE_8        0x02FD0000 + (0b01010000 <<8 + ~0b01010000)
#define CODE_9        0x02FD0000 + (0b11010000 <<8 + ~0b11010000)






int keypad_adc0_read(){
  int x;
  x = analogRead (0);
  lcd.clear();   
  lcd.print("press a key");
  lcd.setCursor(0,1); lcd.print("ADC0= "); lcd.print(x);
  return x;
}

void backlight_on()
{
  digitalWrite(pin_BL, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println("pin_BL=HIGH, backlight ON");  
}

void backlight_off()
{
  digitalWrite(pin_BL, LOW);    // turn the LED off by making the voltage LOW
  Serial.println("pin_BL = LOW, backlight OFF");  
}


void setup_LCD_shield(){
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(pin_BL, OUTPUT);
  Serial.begin(115200);
  Serial.println("lcd testing begin");

  backlight_on();
 
  lcd.begin(16, 2);
  lcd.print("xiaolaba Toshiba");
  lcd.setCursor(0,1);
  lcd.print("TV IRemote");
  delay(3000);

}


int read_adc0 (){
  return keypad_adc0_read();
}

void setup()
{
  pinMode(3,OUTPUT);  /*declare D3 pin as an output pin */
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  setup_LCD_shield();

  // Just to know which program is running on my Arduino
  Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

  /*
   * The IR library setup. That's all!
   */
  IrSender.begin(); // Start with IR_SEND_PIN as send pin and if NO_LED_FEEDBACK_CODE is NOT defined, enable feedback LED at default feedback LED pin

  Serial.print(F("Ready to send IR signals at pin "));
  Serial.println(IR_SEND_PIN);

}


void loop() {
  int x = read_adc0();
  //Serial.println(x, DEC);

  if (x > 720 && x < 900 ) {
    Serial.println("CH SELECT button");
    send_ir (CODE_CH_NEXT);

    lcd.print(" CH+");
    delay(200);
    return;
  }
  if (x > 485 && x < 650 ) {
    Serial.println("POWER ON, LEFT button");
    send_ir (CODE_ON);
    lcd.print(" POWER");    
    delay(200);
    return;
  }
  if (x > 290 && x < 400 ) {
    Serial.println("VOL DOWN button");
    send_ir (CODE_VOL_DOWN);
    IrSender.sendNEC(0, 0, 4);  // repeat code 4 times   
    //send_ir (CODE_CH_PREV);
    lcd.print(" VOL-");        
    delay(200);
    return;
  }
  if (x > 150 && x < 240 ) {
    Serial.println("VOL UP button");
    send_ir (CODE_VOL_UP);
    IrSender.sendNEC(0, 0, 4);  // repeat code 4 times
    lcd.print(" VOL+");     
    delay(200);
    return;
  }
  if (x > 0   && x < 100 ){
    Serial.println("CH SOURCE RIGHT button");
    send_ir (CODE_SOURCE_CHANGE);
    lcd.print(" SOURCE");     
    delay(200);
    return;
  }
  


  while (Serial.available()>0) {
    int c = Serial.read();
    switch(c) {
      case 'p':
        send_ir(CODE_ON);
        break;
      case '1':
        send_ir(CODE_CH_1);
        break;
      case 's':
        send_ir(CODE_SOURCE_CHANGE);
        break;
      case 'n':
        send_ir(CODE_CH_NEXT);
        break;
      case 'd':
        send_ir(CODE_VOL_DOWN);
        break;
      case 'u':
        send_ir(CODE_VOL_UP);
        break;
      default:
        break;
    }
  }
}



void send_ir (uint32_t raw){
  
    uint32_t out = reverseBits(raw);
  
    IrSender.sendNECRaw(out, 2);
//    IrSender.sendNECRaw(raw, 2);    
    Serial.print(raw, HEX); Serial.println(" raw 32bit"); 
    Serial.print(out, HEX); Serial.println(" reversed 32bit");  
    delay(1000);
}


uint32_t reverseBits(uint32_t n)
{
    uint32_t rev = 0;
    uint8_t count = 32;
     
    // traversing bits of 'n' from the right
    while (count > 0)
    {
        // bitwise left shift
        // 'rev' by 1
        rev <<= 1;
         
        // if current bit is '1'
        if (n & 1 == 1)
            rev ^= 1;
         
        // bitwise right shift
        // 'n' by 1
        n >>= 1;

        count--;
             
    }
     
    // required number
    return rev;
}
