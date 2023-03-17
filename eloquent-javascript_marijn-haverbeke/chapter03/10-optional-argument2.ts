function minus(a: number, b: number): number {
    if (b == undefined) return -a;
    return a - b;
}

console.log(minus(10));
console.log(minus(10, 5));
