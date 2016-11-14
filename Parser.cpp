/* Filename: Parser.cpp
 * Author(s): Moiz Qureshi, Ye Huang, Eduardo Rosales
 * Description: Parser Class Definiton 
 * Date: 11/14/16
 */

#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <queue>

#include "Parser.hpp"

using namespace std;


int Parser::getInstrEnum(string s) {
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


string Parser::ParseTokens(queue<string> &tokens) {
  stringstream parsedToken;
  string immBinStr;
  string regBinStr;

  switch(getInstrEnum(tokens.front())) {
    case LI :
      tokens.pop();
      parsedToken << "000";
      immBinStr = getBitsFromInt(6, stoi(tokens.front()));
      cout << immBinStr << endl;
      tokens.pop();
      parsedToken << immBinStr;
      break;

     default : // do nothing
      break;
    
  }

  return parsedToken.str();
}

string Parser::getBitsFromInt(const int width, int num) {
  if (width == 6) {
    bitset<6> imm(num);
    return imm.to_string();
  } else {
    bitset<3> imm(num);
    return imm.to_string();
  } 
}
