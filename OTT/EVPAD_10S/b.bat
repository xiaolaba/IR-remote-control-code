copy "%1" "%cd%\myTVsuper_CH+.wav"
mir.exe myTVsuper_CH+.wav
copy /y "%cd\%myTVsuper_CH+_filtered.wav" "%cd%\%~n1_filtered.wav"
copy /y "%cd\%myTVsuper_CH+_modulated.wav" "%cd%\%~n1_modulated.wav"

del "%cd%\myTVsuper*.wav"

pause