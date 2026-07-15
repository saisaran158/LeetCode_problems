class Solution {
public:
    bool check(vector<int>& weights, int mid, int days){
        int s = 0;
        int day = 1;
        for(int x : weights){
            s+= x;
            if(x > mid)return false;
            if(s > mid){
                day++;
                s=0;
                s+=x;
            }
        }
        if(day <= days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int high = 0;
        for(int x : weights){
            high += x;
        }
        int low = 1;
        int ans;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(weights, mid, days)){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};