/**
 * Reverses an array using recursion.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) (recursive call stack + result array)
 *
 * @param {number[]} nums - The input array.
 * @param {number} [index=0] - The current index (used internally).
 * @param {number[]} [result=[]] - The array that stores the reversed result.
 * @returns {number[]} A new array containing the elements in reverse order.
 */
function reverseArray(nums, index = 0, result = []) {
    if (index >= nums.length) {
        return result
    }

    reverseArray(nums, index + 1, result)
    result.push(nums[index])

    return result
}

/**
 * Reverses an array in place using recursion.
 *
 * Time Complexity: O(n²) (due to repeated `shift()` operations)
 * Space Complexity: O(n) (recursive call stack)
 *
 * @param {number[]} nums - The array to reverse.
 * @returns {number[]} The same array instance with elements reversed.
 */
function reverseArray_inPlace(nums) {
    if (nums.length === 0) {
        return nums
    }

    const current = nums.shift()
    reverseArray(nums)
    nums.push(current)

    return nums
}