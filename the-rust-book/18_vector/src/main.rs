fn main() {
    let v: Vec<i32> = Vec::new();
    println!("{v:?}");

    let v = vec![1, 2, 3];
    println!("{v:?}");

    let mut v = Vec::new();

    v.push(5);
    v.push(6);
    v.push(7);

    println!("{v:?}, {}, {}, {}", v[0], v[1], v[2]);

    let second = v.get(2);
    match second {
        Some(second) => println!("The second value is {second}"),
        None => println!("The second value is not exist"),
    }

    let handard = v.get(100);
    match handard {
        Some(handard) => println!("The handard value is {handard}"),
        None => println!("The handard value is not exist"),
    }

    for i in &v {
        println!("{i}");
    }

    for i in &mut v {
        *i += 50;
        println!("{i}");
    }

    let row = vec![
        SpreadSheetCell::Int(3),
        SpreadSheetCell::Text(String::from("blue")),
        SpreadSheetCell::Float(10.12),
    ];

    println!("{row:?}");
}

#[derive(Debug)]
#[allow(unused)]
enum SpreadSheetCell {
    Int(i32),
    Float(f64),
    Text(String),
}
