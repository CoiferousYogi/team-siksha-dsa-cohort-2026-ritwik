/**
 * Generates all unique subsets of an array.
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(2^n)
 *
 * @param {number[]} nums - The input array (may contain duplicate values).
 * @returns {number[][]} A 2D array containing all unique subsets.
 */
function subsetsWithDup(nums: number[]) {
    const result: number[][] = []
    
    const subsets = (index: number, currentSet: number[]) => {
        if (index >= nums.length) {
            result.push(currentSet.slice())
            return result
        }

        currentSet.push(nums[index])
        subsets(index + 1, currentSet)
        currentSet.pop()
        while(index < nums.length && nums[index] === nums[index + 1]) {
            index++
        }
        subsets(index + 1, currentSet)

        return result
    }

    nums.sort((a,b) => a - b)
    subsets(0, [])

    return result
}

/**
 * Generates all unique subsets by grouping elements based on their frequency.
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(2^n)
 *
 * @param {number[]} nums - The input array (may contain duplicate values).
 * @returns {number[][]} A 2D array containing all unique subsets.
 */
function subsetsWithDup_groupByFrequency(nums: number[]) {
    const result: number[][] = []
    const frequency: Map<number, number> = new Map()

    for (let i = 0; i < nums.length; i++) {
        frequency.set(nums[i], (frequency.get(nums[i]) ?? 0) + 1)
    }

    const uniqueNums = Array.from(frequency.keys())

    const subsets = (index: number, currentSet: number[]) => {
        if (index >= uniqueNums.length) {
            result.push(currentSet.slice())
            return
        }

        const num = uniqueNums[index]
        const numFrequency = frequency.get(num)

        for (let count = 0; count <= numFrequency; count++) {
            for (let i = 0; i < count; i++) {
                currentSet.push(num)                
            }

            subsets(index + 1, currentSet)

            for (let i = 0; i < count; i++) {
                currentSet.pop()                
            }
        }
    }

    subsets(0, [])

    return result
}
