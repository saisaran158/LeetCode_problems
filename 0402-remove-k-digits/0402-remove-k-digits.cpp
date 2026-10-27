class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        for(int i = 0; i < num.size(); i++){
            while(!s.empty() && s.top() > num[i] && k > 0){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        string res = "";
        while(!s.empty()){
            res += s.top();
            s.pop();
        }
        while(res.size() > 0 && res[res.size() - 1] == '0'){
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        while(k > 0 && res.size() > 0){
            res.pop_back();
            k--;
        }
        if(res.size() == 0) return "0";
        return res;
    }
};