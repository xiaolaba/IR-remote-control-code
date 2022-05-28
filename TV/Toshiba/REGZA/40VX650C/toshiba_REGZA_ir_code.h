// START \TV\IR_remote_decoder\IR_decoder\IR_decoder.ino from May 28 2022
//Using library version 3.5.0
// c-header file
//CT90296, CT90337, CT90301, CT90307

// TV
#define key_0001 0x2FD48B7 // Protocol=NEC Address=0x40 Command=0x12 Raw-Data=0xED12BF40 32 bits LSB first, on/off
#define key_0002 0x2FD807F // Protocol=NEC Address=0x40 Command=0x1 Raw-Data=0xFE01BF40 32 bits LSB first, 1
#define key_0003 0x2FD40BF // Protocol=NEC Address=0x40 Command=0x2 Raw-Data=0xFD02BF40 32 bits LSB first, 2
#define key_0004 0x2FDC03F // Protocol=NEC Address=0x40 Command=0x3 Raw-Data=0xFC03BF40 32 bits LSB first, 3
#define key_0005 0x2FD20DF // Protocol=NEC Address=0x40 Command=0x4 Raw-Data=0xFB04BF40 32 bits LSB first, 4
#define key_0006 0x2FDA05F // Protocol=NEC Address=0x40 Command=0x5 Raw-Data=0xFA05BF40 32 bits LSB first, 5
#define key_0007 0x2FD609F // Protocol=NEC Address=0x40 Command=0x6 Raw-Data=0xF906BF40 32 bits LSB first, 6
#define key_0008 0x2FDE01F // Protocol=NEC Address=0x40 Command=0x7 Raw-Data=0xF807BF40 32 bits LSB first, 7
#define key_0009 0x2FD10EF // Protocol=NEC Address=0x40 Command=0x8 Raw-Data=0xF708BF40 32 bits LSB first, 8
#define key_0010 0x2FD906F // Protocol=NEC Address=0x40 Command=0x9 Raw-Data=0xF609BF40 32 bits LSB first, 9
#define key_0011 0x2FD4AB5 // Protocol=NEC Address=0x40 Command=0x52 Raw-Data=0xAD52BF40 32 bits LSB first, swap
#define key_0012 0x2FD00FF // Protocol=NEC Address=0x40 Command=0x0 Raw-Data=0xFF00BF40 32 bits LSB first, 0
#define key_0013 0x2FD28D7 // Protocol=NEC Address=0x40 Command=0x14 Raw-Data=0xEB14BF40 32 bits LSB first, source
#define key_0014 0x2FD58A7 // Protocol=NEC Address=0x40 Command=0x1A Raw-Data=0xE51ABF40 32 bits LSB first, VOL+
#define key_0015 0x2FD08F7 // Protocol=NEC Address=0x40 Command=0x10 Raw-Data=0xEF10BF40 32 bits LSB first, MUTE
#define key_0016 0x2FDD827 // Protocol=NEC Address=0x40 Command=0x1B Raw-Data=0xE41BBF40 32 bits LSB first, CH+
#define key_0017 0x2FD7887 // Protocol=NEC Address=0x40 Command=0x1E Raw-Data=0xE11EBF40 32 bits LSB first, VOL-
#define key_0018 0x2FDC639 // Protocol=NEC Address=0x40 Command=0x63 Raw-Data=0x9C63BF40 32 bits LSB first, QUICK
#define key_0019 0x2FDF807 // Protocol=NEC Address=0x40 Command=0x1F Raw-Data=0xE01FBF40 32 bits LSB first, CH-
#define key_0020 0x2FDA25D // Protocol=NEC Address=0x40 Command=0x45 Raw-Data=0xBA45BF40 32 bits LSB first, GUIDE
#define key_0021 0x2FDC23D // Protocol=NEC Address=0x40 Command=0x43 Raw-Data=0xBC43BF40 32 bits LSB first, EXIT
#define key_0022 0x2FD9867 // Protocol=NEC Address=0x40 Command=0x19 Raw-Data=0xE619BF40 32 bits LSB first, UP
#define key_0023 0x2FD42BD // Protocol=NEC Address=0x40 Command=0x42 Raw-Data=0xBD42BF40 32 bits LSB first, LEFT
#define key_0024 0x2FD847B // Protocol=NEC Address=0x40 Command=0x21 Raw-Data=0xDE21BF40 32 bits LSB first, OK
#define key_0025 0x2FD02FD // Protocol=NEC Address=0x40 Command=0x40 Raw-Data=0xBF40BF40 32 bits LSB first, RIGHT
#define key_0026 0x2FDB847 // Protocol=NEC Address=0x40 Command=0x1D Raw-Data=0xE21DBF40 32 bits LSB first, DOWN
#define key_0027 0x2FD6897 // Protocol=NEC Address=0x40 Command=0x16 Raw-Data=0xE916BF40 32 bits LSB first, INFO
#define key_0028 0x2FD26D9 // Protocol=NEC Address=0x40 Command=0x64 Raw-Data=0x9B64BF40 32 bits LSB first, RETURN
#define key_0029 0x2FD12ED // Protocol=NEC Address=0x40 Command=0x48 Raw-Data=0xB748BF40 32 bits LSB first, RED
#define key_0030 0x2FD926D // Protocol=NEC Address=0x40 Command=0x49 Raw-Data=0xB649BF40 32 bits LSB first, GREEN
#define key_0031 0x2FD52AD // Protocol=NEC Address=0x40 Command=0x4A Raw-Data=0xB54ABF40 32 bits LSB first, YELLOW
#define key_0032 0x2FDD22D // Protocol=NEC Address=0x40 Command=0x4B Raw-Data=0xB44BBF40 32 bits LSB first, BLUE
#define key_0033 0x2FDC837 // Protocol=NEC Address=0x40 Command=0x13 Raw-Data=0xEC13BF40 32 bits LSB first, DOUBY I/II
#define key_0034 0x2FD30CF // Protocol=NEC Address=0x40 Command=0xC Raw-Data=0xF30CBF40 32 bits LSB first, SUBTITLE

#define key_0035 0x2FD9A65 // Protocol=NEC Address=0x40 Command=0x59 Raw-Data=0xA659BF40 32 bits LSB first, SCREEN SIZE
#define key_0036 0x2FD8877 // Protocol=NEC Address=0x40 Command=0x11 Raw-Data=0xEE11BF40 32 bits LSB first, SCREEN MODE

#define key_0037 0x2FDDA25 // Protocol=NEC Address=0x40 Command=0x5B Raw-Data=0xA45BBF40 32 bits LSB first, EJECT
#define key_0038 0x2FD22DD // Protocol=NEC Address=0x40 Command=0x44 Raw-Data=0xBB44BF40 32 bits LSB first, STOP
#define key_0039 0x2FDE21D // Protocol=NEC Address=0x40 Command=0x47 Raw-Data=0xB847BF40 32 bits LSB first, PLAY
#define key_0040 0x2FD44BB // Protocol=NEC Address=0x40 Command=0x22 Raw-Data=0xDD22BF40 32 bits LSB first, PAUSE/SLOW FORWARD
#define key_0041 0x2FD2AD5 // Protocol=NEC Address=0x40 Command=0x54 Raw-Data=0xAB54BF40 32 bits LSB first, BACKWARD
#define key_0042 0x2FDCA35 // Protocol=NEC Address=0x40 Command=0x53 Raw-Data=0xAC53BF40 32 bits LSB first, FAST BACKWARD
#define key_0043 0x2FDB04F // Protocol=NEC Address=0x40 Command=0xD Raw-Data=0xF20DBF40 32 bits LSB first, FAST FORWARD
#define key_0044 0x2FDA857 // Protocol=NEC Address=0x40 Command=0x15 Raw-Data=0xEA15BF40 32 bits LSB first, FORWARD


// REGZA-Link
#define key_0029 0x27D46B9 // Protocol=NEC Address=0xBE40 Command=0x62 Raw-Data=0x9D62BE40 32 bits LSB first, ROOT, RED
#define key_0030 0x27DAE51 // Protocol=NEC Address=0xBE40 Command=0x75 Raw-Data=0x8A75BE40 32 bits LSB first, CONTENTS
#define key_0031 0x27D2ED1 // Protocol=NEC Address=0xBE40 Command=0x74 Raw-Data=0x8B74BE40 32 bits LSB first, TOP
#define key_0032 0x27D4EB1 // Protocol=NEC Address=0xBE40 Command=0x72 Raw-Data=0x8D72BE40 32 bits LSB first, DVD
#define key_0033 0x27DB649 // Protocol=NEC Address=0xBE40 Command=0x6D Raw-Data=0x926DBE40 32 bits LSB first, AUDIO
#define key_0034 0x27DCE31 // Protocol=NEC Address=0xBE40 Command=0x73 Raw-Data=0x8C73BE40 32 bits LSB first, SET UP

#define key_0035 0x2FD9A65 // Protocol=NEC Address=0x40 Command=0x59 Raw-Data=0xA659BF40 32 bits LSB first, SCREEN SIZE
#define key_0036 0x2FD8877 // Protocol=NEC Address=0x40 Command=0x11 Raw-Data=0xEE11BF40 32 bits LSB first, SCREEN MODE

#define key_0037 0x27DA659 // Protocol=NEC Address=0xBE40 Command=0x65 Raw-Data=0x9A65BE40 32 bits LSB first, MENU
#define key_0038 0x27DE619 // Protocol=NEC Address=0xBE40 Command=0x67 Raw-Data=0x9867BE40 32 bits LSB first, ATV/DTV
#define key_0039 0x27D6699 // Protocol=NEC Address=0xBE40 Command=0x66 Raw-Data=0x9966BE40 32 bits LSB first, LIST
#define key_0040 0x27D16E9 // Protocol=NEC Address=0xBE40 Command=0x68 Raw-Data=0x9768BE40 32 bits LSB first, DOWNWARD
#define key_0041 0x27D36C9 // Protocol=NEC Address=0xBE40 Command=0x6C Raw-Data=0x936CBE40 32 bits LSB first, BACKWARD     
#define key_0042 0x27D9669 // Protocol=NEC Address=0xBE40 Command=0x69 Raw-Data=0x9669BE40 32 bits LSB first, FAST BACKWARD
#define key_0043 0x27D56A9 // Protocol=NEC Address=0xBE40 Command=0x6A Raw-Data=0x956ABE40 32 bits LSB first, FAST FORWARD
#define key_0044 0x27DD629 // Protocol=NEC Address=0xBE40 Command=0x6B Raw-Data=0x946BBE40 32 bits LSB first, FORWARD


// DVD
#define key_0031 0xA25D7B84 // Protocol=NEC Address=0x45 Command=0xDE Raw-Data=0x21DEBA45 32 bits LSB first, TOP YELLOW
#define key_0032 0xA25D21DE // Protocol=NEC Address=0x45 Command=0x84 Raw-Data=0x7B84BA45 32 bits LSB first, DVD
#define key_0033 0xA25DE41B // Protocol=NEC Address=0x45 Command=0x27 Raw-Data=0xD827BA45 32 bits LSB first, AUDIO
#define key_0034 0xA25D04FB // Protocol=NEC Address=0x45 Command=0x20 Raw-Data=0xDF20BA45 32 bits LSB first, SETUP

#define key_0035 0x2FD9A65 // Protocol=NEC Address=0x40 Command=0x59 Raw-Data=0xA659BF40 32 bits LSB first, SCREEN SIZE
#define key_0036 0x2FD8877 // Protocol=NEC Address=0x40 Command=0x11 Raw-Data=0xEE11BF40 32 bits LSB first, SVREEN MODE

#define key_0037 0xA25DAF50 // Protocol=NEC Address=0x45 Command=0xF5 Raw-Data=0xAF5BA45 32 bits LSB first, EJECT
#define key_0038 0xA25D28D7 // Protocol=NEC Address=0x45 Command=0x14 Raw-Data=0xEB14BA45 32 bits LSB first, STOP
#define key_0039 0xA25DA857 // Protocol=NEC Address=0x45 Command=0x15 Raw-Data=0xEA15BA45 32 bits LSB first, PLAY
#define key_0040 0xA25D00FF // Protocol=NEC Address=0x45 Command=0x0 Raw-Data=0xFF00BA45 32 bits LSB first, PAUSE
#define key_0041 0xA25DC43B // Protocol=NEC Address=0x45 Command=0x23 Raw-Data=0xDC23BA45 32 bits LSB first, BACKWARD
#define key_0042 0xA25D9867 // Protocol=NEC Address=0x45 Command=0x19 Raw-Data=0xE619BA45 32 bits LSB first, FAST BACKWARD
#define key_0043 0xA25DC837 // Protocol=NEC Address=0x45 Command=0x13 Raw-Data=0xEC13BA45 32 bits LSB first, FAST FORWARD
#define key_0044 0xA25D24DB // Protocol=NEC Address=0x45 Command=0x24 Raw-Data=0xDB24BA45 32 bits LSB first, FORWARD

