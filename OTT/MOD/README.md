中華電信 MOD, IR REMOTRE CONTROL SIGNAL  
MODEL : MRC42, http://mod.cht.com.tw/download/file/mrc42_userguide_www_20141111.pdf  



NEC FORMAT, 38KHZ, 1/3 duty cycle, 7.75us ON time  

header = 9ms brust, 4.5ms off, 16T + 8T,
32bit data,  
bit 0 = 1T brust, 1T off  
bit 1 = 1T brust, 3T off  
Stop  = 1T brust + off 110ms - 70.6ms  

example, CH+
IR steram = 01111101_01111101_11011110_00100001  
01111101011111011101111000100001  
0x7D, 0x7D, 0xDE, 0x21  
MSB send first
test result, timing +6% longer than designed, MOD receiver is still working flawlessly, distance 3 meters.    
![MOD_CH_UP_decoded.JPG](MOD_CH_UP_decoded.JPG)  

.
outline  
![MOD_MRC42.JPG](MOD_MRC42.JPG)

CH_UP 0x7d7dde21
  

left, new android tv box like,   
right, old model, used remote MRC42  
MOD_IPTV.JPG
![MOD_IPTV.JPG](MOD_IPTV.JPG)
