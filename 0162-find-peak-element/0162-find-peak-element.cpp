class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        if(nums.size()==1) return 0;
        while(l<=h){
            int mid=l+(h-l)/2;

            if(mid==0){
                if(nums[mid]>nums[mid+1]) return mid;
                l=mid+1;
            }else if(mid==nums.size()-1){
                if(nums[mid]>nums[mid-1]) return mid;
                h=mid-1;
            }else{
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                    return mid;
                }else if(nums[mid]>nums[mid-1]) l=mid+1;
                else h=mid-1;
            }
        }
        return -1;
    }
};