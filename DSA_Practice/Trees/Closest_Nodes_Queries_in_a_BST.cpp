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
    vector<int> arr;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }

    void find(vector<int>& arr, int q, int& pred, int& succ){
        int l=0;int r=arr.size()-1;
        pred=succ=-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(arr[mid]==q){
                pred=succ=arr[mid];
                return;
            }
            else if(arr[mid]<q){
                pred=arr[mid];
                l=mid+1;
            }
            else{
                succ=arr[mid];
                r=mid-1;
            }
           
        }
        return;
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n=queries.size();
        inorder(root);
        vector<vector<int>> result(n);
        int pred=-1,succ=-1;
        for(int i=0;i<n;i++){
            find(arr,queries[i],pred,succ);
            result[i]={pred,succ};
        }
        
        return result;
    }
};