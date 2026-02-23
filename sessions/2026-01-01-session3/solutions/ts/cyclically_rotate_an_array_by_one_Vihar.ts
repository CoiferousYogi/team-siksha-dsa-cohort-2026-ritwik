// Problem link: https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1

/**
 * 
 * @param nums - array of numbers
 */
function rotateByOne(nums: number[]) {
  let last = nums[nums.length - 1];

  for (let i = nums.length - 1; i > 0; i--) {
    nums[i] = nums[i - 1];
  }

  nums[0] = last;
}
