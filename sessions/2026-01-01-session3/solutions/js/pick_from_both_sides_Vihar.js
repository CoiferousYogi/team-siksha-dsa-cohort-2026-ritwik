/**
 * @param {number[]} A - array of numbers
 * @param {number} B - number of elements to pick
 * @returns {number} maximum sum of picking B elements from either side
 */
function pickFromBothSides_bruteForce(A, B) {
  let fromLeft = B;
  let maximumSum = -Infinity;

  while (fromLeft >= 0) {
    let sum = 0;

    for (let i = 0; i < fromLeft; i++) {
      sum += A[i];
    }

    let fromRight = B - fromLeft;

    for (let i = 0; i < fromRight; i++) {
      sum += A[A.length - 1 - i];
    }

    maximumSum = Math.max(sum, maximumSum);
    fromLeft--;
  }

  return maximumSum;
}

/**
 * @param {number[]} A - array of numbers
 * @param {number} B - number of elements to pick
 * @returns {number} maximum sum of picking B elements from either side
 */
function pickFromBothSides_slidingWindow(A, B) {
  let sum = 0;

  // First take all elements from left
  for (let i = 0; i < B; i++) {
    sum += A[i];
  }

  let maximumSum = sum;

  // Replace elements from left with elements from right, one by one
  for (let i = 1; i <= B; i++) {
    sum -= A[B - i];
    sum += A[A.length - i];

    maximumSum = Math.max(sum, maximumSum);
  }

  return maximumSum;
}
