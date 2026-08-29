class Solution {
public:
    bool check(vector<int>& time, int& totalTrips, long long mid){
        long long t = 0;
        for(long long x : time){
            if(x <= mid){
                t += (mid / x);
            }
            if(t >= totalTrips) return true;
        }
        return t >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = 1LL * *min_element(time.begin(), time.end()) * totalTrips;
        long long ans, mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(check(time, totalTrips, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};