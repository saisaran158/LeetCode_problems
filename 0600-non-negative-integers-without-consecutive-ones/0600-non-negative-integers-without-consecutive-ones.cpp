class Solution {
public:
    int dp[33][2][3];
    int rec(int i, int& size, string& nums, bool tight, int prev){
        if(i == size) return 1;
        if(dp[i][tight][prev] != -1) return dp[i][tight][prev];
        int ans = 0;
        int up = (tight == true) ? nums[i] - '0' : 1;
        for(int digit = 0; digit <= up; digit++){
            if((prev == 1 && digit == 1)) continue;
            ans += rec(i + 1, size, nums, (tight == true && digit == up), digit == 1);
        }

        return dp[i][tight][prev] = ans;
    }
    int findIntegers(int n) {
        string nums = "";
        while(n > 0){
            if(n % 2){
                nums += '1';
            }
            else{
                nums += '0';
            }
            n = n / 2;
        }
        reverse(nums.begin(), nums.end());
        memset(dp, -1, sizeof(dp));
        int tot = nums.size();
        return rec(0, tot, nums, 1, 2);
    }
};