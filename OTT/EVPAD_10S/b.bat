copy "%1" "%cd%/myTVsuper_CH+.wav"
mir.exe myTVsuper_CH+.wav
ren myTVsuper_CH+_filtered.wav %~n1_filtered.wav
ren myTVsuper_CH+_modulated.wav %~n1_modulated.wav

pause