class TrieNode {
public:
    TrieNode* children[27];
    bool ie=false;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    bool insert(const string &word) {
        TrieNode* current = root;
        for (int i=1;i<word.size();i++) {
            if(word[i]=='/'){
                if(!current->children[26]){
                    current->children[26]=new TrieNode();
                }else if(current->children[26]->ie==true){
                    return 0;
                }
                current=current->children[26];
            }else{
                if (!current->children[word[i]-'a']) {
                    current->children[word[i]-'a'] = new TrieNode();
                }
                current = current->children[word[i]-'a'];
            }
        }
        current->ie=true;
        return 1;
    }
    // void getString(TrieNode* node,string cw,vector<string> &ans){
    //     if(!node) return;
    //     if(node->ie==true) ans.push_back('/'+cw.substr(0,cw.size()-1));
    //     for(int i=0;i<27;i++){
    //         char c;
    //         if(node->children[i]){
    //             if(i==26){
    //                 c='/';
    //             }else{
    //                 c='a'+i;
    //             }
    //             getString(node->children[i],cw+c,ans);
    //         }
    //     }
    // }
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie* trie=new Trie();
        vector<string> ans;
        std::sort(folder.begin(), folder.end(), [](const std::string &a, const std::string &b) {
        return a.length() < b.length();
    });
        for(auto i:folder){
            if(trie->insert(i+'/')) ans.push_back(i);
        }
        // trie->getString(trie->root,"",ans);
        return ans;
    }
};