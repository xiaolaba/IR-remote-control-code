/* xiaolaba
 2018-JUN-04, test ok
 MagicTV, OTT, IR remote
 https://github.com/xiaolaba/IR-remote-control-code/tree/master/OTT/myTV_Super
*/

/*
 IR remote control model, MagicTV
 IR remote signal, NEC, RAW code 0x1B54xxxx, 
 that is result of LSB first send first of a byte
 ie. 0x1B = 0b 0001,1011, send it MSB fisrt, but store LSB first, became  0b 1101,1000 = 0xD8
 ie. 0x54 = 0b 0101,0100, send it MSB fisrt, but store LSB first, became  0b 0010,1010 = 0x2A

 +0x0100, see https://xiaolaba.wordpress.com/2018/10/28/sdcc-0x0100-bug-if-0x01-or-0x7b/
 one used ~() operator, not just inverting bit, it has -0x0100 due to C-preprocessor
 do not know why, but it is something C and the style,
 perhaps 2's completment 
 https://www.programiz.com/c-programming/bitwise-operators

 # Twist in bitwise complement operator in C Programming
 # The bitwise complement of 35 (~35) is -36 instead of 220, but why?
 # For any integer n, bitwise complement of n will be -(n+1). To understand this, you should have the knowledge of 2's complement.

 my record, https://xiaolaba.wordpress.com/2018/10/28/sdcc-0x0100-bug-if-0x01-or-0x7b/

*/

#define magicTV_NEC_ADDRESS 0xD82A0000

#define magicTV_CH_UP   magicTV_NEC_ADDRESS + (0x16 <<8) + 0x0100 + (~0x16);
#define magicTV_CH_DN   magicTV_NEC_ADDRESS + (0x17 <<8) + 0x0100 + (~0x17);


/*

// https://xiaolaba.wordpress.com/2016/10/05/imitate-magictv-remote-control-only-for-ch-and-ch/

void MagicTV_CH_UP (){
  digitalWrite(LED, LOW);
  Serial.println(F("MagicTV CH+, await 1 sec"));
  irsend.sendNEC(0x1B546897,32);
  delay(2000);
//  digitalWrite(LED, HIGH);
//  warning_blink_led(5);
}

void MagicTV_CH_DOWN () {
  digitalWrite(LED, LOW);
  Serial.println(F("MagicTV CH-, await 1 sec"));
  irsend.sendNEC(0x1B54E817,32);
  delay(2000);
//  digitalWrite(LED, HIGH);   
//  warning_blink_led(5);
}

*/