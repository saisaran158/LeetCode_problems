class Solution {
public:
    long long dp[16][2][2][600];
    long long rec(int i, int size, string& nums, bool tight, bool lz, int count){
        if(i == size){
            if(count == 0 && !lz) return 1;
            return 0;
        }
        if(dp[i][tight][lz][count + 99] != -1) return dp[i][tight][lz][count + 99];
        long long ans = 0;
        int up = tight ? nums[i] - '0' : 9;
        for(int j = 0; j <= up; j++){
            if(lz && j == 0){
                ans += rec(i + 1, size, nums, 0, 1, 0);
            }
            else{
                if(i % 2){
                    ans += rec(i + 1, size, nums, (tight && j == up), (lz && j == 0), count + j);
                }
                else{
                    ans += rec(i + 1, size, nums, (tight && j == up), (lz && j == 0), count - j);
                }
            }
        }
        return dp[i][tight][lz][count + 99] = ans;
    }
    long long countBalanced(long long low, long long high) {
        string second = to_string(high);
        string first = to_string(low - 1);
        memset(dp, -1, sizeof(dp));
        long long b = rec(0, second.size(), second, 1, 1, 0);
        memset(dp, -1, sizeof(dp));
        long long a = rec(0, first.size(), first, 1, 1, 0);
        return b - a;
    }
};