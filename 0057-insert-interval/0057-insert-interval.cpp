class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>>res;
        if(n == 0){
            res.push_back(newInterval);
            return res;
        }
        int low = 0;
        int high = n;
        int mid;
        while(low < high){
            mid = low + (high - low) / 2;
            if(intervals[mid][0] < newInterval[0]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        for(int i = 0; i < low; i++){
            res.push_back({intervals[i]});
        }
        if(res.empty()){
            res.push_back(newInterval);
        }
        else if(res.back()[1] >= newInterval[0]){
            res.back()[1] = max(res.back()[1], newInterval[1]);
        }
        else{
            res.push_back(newInterval);
        }
        for(int i = low; i < n; i++){
            if(res.back()[1] >= intervals[i][0]){
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};