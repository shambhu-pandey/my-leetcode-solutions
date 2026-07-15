# 🚀 Binary Tree Preorder Traversal

🔗 **LeetCode Link:**  
https://leetcode.com/problems/binary-tree-preorder-traversal/

---

## 🎯 Difficulty

**Easy**

---

## 🏷️ Tags

Stack, Tree, Depth-First Search, Binary Tree

---

## 📖 Problem Description

Given the root of a binary tree, return the preorder traversal of its nodes' values.

 
Example 1:


Input: root = [1,null,2,3]

Output: [1,2,3]

Explanation:




Example 2:


Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [1,2,4,5,6,7,3,8,9]

Explanation:




Example 3:


Input: root = []

Output: []


Example 4:


Input: root = [1]

Output: [1]


 
Constraints:


	The number of nodes in the tree is in the range [0, 100].
	-100 <= Node.val <= 100


 
Follow up: Recursive solution is trivial, could you do it iteratively?


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
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:21:47*
