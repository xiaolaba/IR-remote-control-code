// xiaolaba
// 2018-OCT-28
// MOD, Taiwan CHT OTT service.
// http://mod.cht.com.tw/download/file/mrc42_userguide_www_20141111.pdf

// IR remote control model, MRC42
// MOD IR remote signal, NEC, RAW code 0x7d7dxxxx, 
// that is result of LSB first send first of a byte
// ie. 0x7D = 0b0111,1101, send it MSB fisrt, but store LSB first,
// it became  0b1011,1110 = 0xBE 

#define MOD_NEC_ADDRESS 0xBEBE00
#define MOD_CH_UP 0x7B
#define MOD_CH_DN 0x7C
#define MOD_POWER 0x70
#define MOD_VOL_UP 0x54
#define MOD_VOL_DN 0x55

//#define MOD_CH_UP 0x0f0f0f0f  ;;test dummy
