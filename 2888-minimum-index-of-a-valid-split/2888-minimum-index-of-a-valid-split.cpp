class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int cnt=0,el;

        vector<int> v1(n,-1);
        for(int i=0;i<n;i++){
            if(cnt==0){
                el=nums[i];
                cnt++;
            }else if(nums[i]==el) cnt++;
            else cnt--;
        }
        cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el) cnt++; 
        }
        if(cnt*2<=n) return -1;
        else{
            int c=0;
            for(int i=0;i<n-1;i++){
                if(nums[i]==el) c++;
                if(c*2>i+1 && (cnt-c)*2>(n-i-1)) return i;
            }
        }
        return -1;
    }
};