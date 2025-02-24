/**
 * @param {number} n
 * @return {Function} counter
 */
const createCounter = function(n) {
    return function() {
        return n++;
    };
};

// Example usage:
const counter = createCounter(10);

console.log(counter()); // 10
console.log(counter()); // 11
console.log(counter()); // 12

// Another test case
const counter2 = createCounter(-2);
console.log(counter2()); // -2
console.log(counter2()); // -1
console.log(counter2()); // 0
console.log(counter2()); // 1
console.log(counter2()); // 2
