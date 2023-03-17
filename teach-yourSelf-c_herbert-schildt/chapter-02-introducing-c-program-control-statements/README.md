# Chapter 02 - Introducing C's Program Control Statements

## English Words:-

1. backbone = মেরুদন্ড
2. forms = ফর্ম
3. circumstances = পরিস্থিতি

## key:-

### 2.1 - Become Familiar with The `if`

1. `if` selection statement
2. relation operators `>`, `<`, `==`
3. `true` is any `nonzero` and `false` is `zero`

### 2.2 - Add the `else`

### 2.3 - Create Blocks of code

1. a code block

### 2.4 - Use the for Loop

1. for loop: `for(initialization; conditional-test; increment) statement;`

### 2.5 - Substitute C's Increment and decrement operators

1. increment operator `++`
2. decrement operator `--`

### 2.6 - Expand printf()'s capabilities

1. Backslash codes can use anywhere you can use a normal character.
2. The backslash constants are also referred to as `escape sequences`.
3. Table - C's Backslash Codes
   | Code | Meaning |
   | :---- | ----------------------------------------------------- |
   | `\b` | Backspace |
   | `\f` | Form feed |
   | `\n` | Newline |
   | `\r` | Carriage return |
   | `\t` | Horizontal tab |
   | `\"` | Double quote |
   | `\'` | Single quote |
   | `\0` | Null |
   | `\\` | Backslash |
   | `\v` | Vertical tab |
   | `\a` | Alert |
   | `\?` | Question mark |
   | `\/v` | Octal constant (where N is an octal value) |
   | `\XN` | Hexadecimal constant (where N is a hexadecimal value) |
4. `\n` is encounters as `carriage return / linefeed combination`
5. The backslash codes are character constants.

### 2.7 - Program with C's relational and Logical Operators

1. Relational Operators
   | Operator | Action |
   | -------- | --------------------- |
   | `>` | Greater than |
   | `>=` | Greater then or equal |
   | `<` | Less then |
   | `<=` | Less Than or equal |
   | `==` | Equal |
   | `!=` | Not equal |
2. The relational and logical operators are both lower in precedence then the arithmetic operators.
3. Logical operator
   | Operator | Action |
   | -------- | ------ |
   | `&&` | AND |
   | \|\| | OR |
   | `!` | NOT |
4. The relational and Logical operators always produce the value `1` for `true` and the `0 `for `false`
5. Relative precedence

   | Highest | `!`               |
   | ------- | ----------------- |
   |         | `>` `>=` `<` `<=` |
   |         | `==` `!=`         |
   |         | `&&`              |
   | Lowest  | \|\|              |
