class Solution {
public:
    void dfs(int start, int& destination, vector<vector<int>>&graph, vector<int>path, vector<vector<int>>&res, vector<int>&vis){
        if(start == destination){
            res.push_back(path);
            return;
        }
        vis[start] = 1;
        for(auto it : graph[start]){
            if(!vis[it]){
                path.push_back(it);
                dfs(it, destination, graph, path, res, vis);
                path.pop_back();
            }
        }
        vis[start] = 0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int source = 0;
        int destination = graph.size() - 1;
        vector<int>vis(destination + 1, 0);
        vector<vector<int>>res;
        vector<int>path;
        path.push_back(0);
        dfs(source, destination, graph, path, res, vis);
        return res;
    }
};