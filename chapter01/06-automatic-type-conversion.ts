console.log(8 * null); // 0
console.log("5" - 1); // 4
console.log("5" + 1); // 51
console.log("five" * 2); // NaN
console.log(false == 0); // true
// type coercion
console.log(null == undefined); // true
console.log(null == 0); // false
console.log(0 == false); // true
console.log("" == false); // true
console.log(0 === false); // false
console.log("" === false); // false
// short-circuit evaluation
console.log(null || "user"); // "user"
console.log("Agnes" || "user"); // Agnes
// we see four type of javascript values: number, string, boolean, undefined
