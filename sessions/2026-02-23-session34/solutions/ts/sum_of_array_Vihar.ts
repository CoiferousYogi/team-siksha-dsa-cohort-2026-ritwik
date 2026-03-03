// Probilem link: https://www.geeksforgeeks.org/problems/sum-of-array2326/1

/**
 * Calculates the sum of all elements in an array using recursion.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) (recursive call stack)
 *
 * @param {number[]} nums - The input array.
 * @param {number} [index=0] - The current index (used internally).
 * @returns {number} The total sum of the array elements.
 */
function sumOfArray(nums: number[], index: number = 0) {
    if (index >= nums.length) {
        return 0
    }

    return nums[index] + sumOfArray(nums, index + 1)
}

/**
 * Calculates the sum of all elements in an array using a recursive helper.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) (recursive call stack)
 *
 * @param {number[]} nums - The input array.
 * @returns {number} The total sum of the array elements.
 */
function sumOfArray_helperBased(nums: number[]) {   
    const sum = (index: number): number => {
        if (index >= nums.length) {
            return 0
        }

        return nums[index] + sum(index + 1)
    }

    return sum(0)
}