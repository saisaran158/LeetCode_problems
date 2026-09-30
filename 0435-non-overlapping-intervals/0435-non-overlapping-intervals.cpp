class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 1;
        sort(intervals.begin(), intervals.end(),[](auto a, auto b){
            return a[1] < b[1];
        });
        int curr = intervals[0][1];
        for(int i = 0; i < intervals.size() - 1; i++){
            if(curr <= intervals[i + 1][0]){
                ans++;
                curr = intervals[i + 1][1];
            }
        }
        return intervals.size() - ans;
    }
};