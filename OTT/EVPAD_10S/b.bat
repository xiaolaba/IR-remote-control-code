copy "%1" "%cd%/myTVsuper_CH+.wav"
mir.exe myTVsuper_CH+.wav
ren myTVsuper_CH+_filtered.wav %1~n_filtered.wav
ren myTVsuper_CH+_modulated.wav %1~n_modulated.wav

pause