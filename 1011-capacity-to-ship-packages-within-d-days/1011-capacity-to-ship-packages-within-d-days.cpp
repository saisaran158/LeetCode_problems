class Solution {
public:
    bool check(int mid, vector<int>& weights, int day){
        int s = 0;
        int days = 1;
        for(int x : weights){
            s += x;
            if(x > mid)return false;
            if(s > mid){
                days++;
                s = 0;
                s += x;
            }
        }
        if(days <= day){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(), 0);
        while(low <= high){
            int mid = low + (high - low) /2;
            if(check(mid, weights, days)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low; 
    }
};