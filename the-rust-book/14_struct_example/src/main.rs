#[derive(Debug)]
struct Rect {
    width: u32,
    height: u32,
}

impl Rect {
    fn area(&self) -> u32 {
        self.width * self.height
    }

    fn width(&self) -> bool {
        self.width > 0
    }
}

fn main() {
    let rect = Rect {
        width: 30,
        height: 50,
    };

    println!(
        "The area of {rect:?} is {}, width valid: {}",
        rect.area(),
        rect.width()
    );
    println!("The area of {rect:#?} is {}", rect.area());

    let scale = 2;

    let rect2 = Rect {
        width: dbg!(30 * scale),
        height: 50,
    };

    dbg!(rect2);
}
