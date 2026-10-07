class Solution {
public:
    int dp[10][2][2][1023];
    int rec(int i, int size, string& nums, bool tight, bool lz, int mask){
        if(i == size){
            if(!lz) return 1;
            return 0;
        }
        if(dp[i][tight][lz][mask] != -1) return dp[i][tight][lz][mask];
        int ans = 0;
        int up = (tight) ? nums[i] - '0' : 9;
        for(int digit = 0; digit <= up; digit++){
            if(lz && digit == 0){
                ans += rec(i + 1, size, nums, 0, lz, mask);
            }
            else{
                int check = mask >> digit & 1;
                if(!check){
                    ans += rec(i + 1, size, nums, (tight && digit == up), (lz && digit == 0), mask | 1 << digit);
                }
            }
        }
        return dp[i][tight][lz][mask] = ans;
    }
    int countSpecialNumbers(int n) {
        string nums = to_string(n);
        memset(dp, -1 , sizeof(dp));
        return rec(0, nums.size(), nums, 1, 1, 0);
    }
};