/*
 * Filename: checkCmd.c
 * Author: jinye xu
 * userid: cs30xen
 * Description: check if cmdString equals any of the elements of commands 
 * Date: Oct. 26
 * Source of Help:Piazza
 */
 
#include "pa2.h"
#include "strings.h"

int 
checkCmd(const char* const cmdString, const char* const commands[]){
  int i = 0;  
  while(commands[i] != '\0'){
    int result=strcmp(cmdString, commands[i]);
    if(result==0){
      return i;
    }
    
    i++;
  }

  return -1;


}
