#include "diagnostic.h"

#include <gtest/gtest.h>
#include <stdlib.h> /* srand, rand */

#include <iostream>
#include <random>
#include <string>
#include <unordered_map>

#include "diagnostic.h"

using namespace std;

TEST(Diagnostics, Accessors) {
  unordered_map<string, ary::Disposition> dispMap = {{"TESTA", ary::info}};
  auto diag = ary::Diagnostics::getInstance();

  diag.setDiagnosticMap(dispMap);
  diag.msg("TESTA", "This is message test for accessors TESTA info");
  diag.AddDiagnostic("TESTB", ary::info);
  diag.AddDiagnostic("TESTB", ary::warn);

  EXPECT_EQ(diag.getDiagnosticMap().size(), 2);

  diag.msg("TESTB", "This is message test for accessors TESTB warn");
  diag.RemoveDiagnostic("TESTA");

  EXPECT_EQ(diag.getDiagnosticMap().size(), 1);
}

TEST(Diagnostics, Dispositions) {
  unordered_map<string, ary::Disposition> dispMap = {
      {"TESTA", ary::info},
      {"TESTB", ary::warn},
      {"TESTC", ary::error},
      {"TESTD", ary::critical},
      {"TESTF", ary::ignore},
      {"TESTG", ary::error_as_warn},
      {"TESTH", ary::critical_as_warn},
  };

  auto diag = ary::Diagnostics::getInstance();
  diag.setDiagnosticMap(dispMap);

  diag.msg("TESTA", "This is message test for dspositions TESTA info");
  diag.msg("TESTB", "This is message test for dspositions TESTB warn");
  // diag.msg("TESTC", "This is message test for dspositions TESTC error"); Will
  // exit application diag.msg("TESTD", "This is message test for dspositions
  // TESTD critical"); Will exit application
  diag.msg(
      "TESTF",
      "This is message test for dspositions TESTF ignore");  // will not sure up
  diag.msg("TESTG", "This is message test for dspositions TESTG error_as_warn");
  diag.msg("TESTH",
           "This is message test for dspositions TESTH critical_as_warn");

  EXPECT_EQ(diag.getDiagnosticMap().size(), 7);
}
