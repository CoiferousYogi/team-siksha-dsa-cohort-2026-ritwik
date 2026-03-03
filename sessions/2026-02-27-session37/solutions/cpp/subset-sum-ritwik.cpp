/*
Problem statement
You are given an array 'nums' of ‘n’ integers.
Return all subset sums of 'nums' in a non-decreasing order.

Note:
Here subset sum means sum of all elements of a subset of 'nums'. A subset of 'nums' is an array formed by removing some (possibly zero or all) elements of 'nums'.


For example
Input: 'nums' = [1,2]

Output: 0 1 2 3

Explanation:
Following are the subset sums:
0 (by considering empty subset)
1 
2
1+2 = 3
So, subset sum are [0,1,2,3].
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3
1 2 3
Sample output 1 :
0 1 2 3 3 4 5 6
Explanation For Sample Output 1:
For the first test case,
Following are the subset sums:
0 (by considering empty subset)
1
2
1+2 = 3
3
1+3 = 4
2+3 = 5
1+2+3 = 6
So, subset-sums are [0,1,2,3,3,4,5,6]
Sample Input 2 :
2 
4 5
Sample output 2 :
0 4 5 9
Expected Time Complexity:
Try to do this in O(n*2^n). 
Constraints:
1 <= n <= 15
0 <= nums[i] <= 5000

Time limit: 1 sec
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BruteForceSolution{
private:
void findSubsets(vector<int>& nums, vector<int>& subset, vector<vector<int>>& res, int idx) {
	if(idx == nums.size()) {
		res.push_back(subset);
		return;
	}

	// select element at idx
	subset.push_back(nums[idx]);

	findSubsets(nums, subset, res, idx+1);

	// backtrack => de-select element at idx
	subset.pop_back();

	findSubsets(nums, subset, res, idx+1);
}

public:
vector<int> subsetSum(vector<int> &nums){
	// Write your code here.	
	vector<vector<int>> res;

	vector<int> subset;

	findSubsets(nums, subset, res, 0);

	vector<int> sums;


	for(const auto& row : res) {
		int sum = 0;
		for(const auto& ele : row) {
			sum += ele;
		}
		sums.push_back(sum);
	}

	sort(sums.begin(), sums.end());

	return sums;

}
};

class OptimalSolution {
public:
    void subsets(vector<int>& nums, vector<int>& sums, int sum, int idx) {
        if(idx == nums.size()) {
            sums.push_back(sum);
            return;
        }

        // add element at idx to sum
        subsets(nums, sums, sum+nums[idx], idx+1);

        // backtrack
        subsets(nums, sums, sum, idx+1);
    }

    vector<int> subsetSums(vector<int>& nums) {
        vector<int> sums;
        
        subsets(nums, sums, 0, 0);

        sort(sums.begin(), sums.end());
        return sums;
    }
};


int main() {
        vector<int> nums = {1,2,3};

        OptimalSolution op;

        vector<int> sums = op.subsetSums(nums);

        for(int ele : sums) {
            cout<<ele<<" ";
        }
        cout<<endl;
    return 0;
}