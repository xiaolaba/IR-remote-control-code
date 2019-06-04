/* xiaolaba
 2018-JUN-04, test ok
 myTV Super, OTT, IR remote
 https://github.com/xiaolaba/IR-remote-control-code/tree/master/OTT/myTV_Super
*/

/*
 IR remote control model, myTV Super
 IR remote signal, NEC, RAW code FB00xxxx, 
 that is result of LSB first send first of a byte
 ie. 0xFB = 0b 0011,0010, send it MSB fisrt, but store LSB first, became  0b 0100,1100 = 0xDF
 ie. 0x00 = 0b 0000,0000, send it MSB fisrt, but store LSB first, became  0b 0000,0000 = 0x00

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

#define myTV_super_NEC_ADDRESS 0xDF000000

#define myTV_super_POWER   myTV_super_NEC_ADDRESS + (28 <<8) + 0x0100 + (~28);

#define myTV_super_CH_UP   myTV_super_NEC_ADDRESS + (26 <<8) + 0x0100 + (~26);
#define myTV_super_CH_DN   myTV_super_NEC_ADDRESS + (72 <<8) + 0x0100 + (~72);   // not working ? not debug yet

#define myTV_super_VOL_UP  myTV_super_NEC_ADDRESS + (7  <<8) + 0x0100 + (~7);
#define myTV_super_VOL_DN  myTV_super_NEC_ADDRESS + (71 <<8) + 0x0100 + (~71);

/*
1,NEC2,0xFB0038C7,0xDF,0x0,28,227,32_bits,  ON/OFF
2,NEC2,0xFB0020DF,0xDF,0x0,4,251,32_bits,   TV/VOD
3,NEC2,0xFB0058A7,0xDF,0x0,26,229,32_bits,  CH+   
4,NEC2,0xFB00E21D,0xDF,0x0,71,184,32_bits,  VOL-  
5,NEC2,0xFB00609F,0xDF,0x0,6,249,32_bits,   OK    
6,NEC2,0xFB00E01F,0xDF,0x0,7,248,32_bits,   VOL+  
7,NEC2,0xFB0012ED,0xDF,0x0,72,183,32_bits,  CH-   
8,NEC2,0xFB0050AF,0xDF,0x0,10,245,32_bits,  HOME  
9,NEC2,0xFB00926D,0xDF,0x0,73,182,32_bits,  EXIT  
10,NEC2,0xFB0018E7,0xDF,0x0,24,231,32_bits, MENU  
11,NEC2,0xFB00807F,0xDF,0x0,1,254,32_bits,  >||   
12,NEC2,0xFB00FA05,0xDF,0x0,95,160,32_bits, PAUSE 
13,NEC2,0xFB009867,0xDF,0x0,25,230,32_bits, <<    
14,NEC2,0xFB001AE5,0xDF,0x0,88,167,32_bits, >>    
15,NEC2,0xFB002AD5,0xDF,0x0,84,171,32_bits, 1     
16,NEC2,0xFB006897,0xDF,0x0,22,233,32_bits, 2     
17,NEC2,0xFB00A857,0xDF,0x0,21,234,32_bits, 3     
18,NEC2,0xFB000AF5,0xDF,0x0,80,175,32_bits, 4     
19,NEC2,0xFB0048B7,0xDF,0x0,18,237,32_bits, 5     
20,NEC2,0xFB008877,0xDF,0x0,17,238,32_bits, 6     
21,NEC2,0xFB0032CD,0xDF,0x0,76,179,32_bits, 7     
22,NEC2,0xFB00708F,0xDF,0x0,14,241,32_bits, 8     
23,NEC2,0xFB00B04F,0xDF,0x0,13,242,32_bits, 9     
24,NEC2,0xFB003AC5,0xDF,0x0,92,163,32_bits, MUTE  
25,NEC2,0xFB0030CF,0xDF,0x0,12,243,32_bits, 0     
26,NEC2,0xFB0008F7,0xDF,0x0,16,239,32_bits, <X  
*/
