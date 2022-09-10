// echg2 prints its command-line arguments

package main

import (
	"fmt"
	"os"
)

func main() {
	// var s string
	// var s string = ""
	// var s = ""
	s := ""
	for _, arg := range os.Args[1:] {
		s += " " + arg
	}
	fmt.Println(s)
}
