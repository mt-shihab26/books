const str = `Down on the sea`
const str2 = "Lie on the ocean"
const str3 = 'Float on the ocean'

console.log(str);
console.log(str2);
console.log(str3);

// escaping the character
const escaping = "This is the first line\nAnd this is the second";
const escaping2 = "A new line character is written like \"\\n\"."; // "\n". 
console.log(escaping);
console.log(escaping2);


/*
JavaScript’s
representation uses 16 bits per string element, which can describe up to 216
different characters.
*/


const string_concatenation = "con" + "cat" + "tena" + "tion";
console.log(string_concatenation);


const string_literals = `half of 100 is ${100 / 2}`;
console.log(string_literals)
// ${} called template literal
