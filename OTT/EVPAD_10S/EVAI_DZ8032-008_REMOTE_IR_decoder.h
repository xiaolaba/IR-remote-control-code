// xiaolaba, 2023/OCT/27
// START E:\2019-11-11_H_trip\DIY\TV\IR_remote_decoder\IR_decoder\IR_decoder.ino build from Oct 27 2023
// Using library version 4.1.0
// c-header file
// vcc=A5, IR_REC=A4, GND=A3

#define key_0001 0x00FF02FD // red power, Protocol=NEC Address=0x0 Command=0x40 Raw-Data=0xBF40FF00 32 bits LSB first
#define key_0002 0x00FF8F70 // green power, Protocol=NEC Address=0x0 Command=0xF1 Raw-Data=0xEF1FF00 32 bits LSB first
#define key_0003 0x00FF4FB0 // speaker+, Protocol=NEC Address=0x0 Command=0xF2 Raw-Data=0xDF2FF00 32 bits LSB first
#define key_0004 0x00FFCF30 // speaker-, Protocol=NEC Address=0x0 Command=0xF3 Raw-Data=0xCF3FF00 32 bits LSB first
#define key_0005 0x20DE708F // AV/TV, Protocol=NEC Address=0x7B04 Command=0xE Raw-Data=0xF10E7B04 32 bits LSB first
#define key_0006 0x00FFAF50 // MUTE, Protocol=NEC Address=0x0 Command=0xF5 Raw-Data=0xAF5FF00 32 bits LSB first
#define key_0007 0x00FF32CD // MENU, Protocol=NEC Address=0x0 Command=0x4C Raw-Data=0xB34CFF00 32 bits LSB first
#define key_0008 0x00FF827D // speaker off, Protocol=NEC Address=0x0 Command=0x41 Raw-Data=0xBE41FF00 32 bits LSB first
#define key_0009 0x00FF00FF // mouse mode, Protocol=NEC Address=0x0 Command=0x0 Raw-Data=0xFF00FF00 32 bits LSB first
#define key_0010 0x00FF48B7 // torch, Protocol=NEC Address=0x0 Command=0x12 Raw-Data=0xED12FF00 32 bits LSB first
#define key_0011 0x00FF6897 // UP, Protocol=NEC Address=0x0 Command=0x16 Raw-Data=0xE916FF00 32 bits LSB first
#define key_0012 0x00FF8A75 // LEFT, Protocol=NEC Address=0x0 Command=0x51 Raw-Data=0xAE51FF00 32 bits LSB first
#define key_0013 0x00FFC837 // OK, Protocol=NEC Address=0x0 Command=0x13 Raw-Data=0xEC13FF00 32 bits LSB first
#define key_0014 0x00FF0AF5 // RIGHT, Protocol=NEC Address=0x0 Command=0x50 Raw-Data=0xAF50FF00 32 bits LSB first
#define key_0015 0x00FF58A7 // DOWN, Protocol=NEC Address=0x0 Command=0x1A Raw-Data=0xE51AFF00 32 bits LSB first
#define key_0016 0x00FF8877 // HOME, Protocol=NEC Address=0x0 Command=0x11 Raw-Data=0xEE11FF00 32 bits LSB first
#define key_0017 0x00FF04FB // BLUE MIRCOPHONE, Protocol=NEC Address=0x0 Command=0x20 Raw-Data=0xDF20FF00 32 bits LSB first
#define key_0018 0x00FF9867 // RETURN, rotocol=NEC Address=0x0 Command=0x19 Raw-Data=0xE619FF00 32 bits LSB first
#define key_0019 0x00FF08F7 // VOL-, Protocol=NEC Address=0x0 Command=0x10 Raw-Data=0xEF10FF00 32 bits LSB first
#define key_0020 0x00FF18E7 // VOL+, Protocol=NEC Address=0x0 Command=0x18 Raw-Data=0xE718FF00 32 bits LSB first
#define key_0021 0x00FF728D // 1, Protocol=NEC Address=0x0 Command=0x4E Raw-Data=0xB14EFF00 32 bits LSB first
#define key_0022 0x00FFB04F // 2, Protocol=NEC Address=0x0 Command=0xD Raw-Data=0xF20DFF00 32 bits LSB first
#define key_0023 0x00FF30CF // 3, Protocol=NEC Address=0x0 Command=0xC Raw-Data=0xF30CFF00 32 bits LSB first
#define key_0024 0x00FF52AD // 4, Protocol=NEC Address=0x0 Command=0x4A Raw-Data=0xB54AFF00 32 bits LSB first
#define key_0025 0x00FF906F // 5, Protocol=NEC Address=0x0 Command=0x9 Raw-Data=0xF609FF00 32 bits LSB first
#define key_0026 0x00FF10EF // 6, Protocol=NEC Address=0x0 Command=0x8 Raw-Data=0xF708FF00 32 bits LSB first
#define key_0027 0x00FF629D // 7, Protocol=NEC Address=0x0 Command=0x46 Raw-Data=0xB946FF00 32 bits LSB first
#define key_0028 0x00FFA05F // 8, Protocol=NEC Address=0x0 Command=0x5 Raw-Data=0xFA05FF00 32 bits LSB first
#define key_0029 0x00FF20DF // 9, Protocol=NEC Address=0x0 Command=0x4 Raw-Data=0xFB04FF00 32 bits LSB first
#define key_0030 0x00FF42BD // delete, Protocol=NEC Address=0x0 Command=0x42 Raw-Data=0xBD42FF00 32 bits LSB first
#define key_0031 0x00FF807F // 0, Protocol=NEC Address=0x0 Command=0x1 Raw-Data=0xFE01FF00 32 bits LSB first
#define key_0032 0x00FFA25D // internet, Protocol=NEC Address=0x0 Command=0x45 Raw-Data=0xBA45FF00 32 bits LSB first
