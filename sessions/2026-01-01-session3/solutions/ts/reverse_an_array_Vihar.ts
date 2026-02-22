// Problem link: https://www.geeksforgeeks.org/problems/reverse-an-array/1

/**
 * @param {number[]} nums - array of numbers
 */
function reverseArray(nums: number[]) {
  for (let i = 0; i < Math.floor(nums.length / 2); i++) {
    const reverseIndex = nums.length - 1 - i;

    const temp = nums[i];
    nums[i] = nums[reverseIndex];
    nums[reverseIndex] = temp;
  }
}
