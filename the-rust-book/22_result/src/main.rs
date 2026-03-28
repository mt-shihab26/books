use std::fs::File;

fn main() {
    let hello = File::open("hello.txt");

    let hello = match hello {
        Ok(file) => file,
        Err(error) => panic!("Problem opening the file: {error:?}"),
    };

    println!("{hello:?}");
}
