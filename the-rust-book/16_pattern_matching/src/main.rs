#[derive(Debug)]
enum State {
    Alabama,
    Alaska,
}

enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter(State),
}

fn cents(coin: &Coin) -> u8 {
    match coin {
        Coin::Penny => {
            println!("Lucky penny!");
            1
        }
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter(state) => {
            println!("State quarter from {state:?}");
            25
        }
    }
}

fn plus_one(x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(i) => Some(i + 1),
    }
}

fn main() {
    println!("{}", cents(&Coin::Penny));
    println!("{}", cents(&Coin::Nickel));
    println!("{}", cents(&Coin::Dime));
    println!("{}", cents(&Coin::Quarter(State::Alabama)));
    println!("{}", cents(&Coin::Quarter(State::Alaska)));

    println!("5 + 1 = {:?}", plus_one(Some(5)));
    println!("6 + 1 = {:?}", plus_one(Some(6)));
    println!("None + 1 = {:?}", plus_one(None));

    let dice_roll = 9;

    match dice_roll {
        3 => println!("three"),
        7 => println!("seven"),
        other => println!("{other}"),
    }

    match dice_roll {
        3 => println!("three"),
        7 => println!("seven"),
        _ => println!("other"),
    }

    match dice_roll {
        3 => println!("three"),
        7 => println!("seven"),
        _ => (),
    }
}
