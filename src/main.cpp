#include <argparse/argparse.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "ary.h"

using namespace std;

int main(int argc, char* argv[]) {
  argparse::ArgumentParser program("Ary");

  program.add_argument("input_file").help("input .ary file to be compiled");

  try {
    program.parse_args(argc, argv);
  } catch (const std::exception& err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    return 1;
  }

  string filePath = program.get<string>("input_file");

  ifstream file;
  file.open(filePath);
  if (!file) {
    stringstream msg;
    msg << "unable to open file \'" << filePath << "\'";
    DIAG_COMP_MSG("FILE_DOES_NOT_EXIST", msg.str());
  }

  return 0;
}