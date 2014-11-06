/*
 * Filename: ripple.s
 * Author: jinye xu
 * userid: cs30xen
 * Description: rotates the current light patterns in the light banks by 
 *		rippleCnt places displaying the light banks after each 
 *		single bit rotate 
 * Date: Nov. 1
 * Source of Help: Piazza
 */

	.global ripple
	.section ".text"

MSB_MASK=0x80000000

LSB_MASK=0x00000001

ripple:
	save	%sp,-96,%sp

	ld	[%i0],%l0		!lightBank[0]

	ld	[%i0+4],%l1		!lightBank[1]
	

	mov	0x0000003F, %l2		!bit mask
	
	set	MSB_MASK,%l6		!setting MSB_MASK to %l6
	and	%i1,%l6,%l4		!checking the sign
	

	cmp	%l4,%g0			!check the sign
	be	pre_rotate_left		!positive
	nop
	
	neg	%i1
	and	%i1,%l2,%l3		!rippleCnt to %l3
	cmp	%l3,%g0			!if it rotates
	be	end
	nop
		
	

rotate_right:

	and	%l0,LSB_MASK,%l4
	sll	%l4,31,%l4

	and	%l1,LSB_MASK,%l5
	sll	%l5,31,%l5

	srl	%l0,1,%l0
	srl	%l1,1,%l1
	
	or	%l4,%l1,%l1
	or	%l5,%l0,%l0
	
	st	%l0,[%i0]
	st	%l1,[%i0+4]
	mov	%i0,%o0
	call	displayLights
	nop


	dec	%l3
	cmp	%l3,%g0	
	bg	rotate_right
	nop

	ba	store
	nop


pre_rotate_left:

	and	%i1,%l2,%l3		!roateCnt to %l3
	cmp	%l3,%g0			!if it rotates
	be	end
	nop
		

rotate_left:
	and	%l0,%l6,%l4
	srl	%l4,31,%l4

	and	%l1,%l6,%l5
	srl	%l5,31,%l5

	sll	%l0,1,%l0
	sll	%l1,1,%l1
	
	or	%l4,%l1,%l1
	or	%l5,%l0,%l0

	st	%l0,[%i0]
	st	%l1,[%i0+4]
	mov	%i0,%o0
	call	displayLights
	nop
	

	dec	%l3
	cmp	%l3,%g0	
	bg	rotate_left
	nop

	ba	store
	nop
	
store:
	st	%l0,[%i0]
	st	%l1,[%i0+4]

	ret
	restore
end:
	ret
	restore
	



	
	
