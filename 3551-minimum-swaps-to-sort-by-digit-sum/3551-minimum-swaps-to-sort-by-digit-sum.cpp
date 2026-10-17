class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int, int>>vp;
        int sum;
        int org;
        for(int x : nums){
            sum = 0;
            org = x;
            while(x){
                sum += (x % 10);
                x = x / 10;
            }
            vp.push_back({sum, org});
        }
        sort(vp.begin(), vp.end(), [](auto l, auto m){
            if(l.first == m.first){
                return l.second < m.second;
            }
            return l.first < m.first;
        });
        int i = 0;
        unordered_map<int, int>mp;
        for(auto x : vp){
            mp[x.second] = i;
            i++;
        }
        int n = nums.size();
        vector<int>vis(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            int cycle = 0;
            while(!vis[i]){
                vis[i] = 1;
                i = mp[nums[i]];
                cycle++;
            }
            ans += (cycle - 1);
        }
        return ans;
    }
};