class Solution {
public:
    bool check(vector<int>& citations, int mid){
        int c = 0;
        for(int x : citations){
            if(x >= mid){
                c++;
            }
        }
        if(c >= mid) return true;
        return false;
    }
    int hIndex(vector<int>& citations) {
        int low = 0;
        int high = 0;
        for(int x : citations){
            if(x > high){
                high = x;
            }
        }
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(citations, mid)){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low == 0 ? 0 : low - 1;
    }
};