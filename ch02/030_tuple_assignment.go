package main

import (
	"fmt"
	"os"
)

func gcd(x, y int) int {
	for y != 0 {
		x, y = y, x%y
	}
	return x
}

func fib(n int) int {
	x, y := 0, 1
	for i := 0; i < n; i++ {
		x, y = y, x+y
	}
	return x
}

func main() {
	x, y := 10, 20
	a := [5]int{1, 2, 3, 4, 5}

	x, y = y, x
	a[0], a[1] = a[1], a[0]
	fmt.Println(x, y)
	fmt.Println(a)

	i, j, k := 2, 3, 5
	fmt.Println(i, j, k)

	f, err := os.Open("foo.txt")
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println(f)

	m := map[string]int{
		"hello": 100,
		"world": 200,
	}
	v, ok := m["hello"]
	fmt.Println(v, ok)

	v2, ok := m["b"]
	fmt.Println(v2, ok)

	for _, v := range m {
		fmt.Println(v)
	}
}
