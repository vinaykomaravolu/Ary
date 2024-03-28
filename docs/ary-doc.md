- [Ary Documentation](#ary-documentation)
  - [Basic example](#basic-example)
  - [Data Types](#data-types)
  - [Operators](#operators)
    - [Arithmetic Operators](#arithmetic-operators)
    - [Assignment Operators](#assignment-operators)
    - [Comparison Operators](#comparison-operators)
    - [Logical Operators](#logical-operators)
    - [Bitwise Operators](#bitwise-operators)
    - [Upcoming Operators](#upcoming-operators)
  - [Functions](#functions)
  - [Control Flows](#control-flows)
  - [Classes/Objects/User Defined Data Types](#classesobjectsuser-defined-data-types)
  - [File Import](#file-import)

# Ary Documentation


## Basic example

```
func main(): void{
    string n = "Hello world";
    print(n);
}
```

## Data Types
| Data Type      | Keyword        | Example                                                | Description                                 |
|----------------|----------------|--------------------------------------------------------|---------------------------------------------|
| Integer        | `int`          | `int a = 1;`                                           | Represents a 64-bit integer value.          |
| Float          | `float`        | `float b = 2.0;`                                       | Represents a floating-point number.         |
| String literals| `string`       | `string d = "hello";`                                  | Represents a sequence of characters.        |
| Character      | `char`         | `char c = 'h';`                                        | Represents a single character.              |
| Boolean        | `bool`         | `bool j = false;`                                      | Represents a boolean value (true/false).    |
| Function       | `func`         | `func add<int,int,int>: int = (int a, int b, int c): int{ return a + b + c; }` | Represents a function variable. |
| Array          | `int[]`        | `int[3] i; i[0] = 1; i[1] = 2; i[2] = 3;`               | Represents an array of integers.           |
|                |                | `int[] k = {1, 3, 4, 5};`                              | Represents a dynamically sized array of integers. |
| Struct         | `struct`       | `struct Point { int x; int y; } Point p; p.x = 10; p.y = 20;` | Represents a composite data type consisting of multiple fields. |
| Pointer        | `int*`         | `int x = 42; int* ptr = &x;`                            | Represents a pointer to an integer value.  |
| Enum           | `enum`         | `enum Color { RED, GREEN, BLUE } Color c = Color.RED;` | Represents a set of named integer constants.|

## Operators

### Arithmetic Operators

| Operator Name | Operator Symbol | Example                 | Description                                 |
|---------------|-----------------|-------------------------|---------------------------------------------|
| Exponent | \*\* | `int a = 2 ** 3;`          | Calculates the exponent of a number.       |
| Modulus | % | `int b = 22 % 8;`           | Finds the remainder of division.           |
| Division | / | `float d = 22 / 8;`         | Performs division.                         |
|  |  | `int dd = 22 / 8;`         | Performs integer division (floor division).|
| Multiplication | \* | `int e = 3 * 3;`            | Multiplies two numbers.                    |
| Subtraction | - | `int f = 5 - 2;`            | Subtracts one number from another.         |
| Addition | + | `int h = 2 + 2;`            | Adds two numbers.                          |
| Increment | ++ | `int i = 10; int k = i++;` | Post-increment: Increments a variable by 1 after returning its value.|
|  |  | `int i = 10; int j = ++i;` | Pre-increment: Increments a variable by 1 before returning its value. |
| Decrement | -- | `int i = 10; int k = i--;` | Post-decrement: Decrements a variable by 1 after returning its value.|
|  |  | `int i = 10; int j = --i;` | Pre-decrement: Decrements a variable by 1 before returning its value. |


### Assignment Operators


| Operator Name | Symbol | Example                | Description                                 |
|---------------|--------|------------------------|---------------------------------------------|
| Addition Assignment | += | `x += 3;`             | Adds the value on the right to the variable on the left and assigns the result to the variable. |
| Subtraction Assignment | -= | `y -= 4;`          | Subtracts the value on the right from the variable on the left and assigns the result to the variable. |
| Multiplication Assignment | *= | `z *= 5;`       | Multiplies the variable on the left by the value on the right and assigns the result to the variable. |
| Division Assignment | /= | `m /= 4;`             | Divides the variable on the left by the value on the right and assigns the result to the variable. |
| Modulus Assignment | %= | `n %= 5;`             | Performs modulus operation on the variable on the left with the value on the right and assigns the result to the variable. |
| Right Shift Assignment | >>= | `o >>= 2;`       | Shifts the bits of the variable on the left to the right by the number of bits specified on the right and assigns the result to the variable. |
| Left Shift Assignment | <<= | `p <<= 2;`         | Shifts the bits of the variable on the left to the left by the number of bits specified on the right and assigns the result to the variable. |
| Bitwise AND Assignment | &= | `q &= 9;`          | Performs bitwise AND operation between the variable on the left and the value on the right and assigns the result to the variable. |
| Bitwise XOR Assignment | ^= | `r ^= 6;`          | Performs bitwise XOR operation between the variable on the left and the value on the right and assigns the result to the variable. |
| Bitwise OR Assignment | &#124;= | `s &#124;= 3;`           | Performs bitwise OR operation between the variable on the left and the value on the right and assigns the result to the variable. |

### Comparison Operators


| Operator Name          | Symbol | Example                               | Description                                           |
|------------------------|--------|---------------------------------------|-------------------------------------------------------|
| Equal to               | ==     | `bool result1 = (a == b);`           | Checks if the values on both sides are equal.        |
| Not equal to           | !=     | `bool result2 = (c != d);`           | Checks if the values on both sides are not equal.    |
| Greater than           | >      | `bool result3 = (e > f);`            | Checks if the value on the left is greater than the value on the right. |
| Less than              | <      | `bool result4 = (g < h);`            | Checks if the value on the left is less than the value on the right. |
| Greater than or equal to | >=   | `bool result5 = (i >= j);`           | Checks if the value on the left is greater than or equal to the value on the right. |
| Less than or equal to  | <=     | `bool result6 = (k <= l);`           | Checks if the value on the left is less than or equal to the value on the right. |

### Logical Operators


| Operator Name | Symbol | Example                            | Description                            |
|---------------|--------|------------------------------------|----------------------------------------|
| Logical NOT   | !      | `bool a = true; bool b = !a;`     | Negates the value of the expression.  |
| Logical AND   | &&     | `bool c = true; bool d = false; bool e = c && d;` | Returns true if both expressions evaluate to true. |
| Logical OR    | \|\|   | `bool f = true; bool g = false; bool h = f \|\| g;` | Returns true if either expression evaluates to true. |

### Bitwise Operators

| Operator Name    | Symbol | Example                            | Description                            |
|------------------|--------|------------------------------------|----------------------------------------|
| Bitwise NOT      | ~      | `int a = 5; int b = ~a;`           | Bitwise negation of the operand.       |
| Bitwise AND      | &      | `int c = 12; int d = 9; int e = c & d;` | Bitwise AND operation between the operands. |
| Bitwise OR       | \|     | `int f = 5; int g = 3; int h = f \| g;` | Bitwise OR operation between the operands.  |
| Bitwise XOR      | ^      | `int i = 10; int j = 6; int k = i ^ j;` | Bitwise XOR operation between the operands. |
| Left Shift       | <<     | `int l = 4; int m = l << 2;`         | Shifts the bits of the first operand to the left by the number of bits specified by the second operand. |
| Right Shift      | >>     | `int n = 16; int o = n >> 2;`       | Shifts the bits of the first operand to the right by the number of bits specified by the second operand. |


### Upcoming Operators

- [ ] Pointer *,->
- [ ] Derefence $
- [ ] Inline if-else ?: 
- [ ] Parallelism 
- [ ] Null pointer check ??
- [ ] Null pointer inline assignment ??= 

## Functions

| Function Type               | Example                                                   | Description                                    |
|-----------------------------|-----------------------------------------------------------|------------------------------------------------|
| Default Return Value        | ```func output(string a) { print(a); }```                | Function with default return type `void`.     |
| Function Return Type        | ```func add(int a, int b): int { return a + b; }```      | Function with explicit return type `int`.     |
| Reference Parameter         | ```func addTo(int & a, int b) { a += b; }```             | Function with a reference parameter.          |
| Templated Function          | ```type<T>; func subtract(T a, T b): T { return a - b; }```       | Function templated on type `T`.               |
| Declare/Define Function Var | ```func mult<float,float>: float;```                     | Declaration of a function variable `mult`.    |
|                             | ```func mult = (float a, float b): float { return a * b; }``` | Definition of the function variable `mult`. |
| Inline Functional Programming | ```float n = (float a, float b): float { return a * b; }(10,10);``` | Inline functional declaration and call.         |
| Main Entry Function         | ```func main() { ... }```                                | Main entry function.                          |

## Control Flows

| Control Flow | Keyword | Example | Description |
|--------------|---------|---------|-------------|
| If Statement | if, else, else if | ```if !(true && true) { print("false"); } else if !false { print("true"); } else { print("false"); }``` | Executes different code blocks based on conditions. |
| While Statement | while | ```int a = 0; while a < 10 { print(a); a++; }``` | Executes a block of code repeatedly as long as a condition is true. |
| For Statement | for | ```for int i: 1..100 { print(i); }``` | Iterates a block of code a fixed number of times. |

## Classes/Objects/User Defined Data Types

Currently there is no support for user defined data types

## File Import

You are able to import code from relative files. Conflicting declarations will choose the first declaration found and ignore the rest.

```
// File: lib/helper.ary

func add(int a, int b): int {
    return a + b;
}

```

```
import lib/helper.ary

func main(): void{
    print(add(1,2)); // Should output 3
}
```
