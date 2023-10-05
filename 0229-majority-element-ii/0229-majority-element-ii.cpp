class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        int cnt1=0,cnt2=0;
        int e1=INT_MIN,e2=INT_MIN;

        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=e2){
                e1=nums[i];
                cnt1++;
            }else if(cnt2==0 && nums[i]!=e1){
                e2=nums[i];
                cnt2++;
            }else if(nums[i]==e1) cnt1++;
            else if(nums[i]==e2) cnt2++;
            else{
                cnt1--;cnt2--;
            }
        }
        cnt1=0;cnt2=0;

        for(int i=0;i<n;i++){
            if(nums[i]==e1) cnt1++;
            else if(nums[i]==e2) cnt2++;
        }

        int a=(int)n/3 + 1;
        if(cnt1>=a) ans.push_back(e1);
        if(cnt2>=a) ans.push_back(e2);

        return ans;
    }
};