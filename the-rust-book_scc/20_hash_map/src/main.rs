use std::collections::HashMap;

fn main() {
    let mut scores = HashMap::new();

    scores.insert("Blue".to_string(), 10);
    scores.insert("Yellow".to_string(), 10);
    scores.insert("Yellow".to_string(), 25);

    scores.entry("Yellow".to_string()).or_insert(50);

    let team_name = "Blue".to_string();
    let team_score = scores.get(&team_name).copied().unwrap_or(0);

    println!("{team_name} = {team_score}");

    for (key, value) in &scores {
        println!("{key}: {value}");
    }

    println!("{scores:?}");

    let text = "hello world wonderful world";

    let mut counts = HashMap::new();

    for word in text.split_whitespace() {
        let count = counts.entry(word).or_insert(0);
        *count += 1;
    }

    println!("{counts:?}");
}
