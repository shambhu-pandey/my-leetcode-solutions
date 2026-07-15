# Count Complete Tree Nodes

🔗 Link:
https://leetcode.com/problems/count-complete-tree-nodes/

## Difficulty

Easy

## Tags

Binary Search, Bit Manipulation, Tree, Binary Tree

## Problem Description

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than&nbsp;O(n)&nbsp;time complexity.

&nbsp;
Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6


Example 2:


Input: root = []
Output: 0


Example 3:


Input: root = [1]
Output: 1


&nbsp;
Constraints:


	The number of nodes in the tree is in the range [0, 5 * 104].
	0 &lt;= Node.val &lt;= 5 * 104
	The tree is guaranteed to be complete.



## Solution

See `solution.cpp`

## Intuition

The provided solution uses a standard **In-Order Depth First Search (DFS)** traversal to visit every node in the tree and increment a counter. While this is a conceptually straightforward way to count nodes in *any* binary tree, it completely ignores the defining characteristic of this problem: the tree is a **Complete Binary Tree**. 

Because of this, the provided solution does not run in optimal time. An interviewer will expect you to exploit the structural properties of a complete binary tree to achieve a sub-linear time complexity.

---

## Pattern

* **Provided Solution:** **Full Tree Traversal (DFS / In-Order)**. It visits $N$ nodes sequentially.
* **Optimal Solution:** **Decrease and Conquer (Binary Search-like)**. By leveraging the heights of the subtrees, we can prune entire subtrees and calculate their sizes in $O(1)$ time.

---

## Key Trick

In a **Complete Binary Tree**, if the height of the left-most path equals the height of the right-most path, the tree is a **Perfect Binary Tree**. 
The number of nodes in a perfect binary tree of height $h$ (where a single root node has height 1) is:
$$\text{Nodes} = 2^h - 1$$

By checking this property recursively, we can skip traversing large portions of the tree entirely.

---

## Approach

The provided code works as follows:
1. Initialize an integer accumulator `ans` to `0`.
2. Perform an in-order traversal:
   * Recursively visit the left subtree.
   * Increment `ans` by `1` when visiting the current node.
   * Recursively visit the right subtree.
3. Return the accumulated count.

---

## Complexity

* **Time:** $O(N)$ — Where $N$ is the total number of nodes in the tree. Every node is visited exactly once.
* **Space:** $O(\log N)$ — The recursion stack depth is equal to the height of the tree. Since the tree is complete, its height is guaranteed to be $O(\log N)$.

---

## Interview Tip

If you propose an $O(N)$ solution for this problem in an interview, the interviewer will immediately ask: **"How can you optimize this using the fact that the tree is complete?"**

Whenever a problem specifies a *Complete Binary Tree* or a *Binary Search Tree*, your target time complexity should almost always be logarithmic (e.g., $O(\log N)$ or $O(\log^2 N)$), not linear ($O(N)$).

---

## Common Mistake

* **Over-traversal:** Writing a standard `1 + countNodes(left) + countNodes(right)` recursive function. While simple, it runs in $O(N)$ and fails to utilize the physical structure of the tree.
* **Incorrect height definition:** Mixing up 0-based height (edges) and 1-based height (nodes) when calculating $2^h - 1$.

---

## Alternative Approach

The optimal approach compares the left-most depth and the right-most depth of the current subtree. 

* If `leftHeight == rightHeight`, the tree is perfect. Return $2^{\text{height}} - 1$ using bit-shifting (`(1 << height) - 1`).
* If they are not equal, recursively call the function on the left and right subtrees and add $1$ for the current root.

### Optimal $O(\log^2 N)$ C++ Code:

```cpp
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int leftHeight = 0, rightHeight = 0;
        TreeNode* leftNode = root;
        TreeNode* rightNode = root;
        
        // Find the height of the left-most path
        while (leftNode) {
            leftHeight++;
            leftNode = leftNode->left;
        }
        
        // Find the height of the right-most path
        while (rightNode) {
            rightHeight++;
            rightNode = rightNode->right;
        }
        
        // If heights are equal, it's a perfect binary tree
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1; // 2^height - 1
        }
        
        // Otherwise, recurse for left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```

### Complexity of Optimal Approach:
* **Time Complexity:** $O(\log^2 N)$ or $O((\log N)^2)$. In each step, we calculate the height which takes $O(\log N)$ time. Since the tree is complete, at least one of the subtrees (left or right) will always be a perfect binary tree, meaning recursion only continues down one path. Thus, we make $O(\log N)$ recursive steps, each taking $O(\log N)$ time.
* **Space Complexity:** $O(\log N)$ to store the recursion stack frames.
