/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        if(traversal.size()==0) return NULL;
        vector<TreeNode*> v(1001,NULL);
        int i=0;
        string s="";
        while(i<traversal.length() && traversal[i]!='-'){
                s+=traversal[i];
                i++;
            }
        TreeNode* root=new TreeNode(stoi(s));
        v[0]=root;
        while(i<traversal.length()){
            string s="";
            int c=0;
            while(traversal[i]=='-'){
                c++;
                i++;
            }
            while(i<traversal.length() && traversal[i]!='-'){
                s+=traversal[i];
                i++;
            }
            TreeNode* temp=new TreeNode(stoi(s));
            if(v[c-1]->left==NULL){
                v[c-1]->left=temp;
            }else{
                v[c-1]->right=temp;
            }
            v[c]=temp;
        }
        return root;
    }
};