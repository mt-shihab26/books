# the-go-programming-language

The Go Programming Language (Alan A. A. Donovan and Brian Kernighan) Book's Code Collection

## Links

-   https://github.com/adonovan/gopl.io
-   https://drive.google.com/file/d/1ICn7mN8mKaouTJISo6VC--yh0l9JC084/view?usp=share_link

## Commands

-   `go run <file-name.go>` compile, links and run
-   `go build <file-name.go` compile, links, executable binary
-   `go doc` Seeing docs
-   `go install` installing binary in $GOPATH/bin/ directory
-   `go fmt` formatting go code

## ch02 - Program Structure

-   Go has 25 keywords
    -   `break`, `case`, `chan`
    -   `const`, `continue`, `default`
    -   `defer`, `else`, `fallthrough`
    -   `for`, `func`, `go`
    -   `goto`, `if`, `import`
    -   `interface`, `map`, `package`
    -   `range`, `return`, `select`
    -   `struct` `switch`, `type`,
    -   `var`
-   Built-in constants, types and functions
    -   Constants:
        -   `true`, `false`, `iota`,`nil`
    -   Types:
        -   Integers: `int`, `int8`, `int16`, `int32`, `int64`, `uint`, `uint8`, `uint16`, `uint32`, `uint64`,`uintptr`
        -   Floats: `float32`, `float64`
        -   Complexes: `complex128` `complex64`
        -   Booleans: `bool`
        -   Characters: `byte` `rune`
        -   Strings: `string`
        -   Errors: `error`
    -   Functions:
        -   `make`, `len`, `cap`,
        -   `new`, `append`, `copy`
        -   `close`, `delete`, `complex`
        -   `real`, `imag`, `panic`,
        -   `recover`
-   There are four major kinds of declarations:
    -   `var`, `const`, `type`, `func`
-   Zero values of Types:
    -   numbers: `0`
    -   booleans: `false`
    -   strings: `""`
    -   interface and reference types (slice, pointer, map, channel, function): `nil`
-   Pointers
    -   `&x` : address of x
    -   `*int` : pointer to int
    -   `p *int = x`: p points to x or p contains th address of x
    -   The zero value for a pointer of any type is `nil`
-   The new Function
    -   The expression `new(T)` create an unnamed variable of type T, initializes it to the zero value of T, and returns it's address, which is a value of type `*T`
    -   two variables whose type carries no information and is therefore of size zero, such as struct{} or [0]int, may, dep ending on the implementation, have the same address
    -   The new function is relatively rarely used because the most common unnamed variables are of struct types, for which the str uct literal syntax is more flexible.
-   Lifetime of Variables
    -   A compiler may choose to allocate local variables on the heap or on the stack but, perhaps surprisingly, this choice is not determined by whether var or new was used to declare the variable.
    -   Garbage collection is a tremendous help in writing cor rect programs, but it does not relieve you of the burden of thinking about memory. You don’t need to explicitly allocate and free memory, but to write efficient programs you still need to be aware of the lifetime of variables. For example, keeping unnecessary pointers to short-lived objects wit hin long-lived objects, especially global variables, will prevent the garbage collector from reclaiming the short-lived objects.
-   Assignments
-   Tuple Assignments
-   Assignability: implicit assignments
    -   Assignment statements are an explicit form of assignment, but there are many places in a program where an assignment occurs implicitly: a function call, a return statement implicitly assigns the return operands;
    -   An assignment, `explicit` or `implicit`, is always legal if the left-hand side (the variable) and the right-hand side (the value) have the same typ e
    -   `==` and `!=` is related to assignability, here also same rule applied.
-   Type Declaration
    -   `Celsius(t)` and `Fahrenheit(t)` are conversions, not function calls
    -   For every type `T`, there is a corresponding conversion operation `T(x)` that converts the value `x` to type `T`
    -   A conversion from one type to another is allowed if both have the same underlying type, or if both are unnamed pointer types that point to variables of the same underlying type; these conversions change the type but not the representation of the value.
    -   If x is assignable to `T`, a conversion is permitted but is usually redundant
    -   In any case, a conversion never fails at run time.
    -   The underlying type of a named type determines its structure and representation, and als o the set of intrinsic operations it supports, which are the same as if the underlying type had been used directly. That means that arithmetic operators work the same for Celsius and Fahrenheit as they do for float64, as you might expect
-   Packages and Files
    -   In Go, a simple rule governs which identifiers are exported and which are not: exported identifiers start with an upper-case letter.
