class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int index=0,i=0,temp;
        while(i<n){
            while(i<n && nums[i]==temp){
                i++;
            }
            if(i<n){
                nums[index]=nums[i];
                temp=nums[i];
                index++;
            }
            i++;
        }
        return index;
    }
};