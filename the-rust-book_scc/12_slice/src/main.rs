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

    let a = [1, 2, 3, 4, 5];
    let x = &a[1..3];

    println!("The slice of {:?} is {:?}", a, x);
}

fn first_word(s: &str) -> &str {
    for (i, c) in s.chars().enumerate() {
        if c == ' ' {
            return &s[..i];
        }
    }

    &s[..]
}
