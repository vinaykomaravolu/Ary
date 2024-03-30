#ifndef ARY_DIAGNOSTIC_H_
#define ARY_DIAGNOSTIC_H_

#include <memory.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/spdlog.h>

#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

namespace ary {

enum Disposition {
  info,
  warn,
  error,
  critical,
  fatal,
  ignore,
};

class Diagnostics {
 public:
  Diagnostics(string type);
  Diagnostics(string type, unordered_map<string, Disposition>& disp);
  void setDiagnosticMap(unordered_map<string, Disposition>& disp);
  unordered_map<string, Disposition> getDiagnosticMap();
  void AddDiagnostic(string diag, Disposition disp);
  void RemoveDiagnostic(string diag);
  void msg(string diag, string msg);

 private:
  string sType_;
  unordered_map<string, Disposition> mDspositions_;
  shared_ptr<spdlog::logger> spLogger_;
  shared_ptr<spdlog::logger> spLoggerErr_;
};
}  // namespace ary
#endif  // ARY_DIAGNOSTIC_H_