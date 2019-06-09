/* xiaolaba
 2018-JUN-04, test ok
 Onkyo Amplifier, IR remote
 https://xiaolaba.wordpress.com/2016/10/05/imitate-magictv-remote-control-only-for-ch-and-ch/
*/

/*
 IR remote control model, Onkyo RC-837M
 IR remote signal, NEC, RAW code 0x4BB6xxxx, 
 that is result of LSB first send first of a byte
 ie. 0x4B = 0b 0100,1011, send it MSB fisrt, but store LSB first, became  0b 1101,0010 = 0xD2
 ie. 0xB6 = 0b 1011,1010, send it MSB fisrt, but store LSB first, became  0b 0110,1101 = 0x6D

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

/*
#define onkyo_NEC_ADDRESS 0xD26D0000
#define onkyo_VOL_UP   onkyo_NEC_ADDRESS + (0x02u <<8) + (unsigned char)(~0x02);
#define onkyo_VOL_DN   onkyo_NEC_ADDRESS + (0x03u <<8) + (unsigned char)(~0x03);
*/

// on the fly calculate 4th byte of address, it is 3rd byte inverted as NEC IR procotol
// 2019-JUN-08. test, no repsonse
// RAW IR singal stream
#define onkyo_NEC_ADDRESS 0x4BB60000
#define onkyo_VOL_UP   onkyo_NEC_ADDRESS + (0x40BF);
#define onkyo_VOL_DN   onkyo_NEC_ADDRESS + (0xC03F);


/*

// https://xiaolaba.wordpress.com/2016/10/05/imitate-magictv-remote-control-only-for-ch-and-ch/

void Onkyo_VOL_UP(){
  digitalWrite(LED, LOW);  
  Serial.println(F("Onkyo Volume up"));
  irsend.sendNEC(0x4BB640BF,32);
  delay(39); //2016-10-07, must add this delay, or appleTV will has interference
//  digitalWrite(LED, HIGH);
//  warning_blink_led(5);  
}

void Onkyo_VOL_DOWN(){
  digitalWrite(LED, LOW);  
  Serial.println(F("Onkyo Volume down"));
  irsend.sendNEC(0x4BB6C03F,32);
  delay(39); //2016-10-07, must add this delay, or appleTV will has interference  
//  digitalWrite(LED, HIGH);
//  warning_blink_led(5);
    
}


*/