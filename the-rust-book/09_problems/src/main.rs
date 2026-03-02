fn main() {
    let celsius = temp(98.6);
    println!("temperature: {} celsius", celsius);

    for i in 1..11 {
        println!("{i}th - {} ", fib(i))
    }
}

fn temp(fahrenheit: f64) -> f64 {
    (fahrenheit - 32.0) * (5.0 / 9.0)
}

fn fib(n: u32) -> u32 {
    if n == 1 {
        return 0;
    }

    if n == 2 {
        return 1;
    }

    let mut a = 0;
    let mut b = 1;

    for _ in 2..n {
        let t = a;
        a = b;
        b = t + b;
    }

    b
}
