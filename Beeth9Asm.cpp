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

#include "Parser.hpp"

using namespace std;

// checkFilenameErrors Function Signature
bool checkFileErrors(int argc, char **argv);

// tokenizeString Function Signature
void tokenizeString(string line, queue<string> &tokens);

int main (int argc, char **argv) {
  // Local Variables
  ifstream input;       // Input file
  ofstream output;      // Output file
  Parser parser;
  queue<string> tokens;
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

  while (input) {
    string line;
    getline(input, line);
    
    // if the first char in the line is a tab, remove it
    if (line[0] == 9) {
      line.erase(0,1); 
    }

    switch (line[0]) {
      case 0 : // do nothing if null char
        break;
      
      case 9 : // do nothing if tab char
        break;

      case 32 : // do nothing if space char
        break;

      case 47 : // do nothing if / char
        break;

      default : tokenizeString(line, tokens); 
                machineCode = parser.ParseTokens(tokens);
                output << machineCode << endl;
        break;
    } 
  } 

  // Close the input and output files
  input.close();
  output.close();

  return 0;
}

/* Function Name: 
 * Function Prototype:
 * Description:
 * Input Parameters: 
 * Return Values/Type:
 */
void tokenizeString(string line, queue<string> &tokens) {
  // Get position of first tab char in instruction line and delete
  // everthing after that since its a comment
  int tabPosition = line.find_first_of(9);
  line.erase(tabPosition);
  
  // Erase all occurrences of delimiting and junk characters from one line
  // of Beeth9 assembly code
  line.erase(std::remove(line.begin(), line.end(), ','), line.end()); 
  line.erase(std::remove(line.begin(), line.end(), '$'), line.end()); 
  line.erase(std::remove(line.begin(), line.end(), '%'), line.end()); 
  line.erase(std::remove(line.begin(), line.end(), '('), line.end()); 
  line.erase(std::remove(line.begin(), line.end(), ')'), line.end()); 
 
  
  //cout << line << endl;

  // Use string stream to tokenize assembly instruction
  stringstream ss(line);
  string token;

  // get important parts of assembly instruction and put in queue
  while(getline(ss, token, ' ')) {
    tokens.push(token);
  }
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

