class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;
        for(auto i:s){
            if(i=='#') {
                if(!s1.empty()) s1.pop();
            }
            else s1.push(i);
        }
        for(auto i:t){
            if(i=='#'){
                if(!s2.empty()) s2.pop();
            }
            else s2.push(i);
        }
        s="";t="";
        while(!s1.empty()){
            char a=s1.top();s1.pop();
            s+=a;
        }
        while(!s2.empty()){
            char a=s2.top();s2.pop();
            t+=a;
        }
        return s==t;
    }
};