/*
 * Filename: testset.c
 * Author: jinye xu
 * Userid: cs30xen
 * Description: Unit test program to test the function set
 * Date: Nov. 1, 2014
 * Sources of Help: Piazza 
 */ 

#include <stdio.h>
#include <errno.h>

#include "test.h"
#include "pa2.h"
#include "strings.h"


/*
 * void set(unsigned int lightBank[], const unsigned int bank0,
 * const unsigned int bank1) 
 */

void
testset(){
  printf("Testing set()\n");
  
  unsigned int lightBank[]={0x12345678,0xFFFFFFFF};
  const unsigned int bank0=0x11111111;
  const unsigned int bank1=0x00000000;

  set(lightBank,bank0,bank1);
  TEST(lightBank[0]==0x13355779);
  TEST(lightBank[1]==0xFFFFFFFF);
 
  lightBank[0]=0x00000000;
  lightBank[1]=0x00000000;

  set(lightBank,0x12345678,0x123ABCDE);

  TEST(lightBank[0]==0x12345678);
  TEST(lightBank[1]==0x123ABCDE);

  
  printf("Finished running tests on set\n");




}

int
main(){
  testset();
  return 0;
  

}
