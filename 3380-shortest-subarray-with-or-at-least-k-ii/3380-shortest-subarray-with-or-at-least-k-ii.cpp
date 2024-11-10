class Solution {
public:

    void solve1(int n,vector<int>& v){
        int i=0;
        while(n){
            if(n&1)v[i]++;
            i++;
            n=n>>1;
        }
    }
    void solve2(int n,vector<int>& v){
        int i=0;
        while(n){
            if(n&1)v[i]--;
            i++;
            n=n>>1;
        }
    }

    int solve4(vector<int>&v){
        int a=0;
        for(int i=0;i<31;i++){
            a=a+(v[i]>0) * (1<<i);
        }
        return a;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> v(31,0);
        int i=0,j=0;
        int o=0,ans=nums.size()+1;
        while(j<nums.size()){
            solve1(nums[j],v);
            while(i<=j && solve4(v)>=k){
                ans=min(ans,(j-i+1));
                solve2(nums[i],v);
                i++;
            }
            j++;
        }
        return ans==nums.size()+1?-1:ans;
    }
};