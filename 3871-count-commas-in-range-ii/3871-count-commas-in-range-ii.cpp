class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        if(n >= 1000){
            long long up = n < 999999 ? n : 999999;
            ans += (up - 999) * 1;
        }
        if(n >= 1000000){
            long long up = n < 999999999 ? n : 999999999;
            ans += (up - 999999) * 2;
        }
        if(n >= 1000000000){
            long long up = n < 999999999999 ? n : 999999999999;
            ans += (up - 999999999) * 3;
        }
        if(n >= 1000000000000){
            long long up = n < 1000000000000000 ? n : 1000000000000000;
            ans += (up - 999999999999) * 4;
        }
        if(n == 1000000000000000)ans++;
        return ans;
    }
};