# Beeth9 ISA Assembly Codes
* **Filename:** README
* **Authors:** Moiz Qureshi, Ye Huang, Eduardo Rosales
* **Description:** README file
* **Date:** 10/8/16

![picture alt](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6f/Beethoven.jpg/220px-Beethoven.jpg)

This repository contains the custom Beeth9 ISA assembly code for CSE141L 
programs 17, 18, & 19. 

##Program 17:

Program that finds the product of three unsigned numbers, ie, A * B * C. The 
operands are found in memory locations 1 (A), 2 (B), and 3 (C). The result 
will be written into locations 4 (high bits) and 5 (low bits). There may be 
overflow, in which case only the low 16 bits will be stored. Beeth9 ISA does 
NOT have a “multiply” operation. 

Dynamic Instruction Count:

##Program 18:

Program that finds the number of entries in an array which contain a 4-bit 
pattern string. For example, if the 4-bit string is 0101, then 11010110 and 
01010101 would both count (the latter would count once, even though the string 
occurs 3 times), while 00111011 would not. The array starts at position 32 and 
is 64 bytes long. The string pattern to search for will be in the lower 4 bits 
of memory address 6. The result shall be written in location 7.

##Program 19:

Program that finds the least distance between all pairs of values in an array 
of 20 bytes. Assume all values are signed 8-bit integers. The array of integers
starts at location 128. The minimum distance will be written to memory location
127. If the array contains the sequence {34, -12, 18, 61, 0, 100, 49, -51, -22,
3, 41, 88, -100, 14, 39, 10, 90, -90, -80, 75}, then the correct answer would 
be 2.

Dynamic Instruction Count:









