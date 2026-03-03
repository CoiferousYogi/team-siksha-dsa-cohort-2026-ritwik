// Problem link: https://leetcode.com/problems/subsets/

/**
 * Generates all possible subsets (the power set) of a given array.
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(n) (recursive call stack, excluding output space)
 *
 * @param {number[]} nums - The input array.
 * @param {number} [index=0] - The current index (used internally).
 * @param {number[]} [currentSet=[]] - The current subset being built (used internally).
 * @param {number[][]} [result=[]] - The array storing all subsets (used internally).
 * @returns {number[][]} An array containing all subsets of the input array.
 */
function subsets(nums, index = 0, currentSet = [], result = []) {
    if (index >= nums.length) {
        result.push(currentSet.slice())
        return result
    }

    currentSet.push(nums[index])
    subsets(nums, index + 1, currentSet, result)
    currentSet.pop()
    subsets(nums, index + 1, currentSet, result)

    return result
}

/**
 * Generates all possible subsets (the power set) of a given array.
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(n) (recursive call stack, excluding output space)
 *
 * @param {number[]} nums - The input array.
 * @returns {number[][]} An array containing all subsets of the input array.
 */
function subsets_helperBased(nums) {
    const result = []
    const subsets = (index, currentSet) => {
        if (index >= nums.length) {
            result.push(currentSet.slice())
            return
        }

        currentSet.push(nums[index])
        subsets(index + 1, currentSet)
        currentSet.pop()
        subsets(index + 1, currentSet)
    }

    subsets(0, [])

    return result
}