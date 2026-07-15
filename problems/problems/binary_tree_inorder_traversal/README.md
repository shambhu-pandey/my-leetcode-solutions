# 🚀 Binary Tree Inorder Traversal

🔗 **LeetCode Link:**  
https://leetcode.com/problems/binary-tree-inorder-traversal/

---

## 🎯 Difficulty

**Easy**

---

## 🏷️ Tags

Stack, Tree, Depth-First Search, Binary Tree

---

## 📖 Problem Description

Given the root of a binary tree, return the inorder traversal of its nodes' values.

 
Example 1:


Input: root = [1,null,2,3]

Output: [1,3,2]

Explanation:




Example 2:


Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

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
    private:
    void recursiveInOrder(TreeNode* root , vector<int> &arr){
        if(root == nullptr) return;

        recursiveInOrder(root->left , arr);
        arr.push_back(root->val);
        recursiveInOrder(root->right , arr);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        recursiveInOrder(root , arr);
        return arr;
    }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:21:45*
