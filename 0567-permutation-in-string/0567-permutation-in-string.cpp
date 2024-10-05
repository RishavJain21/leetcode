class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m =s2.size();
        
        if(n>m) return false;
        
        vector<int> a(26,0),b(26,0);
        
        for(int i=0;i<n;i++){
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
        }
        for(int i=n;i<m;i++){
            if(a==b) return true;
            b[s2[i]-'a']++;
            b[s2[i-n]-'a']--;
        }
        if(a==b) return true;
        return false;
    }
};