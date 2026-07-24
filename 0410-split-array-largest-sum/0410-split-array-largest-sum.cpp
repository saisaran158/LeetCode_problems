class Solution {
public:
    bool check(vector<int>& weights, int capacity, int days){
        int day = 1;
        int sum = 0;
        for(int x : weights){
            sum += x;
            if(sum > capacity){
                day++;
                sum = 0;
                sum += x;
            }
        }
        if(day <= days)return true;
        return false;
    }
    int splitArray(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(weights, mid, days)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};