//converts wav files to my special format which is as follows:

//sample rate of 22050Hz
//file extension .w8

//the file is made up of two sections:
//-4 bytes which contain the number of samples
//-the samples which are all one signed byte


#include <stdio.h>
#include <stdint.h>

#include <sndfile.hh>


//converts from some wav format to the daly format
void convert(short * data)
{
  

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



  //now write it into my new file!!
  FILE * outFile = fopen(outFilename,"w");
  fwrite(&frames,4,1,outFile);
  fwrite()


  return size;
}


int main(int argc,char * * argv)
{
  if (argc != 3)
  {
    printf("you used the wrong number of arguments, fuckhead\n");
    return -1;
  }

  //open the file and shit
  short * data = readWav(argv[1]);

  return 0;
}
