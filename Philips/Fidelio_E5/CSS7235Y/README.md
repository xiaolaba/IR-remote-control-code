IR remote of Hi-END CD player, Marantz CD Player CD-17mkiii<br>
<a target="_blank" rel="noopener noreferrer" href="https://camo.githubusercontent.com/08a63bc1f5083cde62fe28e9a5a4e3187073f574/68747470733a2f2f7869616f6c6162612e66696c65732e776f726470726573732e636f6d2f323031382f30342f7869616f6c6162615f617564696f6c61625f38303030735f72656d6f74652e6a7067"><img src="https://camo.githubusercontent.com/08a63bc1f5083cde62fe28e9a5a4e3187073f574/68747470733a2f2f7869616f6c6162612e66696c65732e776f726470726573732e636f6d2f323031382f30342f7869616f6c6162615f617564696f6c61625f38303030735f72656d6f74652e6a7067" alt="Marantz CD Player CD-17mkiii" data-canonical-src="https://xiaolaba.files.wordpress.com/2018/04/xiaolaba_audiolab_8000s_remote.jpg" style="max-width:100%;"></a></p>
<p>Total 36 keys encoded, <a target="_blank" rel="noopener noreferrer" href="/xiaolaba/IR-remote-control-code/blob/master/Marantz/RC-DA17CD/IR-code_Marantz_RC-DA17CD.txt"><img src="/xiaolaba/IR-remote-control-code/raw/master/Marantz/RC-DA17CD/IR-code_Marantz_RC-DA17CD.txt" alt="Marantz RC-DA17CD IR remote control codes" style="max-width:100%;"></a>, few of them are encoded as RC5X, and two more special keys are there, raw timing and manually decoding</p>
<pre><code>2 Raw (12): 900 -900 900 -850 900 -850 1800 -1750 1800 -850 900 DIGITAL 1
3 Raw (10): 900 -900 1750 -1750 1800 -1750 1800 -850 900 DIGITAL 2


900 as one unit, 900 = M, -850 = S, idle is also = S<br>
MS or SM as one bit encoding, total about 1800<br>
MS = bit 0<br>
SM = bit 1<br>
or inverted as you want<br>
decoded stream is something like this</p>
<pre><code>2	Raw (12): (idle 900) (-900 900) (-850 900) (-850 1800) -1750 1800 -850 900 DIGITAL 1
2	Raw (12): (idle 900) (-900 900) (-850 900) (-850 900) (900 -850) (-850 900) (900 -850) (900 idle) DIGITAL 1
             SM         SM         SM         SM         SM         SM         MS         MS
             1          1          1          1          1          1          0          0
             S1         S2         T          command 0b 0b-11100
             
</code></pre>
<pre><code>3 Raw (10): (idle 900) (-900 1750 -1750 1800 -1750 (1800) (-850 900) DIGITAL 2
3 Raw (10): (idle 900) (-900 850) (850 -850) (-850 900) (900 -850) (-850 900) (900 -850) (900 idle) DIGITAL 2
             SM         SM         MS         SM         MS         SM         MS         MS
             1          1          0          1          0          1          0          0
             S1         S2         T          command 0b-10100
             
</code></pre>
<p>this is possible 8 bit schema but RC5 timing or encoding<br>
in case the first two bit is consiered S1, S2, start bits of RC5<br>
bit 3, toggle bit</p>
<p>complete keys encoding <a target="_blank" rel="noopener noreferrer" href="/xiaolaba/IR-remote-control-code/blob/master/Marantz/RC-DA17CD/IR-code_Marantz_RC-DA17CD.txt"><img src="/xiaolaba/IR-remote-control-code/raw/master/Marantz/RC-DA17CD/IR-code_Marantz_RC-DA17CD.txt" alt="download Marantz RC-DA17CD IR remote control codes" style="max-width:100%;"></a></p>
<pre><code>	IR remote decoder RC5/X	 xiaolaba 2018-JUN-19					
seq	Protocol	RAW_CODE	T	ADDRESS	COMMAND	bits	key
1	RC5	0x53F	0	14	3F	12_bits	CD
2	Raw (12): 900 -900 900 -850 900 -850 1800 -1750 1800 -850 900 	DIGITAL 1
3	Raw (10): 900 -900 1750 -1750 1800 -1750 1800 -850 900 		DIGITAL 2
4	RC5X	0x507	1	14	47	12_bits			DIMMER
5	RC5	0x50B	0	14	B	12_bits			TIME
6	RC5	0x510	1	14	10	12_bits			VOLUME +
7	RC5	0x51D	0	14	1D	12_bits			REPEAT
8	RC5	0x53B	1	14	3B	12_bits			A-B
9	RC5	0x511	0	14	11	12_bits			VOLUME -
10	RC5	0x531	1	14	31	12_bits			CANCEL
11	RC5X	0x528	0	14	68	12_bits			EDIT
12	RC5	0x529	1	14	29	12_bits			PROG
13	RC5	0x501	0	14	1	12_bits			1
14	RC5	0x502	1	14	2	12_bits			2
15	RC5	0x503	0	14	3	12_bits			3
16	RC5	0x504	1	14	4	12_bits			4
17	RC5	0x505	0	14	5	12_bits			5
18	RC5	0x506	1	14	6	12_bits			6
19	RC5	0x507	0	14	7	12_bits			7
20	RC5	0x508	1	14	8	12_bits			8
21	RC5	0x509	0	14	9	12_bits			9
22	RC5	0x523	1	14	23	12_bits			&lt;-
23	RC5	0x500	0	14	0	12_bits			0
24	RC5	0x522	1	14	22	12_bits			-&gt;
25	RC5	0x521	0	14	21	12_bits			|&lt;&lt;
26	RC5	0x535	1	14	35	12_bits			&gt;
27	RC5	0x520	0	14	20	12_bits			&gt;&gt;|
28	RC5	0x532	1	14	32	12_bits			&lt;&lt;
29	RC5	0x530	0	14	30	12_bits			II
30	RC5	0x534	1	14	34	12_bits			&gt;&gt;
31	RC5	0x52D	0	14	2D	12_bits			OPEN/CLOSE
32	RC5	0x536	1	14	36	12_bits			STOP
33	RC5	0x51C	0	14	1C	12_bits			RANDOM
34	RC5X	0x518	1	14	58	12_bits			CD TEXT
35	RC5	0x50F	0	14	F	12_bits			SCROLL
36	RC5	0x52B 	1 	14 	2B 	12_bits 		HIGHLIGHT S

