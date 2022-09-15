// Lissajous generates GIF animations of random Lissajous figures.
package main

import (
	"os"

	"github.com/shihab4t/the-go-programming-language/ch01/014_lissajous/lissajous"
)

func main() {
	lissajous.Lissajous(os.Stdout)
}
