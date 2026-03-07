#[derive(Debug)]
struct Rect {
    width: u32,
    height: u32,
}

fn area(rect: &Rect) -> u32 {
    rect.width * rect.height
}

fn main() {
    let rect = Rect {
        width: 30,
        height: 50,
    };

    println!("The are of {rect:?} is {}", area(&rect));
    println!("The are of {rect:#?} is {}", area(&rect));

    let scale = 2;

    let rect2 = Rect {
        width: dbg!(30 * scale),
        height: 50,
    };

    dbg!(rect2);
}
