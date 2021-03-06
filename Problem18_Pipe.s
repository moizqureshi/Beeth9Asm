/* Filename: Problem18.s
 * Authors: Moiz Qureshi, Ye Huang, Eduardo Rosales
 * Description: Assembly Instructions for Problem 18 using Beeth9 ISA
 * Date: 10/9/2016
 */

/* Problem18 Pseduocode:
 * 1. Get 4-bit Pattern from memory
 * 2. while i < 64: (since there are 64 byte elements in the array)
 * 3. 	use special "patr" instruction to determine if 4-bit pattern
 * 	exists within the 5 locations of the byte in the array
 * 4.   if byte contains at least one pattern, increment pattern count
 * 5. store pattern count to memory

/* Registers Used:
 * r0 - temporary register
 * r1 - bit pattern loaded from mem address 6 
 * r2 - temporary array byte element holder
 * r3 - start mem address of array (32) and increments to get next byte 
 * 	offset
 * r4 - loop counter
 * r5 - loop limit
 * r6 - holds branch offset
 * r7 - # of total occurences of pattern (once per byte)
 * rOv - overflow register (here just for identification)
 */


	li 6			# load value 6 into r0 (mem address of pattern)
	add $r1, $r0		# copy r0 into r1
	lw ($r1)		# load pattern byte into r1 

	li 32			# load value 32 into r0 (mem address of array)
	add $r3, $r0		# copy r0 into r3


	li 63			# load value 63  into r0 
	add $r5, $r0		# copy r0 into r5
	inc $r5			# increment r5 by 1 (outerloop counter) to get
				# value of 64
	
	add $r5, $r3		# Add 32 to 64, to get outerloop limit

	slt $r4, $r5		# rOv = (r4 < r5) ? 1:0
	
	li 18			# load value of 18 (+offset to end)
	bez $r0			# if rOv == 0, then branch to end
	nop

	clr $r0			# clear r0
	add $r0, $r1		# copy pattern to check for into r0

	clr $r2			# clear r2
	add $r2, $r3		# r2 = r2 + r3
	lw ($r2)		# load next byte value into r2
	
	patr $r2		# checks the five locations of register r2 byte
				# and determines if it contains the 4 bit 
				# pattern in the LSBs of register r0 (r0[3:0]),
				# if so then rOv is set to 1
				# rOv = (r2 contains r0[3:0]) ? 1:0
	
	li 3			# load value of 3 (+offset to loopEnd)
	bez $r0			# if rOv == 0, then branch to loopEnd
	nop
	
	inc $r7			# increment r7 (pattern count), since 4 bit 
				# pattern was found at least once in the byte

	inc $r3			# increment r3 (offset to get next byte)
	inc $r4			# increment r4 (loop counter)
	
	li 18			# load value of 18 into r0
	twcmp $r0		# take 2's complement of 14 to get -14 in r0
	branch $r0		# always branch to loop
	nop

	li 7			# load value of 7 into r0
	sw $r7			# store r7 (pattern count) into mem address
				# pointed by r0 (mem address 7)
	
	halt 			# send halt signal to end program
