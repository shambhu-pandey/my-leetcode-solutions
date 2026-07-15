# 🚀 Construct Binary Tree from Inorder and Postorder Traversal

🔗 **LeetCode Link:**  
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

---

## 🎯 Difficulty

**Medium**

---

## 🏷️ Tags

Array, Hash Table, Divide and Conquer, Tree, Binary Tree

---

## 📖 Problem Description

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 
Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]


Example 2:


Input: inorder = [-1], postorder = [-1]
Output: [-1]


 
Constraints:


	1 <= inorder.length <= 3000
	postorder.length == inorder.length
	-3000 <= inorder[i], postorder[i] <= 3000
	inorder and postorder consist of unique values.
	Each value of postorder also appears in inorder.
	inorder is guaranteed to be the inorder traversal of the tree.
	postorder is guaranteed to be the postorder traversal of the tree.



---

## 💻 My Solution

```cpp
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
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:20:53*
