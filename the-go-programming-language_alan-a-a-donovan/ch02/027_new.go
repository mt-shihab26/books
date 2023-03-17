package main

func newInt() *int {
	return new(int)
}

func newInt2() *int {
	var dummy int
	return &dummy
}

// because new is function we can redefine.
// Of course, within delta, the built-in new function is unavailable
func delta(old, new int) int {
	return new - old
}

func main() {
	p := new(int) // p, of type *int, points to an unnamed int variable
	println(*p)   // "0"
	*p = 2
	println(*p) // 2

	p = newInt()
	*p = 20
	println(*p)

	p = newInt2()
	*p = 25
	println(*p)

	p = new(int)
	q := new(int)

	println(p == q)
}
