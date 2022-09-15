package handler

import (
	"fmt"
	"net/http"
)

// handler echoes the path component
func Handler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "URL.PATH = %q\n", r.URL.Path)
}
