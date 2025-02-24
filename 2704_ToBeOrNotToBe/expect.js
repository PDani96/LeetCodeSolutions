/**
 * @param {string|number} val
 * @return {Object}
 */
const expect = function(val) {
    return {
        toBe: (expected) => {
            if (expected === val) {
                return true;
            }
            throw new Error("Not Equal");
        },
        notToBe: (expected) => {
            if (expected !== val) {
                return true;
            }
            throw new Error("Equal");
        }
    };
};

// Test Cases
try {
    console.log(expect(5).toBe(5)); // true
} catch (error) {
    console.error(error.message);
}

try {
    console.log(expect(5).notToBe(5)); // throws "Equal"
} catch (error) {
    console.error(error.message);
}

try {
    console.log(expect(5).notToBe(10)); // true
} catch (error) {
    console.error(error.message);
}

try {
    console.log(expect("hello").toBe("hello")); // true
} catch (error) {
    console.error(error.message);
}

try {
    console.log(expect("hello").toBe("world")); // throws "Not Equal"
} catch (error) {
    console.error(error.message);
}
