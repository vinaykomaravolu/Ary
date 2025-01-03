#ifndef INCLUDE_DIAGNOSTIC_H_
#define INCLUDE_DIAGNOSTIC_H_

#include <memory.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/spdlog.h>

#include <iostream>
#include <map>
#include <memory>
#include <sstream>
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

class Diagnostics {
 public:
  void setDiagnosticMap(unordered_map<string, Disposition> disp);
  unordered_map<string, Disposition> getDiagnosticMap();
  void AddDiagnostic(string diag, Disposition disp);
  void RemoveDiagnostic(string diag);
  void msg(string diag, string msg);
  static Diagnostics& getInstance();
  void setExceptions(bool enable);

 private:
  Diagnostics(string type);
  Diagnostics(string type, unordered_map<string, Disposition> disp);

  string sType_;
  unordered_map<string, Disposition> mDspositions_;
  shared_ptr<spdlog::logger> spLogger_;
  shared_ptr<spdlog::logger> spLoggerErr_;
  // runtime exception tag
  bool exceptions_{true};
};

// Compiler diagnostics
inline std::unordered_map<std::string, Disposition> gCompDispMap = {
    {"FILE_DOES_NOT_EXIST", error},    {"FILE_ERROR_READING", error},
    {"LEXER_INPUT_BUFFER_SIZE", info}, {"LEXER_RULE_NOT_FOUND", error},
    {"LEXER_SCANNER_ERROR", error},    {"LEXER_TOKEN_INFO", info}};
}  // namespace ary

// Macro definition for easy access to diagnostics
#define DIAG_COMP_MSG(DIAG, MSG) ary::Diagnostics::getInstance().msg(DIAG, MSG);

#endif  // INCLUDE_DIAGNOSTIC_H_
