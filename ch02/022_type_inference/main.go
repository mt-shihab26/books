package main

import (
	"fmt"
	"os"
)

func main() {
	// nframes := 1
	// anim := gif.GIF{LoopCount: nframes}
	// freq := rand.Float64() * 3.0
	// t := 0.0

	// i := 100

	// var boiling float64 = 100

	// var names []string
	// var err error
	// var p Point

	i, j := 0, 1

	i, j = j, i

	fmt.Println(i, j)

	f, err := os.Open("main.go")
	if err != nil {
		fmt.Println(err.Error())
	}
	f.Close()

	// in, err := os.Open("main.go")
	// out, err := os.Create("text.go")

	// f, err := os.Open(infile)
	// f, err := os.Create(outfile) // compile error: no new variables
}
