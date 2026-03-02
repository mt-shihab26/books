mod problems;

use problems::convert_temperature;

fn main() {
    let celsius = convert_temperature(98.6);
    println!("Temperature: {} Celsius", celsius);
}
