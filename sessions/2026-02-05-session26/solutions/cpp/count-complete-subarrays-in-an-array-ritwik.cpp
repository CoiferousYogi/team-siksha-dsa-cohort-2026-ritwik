#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        int countCompleteSubArrayOpt(vector<int>& arr) {
            // optimal approach: using sliding window + map + set

            // we will first find out all the unique elements in the array using set
            unordered_set<int> st;

            for(int i = 0; i < arr.size(); i++) {
                st.insert(arr[i]);
            }

            int k = st.size();

            // variable size sliding window
            unordered_map<int, int> mp;
            int count = 0;
            int left = 0;

            for(int right = 0; right < arr.size(); right++) {
                mp[arr[right]]++;

                while(mp.size() == k) {
                    count = count + (arr.size()-right);

                    mp[arr[left]]--;
                    if(mp[arr[left]] == 0) {
                        mp.erase(arr[left]);
                    }
                    left++;
                }
            }
            return count;
        }
};

int main() {
    return 0;
}