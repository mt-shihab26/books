package main

import (
	"fmt"
	"log"
	"net/http"
)

// handler echoes the path component
func Handler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "URL.PATH = %q\n", r.URL.Path)
}

func main() {
	http.HandleFunc("/", Handler) // each request call handler
	log.Fatal(http.ListenAndServe("localhost:8000", nil))
}
