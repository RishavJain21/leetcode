class Solution {
public:
    bool solve(vector<int>& pos,int m,int mid){
        int temp=pos[0];
        m--;
        for(int  i=1;i<pos.size();i++){
            if(pos[i]-temp<mid) continue;
            m--;
            temp=pos[i];
        }
        return m<=0;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int ans;
        int l=1,h=pos[pos.size()-1];

        while(l<=h){
            int mid=l+(h-l)/2;

            if(solve(pos,m,mid)){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};