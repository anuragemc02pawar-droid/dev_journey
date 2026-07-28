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
    int mx=0;
    int sum(TreeNode* root,unordered_map<int,int>& mp){
        if(!root) return 0;
        int l=sum(root->left,mp);
        int r=sum(root->right,mp);
        int sm=l+r+root->val;

        mp[sm]++;

        mx=max(mx,mp[sm]);        
        return sm;
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp;
        sum(root,mp);
        vector<int> ans;
        for(auto it:mp){
            if(it.second==mx){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};