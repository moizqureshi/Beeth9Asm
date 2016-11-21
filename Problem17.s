/* Filename: Problem17.s
 * Authors: Moiz Qureshi, Ye Huang, Eduardo Rosales
 * Description: Assembly Instructions for Problem 17 using Beeth9 ISA
 * Date: 10/9/2016
 */

/* Problem 17 Pseudocode
 * 1.  A (multiplicand)
 * 2.  empty (product-hi)
 * 3.  B (multiplier & product-lo)
 * 4.  if LSB of B is 1: add A to product-hi, and shift the LSB of prodcut-hi 
 *     into the MSB of B (product-lo), and the LSB of B (product-lo) out (shift
 *     product-hi-lo right by 1 bit)
 * 5.  else: shift the LSB of product-hi into the MSB of B (product-lo), and 
 *     the LSB of B (product-lo) out (shift product-hi-lo right by 1 bit)
 * 6.  Repeat steps 1-5 twice with C as the multiplcand and product-lo and 
 *     product-hi as the two different multipliers
 * 7.  Add CAB-productHI-lo to CAB-productLO-hi
 * 8.  Product-HI = CAB-productLO-hi
 * 9.  Product-LO = CAB-productLO-lo

/* Registers Used:
 * r0 - temporary register
 * r1 - A (Multiplicand) & C (Multiplicand)
 * r2 - Product-HI (of A*B) & Product-LO (of C*A*B-HI) 
 * r3 - Product-LO (of A*B) & Product-LO of (C*A*B-LO) & Product-LO (of C*A*B) 
 * r4 - Product-HI (of C*A*B-LO) & Product-HI (of C*A*B)
 * r5 - Product-HI (of C*A*B-HI)  
 * r6 - counter for loops
 * r7 - branch offsets
 * rOv - overflow register (here just for identification)
 */

	li 1			# load value of 1 into r0
	add $r1, $r0		# copy r0 ito r1 (mem address of A)

	li 2			# load value of 2 into r0
	add $r3, $r0		# copy r0 to r3 (mem address of B)
	
	lw ($r1)		# load value of A into r1 from memory
	lw ($r3)		# load value of B into r3 from memory

	li 8			# load value of 8 into r0
	add $r7, $r0		# copy r0 to r7 (loop limit = 8)
	
	slt $r6, $r7		# rOv = (r6 < r7) ? 1:0

	li 16			# load 15 into r0, offset to CmultABLoInit
	bez $r0			# if rOv == 0, then branch to CmultABLoInit
	
	li 1			# load value of 1 into r0 (0x01 bitmask)	
	and $r0, $r3		# r0 = (r0 & r3)
	clsb $r0		# rOv = if (r0 & 0x01 == 0x01) ? 1:0
	
	li 2			# load 1 into r0, offset to shiftProd1
	bez $r0			# if rOv == 1, then branch to shiftProd1
	
	add $r2, $r1		# r2 = r1 + r2; Add A to Product-HI (A*B)

	srl $r2			# right shift r2 (LSB goes into rOv)
	clr $r0			# clear r0
	getov $r0		# set the MSB of r0 to the value of rOv
	
	srl $r3			# right shift r3 (LSB goes into rOv)
	or $r3, $r0		# r3 = r3 | r0

	inc $r6			# increment r6 by 1
	
	li 19			# load 18 into r0
	twcmp $r0		# take 2's Comp of r0 to get -18, offset val
	branch $r0		# branch always to AmultBLoop

	li 3			# load value of 3 into r0 
	add $r1, $r0		# copy r0 to r1 (mem address of C)
	lw ($r1)		# load value of C into r1 from memory
	clr $r6			# reset counter = 0	

	li 8			# load value of 8 into r0
	add $r7, %r0		# copy r0 to r7 (loop limit = 8)
	
	slt $r6, $r7		# rOv = (r6 < r7) ? 1:0
	
	li 16			# load 15 into r0, offset to CmultABHiInit
	bez $r0			# if rOv == 0, then branch to CmultABHiInit

	li 1			# load value of 1 into r0 (0x01 bitmask)
	and $r0, $r3		# r0 = (ro & r3)
	clsb $r0		# rOv = if (r0 & 0x01 == 0x01) ? 1:0
	
	li 2			# load 1 into r0, offset to shiftProd2
	bez $r0			# if rOv == 0, then branch to shiftProd2
	
	add $r4, $r1		# r4 = r4 + r1; Add C to Product-HI (C*A*B-Lo)

	srl $r4			# right shift r4 (LSB goes into rOv)
	clr $r0			# clear r0
	getov $r0		# sets the MSB of r0 to the value of rOv

	srl $r3			# right shift r3 (LSB goes into rOv)
	or $r3, $r0		# r3 = r3 | r0

	inc $r6			# increment r6 by 1
	
	li 19			# load 18 into r0	
	twcmp $r0		# take 2's Comp of r0 to get -18, offset val
	branch $r0		# branch always to CmultABLoLoop

	clr $r6 		# reset counter = 0

	li 8			# load value of 8 into r0
	add $r7, %r0		# copy r0 to r7 (loop limit = 8)
	
	slt $r6, $r7		# rOv = (r6 < r7) ? 1:0
	
	li 16			# load value of 15 into r0, offset to end
	bez $r0			# if rOv == 0, then branch to end

	li 1			# load value of 1 into r0 (0x01 bitmask)
	and $r0, $r2		# r0 = (r0 & r2)
	clsb $r0		# rOv = if (r0 & 0x01 == 0x01) ? 1:0
	
	li 2			# load value of 1 into r0, offset to shiftProd3
	bez $r0			# if rOv == 0, then branch to shiftProd3
	
	add $r5, $r1		# r5 = r5 + r1; Add C to Product-HI (C*A*B-Hi)


	srl $r5			# right shift r5 (LSB goes into rOv)
	clr $r0			# clear r0
	getov $r0		# sets the MSB of r0 to the value of rOv

	srl $r2			# right shift r2 (LSB goes into rOv)
	or $r2, $r0		# r2 = r2 | r0

	inc $r6			# increment r6 by 1

	li 19			# load immediate value of 18 into r0
	twcmp $r0		# take 2's Comp of r0 to get -18, offset val
	branch $r0		# always branch to CmultABHiLoop


	add $r4, $r2 		# add Product-LO (of C*A*B*-Hi) to Product-Hi 
				# (of C*A*B*)

	li 4			# load value of 4 into r0
	sw $r4			# store A*B*C Product-HI into mem address 4, 
				# which is pointed to by r0

	li 5			# load value of 5 into r0
	sw $r3			# store A*B*C Product-LO into mem address 5,
				# which is pointed to by r0
	
	halt			# send halt signal to end program
