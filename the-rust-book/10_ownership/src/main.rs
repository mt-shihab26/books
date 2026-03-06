fn main() {
    let mut s = String::from("hello");

    s = takes_ownership(s);
    let (s, l) = calculate_len(s);

    println!("{s}, len is: {l}");

    let x = 5;

    makes_copy(x);

    println!("{x}");
}

fn takes_ownership(some_string: String) -> String {
    println!("{some_string}");

    some_string
}

fn makes_copy(some_integer: i32) {
    println!("{some_integer}");
}

fn calculate_len(s: String) -> (String, usize) {
    let l = s.len();
    (s, l)
}
