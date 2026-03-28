use std::{fs::File, io::ErrorKind};

fn main() {
    let path = "hello.txt";

    let hello = File::open(&path);

    let hello = match hello {
        Ok(file) => file,
        Err(error) => match error.kind() {
            ErrorKind::NotFound => match File::create(&path) {
                Ok(file) => file,
                Err(error) => panic!("Problem creating the file: {error:?}"),
            },
            _ => panic!("Problem opening the file: {error:?}"),
        },
    };

    println!("{hello:?}");
}
