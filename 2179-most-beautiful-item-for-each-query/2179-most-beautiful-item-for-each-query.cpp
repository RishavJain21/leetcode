class Solution {
public:
    int solve(vector<vector<int>>& v,int n){
        int i=0,j=v.size()-1,mid,ans=0;
        while(i<=j){
            mid=i+(j-i)/2;
            if(v[mid][0]<=n){
                ans=v[mid][1];
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& q) {
        sort(items.begin(),items.end());
        int j=0;
        for(int i=1;i<items.size();i++){
            if(items[i][0]!=items[i-1][0]) items[j++]=items[i-1];
        }
        items[j++]=items[items.size()-1];
        items.resize(j);
        for(int i=1;i<items.size();i++){
            items[i][1]=max(items[i][1],items[i-1][1]);
        }
        vector<int> ans(q.size(),0);
        for(int i=0;i<q.size();i++){
            ans[i]=solve(items,q[i]);
        }
        return ans;
    }
};