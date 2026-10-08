class Solution {
public:
    int dp[5][2][2][2];
    int rec(int i, int size, string& nums, bool tight, bool lz, bool flag) {
        if (i == size) {
            return flag;
        }
        if(dp[i][tight][lz][flag] != -1) return dp[i][tight][lz][flag];
        int ans = 0;
        int up = (tight) ? nums[i] - '0' : 9;
        for (int j = 0; j <= up; j++) {
            if (j == 3 || j == 7 || j == 4)
                continue;
            if (lz && j == 0) {
                ans += rec(i + 1, size, nums, 0, 1, flag);
            } else {
                bool check = false;
                if (j == 2 || j == 5 || j == 6 || j == 9)
                    check = true;
                ans += rec(i + 1, size, nums, (tight && j == up),
                           (lz && j == 0), flag || check);
            }
        }

        return dp[i][tight][lz][flag] = ans;
    }
    int rotatedDigits(int n) {
        string nums = to_string(n);
        memset(dp, -1, sizeof(dp));
        return rec(0, nums.size(), nums, 1, 1, 0);
    }
};