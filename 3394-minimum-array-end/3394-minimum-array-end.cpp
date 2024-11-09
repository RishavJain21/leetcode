class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans=x;
        long long a=1;
        n--;
        while(n){
            if(!(x&a)){
                ans=ans|(n&1)*a;
                n=n>>1;
            }
            a=a<<1;
        }
        return ans;
    }
};