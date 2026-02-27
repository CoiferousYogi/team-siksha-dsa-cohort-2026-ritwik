/**
 * Calculates the factorial of a number using recursion.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) (due to recursive call stack)
 *
 * @param {number} n - A non-negative integer.
 * @returns The factorial of the given number.
 */
function factorial(n: number) {
    if (n <= 1) {
        return 1
    }

    return n * this.factorial(n - 1)
}