class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<pair<int,int>> st1,st2;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(st1.empty() || (!st1.empty() && nums[i]<st1.top().first)){
                st1.push(make_pair(nums[i],i));
            }else{
                while(!st1.empty() && nums[i]>=st1.top().first){
                    auto t2=st1.top();
                    ans=max(ans,i-t2.second);
                    st2.push(t2);
                    st1.pop();
                }
                while(!st2.empty()){
                    auto t3=st2.top();
                    st1.push(t3);
                    st2.pop();
                }
            }
        }
        return ans;
    }
};