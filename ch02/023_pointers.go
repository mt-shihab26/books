package main

import "fmt"

func main() {
	x := 1
	p := &x         // p, of type *int, points to x
	fmt.Println(*p) // 1
	*p = 2          // equivalent to x = 2
	fmt.Println(x)  // 2

	var x2, y int

	fmt.Println(&x2 == &x2, &x2 == &y, &x2 == nil)
}
