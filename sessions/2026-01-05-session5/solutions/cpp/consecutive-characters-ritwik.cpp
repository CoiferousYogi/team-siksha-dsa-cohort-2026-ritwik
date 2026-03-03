/*
The power of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string s, return the power of s.

 

Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <string>

using namespace std;

class Solution {
    public:
    int maxPower(string s) {
        int charCount = 0;
        int maxCharCount = 0;
        int prevChar = '\0'; // initialized to null character

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == prevChar) {
                charCount++;
            }
            else {
                // s[i] != prevChar
                charCount = 1; // new current character also contributes to the count
                prevChar = s[i];
            }

            maxCharCount = max(maxCharCount, charCount);
        }

        return maxCharCount;
    }
};


int main() {
        string str = "abbcccddddeeeeedcba";
        Solution s;
        int ans = s.maxPower(str);
        cout<<ans<<endl;
    return 0;
}