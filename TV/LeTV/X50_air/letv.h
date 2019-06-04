/* xiaolaba
 2018-JUN-04, test ok
 TV, IR remote for LeTV X50_air
 https://github.com/xiaolaba/IR-remote-control-code/tree/master/TV/LeTV/X50_air
*/

/*
 IR remote control model, LeTV
 IR remote signal, NEC, RAW code 0x32A6xxxx, 
 that is result of LSB first send first of a byte
 ie. 0x32 = 0b 0011,0010, send it MSB fisrt, but store LSB first, became  0b 0100,1100 = 0x4C
 ie. 0xA6 = 0b 1010,0110, send it MSB fisrt, but store LSB first, became  0b 0110,0101 = 0x65

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

#define LeTV_NEC_ADDRESS 0x4C650000

#define LeTV_POWER   LeTV_NEC_ADDRESS + (10 <<8) + 0x0100 + (~10);

#define LeTV_CH_UP   LeTV_NEC_ADDRESS + (31 <<8) + 0x0100 + (~31);
#define LeTV_CH_DN   LeTV_NEC_ADDRESS + (30 <<8) + 0x0100 + (~30);

#define LeTV_VOL_UP  LeTV_NEC_ADDRESS + (21 <<8) + 0x0100 + (~21);
#define LeTV_VOL_DN  LeTV_NEC_ADDRESS + (28 <<8) + 0x0100 + (~28);
