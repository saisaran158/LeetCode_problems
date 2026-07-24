class Solution {
public:
    bool check(vector<int> &piles, int h, int mid){
        long long hour = 0;
        for(int x : piles){
            if(x % mid ==0){
                hour += x / mid;
            }
            else{
                hour += (x / mid) + 1;
            }
        }
        if(hour <= h)return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high;
        for(int x : piles){
            if(x > high)
            high = x;
        }
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(check(piles, h, mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;

    }
};