class Solution {
public:
    void dfs(int src, int node, vector<int> adj[], vector<vector<bool>>& vis){
        
        for(auto it : adj[node]){
            if(!vis[src][it]){
                vis[src][it] = true;
                dfs(src, it, adj, vis);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int>adj[n];
        for(auto i : prerequisites){
            adj[i[0]].push_back({i[1]});
        }
        vector<vector<bool>>vis(n, vector<bool>(n, 0));
        for(int i = 0; i < n; i++){
            dfs(i, i, adj, vis);
        }
        vector<bool>ans;
        for(auto it : queries){
            if(vis[it[0]][it[1]]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};