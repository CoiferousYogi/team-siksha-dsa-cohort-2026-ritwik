class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mapp;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            mapp[nums[i]]++;
        }

        for (const auto &pair : mapp)
        {
            if (pair.second > nums.size() / 3)
            {
                ans.emplace_back(pair.first);
            }
        }

        return ans;
    }
};