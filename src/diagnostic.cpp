#include <diagnostic.h>

namespace ary {
Diagnostics::Diagnostics(string type) {
  sType_ = type;
  spLogger_ = spdlog::stdout_color_mt(type);
  spLogger_->set_pattern("[%D %T] [%^%l%$] [%n] [%s] [%!] [line %#]: %v");

  spLoggerErr_ = spdlog::stderr_color_mt(type + " stderr");
  spLoggerErr_->set_pattern("[%D %T] [%^%l%$] [%n] [%s] [%!] [line %#]: %v");
}

Diagnostics::Diagnostics(string type, unordered_map<string, Disposition>& disp)
    : Diagnostics(type) {
  mDspositions_ = disp;
}

void Diagnostics::setDiagnosticMap(unordered_map<string, Disposition>& disp) {
  mDspositions_ = disp;
}

unordered_map<string, Disposition> Diagnostics::getDiagnosticMap() {
  return mDspositions_;
}

void Diagnostics::AddDiagnostic(string diag, Disposition disp) {}

void Diagnostics::RemoveDiagnostic(string diag) {}

void Diagnostics::msg(string diag, string msg) {
  if (mDspositions_.find(diag) == mDspositions_.end()) {
    stringstream ss;
    ss << "Diagnostic not found: " << diag;
    spLoggerErr_->error(ss.str());
  }

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
    case critical:
      SPDLOG_LOGGER_CRITICAL(spLoggerErr_, msg);
      exit(EXIT_FAILURE);
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
  };
}

}  // namespace ary