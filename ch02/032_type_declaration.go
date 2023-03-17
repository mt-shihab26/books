package main

import "fmt"

type Celsius float64
type Fahrenheit float64

const (
	AbsoluteZeroC Celsius = -273.15
	FreezingC     Celsius = 0
	BoilingC      Celsius = 100
)

func CToF(c Celsius) Fahrenheit {
	return Fahrenheit(c*9/5 + 32)
}

func FToC(f Fahrenheit) Celsius {
	return Celsius((f - 32) * 5 / 9)
}

func (c Celsius) String() string {
	return fmt.Sprintf("%g°C", c)
}

func main() {
	fmt.Printf("%g\n", BoilingC-FreezingC)
	boilingC := CToF(BoilingC)
	fmt.Printf("%g\n", boilingC-CToF(FreezingC))
	// fmt.Printf("%g\n", boilingC-FreezingC) // compile error: type mismatch

	var c Celsius
	var f Fahrenheit

	fmt.Println(c == 0)
	fmt.Println(f >= 0)
	// fmt.Println(c == f) // compile error: type mismatch
	fmt.Println(c == Celsius(f))

	h := Celsius(100)
	fmt.Println(h.String())
	fmt.Printf("%v\n", h)   // "100°C"
	fmt.Printf("%s\n", h)   // "100°C"; no need to call String explicitly
	fmt.Println(h)          // "100°C"
	fmt.Printf("%g\n", h)   // "100"; does not call String method
	fmt.Println(float64(h)) // "100"; does not call String method
}
