#ifndef INCLUDE_SHARED_H_
#define INCLUDE_SHARED_H_

#include <memory>
#include <string>
#include <unordered_map>

using namespace std;

namespace ary {

enum Disposition {
  info,
  warn,
  error,
  error_as_warn,
  critical,
  critical_as_warn,
  ignore,
};

// tokenType
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
  PRINT,

  // Operators
  NOT,                 // !
  AND,                 // &&
  OR,                  // ||
  EQUAL,               // ==
  NOT_EQUAL,           // !=
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
  SEMICOLON,  // ;
  COMMA,      // ,
  COLON,      // :

  // Identifers
  IDENTIFIER,

  // Literals
  INTEGER_LITERAL,
  FLOAT_LITERAL,
  STRING_LITERAL,
  CHAR_LITERAL,
  BOOL_LITERAL,

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

  // End of file
  END_OF_FILE
};

// Compiler diagnostics
inline std::unordered_map<std::string, Disposition> gCompDispMap = {
    {"FILE_DOES_NOT_EXIST", error}};
}  // namespace ary

#endif  // INCLUDE_SHARED_H_
