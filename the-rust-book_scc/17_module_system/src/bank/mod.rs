pub mod accounts;
pub mod transactions;

pub mod hello {
    pub mod world {
        pub fn foo() {
            println!("bar");
        }
    }
}

pub fn announce(message: &str) {
    println!("[BANK ANNOUNCEMENT] {message}")
}
