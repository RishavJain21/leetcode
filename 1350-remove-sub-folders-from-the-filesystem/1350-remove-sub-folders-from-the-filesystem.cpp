class TrieNode {
public:
    // Array to store pointers to child nodes; 26 letters + 1 for '/'
    TrieNode* children[27];
    bool ie = false; // Indicates the end of a complete path (a valid folder)
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Function to insert a folder path into the Trie
    bool insert(const string &word) {
        TrieNode* current = root;
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == '/') {
                // Move to or create a node representing the '/' character
                if (!current->children[26]) {
                    current->children[26] = new TrieNode();
                } else if (current->children[26]->ie == true) {
                    // If a complete folder path ends here, the current word is a sub-folder
                    return false;
                }
                current = current->children[26];
            } else {
                // Move to or create a node for the current character
                if (!current->children[word[i] - 'a']) {
                    current->children[word[i] - 'a'] = new TrieNode();
                }
                current = current->children[word[i] - 'a'];
            }
        }
        // Mark the end of a valid folder path
        current->ie = true;
        return true;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie* trie = new Trie(); // Create a Trie to store folder paths
        vector<string> ans;
        
        // Sort folders by length to ensure we process top-level folders first
        std::sort(folder.begin(), folder.end(), [](const std::string &a, const std::string &b) {
            return a.length() < b.length();
        });

        // Iterate through each folder
        for (auto i : folder) {
            // Try to insert the folder path into the Trie
            if (trie->insert(i + '/')) {
                ans.push_back(i); // If successful, it's not a sub-folder, add to the result
            }
        }

        return ans;
    }
};
