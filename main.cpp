#include <string>
#include <memory>
#include <utility>
#include <array>
#include <iostream>


struct ErrorMsg {
    std::string message;
    uint64_t pos;
};

void print_error(const std::string& expr, const ErrorMsg& error) {
    std::printf("\x1b[31m%*c\nerror\x1b[0m: %s\n", (int)error.pos + 1, '^', error.message.c_str());
}

struct Operation {
    enum Kind { add, sub, mul, div, _ } kind;
    uint8_t prior;
    bool left_to_right;

    static const Operation& get(Kind kind) {
        static std::array<Operation, std::to_underlying(Kind::_)> ops = {
            Operation{ mul, 1, true }, Operation{ div, 1, true },
            Operation{ add, 2, true }, Operation{ sub, 2, true },
        };

        return ops[std::to_underlying(kind)];
    }
};

struct Expr;
using ExprPtr = std::unique_ptr<Expr>;

struct OpNode {
    Operation::Kind op;
    ExprPtr lhs, rhs;
};

struct LeafNode {
    uint64_t value;
};

struct Expr {
    // ...

    static ExprPtr parse(const std::string& expr) {
        // ...
    }
};

/*

  Steps:

  1. Create a parser for a mathematical expressions, containing '+', '-', '/', '*', braces 
     and unsigned integral numbers. Make sure it reports great error messages!
  2. Create either a formula tree for the expression.
  3. Print a post-order (LRN) traversal of the obtained tree.

  Bonus: 

  4. Evaluate it!

*/

int main(int, char**) {
    std::string expr;
    std::getline(std::cin, expr);
    // ...
}
