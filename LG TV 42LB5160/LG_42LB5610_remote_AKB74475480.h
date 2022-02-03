// by xiaolaba
// LG TV LG_42LB5610 remote control code
// TV model LG_42LB5610
// remote model AKB74475480_REMOTE_CONTROL

// C-Code header
#define ON_OFF 0x20DF10EF
#define TV_RAD 0x20DF0FF0
#define SUBTITLE 0x20DF9C63
#define RATIO 0x20DF9E61
#define AV_MODE 0x20DF0CF3
#define INPUT 0x20DFD02F
#define DIGIT_1 0x20DF8877
#define DIGIT_2 0x20DF48B7
#define DIGIT_3 0x20DFC837
#define DIGIT_4 0x20DF28D7
#define DIGIT_5 0x20DFA857
#define DIGIT_6 0x20DF6897
#define DIGIT_7 0x20DFE817
#define DIGIT_8 0x20DF18E7
#define DIGIT_9 0x20DF9867
#define LIST 0x20DFCA35
#define DIGIT_0 0x20DF08F7
#define Q_VIEW 0x20DF58A7
#define VOL+ 0x20DF40BF
#define FAV 0x20DF7887
#define PAGE+ 0x20DF00FF
#define GUIDE 0x20DFD52A
#define VOL- 0x20DFC03F
#define MUTE 0x20DF906F
#define PAGE- 0x20DF807F
#define TEXT 0x20DF04FB
#define INFO 0x20DF55AA
#define T_OPT 0x20DF847B
#define SETTING 0x20DFC23D
#define UP 0x20DF02FD
#define Q_MENU 0x20DFA25D
#define LEFT 0x20DFE01F
#define OK 0x20DF22DD
#define RIGHT 0x20DF609F
#define BACK 0x20DF14EB
#define DOWN 0x20DF827D
#define EXIT 0x20DFDA25
#define AD_* 0x20DF8976
#define REC 0x20DFBD42
#define LIVE_TV_STOP 0x20DF8D72
#define BACKWARD 0x20DFF10E
#define PLAY 0x20DF0DF2
#define PAUSE 0x20DF5DA2
#define FAST_FOWARD 0x20DF718E
#define RED 0x20DF4EB1
#define GREEN 0x20DF8E71
#define YELLOW 0x20DFC639
#define BLUE 0x20DF8679


// START E:\2019-11-11_HK_trip\DIY\2022-01-24_LG_42LB5610\IR_decoder\IR_decoder.ino from Feb  3 2022
//Using library version 3.5.0
// c-header file
#define key_0001 0x20DF10EF // Protocol=NEC Address=0x4 Command=0x8 Raw-Data=0xF708FB04 32 bits LSB first
#define key_0002 0x20DF0FF0 // Protocol=NEC Address=0x4 Command=0xF0 Raw-Data=0xFF0FB04 32 bits LSB first
#define key_0003 0x20DF9C63 // Protocol=NEC Address=0x4 Command=0x39 Raw-Data=0xC639FB04 32 bits LSB first
#define key_0004 0x20DF9E61 // Protocol=NEC Address=0x4 Command=0x79 Raw-Data=0x8679FB04 32 bits LSB first
#define key_0005 0x20DF0CF3 // Protocol=NEC Address=0x4 Command=0x30 Raw-Data=0xCF30FB04 32 bits LSB first
#define key_0006 0x20DFD02F // Protocol=NEC Address=0x4 Command=0xB Raw-Data=0xF40BFB04 32 bits LSB first
#define key_0007 0x20DF8877 // Protocol=NEC Address=0x4 Command=0x11 Raw-Data=0xEE11FB04 32 bits LSB first
#define key_0008 0x20DF48B7 // Protocol=NEC Address=0x4 Command=0x12 Raw-Data=0xED12FB04 32 bits LSB first
#define key_0009 0x20DFC837 // Protocol=NEC Address=0x4 Command=0x13 Raw-Data=0xEC13FB04 32 bits LSB first
#define key_0010 0x20DF28D7 // Protocol=NEC Address=0x4 Command=0x14 Raw-Data=0xEB14FB04 32 bits LSB first
#define key_0011 0x20DFA857 // Protocol=NEC Address=0x4 Command=0x15 Raw-Data=0xEA15FB04 32 bits LSB first
#define key_0012 0x20DF6897 // Protocol=NEC Address=0x4 Command=0x16 Raw-Data=0xE916FB04 32 bits LSB first
#define key_0013 0x20DFE817 // Protocol=NEC Address=0x4 Command=0x17 Raw-Data=0xE817FB04 32 bits LSB first
#define key_0014 0x20DF18E7 // Protocol=NEC Address=0x4 Command=0x18 Raw-Data=0xE718FB04 32 bits LSB first
#define key_0015 0x20DF9867 // Protocol=NEC Address=0x4 Command=0x19 Raw-Data=0xE619FB04 32 bits LSB first
#define key_0016 0x20DFCA35 // Protocol=NEC Address=0x4 Command=0x53 Raw-Data=0xAC53FB04 32 bits LSB first
#define key_0017 0x20DF08F7 // Protocol=NEC Address=0x4 Command=0x10 Raw-Data=0xEF10FB04 32 bits LSB first
#define key_0018 0x20DF58A7 // Protocol=NEC Address=0x4 Command=0x1A Raw-Data=0xE51AFB04 32 bits LSB first
#define key_0019 0x20DF40BF // Protocol=NEC Address=0x4 Command=0x2 Raw-Data=0xFD02FB04 32 bits LSB first
#define key_0020 0x20DF7887 // Protocol=NEC Address=0x4 Command=0x1E Raw-Data=0xE11EFB04 32 bits LSB first
#define key_0021 0x20DF00FF // Protocol=NEC Address=0x4 Command=0x0 Raw-Data=0xFF00FB04 32 bits LSB first
#define key_0022 0x20DFD52A // Protocol=NEC Address=0x4 Command=0xAB Raw-Data=0x54ABFB04 32 bits LSB first
#define key_0023 0x20DFC03F // Protocol=NEC Address=0x4 Command=0x3 Raw-Data=0xFC03FB04 32 bits LSB first
#define key_0024 0x20DF906F // Protocol=NEC Address=0x4 Command=0x9 Raw-Data=0xF609FB04 32 bits LSB first
#define key_0025 0x20DF807F // Protocol=NEC Address=0x4 Command=0x1 Raw-Data=0xFE01FB04 32 bits LSB first
#define key_0026 0x20DF04FB // Protocol=NEC Address=0x4 Command=0x20 Raw-Data=0xDF20FB04 32 bits LSB first
#define key_0027 0x20DF55AA // Protocol=NEC Address=0x4 Command=0xAA Raw-Data=0x55AAFB04 32 bits LSB first
#define key_0028 0x20DF847B // Protocol=NEC Address=0x4 Command=0x21 Raw-Data=0xDE21FB04 32 bits LSB first
#define key_0029 0x20DFC23D // Protocol=NEC Address=0x4 Command=0x43 Raw-Data=0xBC43FB04 32 bits LSB first
#define key_0030 0x20DF02FD // Protocol=NEC Address=0x4 Command=0x40 Raw-Data=0xBF40FB04 32 bits LSB first
#define key_0031 0x20DFA25D // Protocol=NEC Address=0x4 Command=0x45 Raw-Data=0xBA45FB04 32 bits LSB first
#define key_0032 0x20DFE01F // Protocol=NEC Address=0x4 Command=0x7 Raw-Data=0xF807FB04 32 bits LSB first
#define key_0033 0x20DF22DD // Protocol=NEC Address=0x4 Command=0x44 Raw-Data=0xBB44FB04 32 bits LSB first
#define key_0034 0x20DF609F // Protocol=NEC Address=0x4 Command=0x6 Raw-Data=0xF906FB04 32 bits LSB first
#define key_0035 0x20DF14EB // Protocol=NEC Address=0x4 Command=0x28 Raw-Data=0xD728FB04 32 bits LSB first
#define key_0036 0x20DF827D // Protocol=NEC Address=0x4 Command=0x41 Raw-Data=0xBE41FB04 32 bits LSB first
#define key_0037 0x20DFDA25 // Protocol=NEC Address=0x4 Command=0x5B Raw-Data=0xA45BFB04 32 bits LSB first
#define key_0038 0x20DF8976 // Protocol=NEC Address=0x4 Command=0x91 Raw-Data=0x6E91FB04 32 bits LSB first
#define key_0039 0x20DFBD42 // Protocol=NEC Address=0x4 Command=0xBD Raw-Data=0x42BDFB04 32 bits LSB first
#define key_0040 0x20DF8D72 // Protocol=NEC Address=0x4 Command=0xB1 Raw-Data=0x4EB1FB04 32 bits LSB first
#define key_0041 0x20DFF10E // Protocol=NEC Address=0x4 Command=0x8F Raw-Data=0x708FFB04 32 bits LSB first
#define key_0042 0x20DF0DF2 // Protocol=NEC Address=0x4 Command=0xB0 Raw-Data=0x4FB0FB04 32 bits LSB first
#define key_0043 0x20DF5DA2 // Protocol=NEC Address=0x4 Command=0xBA Raw-Data=0x45BAFB04 32 bits LSB first
#define key_0044 0x20DF718E // Protocol=NEC Address=0x4 Command=0x8E Raw-Data=0x718EFB04 32 bits LSB first
#define key_0045 0x20DF4EB1 // Protocol=NEC Address=0x4 Command=0x72 Raw-Data=0x8D72FB04 32 bits LSB first
#define key_0046 0x20DF8E71 // Protocol=NEC Address=0x4 Command=0x71 Raw-Data=0x8E71FB04 32 bits LSB first
#define key_0047 0x20DFC639 // Protocol=NEC Address=0x4 Command=0x63 Raw-Data=0x9C63FB04 32 bits LSB first
#define key_0048 0x20DF8679 // Protocol=NEC Address=0x4 Command=0x61 Raw-Data=0x9E61FB04 32 bits LSB first
