pub struct Guess {
    value: u32,
}

impl Guess {
    pub fn new(value: u32) -> Self {
        if value < 1 || 100 < value {
            panic!("Guess value must be between 1 and 100, got {value}.")
        }

        Guess { value }
    }

    pub fn value(&self) -> u32 {
        self.value
    }
}
