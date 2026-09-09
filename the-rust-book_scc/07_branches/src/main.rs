fn main() {
    let number = 7;

    let x = if number < 5 {
        println!("condition was true");
        20
    } else {
        println!("condition was false");
        30
    };

    println!("{:?}", x);

    if number % 4 == 0 {
        println!("number is divisiable by 4");
    } else if number % 3 == 0 {
        println!("number is divisiable by 3");
    } else if number % 2 == 0 {
        println!("number is divisiable by 2");
    } else {
        println!("number is not divisiable by 4, 3, or 2");
    }

    let condition = true;

    let number = if condition { 5 } else { 6 };

    println!("number={number}");
}
