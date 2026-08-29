class Solution {
public:
    bool check(vector<int>& quantities, int& n, int mid){
        int s = 0;
        for(int x : quantities){
           if(x % mid == 0){
            s += x / mid;
           } 
           else{
            s += (x / mid) + 1;
           }
        }
        return s <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        int ans, mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(check(quantities, n, mid)){
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