fn main() {
    let mut s = String::from("hello");

    let len = calculate_length(&mut s);

    println!("The length of '{s}' is {len}");
}

fn calculate_length(s: &mut String) -> usize {
    s.push_str("x");

    s.len()
}
