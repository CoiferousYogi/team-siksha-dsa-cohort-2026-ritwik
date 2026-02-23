// Problem link: https://www.geeksforgeeks.org/problems/sum-of-array2326/1

/**
 * @param {number[]} nums - array of numbers
 * @return {number} sum of the array
 */
function arraySum(nums) {
  return nums.reduce((acc, curr) => acc + curr, 0);
}
