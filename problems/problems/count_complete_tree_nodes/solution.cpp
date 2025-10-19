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
    private:
    int inOrder(TreeNode* root , int& ans){
        if(root==NULL){
            return 0;
        }
        inOrder(root->left , ans);
        ans++; // count current node
        inOrder(root->right , ans);

        return ans;
    }
public:
    int countNodes(TreeNode* root) {
        int ans = 0 ;
        inOrder(root , ans);
       
       return ans;
    }
};