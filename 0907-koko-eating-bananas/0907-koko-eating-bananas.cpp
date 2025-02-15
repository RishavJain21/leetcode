class Solution {
public:
    long long solve(vector<int>&piles,int k){
        long long a=0;
        for(auto i:piles){
            a+=ceil(i/(double)k);
        }
        return a;
    }
    int minEatingSpeed(vector<int>& piles, int i) {
        int l=1,h=1e9;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            long long a=solve(piles,mid);
            if(a<=(long long)i){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};