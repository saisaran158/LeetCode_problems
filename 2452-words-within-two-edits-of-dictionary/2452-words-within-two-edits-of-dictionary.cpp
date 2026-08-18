class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> ans;
        for (int i = 0; i < queries.size(); i++) {
            for (int k = 0; k < dictionary.size(); k++) {
                int diff = 0;
                for (int j = 0; j < queries[i].size(); j++) {
                    if (queries[i][j] != dictionary[k][j]) {
                        diff++;
                    }
                    if (diff>2) break;
                }
                if (diff <= 2) {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};