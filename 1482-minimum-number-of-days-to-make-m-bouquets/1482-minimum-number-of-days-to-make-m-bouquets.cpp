class Solution {
public:
    bool check(vector<int>& bloomDay, int& m, int& k, int mid){
        int c = 0;
        int b = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] > mid){
                b = 0;
            }
            if(bloomDay[i] <= mid){
                b++;
                if(b == k){
                    c++;
                    b = 0;
                }
            }
        }
        return c >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        int mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(check(bloomDay, m, k, mid)){
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