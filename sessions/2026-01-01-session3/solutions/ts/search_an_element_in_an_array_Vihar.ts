/**
 * @param arr - array of number
 * @param x - target number to search for
 * @returns index of the target element. -1 if target element doesn't exist.
 */
function search(arr: number[], x: number) {
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === x) {
      return i;
    }
  }
  return -1;
}
