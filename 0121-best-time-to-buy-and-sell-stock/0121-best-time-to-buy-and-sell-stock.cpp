class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>mi){
                ans=max(ans,prices[i]-mi);
            }
            mi=min(mi,prices[i]);
        }

        return ans;
    }
};