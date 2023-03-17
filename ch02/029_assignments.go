package main

import "fmt"

type Person struct {
	name string
}

func main() {
	var (
		x      int
		p      *bool  = new(bool)
		person Person = Person{"fuck"}
		count  [3]int
		scale  int = 20
	)
	count[2] = 1

	x = 1                       // named variable
	*p = true                   // indirect variable
	person.name = "bob"         // struct field
	count[2] = count[2] * scale // array or slice or map element

	count[2] *= scale

	x++
	x--

	fmt.Println(x, *p, person, count)
}
