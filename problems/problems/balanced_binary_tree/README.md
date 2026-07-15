# 🚀 Balanced Binary Tree

🔗 **LeetCode Link:**  
https://leetcode.com/problems/balanced-binary-tree/

---

## 🎯 Difficulty

**Easy**

---

## 🏷️ Tags

Tree, Depth-First Search, Binary Tree

---

## 📖 Problem Description

Given a binary tree, determine if it is height-balanced.

 
Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true


Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false


Example 3:


Input: root = []
Output: true


 
Constraints:


	The number of nodes in the tree is in the range [0, 5000].
	-104 <= Node.val <= 104



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
    pair<bool , int> isBalancedFast(TreeNode* root){
     if(root == NULL){
        return {true , 0};
     }

     pair<bool , int> left = isBalancedFast(root->left);
     pair<bool , int> right = isBalancedFast(root->right);

     int leftAns= left.first;
     int rightAns = right.first;

     int difference = abs(left.second- right.second)<=1;

     pair<bool,int> ans;
     ans.second = max(left.second , right.second)+1;

     if(leftAns && rightAns&& difference){
        ans.first = true;
     }
     else{
        ans.first = false;
     }

     return ans;
    }

    bool isBalanced(TreeNode* root) {
        return isBalancedFast(root).first;
    }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:22:18*
