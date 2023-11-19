let theNumber = Number("23");

if (!Number.isNaN(theNumber)) {
    console.log("Your number is the root of " + theNumber * theNumber);
} else {
    console.log("Hey, Why didn't you give me a number?");
}

if (1 + 1 == 2) console.log("It's true");

let num = 90;

if (num < 10) {
    console.log("Small");
} else if (num < 100) {
    console.log("Medium");
} else {
    console.log("Large");
}

let weather = "rainy";
switch (weather) {
    case "rainy":
        console.log("Remember to bring an umbrella.");
        break;
    case "sunny":
        console.log("Dress lightly.");
    case "cloudy":
        console.log("Go outside.");
        break;
    default:
        console.log("Unknown weather type!");
        break;
}
