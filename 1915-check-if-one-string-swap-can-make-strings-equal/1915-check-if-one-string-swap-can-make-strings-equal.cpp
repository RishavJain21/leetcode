class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.length()!=s2.length()) return 0;
        vector<int> v1(26,0),v2(26,0);
        int c=0;
        for(int i=0;i<s1.length();i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
            if(s1[i]!=s2[i])c++;
            if(c>2) return 0;
        }
        return v1==v2;
    }
};