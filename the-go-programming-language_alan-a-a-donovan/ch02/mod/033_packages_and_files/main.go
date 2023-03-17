package main

import (
	"fmt"

	"github.com/shh26b/the-go-programming-language/ch02/mod/tempconv"
)

func main() {
	fmt.Printf("Brrrr! %v\n", tempconv.AbsoluteZeroC)
	fmt.Println(tempconv.CToF(tempconv.BoilingC))
}
