class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        words.erase(beginWord);
        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            for (int i = 0; i < word.size(); i++) {
                char og = word[i];
                for (char x = 'a'; x <= 'z'; x++) {
                    word[i] = x;
                    if (words.count(word)) {
                        words.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = og;
            }
        }
        return 0;
    }
};