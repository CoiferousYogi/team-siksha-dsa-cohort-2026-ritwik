// Problem link: https://www.geeksforgeeks.org/dsa/max-number-of-one-ii/

/**
 * @param arr - array of 1s and 0s 
 * @returns maximum consecutive 1s after flipping 1 zero
 */
function maxConsecutiveOne(arr: number[]): number {
    let left = 0
    let lastFlipped = -1
    let max = 0

    for (let right = 0; right < arr.length; right++) {
        if (arr[right] === 0 && lastFlipped >= 0) {
            left = lastFlipped + 1
            lastFlipped = right
        } else if (arr[right] === 0) {
            lastFlipped = right
        }

        max = Math.max(right - left + 1, max)
    }

    return max
}