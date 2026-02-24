// Problem link: https://leetcode.com/problems/consecutive-characters/description/

/**
 * @param {string} s - input string
 * @returns {number} the power of the string 
 */
function maxPower(s) {
    let currentPower = 0
    let maxPower = 0

    for (let i = 1; i < s.length; i++) {
        if (s[i] === s[i - 1]) {
            currentPower++
        } else {
            currentPower = 1
        }

        maxPower = Math.max(currentPower, maxPower)
    }

    return maxPower
};