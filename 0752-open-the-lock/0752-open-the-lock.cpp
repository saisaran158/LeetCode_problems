class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, int> mp;
        for (string x : deadends) {
            mp[x]++;
        }
        if (mp.count("0000"))
            return -1;
        int nw;
        queue<pair<string, int>> q;
        set<string> s;
        string next;
        s.insert("0000");
        q.push({"0000", 0});
        while (!q.empty()) {
            string curr = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (curr == target)
                return steps;

            for (int i = 0; i < 4; i++) {
                if (curr[i] == '0') {
                    next = curr;
                    next[i] = '9';
                    if (mp.find(next) == mp.end() && !s.count(next)) {
                        s.insert(next);
                        q.push({next, steps + 1});
                    }
                } else {
                    next = curr;
                    nw = (curr[i] - '0' - 1); next[i] = nw + '0';
                    if (mp.find(next) == mp.end() && !s.count(next)) {
                        q.push({next, steps + 1});
                        s.insert(next);
                    }
                }
                next = curr;
                nw = (curr[i] - '0' + 1) % 10;
                next[i] = nw + '0';
                if (mp.find(next) == mp.end() && !s.count(next)) {
                    q.push({next, steps + 1});
                    s.insert(next);
                }
            }
        }
        return -1;
    }
};