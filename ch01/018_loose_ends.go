package main

import "fmt"

func coinflip() string {
	return "heads"
}

func Touch() {
	heads, tails := 0, 0
	switch coinflip() {
	case "heads":
		heads++
	case "tails":
		tails++
	default:
		fmt.Println("landed on edge")
	}
}

// tagless switch
func Signum(x int) int {
	switch {
	case x > 0:
		return +1
	case x < 0:
		return -1
	default:
		return 0
	}
}

type Point struct {
	X, Y int
}

var p Point

func main() {
	p.X = 20
	p.Y = 30
}
