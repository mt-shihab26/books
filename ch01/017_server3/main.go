package main

import (
	"fmt"
	"log"
	"net/http"
	"strconv"
	"sync"

	"github.com/shh26b/the-go-programming-language/ch01/014_lissajous/lissajous"
)

var mu sync.Mutex
var count int

func main() {
	http.HandleFunc("/", rootHandler)
	http.HandleFunc("/count", countHandler)
	http.HandleFunc("/gif", gifHandler)

	log.Fatal(http.ListenAndServe("localhost:8000", nil))
}

// handler echoes the Path component
func rootHandler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "%s %s %s\n", r.Method, r.URL, r.Proto)

	for k, v := range r.Header {
		fmt.Fprintf(w, "Header[%q] = %q\n", k, v)
	}
	fmt.Fprintf(w, "Host = %q\n", r.Host)
	fmt.Fprintf(w, "RemoteAddr = %q\n", r.RemoteAddr)
	if err := r.ParseForm(); err != nil {
		log.Print(err)
	}
	for k, v := range r.Form {
		fmt.Fprintf(w, "Form[%q] = %q\n", k, v)
	}
}

// counter echoes the number of calls so far
func countHandler(w http.ResponseWriter, r *http.Request) {
	mu.Lock()
	fmt.Fprintf(w, "Count %d\n", count)
	mu.Unlock()
}

func gifHandler(w http.ResponseWriter, r *http.Request) {
	query := r.URL.Query()

	value, err := strconv.Atoi(query.Get("hello"))
	if err != nil {
		fmt.Printf("%v\n", err)
	}

	fmt.Println(value)

	lissajous.Lissajous(w)
}
