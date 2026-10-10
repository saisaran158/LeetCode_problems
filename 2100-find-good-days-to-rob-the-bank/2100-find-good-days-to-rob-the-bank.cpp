class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int>left(n, 0);
        vector<int>right(n, 0);
        left[0] = 0;
        right[n - 1] = 0;
        for(int i = 1; i < n; i++){
            if(security[i - 1] >= security[i]){
                left[i] += left[i - 1] + 1;
            }
        }
        for(int i = n - 2; i >= 0; i--){
            if(security[i] <= security[i + 1]){
                right[i] += right[i + 1] + 1;
            }
        }
        vector<int>res;
        for(int i = 0; i < n; i++){
            if(left[i] >= time && right[i] >= time)
            res.push_back(i);
        }
        return res;
    }
};