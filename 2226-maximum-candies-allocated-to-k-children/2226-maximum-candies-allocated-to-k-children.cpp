class Solution {
public:
    bool check(vector<int>& candies, long long k, long long mid){
        long long c = 0;
        for(int x : candies){
            c += x / mid;
        }
        return c >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1;
        long long high = *max_element(candies.begin(), candies.end());
        long long ans = 0, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(check(candies, k, mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};