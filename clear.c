/*
 * Filename: clear.c
 * Author: jinye xu
 * userid: cs30xen
 * Description: clear the lightBank in correspondence to bank0 and bank1 
 * Date: Nov. 1
 * Source of Help: Piazza
 */

#include "pa2.h"
#include "strings.h"

void
clear(unsigned int lightBank[], const unsigned int bank0,
      const unsigned int bank1){
    lightBank[0]=(~(lightBank[0] & bank0)) & lightBank[0];
    lightBank[1]=(~(lightBank[1] & bank1)) & lightBank[1];


}
