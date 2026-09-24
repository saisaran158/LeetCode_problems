class Solution {
public:
    int rec(int val, unordered_map<int, int>& mp){
        if(val == 1) return 0;
        if(mp.find(val) != mp.end()){
            return mp[val];
        }
        if(val % 2 == 0){
            mp[val] = 1 + rec(val / 2, mp);
        }
        else{
            mp[val] = 1 + rec(3 * val + 1, mp);
        }
        return mp[val];
    }
    int getKth(int lo, int hi, int k) {
        unordered_map<int, int>mp;
        vector<pair<int, int>>vp;
        for(int i = lo; i <= hi; i++){
            vp.push_back({rec(i, mp), i});
        }
        sort(vp.begin(), vp.end());
        int x = 1;
        for(auto it : vp){
            if(x == k){
                return it.second;
            }
            x++;
        }
        return 0;
    }
};