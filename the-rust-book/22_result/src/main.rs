use std::{fs::{self, File}, io::{Error, Read}};
// use std::io::ErrorKind;

fn main() {
    let path = "hello.txt";

    let hello = File::open(&path).expect(&format!("{path} should be included in this project"));

    // let hello = match hello {
    //     Ok(file) => file,
    //     Err(error) => match error.kind() {
    //         ErrorKind::NotFound => match File::create(&path) {
    //             Ok(file) => file,
    //             Err(error) => panic!("Problem creating the file: {error:?}"),
    //         },
    //         _ => panic!("Problem opening the file: {error:?}"),
    //     },
    // };

    println!("{hello:?}");
}

fn read_username_from_file() -> Result<String, Error> {
    let hello = File::open("hello.txt");

    let mut hello = match hello {
        Ok(file) => file,
        Err(error) => return Err(error),
    };

    let mut username = "".to_string();

    match hello.read_to_string(&mut username) {
        Ok(_) => Ok(username)
        Err(e) => Err(e)
    }
}

fn read_username_from_file_2() -> Result<String, Error> {
    let mut hello = File::open("hello.txt")?;
    let mut username = "".to_string();
    hello.read_to_string(&mut username)?;
    Ok(username)
}


fn read_username_from_file_3() -> Result<String, Error> {
    let mut username = "".to_string();
    File::open("hello.txt")?.read_to_string(&mut username)?;
    Ok(username)
}


fn read_username_from_file_4() -> Result<String, Error> {
    fs::read_to_string("hello.txt")
}
