// Problem link: https://leetcode.com/problems/left-and-right-sum-differences/description/

/**
 * @param {number[]} nums - array of numbers
 * @return {number[]} array of differences between left and right indices
 */
function leftRightDifference(nums) {
  let leftSumArr = [];
  let rightSumArr = [];

  let leftSum = 0;
  let rightSum = 0;

  for (let i = 0; i < nums.length; i++) {
    leftSumArr.push(leftSum);
    leftSum += nums[i];

    rightSumArr.push(rightSum);
    rightSum += nums[nums.length - 1 - i];
  }

  rightSumArr.reverse();

  return nums.map((_, index) =>
    Math.abs(leftSumArr[index] - rightSumArr[index])
  );
}
