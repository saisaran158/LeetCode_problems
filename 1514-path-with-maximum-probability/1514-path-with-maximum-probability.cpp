class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        priority_queue<pair<double, int>>pq;
        vector<pair<int, double>>vp[n];
        for(int i = 0; i < edges.size(); i++){
            vp[edges[i][0]].push_back({edges[i][1], succProb[i]});
            vp[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        pq.push({1.0, start_node});
        vector<double>dist(n, 0.0);
        dist[start_node] = 0.0;
        while(!pq.empty()){
            double step = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : vp[node]){
                double cost = it.second;
                int adjnode = it.first;

                if(step * cost > dist[adjnode]){
                    dist[adjnode] = step * cost;
                    pq.push({step*cost, adjnode});
                }
            }
        }
        return dist[end_node];
    }
};