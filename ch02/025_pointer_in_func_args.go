package main

func incr(p *int) *int {
	*p++
	return p
}

func main() {
	v := 1
	println(v)

	println(*incr(&v))
	println(*incr(&v))
	println(*incr(&v))
	println(*incr(&v))
}
