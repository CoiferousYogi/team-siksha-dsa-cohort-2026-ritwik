// Problem link: https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1

/**
 * Rotate array left / counter-clockwise in place
 *
 * @param nums - Array of numbers
 * @param d - amount by which the array will be rotated left
 */
function rotateLeft(nums: number[], d: number) {
  const _d = d % nums.length;

  if (_d === 0) return;

  nums.push(...nums.splice(0, _d));
}

/**
 * Rotate array left / counter-clockwise in place
 *
 * @param nums - Array of numbers
 * @param d - amount by which the array will be rotated left
 */
function rotateLeft_spaceOptimized(nums: number[], d: number) {
  const _d = d % nums.length;

  if (_d === 0) return;

  const reverse = (startIndex: number, endIndex: number) => {
    while (startIndex < endIndex) {
      const temp = nums[startIndex];
      nums[startIndex] = nums[endIndex];
      nums[endIndex] = temp;

      startIndex++;
      endIndex--;
    }
  };

  reverse(0, _d - 1);
  reverse(_d, nums.length - 1);
  reverse(0, nums.length - 1);
}
