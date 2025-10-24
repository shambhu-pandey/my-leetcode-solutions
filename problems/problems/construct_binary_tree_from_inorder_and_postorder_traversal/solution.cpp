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
  void createMapping(vector<int>& inorder , map<int , int>& nodeToIndex, int size){
    for(int i =0; i<size;i++){
        nodeToIndex[inorder[i]]=i;
    }
  }
 TreeNode* solve(vector<int>& inorder, vector<int>& postorder , int& postorderIndex , int inorderStart , int inorderEnd , map<int,int>&nodeToIndex ,int size){
   if(postorderIndex<0 ||inorderStart>inorderEnd){
    return NULL;
   }

   int element = postorder[postorderIndex--];
   TreeNode* root = new TreeNode(element);
   int position = nodeToIndex[element];

 //in case postorder we first right subtree 
   root->right = solve(inorder ,postorder , postorderIndex, position+1 ,inorderEnd , nodeToIndex , size);
     root->left = solve(inorder ,postorder , postorderIndex, inorderStart ,position-1 , nodeToIndex , size);
   
   return root;
 }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        int postorderIndex = size-1;
        int inorderStart =0;
        int inorderEnd=size-1;

        map<int , int> nodeToIndex;
        createMapping(inorder , nodeToIndex ,size);
        TreeNode* ans= solve(inorder , postorder , postorderIndex , inorderStart,inorderEnd , nodeToIndex , size);

        return ans;
    }
};