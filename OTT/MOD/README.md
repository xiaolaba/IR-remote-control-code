中華電信 MOD, IR REMOTRE CONTROL SIGNAL  

NEC FORMAT, 38KHZ, 1/3 duty cycle, 7.75us ON time  

header = 9ms brust, 4.5ms off, 16T + 8T,
32bit data,  
bit 0 = 1T brust, 1T off  
bit 1 = 1T brust, 3T off  
Stop  = 1T brust + off 110ms - 70.6ms  

example CH+
IR steram = 01111101_01111101_11011110_00100001  
01111101011111011101111000100001  
0x7D, 0x7D, 0xDE, 0x21  
MSB send first  
![MOD_CH_UP_decoded.JPG](MOD_CH_UP_decoded.JPG)
  
  
