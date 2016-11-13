/* Filename: Beeth9Asm.cpp
 * Authors: Moiz Qureshi, Ye Huang, Eduardo Rosales
 * Date 11/9/16
 * Description: Driver for Beeth 9 Assembler. Converts Beeth9 assembly code 
 *              into Beeth9 ISA machine code (9 bit instructions)
 */

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// checkFilenameErrors Function Signature
bool checkFileErrors(int argc, char **argv);

int main (int argc, char **argv) {

  // Check if any basic file errors and correct number of args passed in
  if (checkFileErrors(argc, argv)) {
    return EXIT_FAILURE;
  }
  return 0;

}

/* Function Name: checkFileErrors()
 * Function Prototype: checkFileErrors(int argc, char **argv)
 * Description: Function that checks to see if number of input arguments to 
 *              the Beeth9 Assembler program is correct and validates input
 *              and output filenames
 * Input Parameters: 
 *    arg1 - int argc
 *    arg2 - char **argv
 * Return Values/Type: boolean - true if there were no errors, otherwise false
 */
bool checkFileErrors(int argc, char **argv) {
  // Check if number of arguments is 3, if not then output error message and
  // return true 
  if (argc != 3) {
    cout << "Incorrect number of arguments!" << endl;
    cout << "Please run Beeth9 Assembler as following:" << endl;
    cout << "./Beeth9Asm *.s  *.txt" << endl;
    return true;
  }
  // Check if input and output filenames are not the same, if they are then
  // output error message and return true
  else if (strcmp(argv[1], argv[2]) == 0) {
    cout << "The input and output files cannot be the same!" << endl;
    cout << "Please try again with correct inputs." << endl;
    return true;
  } else {
    // Return false since there were errors we reached this point
    return false;
  }
}

