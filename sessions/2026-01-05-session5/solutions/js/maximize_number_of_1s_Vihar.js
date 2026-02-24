// Problem link: https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1
//             : https://leetcode.com/problems/max-consecutive-ones-iii/description/

/**
 * @param {number[]} nums - array of 1s and 0s 
 * @param {number} k - number of 0s that can be flipped to 1s
 * @returns {number} length of maximum consecutive 1s after flipping at most k zeros
 */
function longestOnes(nums, k) {
    let left = 0
    let flipped = 0
    let max = 0
    
    for (let right = 0; right < nums.length; right++) {
        if (nums[right] === 0) {
            flipped++

            while(flipped > k) {
                if (nums[left] === 0) {
                    flipped--
                }
                left++
            }
        }

        max = Math.max(right - left + 1, max)
    }

    return max
}