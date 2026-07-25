class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<pair<int, int>> vp(n);
        for(int i = 0; i < envelopes.size(); i++){
            vp[i].first = envelopes[i][0];
            vp[i].second = envelopes[i][1];
        }
        sort(vp.begin(), vp.end(), [](auto a, auto b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        vector<int> res;
        for(auto it : vp){
            int pos = lower_bound(res.begin(), res.end(), it.second) - res.begin();
            if(res.size() == pos)
            res.push_back(it.second);
            else{
                res[pos] = it.second;
            }
        }
        return res.size();
    }
};