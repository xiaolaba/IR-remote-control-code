# IR-remote-control-code
collection of IR-remote-control-code
xiaolaba

osc = 0x50


update

old project based on https://github.com/najiji/audio-jack-tv-remote, build at minGW or ubuntu, save to github.

3.5mm earphone jack output to IR LED pair, and a static HTML file, IR signal encoded as WAV file, imitate IR streaming code and remote control, works for Android/iOS/PC, no need cellphone APP & development, but general HTML coding is required.

IR RAW code and procotol is available, IR remote control (NEC2 procotol) of myTV-super & MagicTV_MTV7000 are tested.  
NEC protocol and scratching from hard to a very simple timing diagram,
https://xiaolaba.wordpress.com/2018/03/29/bose-lifestyle-5-music-system-%e6%94%b9%e8%a3%9d-ir-%e9%81%99%e6%8e%a7/

### project file upload  
demo for IR remote control via phone jack. [readme](/audio-jack-IR-remote/generator/#readme)  
[/audio-jack-IR-remote/generator/](/audio-jack-IR-remote/generator/) 


![/audio-jack-IR-remote/generator/modified_code.JPG](/audio-jack-IR-remote/generator/modified_code.JPG)



### mir.exe release, 2022-JAN-01 update, how to uses  
go to release page, https://github.com/xiaolaba/IR-remote-control-code/releases/tag/1.0  
download 3 files,  
```
mir.exe
my.html
myTVsuper_CH+.wav
```
run mir.exe, 2 more wav will be produced as,  
```
myTVsuper_CH+_filtered.wav
myTVsuper_CH+_modulated.wav
```

uses Audacity to load all 3 wave files together, will see the wave clean up and IR signal brusting  
