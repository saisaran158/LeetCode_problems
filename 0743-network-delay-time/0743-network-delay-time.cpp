class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        pq.push({0, k});
        vector<pair<int, int>>vp[n + 1];
        for(auto i : times){
            vp[i[0]].push_back({i[1],i[2]});
        }
        while(!pq.empty()){
            int step = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : vp[node]){
                int adjnode = it.first;
                int cost = it.second;

                if(step + cost < dist[adjnode]){
                    dist[adjnode] = step + cost;
                    pq.push({cost + step, adjnode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i < dist.size(); i++){
            if(dist[i] == 1e9) return -1;
            if(dist[i] > ans){
                ans = dist[i];
            }
        }
        return ans;
    }
};