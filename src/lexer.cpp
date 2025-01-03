
#include "lexer.h"

#include <cctype>

using namespace std;

namespace ary {
Lexer::Lexer() {}

void Lexer::scanStr(string InputStr) {}

void Lexer::scanFile(string filePath) {
  ifstream file;
  file.open(filePath);

  if (!file) {
    stringstream msg;
    msg << "unable to open file \'" << filePath << "\'";
    DIAG_COMP_MSG("FILE_DOES_NOT_EXIST", msg.str());
  }

  file.seekg(0, std::ios::end);
  size_t bufferSize = file.tellg();
  file.seekg(0, std::ios::beg);  // Rewind the file pointer to the beginning.

  vector<char> buffer(bufferSize);

  int current = 0;
  int forward = 0;
  int line = 1;
  string lexme = "";
  file.read(buffer.data(), bufferSize);

  while (current < bufferSize) {
    forward = current + 1;
    switch (buffer[current]) {
      // DELIMITERS
      case '(':  // LPAREN
        addToken(TokenType::LPAREN, "(");
        break;
      case ')':  // RPAREN
        addToken(TokenType::RPAREN, ")");
        break;
      case '{':  // LBRACE
        addToken(TokenType::LBRACE, "{");
        break;
      case '}':  // RBRACE
        addToken(TokenType::RBRACE, "}");
        break;
      case '[':  // LBRACKET
        addToken(TokenType::LBRACKET, "[");
        break;
      case ']':  // RBRACKET
        addToken(TokenType::RBRACKET, "]");
        break;
      case ';':  // SEMICOLON
        addToken(TokenType::SEMICOLON, ";");
        break;
      case ',':  // COMMA
        addToken(TokenType::COMMA, ",");
        break;
      case ':':  // COLON
        addToken(TokenType::COLON, ":");
        break;
      // OPERATORS
      case '!':  // NOT or NOT_EQUAL
        if (forward < bufferSize && (buffer[forward] == '=')) {
          addToken(TokenType::NOT_EQUAL, "!=");
        } else {
          addToken(TokenType::NOT, "!");
        }
        break;
      case '&':  // BIT_AND or AND
        if (forward < bufferSize && (buffer[forward] == '&')) {
          addToken(TokenType::AND, "&&");
        } else {
          addToken(TokenType::BIT_AND, "&");
        }
        break;
      case '|':  // OR or BIT_OR
        if (forward < bufferSize && (buffer[forward] == '|')) {
          addToken(TokenType::OR, "||");
        } else {
          addToken(TokenType::BIT_OR, "|");
        }
        break;
      case '=':  // EQUAL or ASSIGN
        if (forward < bufferSize && (buffer[forward] == '=')) {
          addToken(TokenType::EQUAL, "==");
        } else {
          addToken(TokenType::ASSIGN, "=");
        }
        break;
      case '>':  // GREATER or GREATER_EQUAL
        if (forward < bufferSize && (buffer[forward] == '=')) {
          addToken(TokenType::GREATER_EQUAL, ">=");
        } else {
          addToken(TokenType::GREATER, ">");
        }
        break;
      case '<':  // LESS or LESS_EQUAL
        if (forward < bufferSize && (buffer[forward] == '=')) {
          addToken(TokenType::LESS_EQUAL, "<=");
        } else {
          addToken(TokenType::LESS, "<");
        }
        break;
      case '^':  // BIT_XOR
        addToken(TokenType::BIT_XOR, "^");
        break;
      case '~':  // BIT_NOT
        addToken(TokenType::BIT_NOT, "~");
        break;
      case '+':  // ADDITION or INCREMENT
        if (forward < bufferSize && (buffer[forward] == '+')) {
          addToken(TokenType::INCREMENT, "++");
        } else {
          addToken(TokenType::ADDITION, "+");
        }
        break;
      case '-':  // SUBTRACTION or DECREMENT
        if (forward < bufferSize && (buffer[forward] == '-')) {
          addToken(TokenType::DECREMENT, "--");
        } else if (forward < bufferSize && (buffer[forward] == '>')) {
          addToken(TokenType::ARROW, "->");
        } else {
          addToken(TokenType::SUBTRACTION, "-");
        }
        break;
      case '*':  // MULTIPLICATION or EXPONENT
        if (forward < bufferSize && (buffer[forward] == '*')) {
          addToken(TokenType::EXPONENT, "**");
        } else {
          addToken(TokenType::MULTIPLICATION, "*");
        }
        break;
      case '/':  // DIVISION or COMMENT
        if (forward < bufferSize && (buffer[forward] == '/')) {
          addToken(TokenType::COMMENT, "//");

          while (forward < bufferSize && buffer[forward++] == '\n');
        } else {
          addToken(TokenType::DIVISION, "/");
        }
        break;
      case '%':  // MODULUS
        addToken(TokenType::MODULUS, "%");
        break;
      case '.':  // MEMBER_ACCESS
        addToken(TokenType::MEMBER_ACCESS, ".");
        break;
      case '#':  // COMMENT
        addToken(TokenType::COMMENT, "#");
        break;
      case '\'':  // CHAR_LITERAL
      {
        string character = "";
        character += buffer[current];
        while (forward < bufferSize) {
          character += buffer[forward++];
          if (character.back() == '\'') {
            break;
          }
        }
        if (character.size() != 3 || character.back() != '\'') {
          stringstream msg;
          msg << "Incorrect string located at " << current;
          DIAG_COMP_MSG("LEXER_SCANNER_ERROR", msg.str());
        }
        addToken(TokenType::CHAR_LITERAL, character);
        break;
      }
      case '"':  // STRING_LITERAL
      {
        string stringLiteral = "";
        stringLiteral += buffer[current];
        while (forward < bufferSize) {
          stringLiteral += buffer[forward++];
          if (stringLiteral.back() == '"') {
            break;
          }
        }
        if (stringLiteral.size() <= 1 || stringLiteral.back() != '"') {
          stringstream msg;
          msg << "Incorrect string located at " << current;
          DIAG_COMP_MSG("LEXER_SCANNER_ERROR", msg.str());
        }
        addToken(TokenType::STRING_LITERAL, stringLiteral);
        break;
      }
      default:
        if (isdigit(buffer[current])) {  // INTEGER_LITERAL_LITERAL
          string number = "";
          number += buffer[current];
          while (forward < bufferSize && isdigit(buffer[forward])) {
            number += buffer[forward++];
          }
          if (forward < bufferSize &&
              buffer[forward] == '.') {  // FLOAT_LITERAL
            number += buffer[forward++];
            while (forward < bufferSize && isdigit(buffer[forward])) {
              number += buffer[forward++];
            }
            addToken(TokenType::FLOAT_LITERAL, number);
            break;
          }
          addToken(TokenType::INTEGER_LITERAL, number);
          break;
        } else if (isalpha(buffer[current])) {
          string keyword = "";
          keyword += buffer[current];
          while (forward < bufferSize && isalpha(buffer[forward]) ||
                 isdigit(buffer[forward])) {
            keyword += buffer[forward++];
          }

          // KEYWORDS
          std::unordered_map<std::string, TokenType> keywordMap = {
              {"main", TokenType::MAIN},
              {"func", TokenType::FUNC},
              {"type", TokenType::TYPE},
              {"return", TokenType::RETURN},
              {"import", TokenType::IMPORT},
              {"struct", TokenType::STRUCT},
              {"enum", TokenType::ENUM},
              {"if", TokenType::IF},
              {"else", TokenType::ELSE},
              {"for", TokenType::FOR},
              {"while", TokenType::WHILE},
              {"break", TokenType::BREAK},
              {"continue", TokenType::CONTINUE},
              {"constant", TokenType::CONSTANT},
              {"bool", TokenType::BOOL},
              {"float", TokenType::FLOAT},
              {"int", TokenType::INT},
              {"char", TokenType::CHAR},
              {"string", TokenType::STRING},
              {"void", TokenType::STRING}};

          auto it = keywordMap.find(keyword);
          if (it != keywordMap.end()) {
            addToken(it->second, keyword);  // KEYWORDS
          } else {
            // If its not anything else then it is an identifer
            addToken(TokenType::IDENTIFIER, keyword);
          }
        }

        break;
    }
    current = forward;
  }

  stringstream msg;
  msg << "\n" << (*this);
  DIAG_COMP_MSG("LEXER_TOKEN_INFO", msg.str());

  // Check for errors or EOF
  if (!file.eof()) {
    stringstream msg;
    msg << "error reading file." << filePath << "\'";
    DIAG_COMP_MSG("FILE_ERROR_READING", msg.str());
  }

  file.close();
}

void Lexer::addToken(TokenType ttype, string lexme) {
  vTokens_.emplace_back(std::make_shared<Token>(ttype, lexme));
}

std::ostream& operator<<(std::ostream& os, const Lexer& lexer) {
  for (const auto& token : lexer.vTokens_) {
    os << *token << "\n";  // Uses the Token's operator<<
  }
  return os;
}
}  // namespace ary
