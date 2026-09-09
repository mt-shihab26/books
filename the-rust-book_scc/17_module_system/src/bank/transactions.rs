use super::accounts::Account;

pub fn deposit(account: &mut Account, amount: i32) {
    account.balance += amount;
}

pub fn withdraw(account: &mut Account, amount: i32) {
    if account.balance >= amount {
        account.balance -= amount;
    }
}
