/**
 * Calculates the sum of all numbers from n down to 0 using recursion.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) (recursive call stack)
 *
 * @param {number} n - A non-negative integer.
 * @returns {number} The sum of numbers from n to 0.
 */
function recurSum(n: number) {
    if (n === 0) {
        return n
    }

    return n + recurSum(n - 1)
}