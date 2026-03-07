fn main() {
    let s = String::from("Hello world");
    let w = first_word(&s);

    println!("the first word of '{s}' is '{w}'");

    let s = String::from("Hello");
    let w = first_word(&s);

    println!("the first word of '{s}' is '{w}'");

    let s = "This is Rust";
    let w = first_word(&s);

    println!("the first word of '{s}' is '{w}'");

    // s.clear();

    // println!("the first word of '{s}' is '{w}'")
}

fn first_word(s: &str) -> &str {
    for (i, c) in s.chars().enumerate() {
        if c == ' ' {
            return &s[..i];
        }
    }

    &s[..]
}
