# this genertor app is simple tool to build WAVE file upon user input.  
for example, user input bit stream 10, actual IR drive single will be flikcing/off  
the simplicty of IR remote control would be with this basis  
flikcing = IR LED rapidly on and off with certain frequency  
off = IR LED completely off, no emission IR light  
time/duration in between flikcing/off, and more bit stream will form proper control signal.  




### learning material  
Phone jack output, how to get VPinverted phase and the VPP will be 2x

P to max. 
L-GND, R-GND = 1x VPP  
L-R = 2 x VPP, no uses GND

```
//the original code, two channels have same magnitude and phase
            chan_sample[i*2]=sample[i];			// CH1 channel,	
            chan_sample[i*2+1]=sample[i]  	// CH2, thus phone jack output, L- R same phase, refer to GND, 


//change code design, double magnitude
            chan_sample[i*2]=sample[i];			// CH1 channel,	
            chan_sample[i*2+1]=sample[i] * -1; 	// inverted as CH2, thus phone jack output, L-R will get the greatest voltage, no GND used for IR
			
```

### generated wav and intermedeate files for learning  
this is output and plot, it can be seen with 2CH.csv, seeing inverted phase and the VPP will be 2x  
![how-to-get-VPP_max.JPG](how-to-get-VPP_max.JPG)  

this is output wave, uses Audicity to load the 1010.wav, see the same,  
phone jack output will boost to double and drive IR LED  
![how-to-get-VPP_max_wav.JPG](how-to-get-VPP_max_wav.JPG)  

electrical connection like this,  
![IR-circuit.JPG](IR-circuit.JPG)  







