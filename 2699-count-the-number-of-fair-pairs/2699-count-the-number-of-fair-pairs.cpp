class Solution {
public:
    int solve1(vector<int>& nums,int n,int i){
        int j=nums.size()-1,mid,ans=-1;
        while(i<=j){
            mid=i+(j-i)/2;
            if(nums[mid]>=n){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
    int solve2(vector<int>& nums,int n,int i){
        int j=nums.size()-1,mid,ans=-1;
        while(i<=j){
            mid=i+(j-i)/2;
            if(nums[mid]<=n){
                ans=mid;
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        int a,b;
        for(int i=0;i<nums.size();i++){
            a=solve1(nums,lower-nums[i],i+1);
            b=solve2(nums,upper-nums[i],i+1);
            if(a!=-1 && b!=-1 && a<=b) ans=ans+(b-a+1);
        }
        return ans;
    }
};