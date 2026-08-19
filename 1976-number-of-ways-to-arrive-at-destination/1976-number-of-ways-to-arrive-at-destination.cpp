class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
        long long mod = 1e9 + 7;
        vector<pair<int, long long>>vp[n];
        for(auto i : roads){
            vp[i[0]].push_back({i[1], i[2]});
            vp[i[1]].push_back({i[0], i[2]});
        }
        vector<long long>dist(n, 1e18);
        vector<int>ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            long long step = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : vp[node]){
                int adjnode = it.first;
                long long cost = it.second;

                if(step + cost < dist[adjnode]){
                    dist[adjnode] = step + cost;
                    pq.push({step + cost, adjnode});
                    ways[adjnode] = ways[node];
                }
                else if(step + cost == dist[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};