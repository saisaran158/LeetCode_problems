class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int>forb(forbidden.begin(), forbidden.end());
        queue<pair<int, pair<int, int>>>q;
        q.push({0, {0, 0}});
        int up = max(x, *max_element(forbidden.begin(), forbidden.end())) + a + b;
        vector<vector<int>>vis(up + 1, vector<int>(2, 0));
        while(!q.empty()){
            int step = q.front().first;
            int node = q.front().second.first;
            int back = q.front().second.second;
            q.pop();
            if(node == x) return step;
            if(node + a <= up && forb.find(node + a) == forb.end() && vis[node + a][0] == 0 ){
                q.push({step + 1,{node + a, 0}});
                vis[node + a][0] = 1;
            }

            if(node - b >= 0 && back == 0){
                if(forb.find(node - b) == forb.end() && vis[node - b][1] == 0){
                    q.push({step + 1, {node - b, 1}});
                    vis[node - b][1] = 1;
                }
            }
        }
        return -1;
    }
};