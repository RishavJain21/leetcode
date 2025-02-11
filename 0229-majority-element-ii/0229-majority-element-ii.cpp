class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a=INT_MIN,b=INT_MIN;
        int c1=0,c2=0;
        for(int i=0;i<nums.size();i++){
            if(c1==0 && nums[i]!=b){
                c1++;
                a=nums[i];
            }else if(c2==0 && nums[i]!=a){
                c2++;
                b=nums[i];
            }else if(nums[i]==a)c1++;
            else if(nums[i]==b)c2++;
            else{
                c1--;
                c2--;
            }
        }
        int c=int(nums.size()/3)+1;
        c1=0,c2=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==a)c1++;
            if(nums[i]==b)c2++;
        }
        if(c1>=c) ans.push_back(a);
        if(c2>=c) ans.push_back(b);

        return ans;
    }
};