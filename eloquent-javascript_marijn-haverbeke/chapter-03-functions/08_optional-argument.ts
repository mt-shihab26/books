function square(x: number) {
    return x * x;
}

square(2, true, "hedgehog");

function minus(a: number, b: number): number {
    if (b == undefined) return -a;
    return a - b;
}

console.log(minus(10));
console.log(minus(10, 5));

function power(base: number, exponent: number = 2): number {
    let result = 1;
    for (let i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

console.log(power(4));
console.log(power(2, 6));
