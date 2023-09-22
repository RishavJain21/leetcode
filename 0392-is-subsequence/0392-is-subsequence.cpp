class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ind=0;
        if(s.length()==0) return 1;
        for(int i=0;i<t.length();i++){
            if(t[i]==s[ind]) ind++;
            if(ind==s.length()) return 1;
        }
        return 0;
    }
};