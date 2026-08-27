class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>dp(n, 1);
        vector<int>ind(n);
        int maxi = -1e9;
        int lastIndex;
        for(int i = 0; i < n; i++){
            ind[i] = i;
            for(int prev = 0; prev < i; prev++){
                if(nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    ind[i] = prev;
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int>res;
        res.push_back(nums[lastIndex]);
        while(ind[lastIndex] != lastIndex){
            lastIndex = ind[lastIndex];
            res.push_back(nums[lastIndex]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};