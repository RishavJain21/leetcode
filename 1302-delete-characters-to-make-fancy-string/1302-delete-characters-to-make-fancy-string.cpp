class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()<3) return s;
        string ans="";
        ans=ans+s[0]+s[1];
        int j=1,i=2;
        while(i<s.length()){
            if(s[i]==ans[j] && s[i]==ans[j-1]){
                i++;
                continue;
            }
            ans.push_back(s[i]);
            i++;j++;
        }
        return ans;
    }
};