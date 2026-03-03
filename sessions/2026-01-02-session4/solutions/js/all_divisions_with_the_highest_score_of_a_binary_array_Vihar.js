// Problem link: https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/description/

/**
 * @param {number[]} nums - Array of numbers
 * @returns {number[]} Indices with maximum score
 */
function maxScoreIndices(nums) {
  let onesOnRight = nums.reduce((acc, num) => acc + num, 0);
  let zerosOnLeft = 0;

  let maxScore = -Infinity;
  let result = [];

  for (let i = 0; i <= nums.length; i++) {
    const score = onesOnRight + zerosOnLeft;
    if (score > maxScore) {
      result = [i];
      maxScore = score;
    } else if (score === maxScore) {
      result.push(i);
    }

    if (i === nums.length) break;

    if (nums[i] === 0) {
      zerosOnLeft++;
    } else {
      onesOnRight--;
    }
  }

  return result;
}
