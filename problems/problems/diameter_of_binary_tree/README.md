# 🚀 Diameter of Binary Tree

🔗 **LeetCode Link:**  
https://leetcode.com/problems/diameter-of-binary-tree/

---

## 🎯 Difficulty

**Easy**

---

## 🏷️ Tags

Tree, Depth-First Search, Binary Tree

---

## 📖 Problem Description

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 
Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].


Example 2:


Input: root = [1,2]
Output: 1


 
Constraints:


	The number of nodes in the tree is in the range [1, 104].
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
    pair<int , int> diameterFast(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }

        pair<int, int> left =  diameterFast(root->left);
        pair<int , int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second +1;

        pair<int , int> ans;
        ans.first = max(op1 , max(op2 , op3));
        ans.second =  max(left.second , right.second)+1;

        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast(root).first -1;
    }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:22:32*
