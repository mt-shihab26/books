const hol_number = 105;
console.log(hol_number);

const real_number = 9.81;
console.log(real_number);


const scientific_number = 2.998e8;
console.log(scientific_number);
// That is 2.998 x 10^8 = 299,800,000.


const arithmetic_operator = ((((100 + 4) * 11) - 30) / 2) % 10;
console.log(arithmetic_operator);


const special_number = Infinity;
console.log(special_number, typeof special_number);

const special_number2 = -Infinity;
console.log(special_number2, typeof special_number2);

const special_number3 = 233 / 0;
console.log(special_number3, typeof special_number3);

const special_number4 = 0 / 0;
console.log(special_number4, typeof special_number4);

const special_number5 = Infinity - Infinity;
console.log(special_number5, typeof special_number5);

// Number
// - JavaScript uses a fixed number of bits, 64 of them, to store a single number value
// - 10^18 number can be stored in number type
// - The actual maximum whole number that can be stored is more in the range of 9 quadrillion (15 zeros): 2^55 -> 10^15
