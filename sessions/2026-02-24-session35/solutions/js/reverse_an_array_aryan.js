// https://www.geeksforgeeks.org/problems/reverse-an-array/1

/**
 * @param {number[]} arr
 * @returns {void}
 */

class Solution {
    rev(arr, i, j) {
        if (i < j) {
            [arr[j], arr[i]] = [arr[i], arr[j]]
            return this.rev(arr, i + 1, j - 1)
        }
    }

    reverseArray(arr) {
        this.rev(arr, 0, arr.length - 1)
        return arr
    }
}