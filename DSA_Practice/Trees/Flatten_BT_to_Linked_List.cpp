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
    TreeNode* prev=NULL;   //this prev shou;dn't get reset to NULL so declare it globally

    void flatten(TreeNode* root) {
        if(root==NULL) return;
        
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left =NULL;
        prev=root;
    }
};