// single line comment

fn main() {
    println!("add = {}", add(5, 10));

    println!("sub = {}", sub(5, 10));

    println!("mul = {}", mul(5, 10));

    println!("div = {}", div(10, 0));
    println!("div = {}", div(10, 5));
}

fn add(x: i32, y: i32) -> i32 {
    x + y
}

fn sub(x: i32, y: i32) -> i32 {
    x - y
}

fn mul(x: i32, y: i32) -> i32 {
    x * y
}

fn div(x: i32, y: i32) -> i32 {
    if y == 0 {
        return 0;
    }

    x / y
}
