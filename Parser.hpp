/* ilename: Parser.h
 * Author(s): Moiz Qureshi, Ye Huang, Eduardo Rosales
 * Description: Parser Class Definiton & Implementation
 * Date: 11/14/16
 */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <queue>

using namespace std;

class Parser {
public:
  
  typedef enum {LI, CLR, INC, SLL, SRL, TWCMP, HALT, LW, SW, BR, 
               BEZ, LSB, GETOV, PATR, ABS, ADD, SUB, AND, OR, SLT} instr;

  string ParseTokens(queue<string> &tokens);
  
  string getBitsFromInt(const int width, int num);

  int getInstrEnum(string s);


};


#endif // PARSER_HPP

