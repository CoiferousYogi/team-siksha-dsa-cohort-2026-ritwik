/**
 * @param {number[]} arr - array of number
 * @param {number} x - target number to search for
 * @returns {number} index of the target element. -1 if target element doesn't exist.
 */
function search(arr, x) {
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === x) {
      return i;
    }
  }
  return -1;
}
