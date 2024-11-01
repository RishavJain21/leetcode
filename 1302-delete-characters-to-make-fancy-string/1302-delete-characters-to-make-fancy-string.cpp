class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()<3) return s;
        int j=2,i=2;
        while(i<s.length()){
            if(s[i]!=s[j-1] || s[i]!=s[j-2]){
                s[j]=s[i];
                j++;
            }
            i++;
        }
        s.resize(j);
        return s;
    }
};