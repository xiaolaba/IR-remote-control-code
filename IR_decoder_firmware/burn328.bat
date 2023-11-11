

prompt xiao$G$S

::@echo off
@echo :: = REM but no print to screen

::set mcu=ATMEGA8
::set mcu=ATMEGA168P  
set mcu=ATMEGA328P

::mega328 16MHz Xtal arduino nano/uno
set lfuse=0xff
set hfuse=0xda
set efuse=0x05

:: mega328p default fuse 8MHz RC
::set lfuse=0x62
::set hfuse=0xD9
::set efuse=0XFF


set main=IR_decoder.ino.with_bootloader.standard.hex
::set main=IR_decoder.ino.standard.hex


:: Avrdude 6.3, not working with winusb driver usbtiny
::set ac=C:\WinAVR-20100110
::path %ac%\bin;%ac%\utils\bin;%path%;

:: Avrdude 7.1, working with winusb driver usbtiny
set ac=C:\2023-09-25_USBtiny_Avrdude_driver
path %ac%;%path%;

:: test winusb driver + arvdure6.3, result, winusb driver v6.1.1700.16385, usbtiny, not workig 
copy %ac%\avrdude6.3.exe avrdude.exe
copy %ac%\avrdude6.3.conf avrdude.conf

:: test winusb driver + arvdure7.1, result, winusb driver v6.1.1700.16385, usbtiny, good
::copy %ac%\avrdude7.1.exe avrdude.exe
::copy %ac%\avrdude7.1.conf avrdude.conf


@echo on

avrdude -c usbtiny -p %mcu% -U flash:w:"%main%":a -U lfuse:w:%lfuse%:m  -U hfuse:w:%hfuse%:m

pause