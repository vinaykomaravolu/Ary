
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

  // TODO - Add buffer size processing so it doesnt create a crazy large buffer
  while (current < bufferSize) {
    forward = current + 1;
    switch (buffer[current]) {
      // DELIMITERS
      case '\n':  // LPAREN
        line++;
        break;
      case '(':  // LPAREN
        addToken(TokenType::LPAREN, "(", line);
        break;
      case ')':  // RPAREN
        addToken(TokenType::RPAREN, ")", line);
        break;
      case '{':  // LBRACE
        addToken(TokenType::LBRACE, "{", line);
        break;
      case '}':  // RBRACE
        addToken(TokenType::RBRACE, "}", line);
        break;
      case '[':  // LBRACKET
        addToken(TokenType::LBRACKET, "[", line);
        break;
      case ']':  // RBRACKET
        addToken(TokenType::RBRACKET, "]", line);
        break;
      case ';':  // SEMICOLON
        addToken(TokenType::SEMICOLON, ";", line);
        break;
      case ',':  // COMMA
        addToken(TokenType::COMMA, ",", line);
        break;
      case ':':  // COLON
        addToken(TokenType::COLON, ":", line);
        break;
      // OPERATORS
      case '!':  // NOT or NOT_EQUAL
        if (forward < bufferSize && (buffer[forward] == '=')) {
          addToken(TokenType::NOT_EQUAL, "!=", line);
        } else {
          addToken(TokenType::NOT, "!", line);
        }
        break;
      case '&':  // BIT_AND or AND
        if (forward < bufferSize && (buffer[forward] == '&')) {
          addToken(TokenType::AND, "&&", line);
        } else {
          addToken(TokenType::BIT_AND, "&", line);
        }
        break;
      case '|':  // OR or BIT_OR
        if (forward < bufferSize && (buffer[forward] == '|')) {
          addToken(TokenType::OR, "||", line);
        } else {
          addToken(TokenType::BIT_OR, "|", line);
        }
        break;
      case '=':  // EQUAL or ASSIGN
        if (forward < bufferSize && (buffer[forward] == '=')) {
          addToken(TokenType::EQUAL, "==", line);
        } else {
          addToken(TokenType::ASSIGN, "=", line);
        }
        break;
      case '>':  // GREATER or GREATER_EQUAL
        if (forward < bufferSize && (buffer[forward] == '=')) {
          addToken(TokenType::GREATER_EQUAL, ">=", line);
        } else {
          addToken(TokenType::GREATER, ">", line);
        }
        break;
      case '<':  // LESS or LESS_EQUAL
        if (forward < bufferSize && (buffer[forward] == '=')) {
          addToken(TokenType::LESS_EQUAL, "<=", line);
        } else {
          addToken(TokenType::LESS, "<", line);
        }
        break;
      case '^':  // BIT_XOR
        addToken(TokenType::BIT_XOR, "^", line);
        break;
      case '~':  // BIT_NOT
        addToken(TokenType::BIT_NOT, "~", line);
        break;
      case '+':  // ADDITION or INCREMENT
        if (forward < bufferSize && (buffer[forward] == '+')) {
          addToken(TokenType::INCREMENT, "++", line);
        } else {
          addToken(TokenType::ADDITION, "+", line);
        }
        break;
      case '-':  // SUBTRACTION or DECREMENT
        if (forward < bufferSize && (buffer[forward] == '-')) {
          addToken(TokenType::DECREMENT, "--", line);
        } else if (forward < bufferSize && (buffer[forward] == '>')) {
          addToken(TokenType::ARROW, "->", line);
        } else {
          addToken(TokenType::SUBTRACTION, "-", line);
        }
        break;
      case '*':  // MULTIPLICATION or EXPONENT
        if (forward < bufferSize && (buffer[forward] == '*')) {
          addToken(TokenType::EXPONENT, "**", line);
        } else {
          addToken(TokenType::MULTIPLICATION, "*", line);
        }
        break;
      case '/':  // DIVISION or COMMENT
        if (forward < bufferSize && (buffer[forward] == '/')) {
          string comment = "//";

          while (forward < bufferSize && buffer[++forward] != '\n') {
            comment += buffer[forward];
          }
          addToken(TokenType::COMMENT, comment, line);
        } else {
          addToken(TokenType::DIVISION, "/", line);
        }
        break;
      case '%':  // MODULUS
        addToken(TokenType::MODULUS, "%", line);
        break;
      case '.':  // MEMBER_ACCESS
        addToken(TokenType::MEMBER_ACCESS, ".", line);
        break;
      case '#':  // COMMENT
        addToken(TokenType::COMMENT, "#", line);
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
        addToken(TokenType::CHAR_LITERAL, character, line);
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
        addToken(TokenType::STRING_LITERAL, stringLiteral, line);
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
            addToken(TokenType::FLOAT_LITERAL, number, line);
            break;
          }
          addToken(TokenType::INTEGER_LITERAL, number, line);
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
            addToken(it->second, keyword, line);  // KEYWORDS
          } else {
            // If its not anything else then it is an identifer
            addToken(TokenType::IDENTIFIER, keyword, line);
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

void Lexer::addToken(TokenType ttype, string lexme, int line) {
  vTokens_.emplace_back(std::make_shared<Token>(ttype, lexme, line));
}

std::ostream& operator<<(std::ostream& os, const Lexer& lexer) {
  for (const auto& token : lexer.vTokens_) {
    os << *token << "\n";  // Uses the Token's operator<<
  }
  return os;
}
}  // namespace ary
