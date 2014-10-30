/*
 * Filename: strToULong.s
 * Author: jinye xu
 * userid: cs30xen
 * Description: convert strings to longs, and check errors
 * Return: ptrError if endptr is not 0. Otherwise return the converted value
 * Date: Oct. 26
 * Source of Help:Piazza
 */

	
	.global errno

	

	.section ".bss"

	.align 4
errno:
	.skip 4


	.global strToULong

	.section ".text"

PTRSIZ=4
endptrOffset=4

strToULong:
	
	save 	%sp,-(92 + PTRSIZ)&-8, %sp
	
	set	errno, %l1
	st	%g0, [%l1]
	
	
	sub	%fp, PTRSIZ, %o1


	mov	%i0,%o0
	mov	%i1,%o2

	call	strtoul
	nop

	clr	%l0
	ld	[%fp-endptrOffset], %l0

	ldub	[%l0], %l0
	
	

	cmp	%g0, %l0
	be	endptr_OK
	nop
	
	set	ptrError, %l2
	ld	[%l2],%l3
	
	st	%l3,[%l1]

	mov	-1,%i0
	ret
	restore
	
endptr_OK:
	
	mov	%o0,%i0

	ret
	restore
	


