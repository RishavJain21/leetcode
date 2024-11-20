class Solution {
public:
    int takeCharacters(string s, int k) {
        int ans=0;
        int a=0,b=0,c=0;
        for(auto i:s){
            if(i=='a')a++;
            else if(i=='b')b++;
            else c++;
        }
        if(a<k || b<k || c<k) return -1;
        vector<int> w(3,0);
        int l=0;
        for(int r=0;r<s.length();r++){
            w[s[r]-'a']++;
            while(l<=r && (a-w[0]<k || b-w[1]<k || c-w[2]<k)){
                w[s[l]-'a']--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return s.length()-ans;
    }
};