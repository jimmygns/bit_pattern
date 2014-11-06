/*
 * Filename: toggle.s
 * Author: jinye xu
 * userid: cs30xen
 * Description: toggle the lights based on which bits are set
 *              in the bit pattern specified
 * Date: Nov. 1
 * Source of Help: Piazza
 */

	.global toggle
	.section ".text"

toggle:
	save	%sp,-96,%sp

	ld	[%i0],%l0		!lightBank[0]

	ld	[%i0+4],%l1		!lightBank[1]
	
	
	xor	%l0,%i1,%l0
	xor	%l1,%i2,%l1


	st	%l0,[%i0]
	st	%l1,[%i0+4]

	ret
	restore
