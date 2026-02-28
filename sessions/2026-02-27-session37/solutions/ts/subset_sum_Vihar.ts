/**
 * Generates the sums of all possible subsets of an array.
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(2^n) (result array + recursive call stack)
 *
 * @param {number[]} nums - The input array.
 * @returns {number[]} An array containing the sum of every subset (sorted in ascending order).
 */
function subsetSum(nums: number[]) {
    const result: number[] = []

    const subsets = (index: number, currentSum: number) => {
        if (index >= nums.length) {
            result.push(currentSum)
            return
        }

        subsets(index + 1, currentSum + nums[index])
        subsets(index + 1, currentSum)
    }

    subsets(0, 0)
    result.sort((a,b) => a - b)

    return result
}