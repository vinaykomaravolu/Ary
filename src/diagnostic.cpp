#include "diagnostic.h"

namespace ary {
// Public

void Diagnostics::setDiagnosticMap(unordered_map<string, Disposition> disp) {
  mDspositions_ = disp;
}

unordered_map<string, Disposition> Diagnostics::getDiagnosticMap() {
  return mDspositions_;
}

void Diagnostics::AddDiagnostic(string diag, Disposition disp) {
  mDspositions_[diag] = disp;
}

void Diagnostics::RemoveDiagnostic(string diag) {
  auto it = mDspositions_.find(diag);
  if (it != mDspositions_.end()) {
    mDspositions_.erase(diag);
  }
}

void Diagnostics::msg(string diag, string msg) {
  if (mDspositions_.find(diag) == mDspositions_.end()) {
    stringstream ss;
    ss << "Diagnostic not found: " << diag;
    spLoggerErr_->error(ss.str());
  }
  msg = diag + ": " + msg;
  Disposition disp = mDspositions_[diag];
  switch (disp) {
    case info:
      SPDLOG_LOGGER_INFO(spLogger_, msg);
      break;
    case warn:
      SPDLOG_LOGGER_WARN(spLogger_, msg);
      break;
    case error:
      SPDLOG_LOGGER_ERROR(spLoggerErr_, msg);
      exit(EXIT_FAILURE);
      break;
    case error_as_warn:
      SPDLOG_LOGGER_ERROR(spLoggerErr_, msg);
      break;
    case critical:
      SPDLOG_LOGGER_CRITICAL(spLoggerErr_, msg);
      exit(EXIT_FAILURE);
      break;
    case critical_as_warn:
      SPDLOG_LOGGER_CRITICAL(spLoggerErr_, msg);
      break;
    case ignore:
      // ignore diagnostic for these cases
      break;
    default:
      stringstream ss;
      ss << "Unable to find disposition \"" << disp << "\" for diagnostic \""
         << diag << "\"";
      spLoggerErr_->error(ss.str());
      break;
  }
}

Diagnostics& Diagnostics::getInstance() {
  static Diagnostics instance("Compiler", gCompDispMap);
  return instance;
}

// Private
Diagnostics::Diagnostics(string type) {
  sType_ = type;
  spLogger_ = spdlog::stdout_color_mt(type);
  spLogger_->set_pattern("[%D %T] [%^%l%$] [%n] %v");

  spLoggerErr_ = spdlog::stderr_color_mt(type + " stderr");
  spLoggerErr_->set_pattern("[%D %T] [%^%l%$] [%n] %v");
}

Diagnostics::Diagnostics(string type, unordered_map<string, Disposition> disp)
    : Diagnostics(type) {
  mDspositions_ = disp;
}

}  // namespace ary
