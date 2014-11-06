/*
 * Filename: testclear.c
 * Author: jinye xu
 * Userid: cs30xen
 * Description: Unit test program to test the function clear
 * Date: Nov. 1, 2014
 * Sources of Help: Piazza 
 */ 

#include <stdio.h>
#include <errno.h>

#include "test.h"
#include "pa2.h"
#include "strings.h"


/*
 * void clear(unsigned int lightBank[], const unsigned int bank0, 
 * const unsigned int bank1);
 */

void 
testclear(){
  printf("Testing clear()\n");

  unsigned int lightBank[2];

  lightBank[0]=0x00000000;
  lightBank[1]=0x00000000;
   
  clear(lightBank,0x12345678,0xFFFFFFFF);
  TEST(lightBank[0]==0x00000000&&lightBank[1]==0x00000000);
  

  lightBank[0]=0xFFFFFFFF;
  lightBank[1]=0x00000001;

  clear(lightBank,1,1);
  TEST(lightBank[0]==0xFFFFFFFE&&lightBank[1]==0x00000000);

  lightBank[0] = 1;
  lightBank[1] = 0;
  clear(lightBank,1,1);
  TEST(lightBank[0]==0&&lightBank[1]==0);


  lightBank[0] = 1;
  lightBank[1] = 0;
  clear(lightBank,0,0);
  TEST(lightBank[0]==1&&lightBank[1]==0);
  

  
  
  printf("Finishing running tests on clear()\n"); 




}

int
main(){

  testclear();
  return 0;

}
