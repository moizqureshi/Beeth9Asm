# Beeth9 ISA Assembler (C++)
* **Filename:** README
* **Authors:** Moiz Qureshi, Ye Huang, Eduardo Rosales
* **Description:** README file
* **Date:** 10/8/16

![picture alt](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6f/Beethoven.jpg/220px-Beethoven.jpg)

This repository contains the C++ source code for the Beeth9 Assembler. The 
Beeth9 Assembler takes two input arguments, the first being the input Beeth9
assembly file to be assembled into Beeth9 machine code, and the second being
the output text file to write this Beeth9 machine code to. Please see the 
usage section below to see supported Beeth9 Assembler operations and example


**Note:** Beeth9 assembly input files into the Beeth9 Assembler must **not** 
contain any labels (all branch offsets must be explicitly stored in a register)
and all Beeth9 assembly instructions should be tabbed. There is no need to 
remove any comments since the Beeth9 Assembler will ignore them. Refer to the 
the example Beeth9 assembly files (Problem17.s, Problem18.s, or Problem19.s) to
see example formatting. Furthermore, refer Beeth9MachineCode.txt to see 
combined assembled assembly to machine code of the three programs. Note, this 
file was created using the unix "cat" and ">" commands to combine them into one
text file output, after using Beeth9 Assembler to convert three individual 
assembly files into three machine code output text files.
