// Problem link: https://leetcode.com/problems/rotate-array/description/

/**
 * Rotate array right / clockwise in place
 *
 * @param nums - Array of numbers
 * @param k - amount by which the array will be rotated right
 */
function rotateRight(nums: number[], k: number): void {
  const _k = k % nums.length;

  if (_k === 0) return;

  nums.unshift(...nums.splice(nums.length - _k, _k));
}

/**
 * Rotate array right / clockwise in place
 *
 * @param nums - Array of numbers
 * @param k - amount by which the array will be rotated right
 */
function rotateRight_spaceOptimized(nums: number[], k: number): void {
  const _k = k % nums.length;

  if (_k === 0) return;

  const reverse = (startIndex: number, endIndex: number) => {
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
