#include <fcntl.h>
#include <iostream>
#include <sys/mman.h>
#include <string.h>
#include <assert.h>

using namespace std;


int main(int argc, const char **argv)
{
  int v3; 
  char EXPECTED_RESULT[1000] = "bdghnoqqtvxz"; //// you should pick-up this string from your own challenge
  char v4; 
  char v5; 
  int i; 
  int j; 
  int k; 
  int fd; 
  char *v10; 
  char dest[100]; 
  int v12; 
  char v13; 
  uint64_t v14; 
  puts("###");
  printf("### Welcome to %s!\n", *argv);
  puts("###");
  putchar(10);
  puts("This license verifier software will allow you to read the flag.");
  puts("However, before you can do so, you must verify that you are licensed to read flag files!");
  puts("This program consumes a license key over some communication channel that you must figure out.");
  puts("You must also figure out (by reverse engineering this program) what that license key is.");
  puts("Providing the correct license key will net you the flag!");
  v12 = 0;
  v13 = 0;
  puts("Ready to receive your license key!");
  fd = open("jdofj", 0); /// file name is probably custom per chal
  memcpy(&dest, v10 + 8, 0xC);
  
  for ( int i = 0; i <= 5; ++i )
  {
    v5 = dest[i];
    dest[i] = dest[i-11];
    dest[11-i] = v5;
  }
  
  for ( int j = 0; j <= 10; ++j )
  {
    for (int k = 0; k < 11 - j; ++k )
    {
      if ( dest[k] > dest[k+1] )
      {
        v4 = dest[k] ;
        dest[k] = dest[k+1];
        dest[k+1] = v4;
      }
    }
  }
  printf("\n%x",dest);   //// answer along 12 bytes of EXPECTED_RESULT ------> (dest + EXPECTED_RESULT)
  printf("\n");
  cout << "Exptected :   " << EXPECTED_RESULT << endl;
  puts("Checking the received license key!");
  if ( !strncmp((const char *)&dest, EXPECTED_RESULT, 0xc) )
  {
    puts("Correct! Here is your flag:");
    exit(0);
  }
  puts("Wrong! No flag for you!");
  return 0;
}