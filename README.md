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

## Go has 25 keywords

-   `break`, `case`, `chan`
-   `const`, `continue`, `default`
-   `defer`, `else`, `fallthrough`
-   `for`, `func`, `go`
-   `goto`, `if`, `import`
-   `interface`, `map`, `package`
-   `range`, `return`, `select`
-   `struct` `switch`, `type`,
-   `var`

## Built-in constants, types and functions

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

## ch02 - Program Structure

-   There are four major kinds of declarations:
    -   `var`, `const`, `type`, `func`
-   Zero values of Types:
    -   numbers: `0`
    -   booleans: `false`
    -   strings: `""`
    -   interface and reference types (slice, pointer, map, channel, function): `nil`
