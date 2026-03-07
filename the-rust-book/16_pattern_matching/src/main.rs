#[derive(Debug)]
enum State {
    Alabama,
    Alaska,
    // --snip--
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

fn main() {
    println!("{}", cents(&Coin::Penny));
    println!("{}", cents(&Coin::Nickel));
    println!("{}", cents(&Coin::Dime));
    println!("{}", cents(&Coin::Quarter(State::Alabama)));
    println!("{}", cents(&Coin::Quarter(State::Alaska)));
}
