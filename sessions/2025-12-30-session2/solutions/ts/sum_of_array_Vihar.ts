// Problem link: https://www.geeksforgeeks.org/problems/sum-of-array2326/1

/**
 * @param arr - array of numbers
 * @returns sum of the array
 */
function arraySum(arr: number[]): number {
  return arr.reduce((acc, curr) => acc + curr, 0);
}
