use std::{thread::sleep, time::Duration};

fn main() {
    let mut i = 0;

    loop {
        println!("Hello, world! {i}");
        sleep(Duration::from_millis(200));
        i += 1;
    }
}
