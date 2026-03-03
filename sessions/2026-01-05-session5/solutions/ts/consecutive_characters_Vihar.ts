// Problem link: https://leetcode.com/problems/consecutive-characters/

/**
 * @param s - input string
 * @returns the power of the string 
 */
function maxPower(s: string): number {
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