// use std::{thread::sleep, time::Duration};

fn main() {
    // let mut i = 0;
    //
    // loop {
    //     println!("Hello, world! {i}");
    //     sleep(Duration::from_millis(200));
    //     i += 1;
    // }

    let mut counter = 0;

    let result = loop {
        counter += 1;

        if counter == 20 {
            break counter * 2;
        }
    };

    println!("The result is {result}");

    let mut count = 0;

    'counting_up: loop {
        println!("count = {count}");

        let mut remaining = 10;

        loop {
            println!("remaining = {remaining}");

            if remaining == 9 {
                break;
            }

            if count == 2 {
                break 'counting_up;
            }

            remaining -= 1;
        }

        count += 1;
    }

    println!("end count = {count}");

    let mut number = 3;

    while number != 0 {
        println!("{number}");

        number -= 1;
    }

    println!("LEFTOFF!");

    let a = [10, 20, 30, 40, 50];

    let mut index = 0;

    while index < 5 {
        println!("the value is: {}", a[index]);

        index += 1;
    }

    for element in a {
        println!("the value is: {element}");
    }

    for number in 1..4 {
        println!("the number is: {number}");
    }
}
