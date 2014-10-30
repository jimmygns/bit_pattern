/*
 * Filename: displayLights.s
 * Author: jinye xu
 * userid: cs30xen
 * Description: print a pattern to the terminal according to the input
 * Date: Oct. 26
 * Source of Help:Piazza
 */

	.global	displayLights

	.section ".text"

star='*'
dash='-'
space=' '
NL='\n'

displayLights:

	save %sp, -96, %sp
	
	
	clr	%l2			!index checking for loop1 in local register 2
	mov	1,%l2
	

	mov	1,%l6			!index checking for loop2 in local register 6
		
        mov	32, %l3			!loop limit in local register 3

	set	0x80000000, %l4		!bit mask in local register 4

	ld	[%i0],%l0		!the first element

	ld	[%i0+4],%l1		!the second element 


loop1:
	cmp	%l2, %l3		!compare the index to 32
	bg	loop2			!if bigger than or equal to 32 goes to loop2
	nop	
	
	and	%l0, %l4, %l5		!and operation, and %l0, %l4 and store the result in %l5
	cmp	%l5,%l4			!compare %l5 and %l4

	bne	loop10			!not equal means the bit checked is unset, go to loop10
	nop

	mov	star, %o0		!bit checked is set, print *
	call	printChar
	nop
	
	mov	%l2,%o0			!print a space on every bits
	mov	4,%o1			!divide %l2 by 4
	call	.rem
	nop

	cmp	%o0,0			!compare the result to zero
	bne	loop11			!not equal to zero, go to loop11
	nop

	mov	space,%o0		!print a space
	call	printChar
	nop


	sll	%l0,1,%l0		!shift the %l0 to left by 1 bit
	inc	%l2			!incrementing the index %l2

	ba	loop1			!resursive
	nop
	

loop10:
	mov	dash,%o0		!print - for unset bit
	call	printChar
	nop

	mov	%l2,%o0			
	mov	4,%o1
	call	.rem
	nop

	cmp	%o0,0
	bne	loop11
	nop

	mov	space,%o0
	call	printChar
	nop

	sll	%l0,1,%l0	
	inc	%l2

	ba	loop1
	nop

loop11:
	sll	%l0,1,%l0
	inc	%l2

	ba	loop1
	nop





loop2:
	cmp	%l6, %l3
	bg	end
	nop
	
	and	%l1, %l4, %l5
	cmp	%l5,%l4
	bne	loop10
	nop

	mov	star, %o0
	call	printChar
	nop
	
	mov	%l6,%o0
	mov	4,%o1
	call	.rem
	nop

	cmp	%o0,0
	bne	loop21
	nop

	mov	space,%o0
	call	printChar
	nop


	sll	%l1,1,%l1
	inc	%l6

	ba	loop2
	nop
	

loop20:
	mov	dash,%o0
	call	printChar
	nop

	mov	%l6,%o0
	mov	4,%o1
	call	.rem
	nop

	cmp	%o0,0
	bne	loop21
	nop

	mov	space,%o0
	call	printChar
	nop

	sll	%l1,1,%l1	
	inc	%l6

	ba	loop2
	nop

loop21:
	sll	%l0,1,%l0
	inc	%l6

	ba	loop2
	nop

end:
	mov	NL,%O0
	call	printChar
	nop

	ret
	restore
