class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int curr = 0;
        vector<int>res;
        for (char a : seq) {
            if (a == '(') {
                curr++;
                if(curr % 2 == 1) res.push_back(0);
                else res.push_back(1);
            } else {
                if(curr % 2 == 0) res.push_back(1);
                else res.push_back(0);
                curr--;
            }
        }
        return res;
    }
};