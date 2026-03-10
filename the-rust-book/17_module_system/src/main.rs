use bank::accounts::Account;
use bank::announce;
use bank::hello::world::foo;
use bank::transactions::{deposit, withdraw};

mod bank;

fn main() {
    let mut account = Account::new("Bob");
    println!("Created Account: {account:?}");

    deposit(&mut account, 150);
    println!("Deposit Account: {account:?}");

    withdraw(&mut account, 50);
    println!("Withdraw Account: {account:?}");

    announce("Final State");
    println!("Account: {account:?}");

    println!("The owner name is {}", account.owner);

    foo();
}
