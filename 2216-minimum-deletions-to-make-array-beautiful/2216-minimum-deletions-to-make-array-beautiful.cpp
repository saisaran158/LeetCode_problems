class Solution {
public:
    int minDeletion(vector<int>& nums) {
        stack<pair<int, int>>st;
        int c = 0;
        for(int i = 0; i < nums.size(); i++){
            if(st.empty()){
                st.push({nums[i], i - c});
            }
            else if(!st.empty() && st.top().first == nums[i] && st.top().second % 2 == 0){
                c++;
            }
            else{
                st.push({nums[i], i - c});
            }
        }
        if(st.size() % 2 == 1){
            c++;
        }
        return c;
    }
};