# 🚀 Validate Binary Search Tree

🔗 **LeetCode Link:**  
https://leetcode.com/problems/validate-binary-search-tree/

---

## 🎯 Difficulty

**Medium**

---

## 🏷️ Tags

Tree, Depth-First Search, Binary Search Tree, Binary Tree

---

## 📖 Problem Description

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:


	The left subtree of a node contains only nodes with keys strictly less than the node's key.
	The right subtree of a node contains only nodes with keys strictly greater than the node's key.
	Both the left and right subtrees must also be binary search trees.


 
Example 1:


Input: root = [2,1,3]
Output: true


Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.


 
Constraints:


	The number of nodes in the tree is in the range [1, 104].
	-231 <= Node.val <= 231 - 1



---

## 💻 My Solution

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isValidBST(TreeNode root) {
        return check(root , Long.MIN_VALUE , Long.MAX_VALUE);

    }

    private boolean check(TreeNode node , long min , long max){
        if(node ==null) return true;
       
       //in range 
        if(node.val <=min || node.val >=max){
            return false;
        }

        boolean left = check(node.left , min , node.val);// left value must be smaller
        boolean right = check(node.right  , node.val, max);//right value must be greater

        return left && right;
    }
}
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:22:13*
