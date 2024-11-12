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
        vector<vector<int>> v;
        for(int i=1;i<items.size();i++){
            if(items[i][0]!=items[i-1][0]) v.push_back(items[i-1]);
        }
        v.push_back(items[items.size()-1]);
        for(int i=1;i<v.size();i++){
            v[i][1]=max(v[i][1],v[i-1][1]);
        }
        vector<int> ans(q.size(),0);
        for(int i=0;i<q.size();i++){
            ans[i]=solve(v,q[i]);
        }
        return ans;
    }
};