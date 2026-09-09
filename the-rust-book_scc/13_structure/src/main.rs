struct User {
    username: String,
    email: String,
    login_count: u64,
    active: bool,
}

struct Color(i32, i32, i32);
struct Point(i32, i32, i32);

// struct AlwaysEqual;

fn main() {
    let user = User {
        username: String::from("shihab"),
        email: String::from("mt.shihab26@gmail.com"),
        login_count: 1,
        active: true,
    };

    println!(
        "the '{}' has '{}' with login count of {} and he is {}",
        user.username, user.email, user.login_count, user.active
    );

    let user2 = User {
        email: String::from("shihab4t@gmail.com"),
        ..user
    };

    println!(
        "the '{}' has '{}' with login count of {} and he is {}",
        user2.username, user2.email, user2.login_count, user2.active
    );

    println!(
        "the '{}' has '{}' with login count of {} and he is {}",
        "can't use moved value", user.email, user.login_count, user.active
    );

    let black = Color(0, 0, 0);
    let origin = Point(0, 0, 0);

    let Color(x, y, z) = black;

    println!("{x}, {y}, {z}, {}", black.0);

    let Point(x, y, z) = origin;

    println!("{x}, {y}, {z}, {}", origin.0);

    // let subject = AlwaysEqual;
}
