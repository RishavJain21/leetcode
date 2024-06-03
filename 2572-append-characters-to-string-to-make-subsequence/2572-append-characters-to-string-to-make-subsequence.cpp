class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans=t.length();
        int i=0,j=0;
        while(i<s.length() && j<t.length()){
            if(s[i]==t[j]){
                j++;ans--;
            }
            i++;
        }
        return ans;
    }
};