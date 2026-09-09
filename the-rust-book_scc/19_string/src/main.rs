fn main() {
    let mut s = "foo".to_string();

    s.push_str(" bar");

    println!("{s}");

    let s2 = "buz".to_string();

    let s3 = format!("{s} {s2}"); // format doesn't take ownership

    println!("{s}");
    println!("{s2}");
    println!("{s3}");

    let hello = "Здравствуйте";

    let s = &hello[0..4];

    println!("{hello} -> {s}");

    for (i, c) in hello.chars().enumerate() {
        println!("{i} -> {c}");
    }

    for (i, b) in hello.bytes().enumerate() {
        println!("{i} -> {b}");
    }
}
