/*
 * Filename: set.s
 * Author: jinye xu
 * userid: cs30xen
 * Description:  sets the lights based on which bits are set 
 *               in the bit patterns specified 
 * Date: Nov. 1
 * Source of Help: Piazza
 */

	.global set

	.section ".text"

set:
	save	%sp,-96, %sp
	
	ld	[%i0],%l0		!lightBank[0]

	ld	[%i0+4],%l1		!lightBank[1]
	
	
	or	%l0,%i1,%l0
	or	%l1,%i2,%l1


	st	%l0,[%i0]
	st	%l1,[%i0+4]

	ret
	restore
