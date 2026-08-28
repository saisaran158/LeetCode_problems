class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int>adj[n];
        for(vector<int>e : edges){
            adj[e[0]].push_back({e[1]});
            adj[e[1]].push_back({e[0]});
        }
        unordered_set<int>vis(restricted.begin(), restricted.end());

        queue<int>q;
        q.push(0);
        vector<int>visy(n, 0);
        visy[0] = 1;
        int c = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(!vis.count(it) && visy[it] == 0){
                    q.push(it);
                    c++;
                    visy[it] = 1;
                }
            }
        }
        return c;
    }
};