class Solution {
public:
    int racecar(int target) {
        queue<pair<pair<long long, long long>, long long>> q;
        q.push({{0, 1}, 0});
        int limit = 2 * target;
        set<pair<long long, long long>> s;
        s.insert({0, 1});
            while (!q.empty()) {
                long long pos = q.front().first.first;
                long long speed = q.front().first.second;
                long long t = q.front().second;
                q.pop();
                if (pos == target) {
                    return t;
                }
                if (speed + pos <= limit && speed + pos >= -limit && !s.count({speed + pos, speed *2})) {
                    s.insert({speed + pos, speed * 2});
                    q.push({{speed + pos, speed * 2}, t + 1});
                }
                if (speed < 1){
                    if(!s.count({pos, 1})){
                        s.insert({pos, 1});
                        q.push({{pos, 1}, t + 1});
                    }
                }
                else if(!s.count({pos, -1})){
                    s.insert({pos, -1});
                    q.push({{pos, -1}, t + 1});
                }
            }
            return 0;
    }
    };