#include "lexer.h"

#include <gtest/gtest.h>
#include <stdlib.h> /* srand, rand */

#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <unordered_map>

#include "token.h"

using namespace std;
using spLexer = shared_ptr<ary::Lexer>;

TEST(Lexer, Accessors) {}

TEST(Lexer, ScanString) {
  std::string input = R"(
        func main(): void{
            string n = "Hello world";
            print(n);
        }
    )";

  // spLexer lex = make_shared<ary::Lexer>();
}

TEST(Lexer, ScanFile) {
  std::string input = R"(
        // This is a comment
        func main(): void{
            string n = "Hello world";
            char d = 'a';
            bool a = !(true);
            int b = 123;
            float c = 3.14159265;
             // If statement
            if !(true && true) {
                print("false");
            }else if !false{
                print("true");
            }else{
                print("false");
            }

            // While statement
            int a = 0;
            while a < 10 {
                print(a);
                a++;
            }

            print(n);
        }
    )";

  std::ofstream outFile("ScanFile-Test.ary");
  EXPECT_TRUE(outFile.is_open());

  outFile << input;

  outFile.close();

  spLexer lexer = make_shared<ary::Lexer>();
  lexer->scanFile("ScanFile-Test.ary");
}
