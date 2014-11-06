/*
 * Unit Test for ripple.s
 *
 * void ripple( unsigned int mask[], int rippleCnt );
 *
 * Takes mask[0] as high order 32 bits and mask[1] as low order 32 bits
 * and simulates a 64-bit rotate within these two words.
 *
 * Lower 6 bits of rippleCnt is masked to keep rotate range 0-63.
 *
 * Positive rippleCnt - rotate left
 * Negative rippleCnt - rotate right
 */

#include "test.h"       /* For TEST() macro and stdio.h */
#include <stdlib.h>     /* For rand() function prototype */
#include <limits.h>     /* For LONG_MIN and LONG_MAX */
#include "pa2.h"        /* For rotate() function prototype */

void
testripple()
{
    unsigned int mask[2];
    int savedRippleCnt;

    printf( "Testing ripple()\n" );

    /*
     * Test with rippleCnt of 0 - should print nothing .
     */
    mask[0] = 0x01234567;
    mask[1] = 0x89ABCDEF;

    ripple( mask, 0 );

    /*
     * Test masking of lower 6 bits of rotateCnt.
     */

    /* Test with rippleCnt of 64 - should print nothing. */
    mask[0] = 0x01234567;
    mask[1] = 0x89ABCDEF;

    ripple( mask, 64 );
    


    /* Test with rippleCnt of -64 - should print nothing. */
    /* This also tests negating rotateCnt before masking lower 6 bits. */
    mask[0] = 0x01234567;
    mask[1] = 0x89ABCDEF;

    ripple( mask, -64 );

    mask[0] = 0x01234567;
    mask[1] = 0x89ABCDEF;


    ripple(mask, 8);
    
    printf("\n");

    ripple(mask,-8);
    
    
    printf( "Finished running tests on ripple()\n" );

}

int
main()
{
    testripple();

    return 0;
}
