// Problem link: https://www.geeksforgeeks.org/problems/find-the-smallest-and-second-smallest-element-in-an-array3226/1

/**
 * @param {number[]} nums - array of numbers
 * @returns {number[]} smallest and the second smallest element. [-1] if it doesn't exist.
 */
function minAnd2ndMin(nums) {
  let smallest = Infinity;
  let secondSmallest = smallest;

  for (let i = 0; i < nums.length; i++) {
    const num = nums[i];

    if (num < smallest) {
      secondSmallest = smallest;
      smallest = num;
    } else if (num < secondSmallest && num !== smallest) {
      secondSmallest = num;
    }
  }

  return smallest === Infinity || secondSmallest === Infinity
    ? [-1]
    : [smallest, secondSmallest];
}
