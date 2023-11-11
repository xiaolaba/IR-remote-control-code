// TCL 32D3000B IR reomote control code
// START IR_decoder.ino from Apr  9 2022
// Using library version 3.5.0
// c-header file
#define key_0001 0xF3F0C000 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0x30FCF 24 bits LSB first
#define key_0002 0xF2A0D500 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xAB054F 24 bits LSB first
#define key_0003 0xF310CE00 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0x7308CF 24 bits LSB first
#define key_0004 0xF320CD00 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xB304CF 24 bits LSB first
#define key_0005 0xF330CC00 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0x330CCF 24 bits LSB first
#define key_0006 0xF340CB00 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xD302CF 24 bits LSB first
#define key_0007 0xF350CA00 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0x530ACF 24 bits LSB first
#define key_0008 0xF360C900 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0x9306CF 24 bits LSB first
#define key_0009 0xF370C800 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0x130ECF 24 bits LSB first
#define key_0010 0xF380C700 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xE301CF 24 bits LSB first
#define key_0011 0xF390C600 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0x6309CF 24 bits LSB first
#define key_0012 0xF3C0C300 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xC303CF 24 bits LSB first
#define key_0013 0xF300CF00 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xF300CF 24 bits LSB first
#define key_0014 0xF270D800 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0x1B0E4F 24 bits LSB first
#define key_0015 0xFA305C00 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0x3A0C5F 24 bits LSB first
#define key_0016 0xF590A600 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0x6509AF 24 bits LSB first
#define key_0017 0xF080F700 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xEF010F 24 bits LSB first
#define key_0018 0xF560A900 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0x9506AF 24 bits LSB first
#define key_0019 0xFF400B00 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xD002FF 24 bits LSB first
#define key_0020 0xF570A800 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0x150EAF 24 bits LSB first
#define key_0021 0xF6109E00 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0x79086F 24 bits LSB first
#define key_0022 0xF580A700 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xE501AF 24 bits LSB first
#define key_0023 0xF060F900 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0x9F060F 24 bits LSB first
#define key_0024 0xF2F0D000 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xB0F4F 24 bits LSB first
#define key_0025 0xF3A0C500 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xA305CF 24 bits LSB first
#define key_0026 0xF2D0D200 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0x4B0B4F 24 bits LSB first
#define key_0027 0xF2E0D100 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0x8B074F 24 bits LSB first
#define key_0028 0xF020FD00 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xBF040F 24 bits LSB first
#define key_0029 0xF2C0D300 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xCB034F 24 bits LSB first
#define key_0030 0xF9006F00 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xF6009F 24 bits LSB first
#define key_0031 0xF120ED00 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xB7048F 24 bits LSB first
#define key_0032 0xF5A0A500 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xA505AF 24 bits LSB first
#define key_0033 0xF070F800 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0x1F0E0F 24 bits LSB first
#define key_0034 0xF000FF00 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xFF000F 24 bits LSB first
#define key_0035 0xFE801700 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xE8017F 24 bits LSB first
#define key_0036 0xFE401B00 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xD8027F 24 bits LSB first
#define key_0037 0xFD802700 // Protocol=PULSE_DISTANCE Address=0x0 Command=0x0 Raw-Data=0xE401BF 24 bits LSB first

