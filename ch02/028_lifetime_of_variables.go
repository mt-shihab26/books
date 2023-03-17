package main

var global *int

func f() {
	var x int
	x = 1
	global = &x
	println("f(): ", x)
}

func g() {
	y := new(int)
	*y = 1
	println("g(): ", *y)
}

func main() {
	f()
	g()

	println(*global)
}

// Here, x must be heap-allocated because it is still reachable from the variable global after f
// has returned, despite being declared as a local variable; we say x escapes from f. Conversely,
// when g returns, the variable *y becomes unreachable and can be rec ycled. Since *y does not
// escape from g, it’s safe for the compiler to allocate *y on the stack, even though it was
// allocated with new.
