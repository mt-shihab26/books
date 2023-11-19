const square = function (x: number): number {
    return x * x;
};

const makeNoise = function (): void {
    console.log("Pling!");
};

const power = function (base: number, exponent: number): number {
    let result = 1;
    for (let i = 1; i <= exponent; i++) {
        result *= base;
    }
    return result;
};

console.log(square(12));
makeNoise();
console.log(power(2, 10));
