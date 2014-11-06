/*
 * Filename: testcheckCmd.c
 * Author: jinye xu
 * Userid: cs30xen
 * Description: Unit test program to test the function checkCmd.
 * Date: Oct. 26, 2014
 * Sources of Help: Piazza 
 */ 


#include "test.h"
#include "pa2.h"
#include "strings.h"

/*
 * int checkCmd(const char* const cmdString, const char* const commands[])
 *
 * return the integer that correspond to the string input
 */

void
testcheckCmd(){
  printf("Testing checkCmd()\n");

  const char const *commands[]={COMMANDS,'\0'};
  const char const *string="SET";
  
  TEST(checkCmd(commands[0],commands)==0);
  
  TEST(checkCmd(commands[1],commands)==1);
  TEST(checkCmd(commands[2],commands)==2);
  TEST(checkCmd(commands[3],commands)==3);
 
  
  TEST(checkCmd(string,commands)==-1);


  printf("Finished running tests on checkCmd()\n");
}

int 
main(){

  testcheckCmd();
  return 0;
}




