/*
 * Filename: printChar.s
 * Author: jinye xu
 * userid: cs30xen
 * Description: print the character argument to stdout 
 * Date: Oct. 16
 * Source of Help:Piazza
 */


	.global	printChar

	.section ".data"

fmt:
	.asciz	"%c"

	.section ".text"


printChar:
	save	%sp, -96, %sp

	set	fmt, %o0
	mov	%i0, %o1
	call 	printf
	nop

	ret 
	restore
