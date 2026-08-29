class Solution {
public:
    bool check(vector<int>&dist, double& hour, int mid){
        double t = 0;
        int n = dist.size();
        for(int i = 0; i < n; i++){
            if(i != n - 1)
            t += ceil((double)dist[i] / mid);
            else
            t += (double) dist[i] / mid;
        }
        return t <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int high = 1e9;
        int ans = -1, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(check(dist, hour, mid)){
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