#ifndef INCLUDE_TOKENIZER_H_
#define INCLUDE_TOKENIZER_H_

#include <fstream>
#include <iostream>
#include <string>

#inlcude "token.h"

using namespace std;

namespace ary {
class Lexer {
 public:
  Lexer();
  void scan(string fileStr);
  void scan(ifstream file);
  void setPattern();     // TODO
  void removePattern();  // TODO

 private:
};
}  // namespace ary

#endif  // INCLUDE_TOKENIZER_H_
