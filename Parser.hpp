/* ilename: Parser.h
 * Author(s): Moiz Qureshi, Ye Huang, Eduardo Rosales
 * Description: Parser Class Definiton & Implementation
 * Date: 11/15/16
 */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <queue>

using namespace std;

// Parser Class Definition
class Parser {
public:
  
  // Instuctiion typedef enum
  typedef enum {LI, CLR, INC, SLL, SRL, TWCMP, HALT, LW, SW, BR, 
                BEZ, CLSB, GETOV, PATR, ABS, ADD, SUB, AND, OR, SLT, 
                SLTU, NOP} instr;

  // ParseTokens() Function Signature
  string ParseTokens(queue<string> &tokens);
  
  // getBinFromInt Function Signature
  string getBinFromInt(const int width, int num);

  // getBinFromInt Function Signature
  int getInstrEnum(string s);

};
#endif // PARSER_HPP
