//|---------------------------------------------------------------------------
//|   DESCRIPTION
//|  IR wave builder is a tool to assemble .wav audiofiles which contain the
//|  neededed data to emulate a IR remote with two 940nm LEDs driven on the
//|  audio jsck of any device. The IR assembly is built upon the raw IR 
//|  information modulation. The code assumes as an input a signal divided in 
//|  timeunits of equal length. This contains a known number of carrier 
//|  frequency periods. (16 in Philips RC6). The whole code then binary encoded
//|  as a list of high(1) and low(0) timeunits.
//|---------------------------------------------------------------------------

// origial https://github.com/najiji/audio-jack-tv-remote, no fork
// modified for NEC2 procotol and exapaned bit stream; xiaolaba, 2018

/*
// under ubuntu of win10, modified main.cpp has to be chmod every time before it could be compiled.
cd audio-jack-IR-remote
cd generator
chmod +666 main.cpp
g++ main.cpp -o ir_wave_tool $(pkg-config sndfile --cflags --libs)
./ir_wave_tool
*/


#include <iostream>
#include <cmath>
#include "sndfile.hh"

#include <string.h> // for strcat

int main (int argc, const char * argv[])
{
    //---------------------------Configuration-------------------------------
    const int sampleRate=44100; // Audio sample rate
    const int channels=2;       // The number of audio channels to produce

//#define NEC2
#define RC6


#if defined NEC2	
    const int cfreq=38000;      // The NEC infrared carrier frequency, 38KHz, 1T = 9/16ms = 546us
								// logic 0 = 1T brust + 1T silent or off, logic 1 = 1T brust + 3T silent or off
								// xiaolaba 2018
								// https://xiaolaba.wordpress.com/2018/03/29/bose-lifestyle-5-music-system-%e6%94%b9%e8%a3%9d-ir-%e9%81%99%e6%8e%a7/
								// NEC encode to RC6, 1T brust = 1 bit brust, 1T slient = 1 bit silent
								// NEC header = 16T brust +　8T slient = bit stream 11111111 11111111 00000000
	
#endif

#if defined RC6
	//https://www.sbprojects.net/knowledge/ir/rc6.php	
    const int cfreq=36000;      // The philips RC6infrared carrier frequency
    const int pperunit=16;      // The carrier frequency period per time unit, RC6, 1T = 1/36KHZ * 16 = 444us

	// leader pluse = 6T pluses, 2T off
	// data bits = LS,SB,mb2,mb1,mb0,TR,a7-a0,c7-c0 = 22bit x 2T = 44T
	// singal free = 6T off
	// total lenght 58T
    const int length=58;        // Total length of a code (in time units)  
	
    const int multiplier=1;    // The amount of times the code should be repeated
    //---------------------------Configuration END---------------------------
#endif

    std::cout << "Type in your IR command (1=high, 0=low) \n";
    char command[length];
    std::cin >> command;
    std::cout << "Type in the command name (default .wav) \n";
    char outfilename[20];
    std::cin >> outfilename;
	char wav[]=".wav";			// default .wav
	strcat(outfilename, wav);	//
	
    // Prepare sample buffer array
#if defined RC6
    int size = sampleRate*(float(1)/cfreq)*pperunit*length;	// RC6
#elif defined NEC2
    int size = sampleRate*(float(1)/cfreq)*pperunit*length;	// NEC2
#endif
    std::cout << "Creating a wave file with a length of " << size << "\n";
    float sample[size];

	std::cout << "open csv\n";
	FILE *fp;
	fp = fopen("carrier.csv","wb");	//open file
	fprintf(fp, "sine_table\n");	//https://www.cplusplus.com/reference/cstdio/fprintf/  Use the shortest representation: %e or %f

    
	// Put carrier frequency in array
    std::cout << "Storing carrier frequency\n";
    for (int i=0; i<size; i++) //put carrier frequency on whole signal
    {
        sample[i]=sin(float(i)/size*M_PI*cfreq*(float(size)/float(sampleRate)));
        //float(i)/size = factor >=0 & <=1 , last number halfwave multiplicator if==1 -> sine runs only from 0-pi
		std::cout << sample[i];
		std::cout << ",";
		
		// write to file, save carrier frequency table to be *.csv
		//https://rosettacode.org/wiki/Write_float_arrays_to_a_text_file#C
		fprintf(fp, "%.5g\n", sample[i]);		//https://www.cplusplus.com/reference/cstdio/fprintf/  Use the shortest representation: %e or %f
		//fprintf(fp,",");
    }
    std::cout << "\n";	// output to screen
	fprintf(fp, "\n");	// output to file
	fclose(fp);			// close file
    

//	fp = fopen("modified_carrier.csv","wb");	//open file
	// modify carrier frequency
    std::cout << "modifying timeunits\n";
    for(int c=0; c<length; c++)
    {
        if(command[c] == '0') // if no carrier frequency
        {
            int samplepos_end = floor((c+1)*sampleRate*(float(1)/cfreq)*pperunit);
            for(int samplepos = floor(c*sampleRate*(float(1)/cfreq)*pperunit); samplepos<samplepos_end; samplepos++)
            {
                sample[samplepos] = 0;
            }
        }
    }
    //std::cout << "\n";
//	fprintf(fp, "\n");	// output to file
//	fclose(fp);			// close file
	


	fp = fopen("2CH.csv","wb");	//open file
	fprintf(fp, "CH_L,CH_R\n");	//https://www.cplusplus.com/reference/cstdio/fprintf/  Use the shortest representation: %e or %f
    
	// Copy channel to second channels
	// WAV file format, data only, not header, https://www.jianshu.com/p/947528f3dff8
    float chan_sample[size*channels];
    for(int i=0; i<size; i++) //process every sample
    {
        if (channels==1)
        {
            chan_sample[i]=sample[i];	// 8bit single channel
        }
        if (channels==2)
        {

            chan_sample[i*2]=sample[i];			// CH1 channel,	
            chan_sample[i*2+1]=sample[i] * -1; 	// inverted as CH2, thus phone jack output, L-R will get the greatest voltage, no GND used for IR
				
			//output to screen
			std::cout << sample[i];
			std::cout << " ";
			
			// print two columns csv.
			fprintf(fp, "%.5g", chan_sample[i*2]);	//https://www.cplusplus.com/reference/cstdio/fprintf/  Use the shortest representation: %e or %f
			fprintf(fp, ",");
			fprintf(fp, "%.5g", chan_sample[i*2+1]);//https://www.cplusplus.com/reference/cstdio/fprintf/  Use the shortest representation: %e or %f
			fprintf(fp, "\n");	// output to file			

        }
    }
    std::cout << "\n";

	fprintf(fp, "\n");	// output to file
	fclose(fp);			// close file

	



	
    // Multiply whole buffer
    float multipl_sample[size*channels*multiplier];
    int x=0;
    int q=0;
    for(int i=1; i<=multiplier; i++)
    {
        while(x<size*channels*i)
        {
            multipl_sample[x] = chan_sample[q];
            q++;
            x++;
			
			std::cout << multipl_sample[x];
			std::cout << " ";		
        }
        q=0;
    }

    
	// Write File
    std::cout << "writing file with " << sizeof(sample) <<"\n";

	// http://www.mega-nerd.com/libsndfile/api.html
	// SF_FORMAT_WAV          = 0x010000,     /* Microsoft WAV format (little endian). */
	// SF_FORMAT_PCM_16       = 0x0002,       /* Signed 16 bit data */
    const int format=SF_FORMAT_WAV | SF_FORMAT_PCM_16;	
   
	//  const int format=SF_FORMAT_WAV | SF_FORMAT_FLOAT;
    SndfileHandle file;
    file = SndfileHandle(outfilename, SFM_WRITE, format, channels, sampleRate);
    file.write(multipl_sample, size*channels*multiplier);
    
    return 0;
}


