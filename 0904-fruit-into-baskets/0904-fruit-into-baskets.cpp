class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int>mp;
        int maxTrees = 0;
        int left = 0;
        for(int right = 0; right < fruits.size(); right++){
            mp[fruits[right]]++;
            while(mp.size() > 2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            maxTrees = max(maxTrees, right - left + 1);
        }
        return maxTrees;
    }
};