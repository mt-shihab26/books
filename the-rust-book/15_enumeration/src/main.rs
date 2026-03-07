#[derive(Debug)]
enum IpKind {
    V4,
    V6,
}

#[derive(Debug)]
struct IpAddr {
    kind: IpKind,
    address: String,
}

#[derive(Debug)]
enum IpAddr2 {
    V4(String),
    V6(String),
}

fn main() {
    let four = IpKind::V4;
    let six = IpKind::V6;

    println!("{four:?} or {six:?}");

    let home = IpAddr {
        kind: IpKind::V4,
        address: String::from("127.0.0.1"),
    };

    let loopback = IpAddr {
        kind: IpKind::V6,
        address: String::from("::1"),
    };

    println!("{home:?}, {:?}, {}", home.kind, home.address);
    println!("{loopback:?}");

    let home = IpAddr2::V4(String::from("127.0.0.1"));
    let loopback = IpAddr2::V6(String::from("::1"));

    println!("{home:?}");
    println!("{loopback:?}");

    if let IpAddr2::V4(addr) = home {
        println!("IPv4: {}", addr);
    }

    if let IpAddr2::V6(addr) = loopback {
        println!("IPv6: {}", addr);
    }

    let some_number = Some(5);
    let some_char = Some('e');
    let absent_number: Option<i32> = None;

    println!("{some_number:?}, {some_char:?}, {absent_number:?}");
}
