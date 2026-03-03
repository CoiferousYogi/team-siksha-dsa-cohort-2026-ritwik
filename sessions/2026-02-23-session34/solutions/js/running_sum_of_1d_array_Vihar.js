// Problem link: https://leetcode.com/problems/running-sum-of-1d-array/

/**
 * Computes the running sum of an array using a recursive helper.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) (result array + recursive call stack)
 *
 * @param {number[]} nums - The input array.
 * @returns {number[]} A new array where each element is the sum of all previous elements including itself.
 */
function runningSum_helperBased(nums) {
    const sum = (index, result) => {
        if (index >= nums.length) {
            return result
        }

        const previous = result[index - 1] ?? 0

        result.push(previous + nums[index])

        return sum(index + 1, result)
    }
    
    return sum(0, [])
}

/**
 * Computes the running sum of an array using reverse recursion.
 * Modifies the original array in place.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) (recursive call stack)
 *
 * @param {number[]} nums - The array to transform.
 * @returns {number[]} The same array instance containing running sums.
 */
function runningSum_inPlace(nums) {
    if (nums.length <= 1) {
        return nums
    }

    const current = nums.pop()
    const previous = runningSum_inPlace(nums)
    previous.push(previous[previous.length - 1] + current)

    return previous
}

