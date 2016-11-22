/* Filename: Problem19.s
 * Authors: Moiz Qureshi, Ye Huang, Eduardo Rosales
 * Description: Assembly Instructions for Problem 19 using Beeth9 ISA
 * Date: 10/9/2016
 */

/* Registers Used:
 * r0 - temporary register
 * r1 - current mem address of array 
 * r2 - array[i] byte element holder
 * r3 - array[j] byte element holder
 * r4 - outer loop counter (initially i = 0)
 * r5 - inner loop counter (initially j = 1)
 * r6 - minimum distance (min)
 * r7 - next mem address of array in intermediary steps
 * rOv - overflow register (here just for identification)
 */

	li 19			# load value of 19 into r0 (outer loop limit)
	slt $r4, $r0		# rOv = (r4 < r0) ? 1:0

	li 52			# load value of 48 into r0 (offset to end)
	bez $r0			# if rOv == 0, then branch to end

	clr $r7			# clear r7
	add $r7, $r1		# copy r1 into r7 (current mem address)


	li 20			# load value of 20 into r0 (inner loop limit)
	slt $r5, $r0		# rOv = (r5 < r0) ? 1:0

	li 37			# load value of 42 into r0 (offset to 
				# outerloopend)
	bez $r0			# if rOv == 0, then branch to outloopend

	clr $r2			# clear r2
	add $r2, $r1		# copy r1 into r2
	lw ($r2)		# load i'th byte into r2 (arr[i])
	
	inc $r7
	clr $r3			# clear r3
	add $r3, $r7		# copy r7 into r3 (next mem address)
	lw ($r3)		# load j'th byte into r3 (arr[j])

	clr $r0			# clear r0
	add $r0, $r2		# copy r2 into r0 (keep copy of r2 in r0, 
				# before doing subtraction to get distance)

	slt $r2, $r3		# rOv = (r2 < r3) ? 1:0

	li 6			# load value of 5 into r0 (offset to subtract)
	bez $r0			# if rOv == 0, then branch to subract

	slt $r3, $r2		# rOv = (r3 < r2) ? 1:0

	li 3			# load value of 2 into r0 (offset to subtract)
	bez $r0			# if rOv == 0, then branch to subtract
	
	li 25			# load value of 24 into r0 (offset to 
				# equalElements)

	branch $r0		# since r2 == r3, branch to equalElements 


	sub $r2, $r3		# r2 = r2 - r3

	li 7			# load value of 6 into r0, offset to noOverflow
			
	bez $r0			# if rOv == 0, then branch to noOverflow
	
	twcmp $r2		# r2 = 2's complement of r2, since this is the 
				# case that there was negative overflow from 
				# the subtraction. By taking the 2's Comp of
				# the value from this subtraction, this is the
				# distance between the two number when read as
				# an 8-bit unsigned value

	sltu $r2		# rOv = (r2 < r6) ? 1:0

	li 9			# load value of 10 into r0 (offset to 
				# innerLoopEnd 
				
	bez $r0			# if rOv == 0, then branch to innerLoopEnd 
				# since dist(arr[i], arr[j]) was not less 
				# than min
	
	clr $r6			# clear r6
	add $r6, $r2		# copy r2 into r6, since new minimum distance 
				# was found

	
	abs $r2			# r2 = |r2|
	
	sltu $r2		# rOv = (r2 < r6) ? 1:0

	li 3			# load value of 2 into r0 (offset to 
				# innerLoopEnd 
				
	bez $r0			# if rOv == 0, then branch to innerLoopEnd 
				# since dist(arr[i], arr[j]) was not less 
				# than min
	
	clr $r6			# clear r6
	add $r6, $r2		# copy r2 into r6, since new minimum distance 
				# was found
				
	
	inc $r5			# increment r5 (inner loop counter)

	li 39			# load value of 38 into r0
	twcmp $r0		# take 2's complement of 38 (-38) to get offset
				# to innerLoop branch

	branch $r0		# always branch to innerLoop


	inc $r4 		# increment r4 (outer loop counter)
	inc $r1			# increment r1 (mem address of array)
	clr $r5 		# clear inner loop counter
	add $r5, $r4 		# r5 = r5 + r4 (j = i)
	inc $r5 		# r5 = r5 + 1 (j = i +1)

	li 53			# load value of 49 into r0
	twcmp $r0		# take 2's complement of 49 (-49) to get offset
				# to outerloop label

	branch $r0		# always branch ro outerLoop


	clr $r6			# clear r6 (min = 0, since arr[i] == arr[j])

	li 63			# load value of 63 into r0
	inc $r0 		# increment r0 to get 64
	sll $r0			# left shift r0 by 1 to get 128

	clr $r7			# clear r7
	add $r7, $r0		# copy r0 into r7

	li 1			# load value of 1 into r0
	sub $r7, $r0		# r7 = r7 - r0 (r7 = 128 - 1 = 127)

	clr $r0			# clear r0
	add $r0, $r7		# copy r7 into r0 (mem address where min will 
				# be stored - location 127)

	sw $r6			# store r6 into (min) into mem address pointed
				# by r0

	halt			# send halt signal to end program 

	
