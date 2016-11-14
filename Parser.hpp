/* Filename: Parser.h
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
private:

  bitset<6> imm;
  
  int getInstrEnum(string s) {
    if (s == "li") return 0;
    else if (s == "clr") return 1;
    else if (s == "inc") return 2;
    else if (s == "sll") return 3;
    else if (s == "srl") return 4;
    else if (s == "twcmp") return 5;
    else if (s == "halt") return 6;
    else if (s == "lw") return 7;
    else if (s == "sw") return 8;
    else if (s == "br") return 9;
    else if (s == "bez") return 10;
    else if (s == "clsb") return 11;
    else if (s == "getov") return 12;
    else if (s == "patr") return 13;
    else if (s == "abs") return 14;
    else if (s == "add") return 15;
    else if (s == "and") return 16;
    else if (s == "sub") return 17;
    else if (s == "or") return 18;
    else if (s == "slt") return 19;
    else return -1;
  }

public:
  
  typedef enum {LI, CLR, INC, SLL, SRL, TWCMP, HALT, LW, SW, BR, 
               BEZ, LSB, GETOV, PATR, ABS, ADD, SUB, AND, OR, SLT} instr;

  string ParseTokens(queue<string> &tokens) {
    stringstream parsedToken;
    

    switch(getInstrEnum(tokens.front())) {
      case LI :
        tokens.pop();
        parsedToken << "000";
        imm.set(stoi(tokens.front()));
        tokens.pop();
        parsedToken << imm;
        break;

       default : // do nothing
        break;
      
    }

    return parsedToken.str();
  }
};


#endif // PARSER_HPP

