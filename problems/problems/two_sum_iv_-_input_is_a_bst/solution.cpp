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

 // 2 node ka pair batana hai  , ki target value ke equal hai ki nhi agar sum karenge 2 node ko toh
 // toh hm isko inorder find kar ke kar sakte hai because , inorder sorted order me data return karta hai 
 // uske baad 2 pinter wala approach lga lenge inorder ke first element 'i' and last element ko 'j' maan lenge  aur sum karayenge aur agar sum chota hoga target se toh i++ kra denge ya agar sum bda hoga toh j--
 // aise hi hme ek point par mil jaayega toh true return  ya nhi milege toh false 
class Solution {
public:
    TreeNode* inorderTraversal(TreeNode* root , vector<int>&inorder){
        if(root==NULL){
            return NULL;
        }
        inorderTraversal(root->left , inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right , inorder);
        return root;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inorderTraversal(root ,inorder);

        int i = 0 ;
        int j = inorder.size()-1;

        while(i<j){
            int sum = inorder[i]+ inorder[j];

            if(sum==k){
                return true;
            }
            if(sum>k){
                j--;
            }
            if(sum<k){
                i++;
            }
        }
        return false;
    }
};