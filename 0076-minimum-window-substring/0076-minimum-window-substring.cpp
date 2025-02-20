class Solution {
public:
    bool solve(vector<int> &a,vector<int> &b){
        for(int i=0;i<58;i++){
            if(a[i]<b[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int l=0,r=0;
        int start=0,minLength=INT_MAX;
        if(s.length()<t.length()) return "";
        vector<int> a(58,0),b(58,0);
        for(auto i:t){
            b[i-'A']++;
        }
        while(r<s.length()){
            a[s[r]-'A']++;
            
            while(solve(a,b) && l<=r){
                if(minLength==INT_MAX || r-l+1<minLength){
                    start=l;
                    minLength=r-l+1;
                }
                a[s[l++]-'A']--;
            }
            r++;  
        }
        return minLength==INT_MAX?"":s.substr(start,minLength);
    }
};