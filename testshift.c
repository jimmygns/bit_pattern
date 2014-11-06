/* Filename:  testshift.c
 * Author: jinye xu
 * Userid: cs30xen
 * Description: Unit test program to test the function shift
 * Date: Nov. 1, 2014
 * Sources of Help: Piazza 
 */ 

#include <stdio.h>
#include <errno.h>

#include <limits.h>     /* For LONG_MIN and LONG_MAX */

#include "test.h"
#include "pa2.h"
#include "strings.h"


/*
 * shift(unsigned int lightBank[], const int shiftCnt)
 */

void
testshift(){
  printf("Testing shift()\n");

  unsigned int mask[2];
  
  
  mask[0]=0x01234567;
  mask[1]=0x89ABCDEF;

  /*
   * Test with shiftCnt of 0 - should be no change.
   */

  shift(mask,0);
  TEST(mask[0]== 0x01234567 && mask[1] == 0x89ABCDEF );

  shift(mask,32);
  TEST(mask[0]== 0x89ABCDEF && mask[1] == 0x00000000 );


  mask[0]=0x01234567;
  mask[1]=0x89ABCDEF;
  
  shift(mask,-32);
  TEST(mask[0]== 0x00000000 && mask[1] == 0x01234567 );
  

  mask[0]=0xFFFFFFFF;
  mask[1]=0xFFFFFFFF;
  
  shift(mask,-2);
  TEST( mask[0]== 0x3FFFFFFF && mask[1] == 0xFFFFFFFF );
  

  mask[0]=0x01234567;
  mask[1]=0x89ABCDEF;
  
  shift(mask,64);
  TEST(mask[0]== 0x01234567 && mask[1] == 0x89ABCDEF );
  //printf("\n%x %x\n",mask[0],mask[1]); 

  /*
   * should shift left by 1 bit
   */
  mask[0]=0xFFFFFFFF;
  mask[1]=0xFFFFFFFF;
  shift(mask,65);
  TEST(mask[0]== 0xFFFFFFFF && mask[1] == 0xFFFFFFFE );


  /*
   * should shift right by 1 bit
   */
  mask[0]=0xFFFFFFFF;
  mask[1]=0xFFFFFFFF;
  shift(mask,-65);
  TEST(mask[0]== 0x7FFFFFFF && mask[1] == 0xFFFFFFFF );
  

  printf("Finished running tests on shift\n");




}

int
main(){
  testshift();
  return 0;


}
