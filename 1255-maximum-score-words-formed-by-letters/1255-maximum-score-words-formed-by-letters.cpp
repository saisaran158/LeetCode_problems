class Solution {
public:
    int rec(int i, int& n, vector<string>& words, unordered_map<char, int> mp, vector<int>& score){
        if(i == n) return 0;

        int scores = 0;
        int flag = 0;
        unordered_map<char, int>copy = mp;
        for(int j = 0; j < words[i].size(); j++){
            if(mp[words[i][j]] >= 1){
                scores += score[words[i][j] - 'a'];
                mp[words[i][j]]--;
            }
            else{
                flag = 1;
                break;
            }
        }
        int take = 0; 
        if(flag == 0){
            take = scores + rec(i + 1, n, words, mp, score);
            for(int k = 0; k < words[i].size(); k++){
                mp[words[i][k]]++;
            }
        }
        int nontake = rec(i + 1, n, words, copy, score);

        return max(take, nontake);

    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        unordered_map<char, int>mp;
        for(char x : letters){
            mp[x]++;
        }
        return rec(0, n, words, mp, score);
    }
};