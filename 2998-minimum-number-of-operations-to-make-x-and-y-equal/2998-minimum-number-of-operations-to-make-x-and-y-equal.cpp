class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        queue<pair<int, int>>q;
        q.push({x, 0});
        set<int>s;
        s.insert(x);
        while(!q.empty()){
            int n = q.front().first;
            int step = q.front().second;
            q.pop();
            if(n == y) return step;
            if(n % 11 == 0 && !s.count(n / 11)){
                s.insert(n / 11);
                q.push({n / 11, step + 1});
            }

            if(n % 5 == 0 && !s.count(n / 5)){
                s.insert(n / 5);
                q.push({n / 5, step + 1});
            }

            if(!s.count(n + 1)){
                s.insert(n + 1);
                q.push({n + 1, step + 1});
            }

            if(!s.count(n - 1)){
                s.insert(n - 1);
                q.push({n - 1, step + 1});
            }
        }
        return 0;
    }
};