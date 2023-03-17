// echg5 prints its command-line arguments with command name

package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	s := strings.Join(os.Args, " ")
	fmt.Println(s)
}
