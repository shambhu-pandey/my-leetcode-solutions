# 🚀 Binary Tree Zigzag Level Order Traversal

🔗 **LeetCode Link:**  
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

---

## 🎯 Difficulty

**Medium**

---

## 🏷️ Tags

Tree, Breadth-First Search, Binary Tree

---

## 📖 Problem Description

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 
Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]


Example 2:


Input: root = [1]
Output: [[1]]


Example 3:


Input: root = []
Output: []


 
Constraints:


	The number of nodes in the tree is in the range [0, 2000].
	-100 <= Node.val <= 100



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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
       List<List<Integer>> res = new ArrayList<>();

       if(root==null) return res;

       Queue<TreeNode> q = new LinkedList<>();
       q.offer(root);

       boolean rev = false; // false = left→right, true = right→left

       while(!q.isEmpty()){
        int n = q.size();
        LinkedList<Integer> level = new LinkedList<>();

        for(int i =0;i<n; i++){
            TreeNode node = q.poll();

            if(rev)
                level.addFirst(node.val); // reverse
            else
                level.addLast(node.val);

            if(node.left!=null) q.offer(node.left); 
            if(node.right!=null) q.offer(node.right);
        }
        res.add(level);

        // flip direction for next level
        rev = !rev;
       }
         return res;
    }
}
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:21:48*
