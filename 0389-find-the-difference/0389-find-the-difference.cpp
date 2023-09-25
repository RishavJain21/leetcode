class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        int sa=0,ta=0;
        
        for(int i=0;i<s.size();i++){
            sa =sa + s[i];
        }
        for(int i=0;i<t.size();i++){
            ta =ta + t[i];
        }
        
        return ta-sa;
    }
};