class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int, int>>pq;
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[n - 1] = nums[n - 1];
        pq.push({nums[n - 1], n - 1});
        for(int i = n - 2; i >= 0; i--){
            while(i + k < pq.top().second){
                pq.pop();
            }

            dp[i] = nums[i] + pq.top().first;
            pq.push({nums[i] + pq.top().first, i});
        }
        for(int x : dp){
            cout << x<< " ";
        }
        return dp[0];
    }
};