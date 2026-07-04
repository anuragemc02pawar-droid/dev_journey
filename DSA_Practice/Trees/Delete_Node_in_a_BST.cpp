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
 //search key node->left or right can be attached after removing node-> if left(go extreme right adn attach right part) if right(go extreme left and attach left part)
class Solution {
public:
    TreeNode* find(TreeNode* root){
        if(root->right==NULL) return root;
        return find(root->right);
    }
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        TreeNode* rightChild=root->right;
        TreeNode* lastRight = find(root->left);
        lastRight->right=rightChild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val==key){
            return helper(root);            
        }
        TreeNode* dummy=root;
        while(root!=NULL){
            if(root->val>key){
                if(root->left!=NULL && root->left->val==key){
                    root->left=helper(root->left);
                    break;
                }else{
                    root=root->left;
                }
            } else{
                if(root->right!=NULL && root->right->val==key){
                    root->right=helper(root->right);
                    break;
                } else{
                    root=root->right;
                }
            }
        }
        return dummy;
    }
};