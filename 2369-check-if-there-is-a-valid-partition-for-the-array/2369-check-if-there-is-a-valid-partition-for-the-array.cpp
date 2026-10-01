class Solution {
public:
    bool rec(int i, int& n, vector<int>& nums, vector<int>& dp){
        if(i >= n) return true;
        if(dp[i] != -1) return dp[i];
        bool ans = false;
        map<int, int>mp;
        vector<int>rs;
        for(int j = i; j < i + 3 && j < n; j++){
            mp[nums[j]]++;
            rs.push_back(nums[j]);
            if(mp.size() == 1){
                if(mp[nums[j]] == 2){
                    ans = ans || rec(j + 1, n, nums, dp);
                }
                if(mp[nums[j]] == 3){
                    ans = ans || rec(j + 1, n, nums, dp);
                }
            }
            if(mp.size() == 3){
                if(rs[1] - rs[0] == 1 && rs[2] - rs[1] == 1){
                    ans = ans || rec(j + 1, n, nums, dp);
                }
            }
        }

        return dp[i] = ans;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return rec(0, n, nums, dp);
    }
};