#ifndef INCLUDE_TOKENIZER_H_
#define INCLUDE_TOKENIZER_H_

#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <vector>

#include "diagnostic.h"
#include "symboltable.h"
#include "token.h"

using namespace std;

namespace ary {
class Lexer {
 public:
  Lexer();

  void scanStr(string inputStr);
  void scanFile(string filePath);
  void addToken(TokenType ttype, string lexme);

 private:
  vector<shared_ptr<Token>> vTokens_;
  friend ostream& operator<<(ostream& os, const Lexer& lexer);
};
}  // namespace ary

#endif  // INCLUDE_TOKENIZER_H_
