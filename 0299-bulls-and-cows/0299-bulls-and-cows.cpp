class Solution {
public:
    string getHint(string secret, string guess) {
        vector<pair<int,int>> v(10,{0,0});
        int x=0,y=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]) x++;
            else {
                v[(secret[i]-'0')].first++;
                v[(guess[i]-'0')].second++;
            }
        }
        for(auto i:v){
            y+=min(i.first,i.second);
        }
        // cout<<x<<" "<<y<<endl;
        return to_string(x)+"A"+to_string(y)+"B";
    }
};