// Problem link: https://leetcode.com/problems/running-sum-of-1d-array/description

/**
 * @param {number[]} nums - array of numbers
 * @return {number[]} array with running sum of numbers
 */
function runningSum(nums) {
  const result = [nums[0]];

  for (let i = 1; i < nums.length; i++) {
    result.push(result[i - 1] + nums[i]);
  }

  return result;
}
