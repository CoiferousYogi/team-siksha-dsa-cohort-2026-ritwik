#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;


class Solution {
    // brute force approach: making a sorted combined array and then finding the median
    int medianOfTwoSortedArraysBrute(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;

        int left = 0;
        int right = 0;

        while(left < nums1.size() && right < nums2.size()) {
            // nums1[left] < nums2[right]
            if(nums1[left] < nums2[right]) {
                merged.push_back(nums1[left]);
                left++;
            } 
            else if(nums1[left] > nums2[right]) {
                merged.push_back(nums2[right]);
                right++;
            }
            else {
                // nums1[left] == nums2[right]
                merged.push_back(nums1[left]);
                merged.push_back(nums2[right]);
                left++;
                right++;
            }
        }

        while(left < nums1.size()) {
            merged.push_back(nums1[left]);
            left++;
        }

        while(right < nums2.size()) {
            merged.push_back(nums2[right]);
            right++;
        }
        
        int ans = -1;
        if(merged.size() % 2 == 0) {
            int f = merged[merged.size() / 2];
            int s = merged[merged.size()/2 + 1];

            return (f + s) / 2;
        }
        else {
            return merged[merged.size() / 2];
        }

        return -1;

        /*
            TC: O(m + n): For merging the arrays, m + n elements were traversed
            SC: O(m + n): Extra space consumed by merged array
        */
    }

    int medianOfTwoSortedArraysOpt(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), n = n1 + n2;
        if(n1 > n2) 
            return medianOfTwoSortedArraysOpt(nums2, nums1);
        int noOfElementsInLeftPart = (n + 1) / 2;
        int low = 0, high = n1, mid1 = -1, mid2 = -1;

        while(low <= high) {
            mid1 = (low + high) / 2;
            mid2 = noOfElementsInLeftPart - mid1;
            int la = INT_MIN, lb = INT_MIN;
            int ra = INT_MAX, rb = INT_MAX;
            if(mid1 > 0)
                la = nums1[mid1 - 1];
            if(mid2 > 0)
                lb = nums2[mid2 - 1];
            if(mid1 < n1)
                ra = nums1[mid1];
            if(mid2 < n2)
                rb = nums2[mid2];
            if(la <= rb && lb <= ra) {
                if(n % 2 == 0) {
                    int x = max(la, lb) + min(ra, rb);
                    return x / 2.0;
                } else {
                    return max(la, lb);
                }
            } 
            if(la > rb) {
                high = mid1 - 1;
            } else if(lb > ra) {
                low = mid1 + 1;
            }
        }
        return -1;
    }
};