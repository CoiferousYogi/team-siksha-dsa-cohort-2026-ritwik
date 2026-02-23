// Problem link: https://www.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1

/**
 * @param {number[]} nums - array of numbers
 * @returns {number[]} minimum and maximum elements
 */
function getMinMax(nums) {
  let min = Infinity;
  let max = -Infinity;

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] < min) min = nums[i];
    if (nums[i] > max) max = nums[i];
  }

  return [min, max];
}
