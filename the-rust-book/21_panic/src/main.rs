fn main() {
    foo();

    let v = vec![1, 2, 3];

    v[99];
}

fn foo() {
    panic!("Hello, world!");
}
