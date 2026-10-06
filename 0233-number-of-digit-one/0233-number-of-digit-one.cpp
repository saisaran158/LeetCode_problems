class Solution {
public:
    int rec(int i, int size, string& nums, bool tight, int count, vector<vector<vector<int>>>& dp){
        if(i == size) return count;
        if(dp[i][tight][count] != -1) return dp[i][tight][count];
        int total = 0;
        int up = (tight == true) ? nums[i] - '0' : 9;
        for(int digit = 0; digit <= up; digit++){
            total += rec(i + 1, size, nums, (tight == true && digit == up), (digit == 1) ? count + 1 : count, dp);
        }

        return dp[i][tight][count] = total;
    }
    int countDigitOne(int n) {
        string nums = to_string(n);
        int size = nums.size();
        vector<vector<vector<int>>>dp(size, vector<vector<int>>(2, vector<int>(size + 1, -1)));
        return rec(0, size, nums, 1, 0, dp);
    }
};