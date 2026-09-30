class Solution {
public:
    int integerReplacement(int n) {
        queue<pair<long long, long long>>q;
        q.push({n, 0});
        set<long long>s;
        s.insert(n);
        while(!q.empty()){
            long long curr = q.front().first;
            long long steps = q.front().second;
            q.pop();

            if(curr == 1) return steps;

            if(curr % 2 == 0 && !s.count(curr / 2)){
                q.push({curr / 2, steps + 1});
                s.insert(curr / 2);
            }
            else{
                if(!s.count(curr + 1)){
                    s.insert(curr + 1);
                    q.push({curr + 1, steps + 1});
                }
                if(!s.count(curr - 1)){
                    s.insert(curr - 1);
                    q.push({curr - 1, steps + 1});
                }
            }
        }
        return -1;
    }
};