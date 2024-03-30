#include <ary.h>

#include <iostream>

using namespace std;
using namespace ary;

int main() {
  COMP_DIAG_MSG("TEST", "This does not exists");
  ARY_DIAG_MSG("TEST", "This is for ary");
}