class Solution {
public:
    const int MOD = 1e9 + 7;
    const int BASE = 31;
    int lPP(string s){
        int n = s.length();
        long long forward_hash = 0, reverse_hash = 0;
        long long power = 1;
        int longest_palindrome_len = 0;

        for (int i = 0; i < n; i++) {
            forward_hash = (forward_hash * BASE + (s[i] - 'a' + 1)) % MOD;

            reverse_hash = (reverse_hash + (s[i] - 'a' + 1) * power) % MOD;

            power = (power * BASE) % MOD;

            if (forward_hash == reverse_hash) {
                longest_palindrome_len = i ;
            }
        }
        return longest_palindrome_len;
    }
    string shortestPalindrome(string s) {
        int j=lPP(s);
        if(s.length()<2 || j==s.length()-1) return s;
        string a=s.substr(j+1,s.length()-j);
        reverse(a.begin(),a.end());
        return a+s;
    }
};