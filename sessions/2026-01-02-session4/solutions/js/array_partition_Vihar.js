// Problem link: https://leetcode.com/problems/array-partition/description/

/**
 * @param {number[]} nums - array of numbers
 * @returns {number} the maximized sum of all pairs
 */
function arrayPairSum(nums) {
  nums.sort((a, b) => a - b);

  let sum = 0;

  for (let i = 0; i < nums.length; i += 2) {
    sum += nums[i];
  }

  return sum;
}

/**
 * Constraints (important when considering counting sort approach):
 * 1 <= n <= 10^4
 * nums.length == 2 * n
 * -10^4 <= nums[i] <= 10^4
 */

/**
 * @param {number[]} nums - array of numbers
 * @returns {number} the maximized sum of all pairs
 */
function arrayPairSum_countingSort(nums) {
  const offset = 10000;
  const range = 10 ** 4 * 2;

  const counts = new Array(range + 1).fill(0);

  for (const num of nums) {
    counts[num + offset]++;
  }

  let sum = 0;
  let take = true;

  for (let i = 0; i < counts.length; i++) {
    const originalNum = i - offset;
    const count = counts[i];

    if (count > 0) {
      sum += take
        ? Math.ceil(count / 2) * originalNum
        : Math.floor(count / 2) * originalNum;

      if (count % 2 !== 0) {
        take = !take;
      }
    }
  }

  return sum;
}
