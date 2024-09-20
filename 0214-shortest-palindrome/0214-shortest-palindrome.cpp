class Solution {
public:
    const int MOD = 1e9 + 7;
    const int p = 31;
    int lPP(string s){
        int n = s.length();
        long long fh=0,rh=0;
        long long a=1;
        int lpp=0;
        for(int i=0;i<n;i++){
            fh=(fh+(s[i]-'a'+1)*a)%MOD;
            rh=(rh*p+(s[i]-'a'+1))%MOD;

            a=(a*p)%MOD;
            if(fh==rh){
                lpp=i;
            }
        }
        return lpp;
    }
    string shortestPalindrome(string s) {
        int j=lPP(s);
        if(s.length()<2 || j==s.length()-1) return s;
        string a=s.substr(j+1,s.length()-j);
        reverse(a.begin(),a.end());
        return a+s;
    }
};