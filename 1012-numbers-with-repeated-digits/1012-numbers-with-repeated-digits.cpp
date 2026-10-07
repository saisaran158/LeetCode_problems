class Solution {
public:
    int rec(int i, int& size, string& nums, bool tight, bool rep, int mask, bool lz, vector<vector<vector<vector<vector<int>>>>>& dp){
        if(i >= size){
            return rep;
        }
        if(dp[i][tight][rep][mask][lz] != -1) return dp[i][tight][rep][mask][lz];
        int ans = 0;
        int up = (tight == true) ? nums[i] - '0' : 9;
        for(int digit = 0; digit <= up; digit++){
            if(lz && digit == 0){
                ans += rec(i + 1, size, nums, (tight && digit == up), 0, mask, lz, dp);
            }
            else{
                bool now = 1 & (mask >> digit);
                ans += rec(i + 1, size, nums, (tight && digit == up), (rep || now), mask | (1 << digit), (lz && digit == 0), dp);
            }
        }

        return dp[i][tight][rep][mask][lz] = ans;
    }
    int numDupDigitsAtMostN(int n) {
        string nums = to_string(n);
        int size = nums.size();
        vector<vector<vector<vector<vector<int>>>>>dp(11, vector<vector<vector<vector<int>>>>(2, vector<vector<vector<int>>>(2, vector<vector<int>>(1023, vector<int>(2, -1)))));
        return rec(0, size, nums, 1, 0, 0, 1, dp);
    }
};