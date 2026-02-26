// Problem link: https://www.geeksforgeeks.org/problems/search-an-element-in-an-array-1587115621/1

/**
 * Performs a recursive linear search to find the index of a target value.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) (recursive call stack)
 *
 * @param {number[]} nums - The array to search.
 * @param {number} target - The value to find.
 * @param {number} [index=0] - The current index (used internally).
 * @returns {number} The index of the target if found, otherwise -1.
 */
function linearSearch(nums: number[], target: number, index: number = 0) {
    if (index >= nums.length) {
        return -1
    }

    if (nums[index] === target) {
        return index
    }

    return linearSearch(nums, target, index + 1)
}

/**
 * Performs a recursive linear search using a helper function.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) (recursive call stack)
 *
 * @param {number[]} nums - The array to search.
 * @param {number} target - The value to find.
 * @returns {number} The index of the target if found, otherwise -1.
 */
function linearSearch_helperBased(nums: number[], target: number) {
    const search = (index: number) => {
        if (index >= nums.length) {
            return -1
        }

        if (nums[index] === target) {
            return index
        }

        return search(index + 1)
    }

    return search(0)
}

/**
 * Performs a recursive binary search on a sorted array.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) (recursive call stack)
 *
 * @param {number[]} nums - The sorted array to search.
 * @param {number} target - The value to find.
 * @param {number} [left=0] - The left boundary index (used internally).
 * @param {number} [right=nums.length - 1] - The right boundary index (used internally).
 * @returns {number} The index of the target if found, otherwise -1.
 */
function binarySearch(nums: number[], target: number, left: number = 0, right?: number) {
    // Set default if right is undefined
    right = right ?? nums.length - 1

    if (left > right) {
        return -1
    }

    const mid = Math.floor((left + right) / 2)

    if (nums[mid] === target) {
        return mid
    } else if (nums[mid] < target) {
        return binarySearch(nums, target, mid + 1, right)
    } else {
        return binarySearch(nums, target, left, mid - 1)
    }
}

/**
 * Performs a recursive binary search using a helper function.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) (recursive call stack)
 *
 * @param {number[]} nums - The sorted array to search.
 * @param {number} target - The value to find.
 * @returns {number} The index of the target if found, otherwise -1.
 */
function binarySearch_helperBased(nums: number[], target: number) {
    const search = (left: number, right: number) => {
        if (left > right) {
            return -1
        }

        const mid = Math.floor((left + right) / 2)

        if (nums[mid] === target) {
            return mid
        } else if (nums[mid] < target) {
            return search(mid + 1, right)
        } else {
            return search(left, mid - 1)
        }
    }

    return search(0, nums.length - 1)
}