use module_system::bank::accounts::Account;
use module_system::bank::announce;
use module_system::bank::hello::world::foo;
use module_system::bank::transactions::{deposit, withdraw};

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
