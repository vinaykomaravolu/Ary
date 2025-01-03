#include "token.h"

#include <iostream>
#include <string>

using namespace std;

namespace ary {

ostream& operator<<(ostream& os, const Token& token) {
  os << "Token : TokenType: ";
  switch (token.eType_) {
    case TokenType::FUNC:
      os << "FUNC";
      break;
    case TokenType::MAIN:
      os << "FUNC";
      break;
    case TokenType::TYPE:
      os << "TYPE";
      break;
    case TokenType::RETURN:
      os << "RETURN";
      break;
    case TokenType::IMPORT:
      os << "IMPORT";
      break;
    case TokenType::STRUCT:
      os << "STRUCT";
      break;
    case TokenType::ENUM:
      os << "ENUM";
      break;
    case TokenType::IF:
      os << "IF";
      break;
    case TokenType::ELSE:
      os << "ELSE";
      break;
    case TokenType::FOR:
      os << "FOR";
      break;
    case TokenType::WHILE:
      os << "WHILE";
      break;
    case TokenType::BREAK:
      os << "BREAK";
      break;
    case TokenType::CONTINUE:
      os << "CONTINUE";
      break;
    case TokenType::CONSTANT:
      os << "CONSTANT";
      break;
    case TokenType::BOOL:
      os << "BOOL";
      break;
    case TokenType::FLOAT:
      os << "FLOAT";
      break;
    case TokenType::INT:
      os << "INT";
      break;
    case TokenType::CHAR:
      os << "CHAR";
      break;
    case TokenType::STRING:
      os << "STRING";
      break;
    case TokenType::NONE:
      os << "NONE";
      break;
    case TokenType::NOT:
      os << "NOT";
      break;
    case TokenType::AND:
      os << "AND";
      break;
    case TokenType::OR:
      os << "OR";
      break;
    case TokenType::EQUAL:
      os << "EQUAL";
      break;
    case TokenType::ASSIGN:
      os << "ASSIGN";
      break;
    case TokenType::NOT_EQUAL:
      os << "NOT_EQUAL";
      break;
    case TokenType::GREATER:
      os << "GREATER";
      break;
    case TokenType::LESS:
      os << "LESS";
      break;
    case TokenType::GREATER_EQUAL:
      os << "GREATER_EQUAL";
      break;
    case TokenType::LESS_EQUAL:
      os << "LESS_EQUAL";
      break;
    case TokenType::BIT_NOT:
      os << "BIT_NOT";
      break;
    case TokenType::BIT_AND:
      os << "BIT_AND";
      break;
    case TokenType::BIT_OR:
      os << "BIT_OR";
      break;
    case TokenType::BIT_XOR:
      os << "BIT_XOR";
      break;
    case TokenType::LEFT_SHIFT:
      os << "LEFT_SHIFT";
      break;
    case TokenType::RIGHT_SHIFT:
      os << "RIGHT_SHIFT";
      break;
    case TokenType::ASSIGN_ADD:
      os << "ASSIGN_ADD";
      break;
    case TokenType::ASSIGN_SUB:
      os << "ASSIGN_SUB";
      break;
    case TokenType::ASSIGN_MUL:
      os << "ASSIGN_MUL";
      break;
    case TokenType::ASSIGN_DIV:
      os << "ASSIGN_DIV";
      break;
    case TokenType::ASSIGN_MOD:
      os << "ASSIGN_MOD";
      break;
    case TokenType::ASSIGN_LEFT_SHIFT:
      os << "ASSIGN_LEFT_SHIFT";
      break;
    case TokenType::ASSIGN_RIGHT_SHIFT:
      os << "ASSIGN_RIGHT_SHIFT";
      break;
    case TokenType::ASSIGN_BIT_AND:
      os << "ASSIGN_BIT_AND";
      break;
    case TokenType::ASSIGN_BIT_OR:
      os << "ASSIGN_BIT_OR";
      break;
    case TokenType::ASSIGN_BIT_XOR:
      os << "ASSIGN_BIT_XOR";
      break;
    case TokenType::EXPONENT:
      os << "EXPONENT";
      break;
    case TokenType::MODULUS:
      os << "MODULUS";
      break;
    case TokenType::DIVISION:
      os << "DIVISION";
      break;
    case TokenType::MULTIPLICATION:
      os << "MULTIPLICATION";
      break;
    case TokenType::SUBTRACTION:
      os << "SUBTRACTION";
      break;
    case TokenType::ADDITION:
      os << "ADDITION";
      break;
    case TokenType::INCREMENT:
      os << "INCREMENT";
      break;
    case TokenType::DECREMENT:
      os << "DECREMENT";
      break;
    case TokenType::ARROW:
      os << "ARROW";
      break;
    case TokenType::LPAREN:
      os << "LPAREN";
      break;
    case TokenType::RPAREN:
      os << "RPAREN";
      break;
    case TokenType::LBRACE:
      os << "LBRACE";
      break;
    case TokenType::RBRACE:
      os << "RBRACE";
      break;
    case TokenType::LBRACKET:
      os << "LBRACKET";
      break;
    case TokenType::RBRACKET:
      os << "RBRACKET";
      break;
    case TokenType::SEMICOLON:
      os << "SEMICOLON";
      break;
    case TokenType::COMMA:
      os << "COMMA";
      break;
    case TokenType::COLON:
      os << "COLON";
      break;
    case TokenType::IDENTIFIER:
      os << "IDENTIFIER";
      break;
    case TokenType::INTEGER_LITERAL:
      os << "INTEGER_LITERAL";
      break;
    case TokenType::FLOAT_LITERAL:
      os << "FLOAT_LITERAL";
      break;
    case TokenType::STRING_LITERAL:
      os << "STRING_LITERAL";
      break;
    case TokenType::CHAR_LITERAL:
      os << "CHAR_LITERAL";
      break;
    case TokenType::FUNCTION_VARIABLE:
      os << "FUNCTION_VARIABLE";
      break;
    case TokenType::ARRAY:
      os << "ARRAY";
      break;
    case TokenType::POINTER:
      os << "POINTER";
      break;
    case TokenType::DREFERENCE:
      os << "DREFERENCE";
      break;
    case TokenType::REFERENCE:
      os << "REFERENCE";
      break;
    case TokenType::MEMBER_ACCESS:
      os << "MEMBER_ACCESS";
      break;
    case TokenType::POINTER_MEMBER_ACCESS:
      os << "POINTER_MEMBER_ACCESS";
      break;
    case TokenType::COMMENT:
      os << "COMMENT";
      break;
    default:
      os << "UNKNOWN";
      break;
  }

  os << ", Lexme: " << token.sLexme_;
  return os;  // Closing the function here
}

}  // namespace ary
