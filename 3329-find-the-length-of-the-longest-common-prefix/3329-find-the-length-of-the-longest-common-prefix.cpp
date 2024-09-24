class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
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
        }
        current->isEndOfWord = true;
    }

    // vector<int> search(const string &s, int i) {
    //     vector<int> matchedIndices;
    //     TrieNode* current = root;

    //     for (int j = i; j < s.length(); j++) {
    //         if (current->children.find(s[j]) == current->children.end()) {
    //             break;
    //         }
    //         current = current->children[s[j]];
    //         if (current->isEndOfWord) {
    //             matchedIndices.push_back(j + 1);
    //         }
    //     }
    //     return matchedIndices;
    // }
    int longestPrefix(const string &s){
        TrieNode* current = root;
        int i=0;

        for (int j = 0; j < s.length(); j++) {
            if (current->children.find(s[j]) != current->children.end()) {
                i++;
                current = current->children[s[j]];
                // if (current->isEndOfWord) {
                //     lp=i;
                // }
            }else break;
        }
        return i;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans=0;
        Trie* trie=new Trie();
        for(int i=0;i<arr1.size();i++){
            trie->insert(to_string(arr1[i]));
        }
        for(int i=0;i<arr2.size();i++){
            ans=max(ans,trie->longestPrefix(to_string(arr2[i])));
        }
        return ans;
    }
};