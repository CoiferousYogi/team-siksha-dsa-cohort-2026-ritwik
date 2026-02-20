class Solution
{
private:
    // Returns count of elements <= target in the matrix
    // Each row is sorted, so we binary search in every row
    int upperBound(vector<vector<int>> &mat, int n, int m, int target)
    {
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int low = 0, high = m - 1;
            int pos = m; // stores first index where element > target

            // Binary search in row i
            while (low <= high)
            {
                int mid = low + (high - low) / 2;

                if (mat[i][mid] > target)
                {
                    pos = mid;
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            // pos = number of elements <= target in this row
            count += pos;
        }
        return count;
    }

public:
    int median(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        // We want the element at this index in sorted order
        int requiredIndex = (n * m) / 2;

        // STEP 1: Find global min and max in matrix
        int low = INT_MAX, high = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            low = min(low, mat[i][0]);       // first element of row
            high = max(high, mat[i][m - 1]); // last element of row
        }

        // STEP 2: Binary search on VALUE RANGE
        // Not on indices, but on numbers themselves

        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // Count how many elements <= mid
            int count = upperBound(mat, n, m, mid);

            // If enough elements are <= mid,
            // mid could be the median
            if (count > requiredIndex)
            {
                ans = mid;
                high = mid - 1; // try smaller value
            }
            else
            {
                low = mid + 1; // need bigger value
            }
        }

        return ans;
    }
};