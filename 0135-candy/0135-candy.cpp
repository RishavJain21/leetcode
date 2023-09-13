class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n==1) return 1;
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++){
            a[i].first=ratings[i];
            a[i].second=i;
        }
        sort(a.begin(),a.end());
        vector<int> v(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            int mi = a[i].second;
            if(mi==0){
                if(ratings[mi+1]<ratings[mi]) v[mi]=v[mi+1]+1;
                else v[mi]=1;
            }
            else if(mi==n-1){
                if(ratings[mi-1]<ratings[mi]) v[mi]=v[mi-1]+1;
                else v[mi]=1;
            }
            else{
                if(ratings[mi]<ratings[mi+1] && ratings[mi]<ratings[mi-1]) v[mi]=1;
                else if(ratings[mi]>ratings[mi+1] && ratings[mi]>ratings[mi-1]){
                    v[mi]=max(v[mi-1],v[mi+1])+1;
                }
                else if(ratings[mi]>ratings[mi+1] ) {
                    v[mi]=v[mi+1]+1;
                }
                else if(ratings[mi]>ratings[mi-1]){
                    v[mi]=v[mi-1]+1;
                }
                else v[mi]=1;
            }
            ans+=v[mi];
        }
        return ans;
    }
};