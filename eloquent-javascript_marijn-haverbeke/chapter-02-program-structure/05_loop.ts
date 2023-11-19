let num = 0;
while (num <= 12) {
    console.log(num);
    num += 2;
}

// 2^10
let result = 1;
let counter = 0;
while (counter < 10) {
    result *= 2;
    counter++;
}
console.log("2^10 = ", result);

for (let num = 0; num <= 12; num += 2) {
    console.log(num);
}

// 2^10 whit for loop
let result2 = 1;
for (let counter = 0; counter < 10; counter++) {
    result2 *= 2;
}
console.log("2^10 = ", result2);


for (let current = 20; ; current++) {
    if (current % 7 === 0) {
        console.log(current);
        break;
    }
}
