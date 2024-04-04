#ifndef INCLUDE_TOKEN_H_
#define INCLUDE_TOKEN_H_

#include <string>

#include "shared.h"

using namespace std;

namespace ary {
class Token {
 public:
  Token(TokenType type, string value) : eType_(type), sValue_(value){};
  TokenType getTokenType() { return eType_; };
  string getValue() { return sValue_; }
  void setTokenType(TokenType type) { eType_ = type; };
  void setValue(string value) { sValue_ = value; };

 private:
  TokenType eType_;
  string sValue_;
};
}  // namespace ary

#endif  // INCLUDE_TOKEN_H_
