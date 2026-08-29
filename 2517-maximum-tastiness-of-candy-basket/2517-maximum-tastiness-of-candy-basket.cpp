class Solution {
public:
    bool check(vector<int>&prices, int& k, int mid){
        int c = 1;
        for(int i = 0; i < prices.size();){
            i = lower_bound(prices.begin(), prices.end(), prices[i] + mid) - prices.begin();
            if(i < prices.size()){
                c++;
            }
        }
        return c >= k;
    }
    int maximumTastiness(vector<int>& price, int k) {
        int low = 1;
        int n = price.size();
        sort(price.begin(), price.end());
        int high = price[n - 1] - price[0];
        int ans = 0, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(check(price, k, mid)){
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