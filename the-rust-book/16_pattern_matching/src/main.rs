#[derive(Debug)]
enum State {
    Alabama,
    Alaska,
}

impl State {
    fn existed_in(&self, year: u16) -> bool {
        match self {
            State::Alabama => year >= 1819,
            State::Alaska => year >= 1819,
        }
    }
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

fn describe_state_quarter(coin: Coin) -> Option<String> {
    // if let Coin::Quarter(state) = coin {
    //     if state.existed_in(1900) {
    //         Some(format!("{state:?} is pretty old, for America!"))
    //     } else {
    //         Some(format!("{state:?} is relatively new."))
    //     }
    // } else {
    //     None
    // }

    let state = if let Coin::Quarter(state) = coin {
        state
    } else {
        return None;
    };

    if state.existed_in(1900) {
        Some(format!("{state:?} is pretty old, for America!"))
    } else {
        Some(format!("{state:?} is relatively new."))
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

    let config_max = Some(3u8);
    if let Some(max) = config_max {
        println!("The maximum is configured to be {max}");
    } else {
        println!("The maximum not is configured");
    };

    println!(
        "{:?}",
        describe_state_quarter(Coin::Quarter(State::Alabama))
    )
}
