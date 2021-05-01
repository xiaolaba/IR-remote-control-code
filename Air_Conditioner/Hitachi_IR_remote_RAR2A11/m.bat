:: 
xcopy /f %1 myTVsuper_CH+.wav

:: modulate the wav file
mir

:: change output file name
::ren myTVsuper_CH+_modulated.wav %~n1_modulated.wav
ren myTVsuper_CH+_modulated.wav modulated_%~n1%~x1

pause


:: remove temp files
del myTVsuper_CH+_filtered.wav
del myTVsuper_CH+.wav
del myTVsuper_CH+_modulated.wav

