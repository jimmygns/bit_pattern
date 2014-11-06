/*
 * Filename: teststrToULong.c
 * Author: jinye xu
 * Userid: cs30xen
 * Description: Unit test program to test the function strToULong
 * Date: Oct. 28, 2014
 * Sources of Help: Piazza 
 */ 

#include <stdio.h>
#include <errno.h>

#include "test.h"
#include "pa2.h"
#include "strings.h"

int ptrError= EINVAL;

/*
 * unsigned long strToULong(const char* str, const int base)
 * 
 * return the converted long, or error
 */

void
teststrToULong(){
  printf("Testing strToULong()\n");
  
  //const char* str="90";
  //const int base=0;
  
  

  TEST(strToULong("90", 0)==90);

  
  TEST(strToULong("90cc",0)==-1);

  TEST(errno==ptrError);
  
  TEST(strToULong("999999999999",0)==-1);

  TEST(errno!=0);
  TEST(strToULong("123123",0)==123123);
  TEST(errno==0); 
  printf("Finished running tests on strToULong\n");




}

int
main(){
  teststrToULong();
  return 0;
  
}
