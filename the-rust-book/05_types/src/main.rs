fn main() {
    // scalar types

    // integer types
    let decimal = 98_222;
    let hex = 0xff;
    let octal = 0o77;
    let binary = 0b1111_0000;
    let byte = b'A';

    println!("decimal = {decimal}");
    println!("hex = {hex}");
    println!("octal = {octal}");
    println!("binary = {binary}");
    println!("byte = {byte}");

    // floating-point types

    let x = 2.0; // f64;
    let y: f32 = 3.0; // f32

    println!("f64 = {x}");
    println!("f32 = {y}");

    // boolean types
    let t = true;
    let f: bool = false;

    println!("boolean={t}");
    println!("boolean={f}");

    // character types
    let c = 'z';
    let z: char = 'ℤ'; // with explicit type annotation
    let heart_eyed_cat = '😻';
    println!("char={c}");
    println!("char={z}");
    println!("char={heart_eyed_cat}");

    // compound types

    // tuple type
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    println!("tup={:?}", tup);
    println!("tup={:#?}", tup);
    let (x, y, z) = tup;
    println!("tup, x={x}, y={y}, z={z}");
}
