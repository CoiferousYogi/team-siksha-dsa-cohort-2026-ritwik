// https://leetcode.com/problems/sqrtx/description/

/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function (x) {
    if (x < 2) return x

    let l = 2, r = Math.floor(x / 2)
    while (l <= r) {
        let mid = l + Math.floor((r - l) / 2)
        if (mid ** 2 === x) return mid
        else if (mid ** 2 > x) r = mid - 1
        else l = mid + 1
    }
    return r
};