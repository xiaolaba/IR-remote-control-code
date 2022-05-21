# RAW IR stream NEC 32bit  

VOL+  
address /address command /command   
LSB-MSB LSB-MAB  LSB-MSB LSB-MSB  
0x02    ~0x02    0x58    ~0x58  
         0xfd             0xa7   
MSB-LSB  MSB-LSB MSB-LSB  MSB-LSB  
0x40     0xbf    0x1a     0xe5  

IRemote libriary, sendRAW  
0xe51abf40  

address 0xbf40  
command 0x1a  



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
