#include "lexer.h"

#include <gtest/gtest.h>
#include <stdlib.h> /* srand, rand */

#include <iostream>
#include <random>
#include <string>
#include <unordered_map>

#include "shared.h"

using namespace std;
using spLexer = shared_ptr<ary::Lexer>;

TEST(Lexer, Accessors) {}

TEST(Lexer, Scan) {
  std::string input = R"(
        func main(): void{
            string n = "Hello world";
            print(n);
        }
    )";

  spLexer lex = make_shared<ary::Lexer>();
}
