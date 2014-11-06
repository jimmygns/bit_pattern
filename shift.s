/*
 * Filename: shift.s
 * Author: jinye xu
 * userid: cs30xen
 * Description: shift the current light patterns in the light banks
 *              by shiftCnt places
 * Date: Nov. 1
 * Source of Help: Piazza
 */

	
	.global	shift

	.section ".text"

MSB_MASK=0x80000000

LSB_MASK=0x00000001

shift:
	save	%sp, -96, %sp

	ld	[%i0],%l0		!lightBank[0]

	ld	[%i0+4],%l1		!lightBank[1]
		
	set	0x0000003F, %l2		!bit mask
	set	MSB_MASK,%l5
	

	and	%i1,%l5,%l6
	

	cmp	%l6,%g0
	be	pre_shift_left
	nop
	
	neg	%i1
	and	%i1,%l2,%l3		!shiftCnt
	
shift_right:
	
	cmp	%l3,0
	be	store
	nop

	and	%l0,LSB_MASK,%l4

	sll	%l4,31,%l4

	srl	%l0,1,%l0
	srl	%l1,1,%l1
	
	or	%l4,%l1,%l1
	
	dec	%l3
		
	ba	shift_right
	nop

pre_shift_left:

	and	%i1,%l2,%l3		!shiftCnt

shift_left:
	cmp	%l3,0
	be	store
	nop

	and	%l1,%l5,%l4

	srl	%l4,31,%l4

	sll	%l0,1,%l0
	sll	%l1,1,%l1
	
	or	%l4,%l0,%l0
	
	dec	%l3
		
	ba	shift_left
	nop

	
store:
	st	%l0,[%i0]
	st	%l1,[%i0+4]

	ret
	restore

	




