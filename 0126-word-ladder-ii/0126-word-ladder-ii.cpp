class Solution {
public:
    void dfs(string beginWord, string word, vector<vector<string>>& ans, vector<string>& seq, unordered_map<string, int>& mp){
        
        if(word == beginWord){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int step1 = mp[word];
        for(int i = 0; i < word.size(); i++){
            char og = word[i];
            for(char z ='a'; z <='z'; z++){
                word[i] = z;
                if(mp.find(word) != mp.end() && mp[word] + 1 == step1){
                    seq.push_back(word);
                    dfs(beginWord, word, ans, seq, mp);
                    seq.pop_back();
                } 
            }
            word[i] = og;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, int>mp;
        mp[beginWord] = 0;
        dict.erase(beginWord);
        queue<pair<string, int>>q;
        q.push({beginWord, 0});
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            for(int i = 0; i < word.size(); i++){
                char og = word[i];

                for(char z ='a'; z <= 'z'; z++){
                    word[i] = z;
                    if(dict.count(word)){
                        mp[word] = steps + 1;
                        dict.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = og;
            }
        }
        vector<vector<string>>ans;
        vector<string>seq;
        seq.push_back(endWord);
        if(mp.find(endWord) != mp.end()){
            dfs(beginWord, endWord, ans, seq, mp);
        }
        return ans;
    }
};