class Solution {
public:
    void bfs(int V, vector<vector<int>>& vp, vector<int>& vis, int& vertices,
             int& edges) {
        int source = V;
        queue<int> q;
        q.push(V);
        vis[V] = 1;
        vertices++;
        edges += vp[V].size();
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int adj : vp[node]) {
                if (vis[adj] == 0) {
                    vertices++;
                    edges += vp[adj].size();
                    vis[adj] = 1;
                    q.push(adj);
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int count = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int vertices = 0;
                int edges = 0;
                bfs(i, adj, vis, vertices, edges);
                edges = edges / 2;
                if (vertices * (vertices - 1) / 2 == edges) {
                    count++;
                }
            }
        }
        return count;
    }
};