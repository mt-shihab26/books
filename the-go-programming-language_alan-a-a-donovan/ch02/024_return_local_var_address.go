package main

func f() *int {
	v := 1
	return &v
}

func main() {
	x := f()

	y := f()

	println(x, *x)
	println(y, *y)
	println(x == y) // false
}
