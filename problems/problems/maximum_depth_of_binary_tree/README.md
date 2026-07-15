# 🚀 Maximum Depth of Binary Tree

🔗 **LeetCode Link:**  
https://leetcode.com/problems/maximum-depth-of-binary-tree/

---

## 🎯 Difficulty

**Easy**

---

## 🏷️ Tags

Tree, Depth-First Search, Breadth-First Search, Binary Tree

---

## 📖 Problem Description

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 
Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3


Example 2:


Input: root = [1,null,2]
Output: 2


 
Constraints:


	The number of nodes in the tree is in the range [0, 104].
	-100 <= Node.val <= 100



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
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        int val = max(left , right)+1 ;

        return val;
    }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:22:34*
