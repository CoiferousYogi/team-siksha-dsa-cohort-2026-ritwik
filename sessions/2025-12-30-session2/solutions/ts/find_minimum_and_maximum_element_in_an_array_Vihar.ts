// Problem link: https://www.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1

/**
 * @param arr - array of numbers
 * @returns minimum and maximum elements
 */
function getMinMax(arr: number[]): [number, number] {
  let min = Infinity;
  let max = -Infinity;

  for (let i = 0; i < arr.length; i++) {
    if (arr[i] < min) min = arr[i];
    if (arr[i] > max) max = arr[i];
  }

  return [min, max];
}
