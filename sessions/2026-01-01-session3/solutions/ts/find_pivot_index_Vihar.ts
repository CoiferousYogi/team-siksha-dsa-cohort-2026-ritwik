// Problem link: https://leetcode.com/problems/find-pivot-index/description/

/**
 * @param nums - array of numbers
 * @returns pivot index, -1 if pivot index doesn't exist
 */
function pivotIndex(nums: number[]): number {
  let sum = 0;
  const leftSum: number[] = new Array(nums.length);

  for (let i = 0; i < nums.length; i++) {
    leftSum[i] = sum;
    sum += nums[i];
  }

  sum = 0;
  const rightSum: number[] = new Array(nums.length);

  for (let i = nums.length - 1; i >= 0; i--) {
    rightSum[i] = sum;
    sum += nums[i];
  }

  return leftSum.findIndex((_, index) => leftSum[index] === rightSum[index]);
}

/**
 * @param nums - array of numbers
 * @returns pivot index, -1 if pivot index doesn't exist
 */
function pivotIndex_spaceOptimized(nums: number[]): number {
  // Compute the total sum of the array
  // total = left + nums[i] + right (for any index)
  const total = nums.reduce((acc, curr) => acc + curr, 0);

  let leftSum = 0;

  for (let i = 0; i < nums.length; i++) {
    // Right sum can be derived instead of stored:
    // rightSum = total - leftSum - nums[i]
    if (leftSum === total - leftSum - nums[i]) {
      return i;
    }

    leftSum += nums[i];
  }

  return -1;
}
