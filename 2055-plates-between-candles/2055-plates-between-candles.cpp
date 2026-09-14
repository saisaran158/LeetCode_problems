class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int count = 0;
        int n = s.size();
        vector<int>prefix(n + 1, 0);
        vector<int>ind;
        for(int i = 0; i < n; i++){
            if(s[i] == '|'){
                ind.push_back(i);
                count++;
            }
        }
        for(int i = 0; i < n; i++){
            if(s[i] == '|'){
                prefix[i] =  max(0, (n - i - count));
                count--;
            }
        }
        for(int x : prefix){
            cout << x << " ";
        }
        cout << endl;
        vector<int>res;
        for(int i = 0; i < queries.size(); i++){
            int start = queries[i][0];
            int end = queries[i][1];
            int leftmost = lower_bound(ind.begin(), ind.end(), start) - ind.begin();
            int rightmost = upper_bound(ind.begin(), ind.end(), end) - ind.begin() - 1;
            if(leftmost < rightmost)
            res.push_back(prefix[ind[leftmost]] - prefix[ind[rightmost]]);
            else
            res.push_back(0);
        }
        return res;
    }
};