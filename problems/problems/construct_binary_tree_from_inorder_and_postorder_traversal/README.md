# Construct Binary Tree from Inorder and Postorder Traversal

🔗 Link:
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

## Difficulty

Medium

## Tags

Array, Hash Table, Divide and Conquer, Tree, Binary Tree

## Problem Description

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

&nbsp;
Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]


Example 2:


Input: inorder = [-1], postorder = [-1]
Output: [-1]


&nbsp;
Constraints:


	1 &lt;= inorder.length &lt;= 3000
	postorder.length == inorder.length
	-3000 &lt;= inorder[i], postorder[i] &lt;= 3000
	inorder and postorder consist of unique values.
	Each value of postorder also appears in inorder.
	inorder is guaranteed to be the inorder traversal of the tree.
	postorder is guaranteed to be the postorder traversal of the tree.



## Solution

See `solution.cpp`

## Intuition

The key to solving this problem lies in understanding the characteristics of **Inorder** and **Postorder** traversals:
1. **Postorder Traversal (`Left -> Right -> Root`)**: The last element of a postorder sequence is always the **root** of the tree (or subtree).
2. **Inorder Traversal (`Left -> Root -> Right`)**: Once we identify the root element, we can find its position in the inorder sequence. Everything to the **left** of this position belongs to the left subtree, and everything to the **right** belongs to the right subtree.

By starting from the end of the `postorder` array and working our way backwards, we can recursively build the tree from the top down.

---

## Pattern

This problem belongs to the **Divide and Conquer / Tree Reconstruction** pattern. 
* We use a global/reference index to continuously grab the root of the current subtree.
* We divide the inorder range into left and right sub-problems and solve them recursively.

---

## Key Trick

* **Process Right Subtree First**: Because postorder traversal is `Left -> Right -> Root`, if we scan the `postorder` array from right to left (backwards), the sequence of nodes encountered is `Root -> Right -> Left`. Therefore, during reconstruction, **we must build the right subtree before the left subtree**.
* **Index Mapping**: To avoid searching the inorder array linearly ($O(N)$) for each root node, we precompute a lookup map (`nodeToIndex`) that gives us the index of any node in $O(1)$ average time.

---

## Approach

1. **Map Inorder Indices**: Build a map `nodeToIndex` to store the value-to-index mapping of the `inorder` array for quick lookups.
2. **Track Postorder Pointer**: Initialize `postorderIndex` at `size - 1` (the end of the postorder list). Pass this index by reference (`int&`) to keep track of our current root across recursive calls.
3. **Recursive Reconstruction (`solve`)**:
   * **Base Case**: If `inorderStart > inorderEnd` or `postorderIndex < 0`, return `nullptr`.
   * **Select Root**: Retrieve the value at `postorder[postorderIndex]`, decrement `postorderIndex`, and create a new tree node.
   * **Find Split Point**: Look up the root's index in the inorder array using the map. Let this be `position`.
   * **Build Right Subtree**: Recursively construct the right child using the inorder range `[position + 1, inorderEnd]`.
   * **Build Left Subtree**: Recursively construct the left child using the inorder range `[inorderStart, position - 1]`.
   * Return the root.

---

## Complexity

### Time: $O(N \log N)$ (with current implementation) / $O(N)$ (optimized)
* In the provided code, `std::map` is used, which has $O(\log N)$ insertion and lookup times. Since we do $N$ lookups, the overall time complexity is $O(N \log N)$.
* If changed to `std::unordered_map`, lookup is $O(1)$ on average, reducing the time complexity to **$O(N)$**.

### Space: $O(N)$
* **Map Overhead**: The map stores $N$ elements, requiring $O(N)$ space.
* **Recursion Stack**: In the worst-case (skewed tree), the recursion stack can go up to $O(N)$ deep. In a balanced tree, it would be $O(\log N)$.

---

## Interview Tip

In an interview, **always choose `std::unordered_map` over `std::map`** for this problem. Explain to the interviewer that `std::unordered_map` uses a hash table ($O(1)$ average lookup), whereas `std::map` uses a Red-Black tree ($O(\log N)$ lookup). This simple choice optimizes your algorithm from $O(N \log N)$ to $O(N)$.

---

## Common Mistake

1. **Wrong Subtree Construction Order**: Trying to build `root->left` before `root->right`. Since we are iterating backwards through the `postorder` array, the element immediately preceding the root is always part of the right subtree (if it exists). Building the left subtree first will read the wrong elements and corrupt the tree structure.
2. **Value vs. Reference**: Passing `postorderIndex` by value rather than by reference (`int&`). If passed by value, the index decrement won't persist across different branches of the recursive call tree, resulting in duplicate node placements and an incorrect tree.

---

## Alternative Approach

Instead of recursion, you can use an **Iterative Approach** using a Stack.

### How it works:
We can process the `postorder` array from right to left and the `inorder` array from right to left.
* We push nodes to a stack, always going right as long as the stack's top element is not equal to the current element in the reversed `inorder` array.
* When they match, it means we have reached the end of a right path. We pop elements to find the parent node and then attach the next element to the left of that parent.

While harder to write and explain during a 45-minute interview, the iterative approach is highly efficient as it avoids stack overflow risks on extremely deep trees.
