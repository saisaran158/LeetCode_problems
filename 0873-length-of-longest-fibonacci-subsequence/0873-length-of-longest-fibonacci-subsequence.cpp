class Solution {
public:
    int rec(int prev, int curr, vector<int>& arr, unordered_map<int, int>& mp){
        if(curr >= arr.size()) return 0;

        int ans = 0;
        if(mp.find(arr[prev] + arr[curr]) != mp.end()){
            ans = 1 + rec(curr, mp[arr[prev] + arr[curr]], arr, mp);
        }
        else{
            return 0;
        }

        return ans;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        unordered_map<int, int>mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]] = i;
        }
        for(int prev = 0; prev < n; prev++){
            for(int curr = prev + 1; curr < n; curr++){
                ans = max(ans, rec(prev, curr, arr, mp) + 2);
            }
        }
        return ans <= 2 ? 0 : ans;
    }
};