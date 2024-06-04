class Solution {
public:
    int longestPalindrome(string s) {
        int c=0;
        map<char,int> mp;
        for(auto i:s) mp[i]++;

        for(auto i:mp){
            c+=i.second/2*2;
            if(c%2==0 && i.second%2==1) c+=1;
        }
        return c;
    }
};