class Solution {
public:

    int diff(string time1,string time2){
        int a=stoi(time1.substr(0,2))*60+stoi(time1.substr(3,2));
        int b=stoi(time2.substr(0,2))*60+stoi(time2.substr(3,2));
        return min(b-a,1440-b+a);
    }
    int findMinDifference(vector<string>& tp) {
        sort(tp.begin(),tp.end());
        int ans=INT_MAX;
        int n=tp.size();
        for(int i=1;i<n;i++){
            ans=min(ans,diff(tp[i-1],tp[i]));
        }
        ans=min(ans,diff(tp[0],tp[n-1]));
        return ans;
    }
};