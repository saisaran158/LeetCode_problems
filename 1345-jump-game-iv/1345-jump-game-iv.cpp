class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
    
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<int> vis(n, 0);
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0] = 1;
        while (!q.empty()) {
            int node = q.front().first;
            int step = q.front().second;
            q.pop();

            if (node == n - 1) {
                return step;
            }

            if(node - 1 >= 0 && vis[node - 1] == 0){
                vis[node - 1] = 1;
                q.push({node - 1, step + 1});
            }

            if(node + 1 < n && vis[node + 1] == 0){
                vis[node + 1] = 1;
                q.push({node + 1, step + 1});
            }

            for (auto m : mp[arr[node]]) {
                if (vis[m] == 0) {
                    vis[m] = 1;
                    q.push({m, step + 1});
                }
            }
            mp[arr[node]].clear();
        }
        return 0;
    }
};