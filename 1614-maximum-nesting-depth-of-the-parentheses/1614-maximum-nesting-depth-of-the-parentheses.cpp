class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int max=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
                if(max<count){
                    max=count;
                }
            }
            if(s[i]==')'){
                count--;
            }
        }
        return max;
    }
};