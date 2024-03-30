#include "diagnostic.h"

using namespace std;

namespace ary {

// Compiler diagnostics
unordered_map<string, Disposition> gCompDispMap = {{"TEST", info}};

// Ary diagnostics
unordered_map<string, Disposition> gAryDispMap = {{"TEST", error}};

// Global diagnostics
shared_ptr<Diagnostics> gCompDiag =
    std::make_shared<Diagnostics>("Compiler", gCompDispMap);
shared_ptr<Diagnostics> gAryDiag =
    std::make_shared<Diagnostics>("Ary", gAryDispMap);

// Macro definition for easy access to diagnostics
#define COMP_DIAG_MSG(DIAG, MSG) gCompDiag->msg(DIAG, MSG);
#define ARY_DIAG_MSG(DIAG, MSG) gAryDiag->msg(DIAG, MSG);

}  // namespace ary