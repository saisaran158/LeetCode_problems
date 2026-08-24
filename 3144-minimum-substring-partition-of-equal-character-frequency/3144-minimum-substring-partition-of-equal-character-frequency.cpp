class Solution {
public:
    int solve(int i, int& n, string& s, vector<int>& dp,
              vector<vector<int>>& dp1) {
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int minC = INT_MAX;
        vector<int> freq(26, 0);
        int dis = 0;
        int maxFreq = 0;
        for (int j = i; j < n; j++) {
            freq[s[j] - 'a']++;
            if(freq[s[j] - 'a'] == 1) dis++;
            maxFreq = max(maxFreq, freq[s[j] - 'a']);
            if (maxFreq * dis ==  j - i + 1) {
                int cost = 1 + solve(j + 1, n, s, dp, dp1);
                minC = min(cost, minC);
            }
        }
        return dp[i] = minC;
    }
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        return solve(0, n, s, dp, dp1);
    }
};