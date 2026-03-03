// Problem link: https://www.geeksforgeeks.org/problems/find-the-smallest-and-second-smallest-element-in-an-array3226/1

/**
 * @param nums - array of numbers
 * @returns smallest and the second smallest element. [-1] if it doesn't exist.
 */
function minAnd2ndMin(nums: number[]) {
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
