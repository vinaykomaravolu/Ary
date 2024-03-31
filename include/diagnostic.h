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

#include "shared.h"

using namespace std;

namespace ary {

class Diagnostics {
 public:
  void setDiagnosticMap(unordered_map<string, Disposition> disp);
  unordered_map<string, Disposition> getDiagnosticMap();
  void AddDiagnostic(string diag, Disposition disp);
  void RemoveDiagnostic(string diag);
  void msg(string diag, string msg);
  static Diagnostics& getInstance();

 private:
  Diagnostics(string type);
  Diagnostics(string type, unordered_map<string, Disposition> disp);

  string sType_;
  unordered_map<string, Disposition> mDspositions_;
  shared_ptr<spdlog::logger> spLogger_;
  shared_ptr<spdlog::logger> spLoggerErr_;
};

}  // namespace ary

// Macro definition for easy access to diagnostics
#define DIAG_COMP_MSG(DIAG, MSG) ary::Diagnostics::getInstance().msg(DIAG, MSG);

#endif  // INCLUDE_DIAGNOSTIC_H_
