class Solution {
public:
    bool check(vector<int>& position, int& m, int mid){
        int c = 1;
        for(int i = 0; i < position.size();){
            i = lower_bound(position.begin(), position.end(), position[i] + mid) - position.begin();
            if(i < position.size()){
                c++;
            }
        }
        return c >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        int low = 1;
        int high = *max_element(position.begin(), position.end()) - *min_element(position.begin(), position.end());
        sort(position.begin(), position.end());
        int mid, ans;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(check(position, m, mid)){
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