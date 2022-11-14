package main

import (
	"log"
	"net/http"

	"github.com/shh26b/the-go-programming-language/ch01/015_server1/handler"
)

func main() {
	http.HandleFunc("/", handler.Handler) // each request call handler
	log.Fatal(http.ListenAndServe("localhost:8000", nil))
}
