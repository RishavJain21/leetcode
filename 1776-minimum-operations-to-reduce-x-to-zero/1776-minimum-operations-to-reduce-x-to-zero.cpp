class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int t=0;
        for(int i=0;i<n;i++) t+=nums[i];
        if(x>t) return -1;
        int req=t-x;
        if(req==0) return n;
        int ans=INT_MAX;
        int l=0,h=0,s=0;
        while(h<n){
            s+=nums[h];
            h++;
            while(s>req && l<n){
                s-=nums[l];
                l++;
            }
            if(s==req){
                ans=min(ans,n-(h-l));
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};