function warp_value(n: number) {
    const local = n;
    return () => local;
}

const wrap1 = warp_value(1);
const wrap2 = warp_value(2);

console.log(wrap1()); // -> 1
console.log(wrap2()); // -> 2

function multiplier(factor: number) {
    return (num: number) => num * factor;
}

const twice = multiplier(2);
console.log(twice(5)); // -> 10
