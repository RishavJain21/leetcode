class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    // bool isEndOfWord;
    int count=0;
    // TrieNode() {
    //     isEndOfWord = false;
    // }
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
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
            current->count++;
        }
    }
     
    int sumPrefix(const string &s){
        TrieNode* current = root;
        int i=0;

        for (int j = 0; j < s.length(); j++) {
            if (current->children.find(s[j]) != current->children.end()) {
                current = current->children[s[j]];
                i+=current->count;
            }else break;
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