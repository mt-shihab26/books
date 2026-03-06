fn main() {
    let s = String::from("Hello world");
    let w = first_word(&s);

    println!("the first word of '{s}' is '{w}'");

    let s = String::from("Hello");
    let w = first_word(&s);

    println!("the first word of '{s}' is '{w}'")
}

fn first_word(s: &String) -> String {
    let mut word = String::new();

    for c in s.chars() {
        if c == ' ' {
            break;
        }
        word.push(c);
    }

    word
}
