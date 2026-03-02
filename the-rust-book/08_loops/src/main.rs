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
}
