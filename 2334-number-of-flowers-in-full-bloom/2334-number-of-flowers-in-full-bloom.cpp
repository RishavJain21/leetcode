#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pii pair<int,int>
using namespace __gnu_pbds; 

typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        PBDS start,end;
        int cnt=0;
        for(auto i:flowers){
            start.insert({i[0],cnt});
            end.insert({i[1],cnt++});
        }
        vector<int> ans;
        for(auto i:people){
            int a=start.order_of_key({i,cnt});
            int b=end.order_of_key({i,-1});
            // cout<<a<<" "<<b<<endl;
            ans.push_back(a-b);
        }
        return ans;
    }
};