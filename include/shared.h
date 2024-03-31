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

// Compiler diagnostics
inline std::unordered_map<std::string, Disposition> gCompDispMap = {
    {"TEST", info}};
}  // namespace ary

#endif  // INCLUDE_SHARED_H_
