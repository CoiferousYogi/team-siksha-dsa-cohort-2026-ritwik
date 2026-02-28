/**
 * Calculates the nth Fibonacci number using recursion.
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(n) (recursive call stack)
 *
 * @param {number} n - The position in the Fibonacci sequence (0-based).
 * @returns {number} The nth Fibonacci number.
 */
function nthFibonacci(n) {
    if (n <= 1) {
        return n
    }

    return nthFibonacci(n - 1) + nthFibonacci(n - 2)
}

/**
 * Calculates the nth Fibonacci number using recursion with memoization.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) (cache + recursive call stack)
 *
 * @param {number} n - The position in the Fibonacci sequence (0-based).
 * @param {Map<number, number>} [cache=new Map()] - Stores previously computed Fibonacci values.
 * @returns {number} The nth Fibonacci number.
 */
function nthFibonacci_memoized(n, cache = new Map()) {
    if (n <= 1) {
        return n
    }
    if (cache.has(n)) {
        return cache.get(n)
    }

    const result = nthFibonacci_memoized(n - 1, cache) + nthFibonacci_memoized(n - 2, cache)
    
    cache.set(n, result)

    return result
}