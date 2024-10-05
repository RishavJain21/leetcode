class Solution {
public:
    bool solve(unordered_map<string,int> w,string s,int m){
        for(int j=0;j<s.size();j+=m){
            string s1=s.substr(j,m);
            if(w.find(s1)!=w.end()){
                if(w[s1]--==0) return false;
            }else return false;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=words.size(),m=words[0].size();
        vector<int> ans;
        unordered_map<string,int>w;
        for(int i=0;i<n;i++){
            w[words[i]]++;
        }
        int i=0;
        while(i+n*m <= s.length()){
            if(solve(w,s.substr(i,n*m),m)) ans.push_back(i);
            i++;
        }
        return ans;
    }
};