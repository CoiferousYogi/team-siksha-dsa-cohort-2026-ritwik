class Solution
{
private:
    int getDays(vector<int> &nums, int maxWeight)
    {
        int days = 1;
        int currentWeight = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (currentWeight + nums[i] > maxWeight)
            {
                days++;
                currentWeight = nums[i];
            }
            else
            {
                currentWeight += nums[i];
            }
        }
        return days;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int minWeight = *max_element(weights.begin(), weights.end());
        int maxWeight = accumulate(weights.begin(), weights.end(), 0);
        while (minWeight < maxWeight)
        {
            int mid = minWeight + (maxWeight - minWeight) / 2;
            int currDays = getDays(weights, mid);
            if (currDays <= days)
            {
                maxWeight = mid;
            }
            else
            {
                minWeight = mid + 1;
            }
        }
        return maxWeight;
    }
};