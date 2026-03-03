class Solution {
  minAnd2ndMin(arr) {
    // code here
    if (arr.length <= 1) return [-1];

    if (arr.length === 2) {
      if (arr[0] === arr[1]) return [-1];
      if (arr[0] < arr[1]) return [arr[0], arr[1]];
      else return [arr[1], arr[0]];
    }

    let s = arr[0]; // assume smallest to be first arr element
    let ss = Number.MAX_SAFE_INTEGER; //second smallest

    for (let i = 1; i < arr.length; i++) {
      // Found new smallest: set second smallest to smallest and smallest to the newly found element
      if (arr[i] < s) {
        ss = s;
        s = arr[i];
      }
      //Else if the current number is greater than first but less than second: Update second smallest = current element.
      else if (arr[i] > s && arr[i] < ss) {
        ss = arr[i];
      }
    }

    // if second was never updated, all elements were equal
    if (ss === Number.MAX_SAFE_INTEGER) return [-1];

    // return both smallest and second smallest
    return [s, ss];
  }
}
