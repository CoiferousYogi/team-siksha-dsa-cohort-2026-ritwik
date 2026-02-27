// https://leetcode.com/problems/subsets/
/**
 * @param {number[]} nums
 * @return {number[][]}
 */


var subsets = function (nums) {
    let result = []
    function explore(arr, i, temp) {
        if (arr.length == i) {
            result.push([...temp])
            return
        }
        temp.push(arr[i])
        explore(arr, i + 1, temp)
        temp.pop()
        explore(arr, i + 1, temp)
    }
    explore(nums, 0, [])
    return result
};