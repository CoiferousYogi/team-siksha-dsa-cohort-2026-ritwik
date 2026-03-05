// https://leetcode.com/problems/subsets-ii/

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function (arr) {
    arr.sort((a, b) => a - b)
    let result = []
    function explore(arr, i, temp) {
        if (arr.length == i) {

            result.push([...temp])
            return
        }
        temp.push(arr[i])
        explore(arr, i + 1, temp)
        temp.pop()
        // skip duplicates
        while (i + 1 < arr.length && arr[i] === arr[i + 1]) i++
        explore(arr, i + 1, temp)
    }
    explore(arr, 0, [])
    return result
};