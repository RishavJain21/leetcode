class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        int a=0,ans=0;

        for(int i:nums) a=max(a,i);
        vector<int> v(n+a+1,0);
        for(int i:nums)v[i]++;

        for(int i=0;i<v.size();i++){
            if(v[i]>1){
                int c=v[i]-1;
                v[i+1]+=c;
                ans+=c;
            }
        }
        return ans;
    }
};