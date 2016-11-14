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
#include <algorithm>

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
  else if (s == "branch") return 9;
  else if (s == "bez") return 10;
  else if (s == "clsb") return 11;
  else if (s == "getov") return 12;
  else if (s == "patr") return 13;
  else if (s == "abs") return 14;
  else if (s == "add") return 15;
  else if (s == "sub") return 16;
  else if (s == "and") return 17;
  else if (s == "or") return 18;
  else if (s == "slt") return 19;
  else return -1;
}


string Parser::ParseTokens(queue<string> &tokens) {
  stringstream parsedToken;
  string immBinStr;
  string regBinStr;
  string regBinStr2;
  
  switch(getInstrEnum(tokens.front())) {
    case LI :
      tokens.pop();
      parsedToken << "000";
      immBinStr = getBinFromInt(6, stoi(tokens.front()));
      tokens.pop();
      parsedToken << immBinStr;
      break;

    case CLR : 
      tokens.pop();
      parsedToken << "001";
      regBinStr = tokens.front();
      tokens.pop();
      regBinStr.erase(std::remove(regBinStr.begin(), regBinStr.end(), 'r'), 
                      regBinStr.end());
      regBinStr = getBinFromInt(3, stoi(regBinStr));
      parsedToken << regBinStr;
      parsedToken << "000";
      break;

    case INC : 
      tokens.pop();
      parsedToken << "001";
      regBinStr = tokens.front();
      tokens.pop();
      regBinStr.erase(std::remove(regBinStr.begin(), regBinStr.end(), 'r'), 
                      regBinStr.end());
      regBinStr = getBinFromInt(3, stoi(regBinStr));
      parsedToken << regBinStr;
      parsedToken << "001";
      break;
      
    case SLL : 
      tokens.pop();
      parsedToken << "001";
      regBinStr = tokens.front();
      tokens.pop();
      regBinStr.erase(std::remove(regBinStr.begin(), regBinStr.end(), 'r'), 
                      regBinStr.end());
      regBinStr = getBinFromInt(3, stoi(regBinStr));
      parsedToken << regBinStr;
      parsedToken << "010";
      break;

    case SRL : 
      tokens.pop();
      parsedToken << "001";
      regBinStr = tokens.front();
      tokens.pop();
      regBinStr.erase(std::remove(regBinStr.begin(), regBinStr.end(), 'r'), 
                      regBinStr.end());
      regBinStr = getBinFromInt(3, stoi(regBinStr));
      parsedToken << regBinStr;
      parsedToken << "011";
      break;
    
    case TWCMP : 
      tokens.pop();
      parsedToken << "001";
      regBinStr = tokens.front();
      tokens.pop();
      regBinStr.erase(std::remove(regBinStr.begin(), regBinStr.end(), 'r'), 
                      regBinStr.end());
      regBinStr = getBinFromInt(3, stoi(regBinStr));
      parsedToken << regBinStr;
      parsedToken << "100";
      break;
      
    case HALT : 
      tokens.pop();
      parsedToken << "001000101";
      break;
    
    case LW : 
      tokens.pop();
      parsedToken << "001";
      regBinStr = tokens.front();
      tokens.pop();
      regBinStr.erase(std::remove(regBinStr.begin(), regBinStr.end(), 'r'), 
                      regBinStr.end());
      regBinStr = getBinFromInt(3, stoi(regBinStr));
      parsedToken << regBinStr;
      parsedToken << "110";
      break;
    
    case SW : 
      tokens.pop();
      parsedToken << "001";
      regBinStr = tokens.front();
      tokens.pop();
      regBinStr.erase(std::remove(regBinStr.begin(), regBinStr.end(), 'r'), 
                      regBinStr.end());
      regBinStr = getBinFromInt(3, stoi(regBinStr));
      parsedToken << regBinStr;
      parsedToken << "111";
      break;
    
    case BR : 
      tokens.pop();
      parsedToken << "010";
      regBinStr = tokens.front();
      tokens.pop();
      regBinStr.erase(std::remove(regBinStr.begin(), regBinStr.end(), 'r'), 
                      regBinStr.end());
      regBinStr = getBinFromInt(3, stoi(regBinStr));
      parsedToken << regBinStr;
      parsedToken << "000";
      break;
    
    case BEZ : 
      tokens.pop();
      parsedToken << "010";
      regBinStr = tokens.front();
      tokens.pop();
      regBinStr.erase(std::remove(regBinStr.begin(), regBinStr.end(), 'r'), 
                      regBinStr.end());
      regBinStr = getBinFromInt(3, stoi(regBinStr));
      parsedToken << regBinStr;
      parsedToken << "001";
      break;
    
    case CLSB : 
      tokens.pop();
      parsedToken << "010";
      regBinStr = tokens.front();
      tokens.pop();
      regBinStr.erase(std::remove(regBinStr.begin(), regBinStr.end(), 'r'), 
                      regBinStr.end());
      regBinStr = getBinFromInt(3, stoi(regBinStr));
      parsedToken << regBinStr;
      parsedToken << "010";
      break;
    
    case GETOV : 
      tokens.pop();
      parsedToken << "010";
      regBinStr = tokens.front();
      tokens.pop();
      regBinStr.erase(std::remove(regBinStr.begin(), regBinStr.end(), 'r'), 
                      regBinStr.end());
      regBinStr = getBinFromInt(3, stoi(regBinStr));
      parsedToken << regBinStr;
      parsedToken << "011";
      break;
    
    case PATR : 
      tokens.pop();
      parsedToken << "010";
      regBinStr = tokens.front();
      tokens.pop();
      regBinStr.erase(std::remove(regBinStr.begin(), regBinStr.end(), 'r'), 
                      regBinStr.end());
      regBinStr = getBinFromInt(3, stoi(regBinStr));
      parsedToken << regBinStr;
      parsedToken << "100";
      break;
    
    case ABS : 
      tokens.pop();
      parsedToken << "010";
      regBinStr = tokens.front();
      tokens.pop();
      regBinStr.erase(std::remove(regBinStr.begin(), regBinStr.end(), 'r'), 
                      regBinStr.end());
      regBinStr = getBinFromInt(3, stoi(regBinStr));
      parsedToken << regBinStr;
      parsedToken << "101";
      break;
    
    case ADD : 
      tokens.pop();
      parsedToken << "011";
      regBinStr = tokens.front();
      tokens.pop();
      regBinStr.erase(std::remove(regBinStr.begin(), regBinStr.end(), 'r'), 
                      regBinStr.end());
      regBinStr = getBinFromInt(3, stoi(regBinStr));
      parsedToken << regBinStr;
      regBinStr2 = tokens.front();
      tokens.pop();
      regBinStr2.erase(std::remove(regBinStr2.begin(), regBinStr2.end(), 'r'), 
                       regBinStr2.end());
      regBinStr2 = getBinFromInt(3, stoi(regBinStr2));
      parsedToken << regBinStr2;
      break;
    
    case SUB : 
      tokens.pop();
      parsedToken << "100";
      regBinStr = tokens.front();
      tokens.pop();
      regBinStr.erase(std::remove(regBinStr.begin(), regBinStr.end(), 'r'), 
                      regBinStr.end());
      regBinStr = getBinFromInt(3, stoi(regBinStr));
      parsedToken << regBinStr;
      regBinStr2 = tokens.front();
      tokens.pop();
      regBinStr2.erase(std::remove(regBinStr2.begin(), regBinStr2.end(), 'r'), 
                       regBinStr2.end());
      regBinStr2 = getBinFromInt(3, stoi(regBinStr2));
      parsedToken << regBinStr2;
      break;
    
    case AND : 
      tokens.pop();
      parsedToken << "101";
      regBinStr = tokens.front();
      tokens.pop();
      regBinStr.erase(std::remove(regBinStr.begin(), regBinStr.end(), 'r'), 
                      regBinStr.end());
      regBinStr = getBinFromInt(3, stoi(regBinStr));
      parsedToken << regBinStr;
      regBinStr2 = tokens.front();
      tokens.pop();
      regBinStr2.erase(std::remove(regBinStr2.begin(), regBinStr2.end(), 'r'), 
                       regBinStr2.end());
      regBinStr2 = getBinFromInt(3, stoi(regBinStr2));
      parsedToken << regBinStr2;
      break;
    
    case OR : 
      tokens.pop();
      parsedToken << "110";
      regBinStr = tokens.front();
      tokens.pop();
      regBinStr.erase(std::remove(regBinStr.begin(), regBinStr.end(), 'r'), 
                      regBinStr.end());
      regBinStr = getBinFromInt(3, stoi(regBinStr));
      parsedToken << regBinStr;
      regBinStr2 = tokens.front();
      tokens.pop();
      regBinStr2.erase(std::remove(regBinStr2.begin(), regBinStr2.end(), 'r'), 
                       regBinStr2.end());
      regBinStr2 = getBinFromInt(3, stoi(regBinStr2));
      parsedToken << regBinStr2;
      break;
    
    case SLT : 
      tokens.pop();
      parsedToken << "111";
      regBinStr = tokens.front();
      tokens.pop();
      regBinStr.erase(std::remove(regBinStr.begin(), regBinStr.end(), 'r'), 
                      regBinStr.end());
      regBinStr = getBinFromInt(3, stoi(regBinStr));
      parsedToken << regBinStr;
      regBinStr2 = tokens.front();
      tokens.pop();
      regBinStr2.erase(std::remove(regBinStr2.begin(), regBinStr2.end(), 'r'), 
                       regBinStr2.end());
      regBinStr2 = getBinFromInt(3, stoi(regBinStr2));
      parsedToken << regBinStr2;
      break;
    
    default : // do nothing
      break;
  }

  return parsedToken.str();
}

string Parser::getBinFromInt(const int width, int num) {
  if (width == 6) {
    bitset<6> imm(num);
    return imm.to_string();
  } else {
    bitset<3> imm(num);
    return imm.to_string();
  } 
}
