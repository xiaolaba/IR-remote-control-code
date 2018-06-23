
![IR decoded signal](IR-code.txt)

total 36 keys decoded, few of them are encoded as RC5X, and two more special keys are

Raw timing and manually decoding
![code]
2	Raw (12): 900 -900 900 -850 900 -850 1800 -1750 1800 -850 900 DIGITAL 1
3 Raw (10): 900 -900 1750 -1750 1800 -1750 1800 -850 900 DIGITAL 2
[/code]

positive as M
Negative as S
900 as one unit, 900 = M, -850 = S, idle is also = S
MS or SM as one bit encoding, total about 1800
MS = bit 0
SM = bit 1
or inverted as you want
decoded stream is something like this
2	Raw (12): (idle 900) (-900 900) (-850 900) (-850 1800) -1750 1800 -850 900 DIGITAL 1
2	Raw (12): (idle 900) (-900 900) (-850 900) (-850 900) (900 -850) (-850 900) (900 -850) (900 idle) DIGITAL 1
             SM         SM         SM         SM         SM         SM         MS         MS
             1          1          1          1          1          1          0          0
             S1         S2         T          command 0b 0b-11100
             
3 Raw (10): (idle 900) (-900 1750 -1750 1800 -1750 (1800) (-850 900) DIGITAL 2
3 Raw (10): (idle 900) (-900 850) (850 -850) (-850 900) (900 -850) (-850 900) (900 -850) (900 idle) DIGITAL 2
             SM         SM         MS         SM         MS         SM         MS         MS
             1          1          0          1          0          1          0          0
             S1         S2         T          command 0b-10100
             
this is possible 8 bit schema but RC5 timing or encoding
in case the first two bit is consiered S1, S2, start bits of RC5
bit 3, toogle bit

