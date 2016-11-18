/* Filename: Beeth9Asm.cpp
 * Authors: Moiz Qureshi, Ye Huang, Eduardo Rosales
 * Date 11/9/16
 * Description: Driver for Beeth 9 Assembler. Converts Beeth9 assembly code 
 *              into Beeth9 ISA machine code (9 bit instructions)
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <algorithm>
#include <exception>

#include "Parser.hpp"

using namespace std;

// checkFilenameErrors Function Signature
bool checkFileErrors(int argc, char **argv);

// tokenizeString Function Signature
string tokenizeString(string line, queue<string> &tokens);

int main (int argc, char **argv) {
  // Local Variables
  ifstream input;       // Input file
  ofstream output;      // Output file
  Parser parser;
  queue<string> tokens;
  string instruction;
  string machineCode; 

  // Check if any basic file errors and correct number of args passed in
  if (checkFileErrors(argc, argv)) {
    return EXIT_FAILURE;
  }
  
  // Open the input assembly file for reading for further checking,
  // use bianry mode to get filesize
  input.open(argv[1], ifstream::binary);
  input.seekg(0, input.end);
  int fileSize = input.tellg();
  input.seekg(0, input.beg);

  // Check that input assembly file exists and is not empty
  if (input.fail()) {
    cout << "The input assembly file does not exist!" << endl;
    cout << "Try again." << endl;
    input.close();
    return EXIT_FAILURE;
  } else { 
    if (fileSize == 0) {
      cout << "The input assembly file is empty!" << endl;
      cout << "Try again." << endl;
      input.close();
      return EXIT_FAILURE;
    }
  }

  // Close the input file because we no longer need binary mode
  input.close();

  // Open input file again for text reading now
  input.open(argv[1]);

  // Open the output file for writing
  output.open(argv[2]);
  
  // Write comment at top of output txt to denote what assembly file was 
  // converted to machine code
  output << "// " << argv[1] << " Machine Code Output" << endl;

  while (input) {
    string line;
    getline(input, line);
    
    // if the first char in the line is a tab, remove it
    if (line[0] == 9) {
      line.erase(0,1); 
    }

    // Switch-Case that looks at new first char of line. All Beeth9 assembly 
    // code is tabbed (since there are no labels). If the new first char is not
    // a regular letter, then line wont be tokenized, parsed, and machine code
    // printed to output file
    switch (line[0]) {
      case 0 : // do nothing if null char
        break;
      
      case 9 : // do nothing if tab char
        break;

      case 32 : // do nothing if space char
        break;

      case 47 : // do nothing if / char
        break;
      
      // if any other char, then this must be a line of instruction.
      // Tokenize instruction, parse it, and write to output file
      default : instruction = tokenizeString(line, tokens); 
                machineCode = parser.ParseTokens(tokens);
                output << machineCode;
                output << "    // " << instruction << endl;
        break;
    } 
  } 

  // Close the input and output files
  input.close();
  output.close();
  
  // Give message to console that assembler has completed the job
  cout << "Beeth 9 Assembler successfully assembled: " << argv[1] << endl;

  return 0;
}

/* Function Name: tokenizeString() 
 * Function Prototype: 
 *  string tokenizeString(string line, queue<string> &tokens)
 * Description: Function that takes a line of Beeth9 Assembly code, 
 *              and tokenizes it into parts, and puts them in the 
 *              tokens queue
 * Input Parameters: arg1 - string line; arg2 - queue<string> &tokens
 * Return Values/Type: Returns string of assembly line to be written as
 *                     comment next to converted machine code
 */
string tokenizeString(string line, queue<string> &tokens) {
  
  // Erase all occurrences of delimiting and junk characters from one line
  // of Beeth9 assembly code
  line.erase(std::remove(line.begin(), line.end(), ','), line.end()); 
  line.erase(std::remove(line.begin(), line.end(), '$'), line.end()); 
  line.erase(std::remove(line.begin(), line.end(), '%'), line.end()); 
  line.erase(std::remove(line.begin(), line.end(), '('), line.end()); 
  line.erase(std::remove(line.begin(), line.end(), ')'), line.end()); 
  line.erase(std::remove(line.begin(), line.end(), 9), line.end()); 
 
  // Get position of first # char in instruction line and delete
  // everthing after that since its a comment
  int tabPosition = line.find_first_of(35);
  try {
    line.erase(tabPosition);
  } catch (exception &e) {
    // Do nothing :)
  }
  
  // Use string stream to tokenize assembly instruction
  stringstream ss(line);
  string token;

  // get important parts of assembly instruction and put in queue
  while(getline(ss, token, ' ')) {
    tokens.push(token);
  }
  // Return parsed instruction string to be written as comment
  return line;
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
