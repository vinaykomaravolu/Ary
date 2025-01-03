#ifndef INCLUDE_SYMBOLTABLE_H_
#define INCLUDE_SYMBOLTABLE_H_

#include <memory>
#include <string>
#include <unordered_map>

#include "token.h"

using namespace std;

// TODO: we should make the symbol table global since it will be used throughout
// the program

namespace ary {

struct SymbolData {
  TokenType tokenType;
  string lexme;
  string type;
  int line;
  bool declared;
  bool defined;
  string scope;
};

class SymbolTable {
 public:
  SymbolTable();

 private:
  unordered_map<Token, SymbolData> MSymbols_;
};

}  // namespace ary

#endif  // INCLUDE_SYMBOLTABLE_H_
