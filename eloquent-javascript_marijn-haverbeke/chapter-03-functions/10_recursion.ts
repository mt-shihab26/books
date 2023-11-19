const power_x = (base: number, exponent) => {
    if (exponent === 0) {
        return 1;
    }

    return base * power_x(base, exponent - 1);
};

console.log(power_x(2, 3)); // -> 8
