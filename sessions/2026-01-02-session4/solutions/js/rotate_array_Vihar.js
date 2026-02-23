// Problem link: https://leetcode.com/problems/rotate-array/description/

/**
 * Rotate array right / clockwise in place
 *
 * @param {number[]} nums - Array of numbers
 * @param {number} k - amount by which the array will be rotated right
 */
function rotateRight(nums, k) {
  const _k = k % nums.length;

  if (_k === 0) return;

  nums.unshift(...nums.splice(nums.length - _k, _k));
}

/**
 * Rotate array right / clockwise in place
 *
 * @param {number[]} nums - Array of numbers
 * @param {number} k - amount by which the array will be rotated right
 */
function rotateRight_spaceOptimized(nums, k) {
  const _k = k % nums.length;

  if (_k === 0) return;

  const reverse = (startIndex, endIndex) => {
    while (startIndex < endIndex) {
      const temp = nums[startIndex];
      nums[startIndex] = nums[endIndex];
      nums[endIndex] = temp;

      startIndex++;
      endIndex--;
    }
  };

  reverse(0, nums.length - 1);
  reverse(0, _k - 1);
  reverse(_k, nums.length - 1);
}
