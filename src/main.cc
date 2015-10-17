//converts wav files to my special format which is as follows:

//sample rate of 22050Hz
//file extension .w8

//the file is made up of two sections:
//-4 bytes which contain the number of samples
//-the samples which are all one signed byte


#include <stdio.h>
#include <stdint.h>

#include <sndfile.hh>


#define OUT_SAMPLE_RATE 22050


//converts from some wav format to the daly format
char * convert(short * inData,int size,int sampleRate)
{
  int outSize = size / sampleRate * OUT_SAMPLE_RATE;
  char * outData = new char[outSize];

  for (int i = 0;i < outSize;i++)
  {
    int sampleIndex = (int)((float)i / OUT_SAMPLE_RATE * sampleRate);
    outData[i] = (char)(inData[sampleIndex] >> 8);
  }

  return outData;
}


//read in all of the input file's data and transfer it to the output file
void transfer(char * inFilename,char * outFilename)
{
  //read in the data
  SndfileHandle wavFile;
  wavFile = SndfileHandle(inFilename);
  int frames = wavFile.frames();
  int size = wavFile.channels() * (int)wavFile.frames();
  short * data = new short[size];
	wavFile.read(data,size);

  //convert the data to my format
  char * convertedData = convert(data,size,wavFile.samplerate());

  //delete the old data I guess
  delete[] data;

  //now write it into my new file!!
  FILE * outFile = fopen(outFilename,"w");
  fwrite(&frames,4,1,outFile);
  fwrite(convertedData,1,size / wavFile.samplerate() * OUT_SAMPLE_RATE,outFile);
  fclose(outFile);
}


int main(int argc,char * * argv)
{
  if (argc != 3)
  {
    printf("you used the wrong number of arguments, fuckhead\n");
    return -1;
  }

  //open the file and shit
  transfer(argv[1],argv[2]);

  return 0;
}
