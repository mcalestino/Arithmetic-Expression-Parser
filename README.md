## Arithmetic Expressions

An arithmetic expression is defined as a sequence of tokens delimited by whitespaces. Tokens can be operators, numbers, and left/right parentheses. For the purposes of this assignment, the following operators are considered:

* `-` subtraction and `+` addition
* `*` multiplication and `/` division (performs integer division)
* `^` exponentiation (exponent will always be >= 0)

The list above shows operators in order of precedence from lower to higher. Operators with the same precedence occurring in an expression should be evaluated from left to right (left associativity), with the exception of `^` which is right-associative. For example `5 - 2 + 3` should evaluate to `6` and `2 ^ 3 ^ 2` should evaluate to `512`.

Each number in an arithmetic expression is an integer number that may contain multiple digits and may be positive or negative. For example, ` 3 345 -129 0 +321 -1 ` are all valid numbers.

In this assignment, you can assume that all arithmetic expressions (infix and postfix) must have 0 leading and trailing whitespaces. Furthermore, all tokens in an expression must be separated by exactly 1 whitespace.```

***Infix Notation*** is the usual way to write arithmetic expressions in which every operator appears between two operands. More formally, an infix expression is recursively defined as follows:

```
1. any number is a valid infix expression
2. if E is an infix expression, then '( E )' is an infix expression
3. if E1 and E2 are infix expressions, and OP is an operator, then 'E1 OP E2' is an infix expression
```

***Postfix Notation*** is a way to write arithmetic expressions in which every operator follows its operands in the expression. More formally, a postfix expression is recursively defined as follows:

```
1. any number is a valid postfix expression
2. if P1 and P2 are postfix expressions, and OP is an operator, then 'P1 P2 OP' is a postfix expression
```

Parentheses are not necessary in postfix expressions because the order of operations is given by the order of operands and operators (from left to right). The table below shows several examples of equivalent infix and postfix arithmetic expressions.

| Infix Expression          | Postfix expression    | Result |
|---------------------------|-----------------------|--------|
| 1 + 2                     | 1 2 +                 | 3      |
| -10 + 20 * ( 30 / 2 )     | -10 20 30 2 / * +     | 290    |
| ( 5 + 3 ) * 12 / 3        | 5 3 + 12 * 3 /        | 32     |
| 33 + 12 - 12 / ( 4 * -9 ) | 33 12 + 12 4 -9 * / - | 46     |
| 1 + 2 - 3 * 4 / 5 ^ 6     | 1 2 + 3 4 * 5 6 ^ / - | 3      |

