// Problem link: https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/description/

/**
 * @param nums - Array of numbers
 * @returns Indices with maximum score
 */
function maxScoreIndices(nums: number[]): number[] {
  let onesOnRight = nums.reduce((acc, num) => acc + num, 0);
  let zerosOnLeft = 0;

  let maxScore = -Infinity;
  let result: number[] = [];

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
