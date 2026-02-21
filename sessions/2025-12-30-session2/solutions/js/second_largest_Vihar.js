// Problem link: https://www.geeksforgeeks.org/problems/second-largest3735/1

/**
 * @param {number[]} nums - array of numbers
 * @return {number} second largest element. -1 if it doesn't exist.
 */
function getSecondLargest(nums) {
  let largest = -Infinity;
  let secondLargest = largest;

  for (let i = 0; i < nums.length; i++) {
    const num = nums[i];

    if (num > largest) {
      secondLargest = largest;
      largest = num;
    } else if (num > secondLargest && num !== largest) {
      secondLargest = num;
    }
  }

  return secondLargest === -Infinity ? -1 : secondLargest;
}
