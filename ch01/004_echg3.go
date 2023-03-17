// echg3 prints its command-line arguments

package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	s := strings.Join(os.Args[1:], " ")
	fmt.Println(s)
}
