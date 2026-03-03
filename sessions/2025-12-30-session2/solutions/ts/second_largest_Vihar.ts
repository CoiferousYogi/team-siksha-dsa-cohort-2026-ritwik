// Problem link: https://www.geeksforgeeks.org/problems/second-largest3735/1

/**
 * @param nums - array of numbers
 * @returns second largest element. -1 if it doesn't exist.
 */
function getSecondLargest(nums: number[]): number {
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
