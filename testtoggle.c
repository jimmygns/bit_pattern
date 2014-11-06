/*
 * Filename: testtoggle.c
 * Author: jinye xu
 * Userid: cs30xen
 * Description: Unit test program to test the function toggle
 * Date: Nov. 1, 2014
 * Sources of Help: Piazza 
 */ 

#include <stdio.h>
#include <errno.h>

#include "test.h"
#include "pa2.h"
#include "strings.h"


/*
 * void toggle(unsigned int lightBank[], const unsigned int bank0,
 * const unsigned int bank1) 
 */

void
testtoggle(){
  printf("Testing toggle()\n");
 
  unsigned int mask[2];

  mask[0]=0x00000000;
  mask[1]=0x00000000;

  toggle(mask,0x000000FF,0x000000FE);

  TEST(mask[0]==0x000000FF&&mask[1]==0x000000FE);
  
  mask[0]=1;
  mask[1]=0;
  toggle(mask,0,1);
  TEST(mask[0]==1&&mask[1]==1);


  printf("Finishing running tests on toggle()\n");




}

int
main(){

  testtoggle();
  return 0;
}
