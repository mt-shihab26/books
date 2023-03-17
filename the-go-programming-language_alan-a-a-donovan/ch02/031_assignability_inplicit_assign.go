package main

import "fmt"

func main() {
	modals := []string{"gold", "silver", "bronze"}
	// implicitly assigns each element, as if it had been written like this
	modals[0] = "gold"
	modals[1] = "silver"
	modals[2] = "bronze"

	fmt.Println(modals)
}
