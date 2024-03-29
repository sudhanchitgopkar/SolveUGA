class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLIS = 1, sol = 0;

        vector<int> LIS (n, 1), ways (n, 1);
        LIS[n - 1] = 1;
        ways[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--) {
            int curr = nums[i], currLIS = 1, currWays = 1;

            for (int j = i + 1; j < n; j++) {
                if (nums[j] > curr) {
                    if (LIS[j] + 1 > currLIS) {
                        currLIS = LIS[j] + 1;
                        currWays = ways[j];
                    } else if (LIS[j] + 1 == currLIS) {
                        currWays += ways[j];
                    } //if
                } //if
            } //for

            LIS[i] = currLIS;
            ways[i] = currWays;
            maxLIS = max(LIS[i], maxLIS);
        } //for

        for (int i = 0; i < n; i++) {
            if (LIS[i] == maxLIS) sol += ways[i];
        } //for

        return sol;
    }//findNumOfLIS
};
