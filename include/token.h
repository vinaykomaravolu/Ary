#ifndef INCLUDE_TOKEN_H_
#define INCLUDE_TOKEN_H_

#include <string>

using namespace std;

namespace ary {

#define ENUM_TO_STRING(EnumType, value)

enum class TokenType {
  // Keywords
  FUNC,
  TYPE,
  RETURN,
  IMPORT,
  STRUCT,
  ENUM,
  IF,
  ELSE,
  FOR,
  WHILE,
  BREAK,
  CONTINUE,
  CONSTANT,
  BOOL,
  FLOAT,
  INT,
  CHAR,
  STRING,
  NONE,
  // Operators
  NOT,                 // !
  AND,                 // &&
  OR,                  // ||
  EQUAL,               // ==
  NOT_EQUAL,           // !=
  ASSIGN,              // =
  GREATER,             // >
  LESS,                // <
  GREATER_EQUAL,       // >=
  LESS_EQUAL,          // <=
  BIT_NOT,             // ~
  BIT_AND,             // &
  BIT_OR,              // |
  BIT_XOR,             // ^
  LEFT_SHIFT,          // <<
  RIGHT_SHIFT,         // >>
  ASSIGN_ADD,          // +=
  ASSIGN_SUB,          // -=
  ASSIGN_MUL,          // *=
  ASSIGN_DIV,          // /=
  ASSIGN_MOD,          // %=
  ASSIGN_LEFT_SHIFT,   // <<=
  ASSIGN_RIGHT_SHIFT,  // >>=
  ASSIGN_BIT_AND,      // &=
  ASSIGN_BIT_OR,       // |=
  ASSIGN_BIT_XOR,      // ^=
  EXPONENT,            // **
  MODULUS,             // %
  DIVISION,            // /
  MULTIPLICATION,      // *
  SUBTRACTION,         // -
  ADDITION,            // +
  INCREMENT,           // ++
  DECREMENT,           // --
  ARROW,               // ->

  // Delimiters
  LPAREN,     // (
  RPAREN,     // )
  LBRACE,     // {
  RBRACE,     // }
  LBRACKET,   // [
  RBRACKET,   // ]
  SEMICOLON,  // ;`
  COMMA,      // ,
  COLON,      // :

  // Identifers
  IDENTIFIER,

  // Literals
  INTEGER_LITERAL,
  FLOAT_LITERAL,
  STRING_LITERAL,
  CHAR_LITERAL,

  // Main entry function
  MAIN,

  // Other
  FUNCTION_VARIABLE,
  ARRAY,

  // Memory
  POINTER,                // *
  DREFERENCE,             // *
  REFERENCE,              // &
  MEMBER_ACCESS,          // .
  POINTER_MEMBER_ACCESS,  // ->

  // Comment
  COMMENT,
};

class Token {
 public:
  Token(TokenType type, string lexme, int line)
      : eType_(type), sLexme_(lexme), iLine_(line) {};
  TokenType getTokenType() { return eType_; };
  string getLexme() { return sLexme_; };
  int getLine() { return iLine_; };
  void setTokenType(TokenType type) { eType_ = type; };
  void setLexme(string lexme) { sLexme_ = lexme; };
  void setLine(int line) { iLine_ = line; };

 private:
  TokenType eType_;
  string sLexme_;
  int iLine_;
  friend ostream& operator<<(ostream& os, const Token& token);
};
}  // namespace ary

#endif  // INCLUDE_TOKEN_H_
