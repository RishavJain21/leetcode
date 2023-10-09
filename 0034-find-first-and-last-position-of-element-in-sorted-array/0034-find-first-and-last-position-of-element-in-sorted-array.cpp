class Solution {
public:
    int bS(vector<int>& nums, int target,int l,int h){
        while(h>=l){
            int mid=l+(h-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) return bS(nums,target,l,mid-1);
            else return bS(nums,target,mid+1,h);
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(bS(nums,target,0,nums.size()-1)==-1){
            return {-1,-1};
        }
        else{
            int a=bS(nums,target,0,nums.size()-1),b=bS(nums,target,0,nums.size()-1);
            while(a>0){
                if(nums[a]==nums[a-1]) a--;
                else break;
            }
            while(b<nums.size()-1){
                if(nums[b]==nums[b+1]) b++;
                else break;
            }
            return {a,b};
        }
        return {-1,-1};
    }
};