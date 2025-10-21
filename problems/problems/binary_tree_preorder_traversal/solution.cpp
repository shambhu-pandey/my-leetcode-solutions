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
    void recursivePreorder(TreeNode* root , vector<int>& ans){
        if(root==NULL){
            return ;
        }
        ans.push_back(root->val);
        recursivePreorder(root->left ,ans);
        recursivePreorder(root->right,ans);
        
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
       recursivePreorder(root , ans);
        return ans;
    }
};