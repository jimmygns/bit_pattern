/*
 * Filename: main.c
 * Author: jinye xu
 * userid: cs30xen
 * Description: interface, print error messages, display the patterns
 * Date: Nov. 1
 * Source of Help: Piazza
 */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "pa2.h"
#include "strings.h"

#define BASE 0

int ptrError = EINVAL;

int main(int argc, char *argv[]){

  (void) setvbuf(stdout, NULL, _IONBF,0);

  unsigned int lightBank[NUM_OF_BANKS];

  lightBank[0]=0;
  lightBank[1]=0;

  const char const *commands[]={COMMANDS,'\0'};

  int prompt=FALSE;

  FILE *inFile;

  if(argc>2){
    (void)fprintf(stderr,STR_USAGE_MSG,argv[0]);
    return 0;
  }

  if(argc==1){
    prompt=TRUE;
  }
  else
    inFile=fopen(argv[1],"r");


  char buf[BUFSIZ]={0};
  if(prompt==TRUE)
    inFile=stdin;
  char *buf2=buf;
  

  long output1,output2;
  displayLights(lightBank);
  for(DISPLAY_PROMPT; fgets( buf, BUFSIZ, inFile ) != NULL; DISPLAY_PROMPT ){
    char *cmdTok, *argOneTok, *argTwoTok;
    
    

    cmdTok=strtok(buf2, TOKEN_SEPARATORS);
    if(cmdTok==NULL)
      continue;




    /*
     * check what commands to use
     */
    int cmd=checkCmd(cmdTok,commands);
    if(cmd==-1){
      (void)fprintf(stderr,STR_BAD_CMD);
      continue;
    }



    /* cases of set, clear and toggle
     * those who need two arguments
     * checking if there are enough arguments
     */


    if(cmd<3){
      argOneTok = strtok(NULL, TOKEN_SEPARATORS);
      if(argOneTok==NULL){
        (void)fprintf(stderr,STR_ARGS_REQ);
        continue;
      }

      argTwoTok = strtok(NULL, TOKEN_SEPARATORS);
      if(argTwoTok==NULL){
        (void)fprintf(stderr,STR_TWO_ARGS_REQ);
        continue;

      }


      /* arguments are all legal
       * converting the string to long
       */
      output1=strToULong(argOneTok,BASE);
      if(errno==EINVAL){
        (void)fprintf(stderr,STR_STRTOLONG_NOTINT, argOneTok);
        continue;
      }

      //checking the errno
      else if(errno!=0){
        char  bufferError1[100];
        (void)snprintf(bufferError1, 100, STR_STRTOLONG_CONVERTING,
            argOneTok,BASE);
        perror(bufferError1);
        continue;
      }


      /* converting the string to long*/
      output2=strToULong(argTwoTok,BASE);
      if(errno==EINVAL){
        (void)fprintf(stderr,STR_STRTOLONG_NOTINT, argTwoTok);
        continue;
      }


      else if(errno!=0){
        char  bufferError2[100];
        (void)snprintf(bufferError2, 100, STR_STRTOLONG_CONVERTING,
            argTwoTok,BASE);
        perror(bufferError2);
        continue;
      }


    }


    /* cases of shift, rotate and ripple
     * those who only need 1 argument
     * checking if there are enough arguments
     */


    else if(cmd>2&&cmd<6){


      argOneTok = strtok(NULL, TOKEN_SEPARATORS);
      if(argOneTok==NULL){
        (void)fprintf(stderr,STR_ARGS_REQ);
        continue;
      }



      /* arguments are all legal
       * converting the string to long
       */
      output1=strToULong(argOneTok,BASE);
      if(errno==EINVAL){
        (void)fprintf(stderr,STR_STRTOLONG_NOTINT, argOneTok);
        continue;
      }

      //checking the errno
      else if(errno!=0){
        char  bufferError3[100];
        (void)snprintf(bufferError3, 100, STR_STRTOLONG_CONVERTING,
            argOneTok,BASE);
        perror(bufferError3);
        continue;
      }


    }


    switch(cmd){

      case 0:
        set(lightBank,output1,output2);
        displayLights(lightBank);
        break;

      case 1:
        clear(lightBank,output1,output2);
        displayLights(lightBank);
        break;

      case 2:
        toggle(lightBank,output1,output2);
        displayLights(lightBank);
        break;

      case 3:
        shift(lightBank,output1);
        displayLights(lightBank);
        break;

      case 4:
        rotate(lightBank,output1);
        displayLights(lightBank);
        break;

      case 5:
        ripple(lightBank,output1);
        break;

      case 6:
        (void)fprintf(stdout,STR_HELP_MSG);
        break;

      case 7:
        return 0;



    }



  }


  return 0;



}



