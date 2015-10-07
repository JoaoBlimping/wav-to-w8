//converts wav files to my special format which is as follows:

//sample rate of 22050Hz
//file extension .w8

//the file is made up of two sections:
//-3 bytes which contain the number of samples
//-the samples which are all one signed byte


#include <stdio.h>
#include <stdint.h>


int main(int argc,char * * argv)
{
  if (argc != 3)
  {
    printf("you used the wrong number of arguments, fuckhead\n");
    return -1;
  }

  return 0;
}
