class TrieNode {
public:
    // unordered_map<char, TrieNode*> children;
    TrieNode* children[26];
    int count=0;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string &word) {
        TrieNode* current = root;
        for (char c : word) {
            if (!current->children[c-'a']) {
                current->children[c-'a'] = new TrieNode();
            }
            current = current->children[c-'a'];
            current->count++;
        }
    }
     
    int sumPrefix(const string &s){
        TrieNode* current = root;
        int i=0;

        for (int j = 0; j < s.length(); j++) {
            current = current->children[s[j]-'a'];
            i+=current->count;
        }
        return i;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        Trie* trie=new Trie();
        for(int i=0;i<words.size();i++){
            trie->insert(words[i]);
        }
        for(int i=0;i<words.size();i++){
            ans.push_back(trie->sumPrefix(words[i]));
        }
        return ans;
    }
};