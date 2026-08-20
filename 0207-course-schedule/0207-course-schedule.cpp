class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        for (auto i : prerequisites) {
            indegree[i[1]]++;
        }
        vector<int> vp[numCourses];
        for (auto it : prerequisites) {
            vp[it[0]].push_back(it[1]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto a : vp[node]){
                indegree[a]--;
                if(indegree[a] == 0)
                q.push(a);
            }
        }
        return topo.size() == numCourses;
    }
};