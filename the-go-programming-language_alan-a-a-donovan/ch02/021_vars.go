package main

import (
	"fmt"
	"os"
)

func main() {
	var s string
	fmt.Println(s) // ""

	// var i, j, k int                 // int , int , int
	// var b, f, s = true, 2.3, "four" // bool, float64, string

	var f, err = os.Open("./main.go")
	if err != nil {
		fmt.Println(err)
	}
	defer f.Close()

	fmt.Println(f)
}
