class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        for(int i=1;i<s.length();i+=2){
            if(s[i]!=s[i-1]) ans=ans+1;
        }
        return ans;
    }
};