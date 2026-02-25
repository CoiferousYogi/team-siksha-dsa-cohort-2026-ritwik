// Problem Link : https://leetcode.com/problems/running-sum-of-1d-array/

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var runningSum = function (nums) {
    const n = nums.length
    const arr = new Array(n)
    let count = 0
    for (let i = 0; i < n; i++) {
        count += nums[i]
        arr[i] = count
    }
    return arr
};