# Next Greater Element I

🔗 Link:
https://leetcode.com/problems/next-greater-element-i/

## Difficulty

Easy

## Tags

Array, Hash Table, Stack, Monotonic Stack

## Problem Description

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 &lt;= i &lt; nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

&nbsp;
Example 1:


Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.


Example 2:


Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.


&nbsp;
Constraints:


	1 &lt;= nums1.length &lt;= nums2.length &lt;= 1000
	0 &lt;= nums1[i], nums2[i] &lt;= 104
	All integers in nums1 and nums2 are unique.
	All the integers of nums1 also appear in nums2.


&nbsp;
Follow up: Could you find an O(nums1.length + nums2.length) solution?

## Solution

See `solution.cpp`

## Intuition

To find the "next greater element" for any number, we need to look at the elements to its right. 

If we traverse the array from **right to left**, we can maintain a history of the elements we have already processed. If we encounter a number that is larger than the elements to its right, those smaller elements can never be the "next greater element" for any numbers further to the left (they are effectively "shadowed" or blocked by the larger number). This survival-of-the-fittest behavior perfectly matches the properties of a **Stack**.

## Pattern

This problem is a classic application of the **Monotonic Stack** pattern. 
* We maintain a stack where the elements are kept in a strict order (in this case, monotonic decreasing from bottom to top).
* We combine this with a **Hash Map** to store the relationship between each element in `nums2` and its next greater element, allowing $O(1)$ lookup when querying for `nums1`.

## Key Trick

The key trick is **processing the array backwards (right-to-left)** and **ruthlessly popping smaller elements**. 

As we move left, if the current element `nums2[i]` is greater than or equal to the top of the stack, we pop the stack. 
* Why? Because `nums2[i]` is both **larger** and **closer** to any incoming elements from the left. The popped elements will never be needed again.

## Approach

1. **Initialize**: Create an empty stack `st` and a hash map `mp`.
2. **Backward Pass (`nums2`)**: Iterate from `n2 - 1` down to `0`:
   * While the stack is not empty and the top of the stack is less than or equal to the current element `nums2[i]`, **pop** the stack.
   * If the stack is empty, it means there is no greater element to the right. Store `-1` in the map for `nums2[i]`.
   * Otherwise, the top of the stack is the next greater element. Store `st.top()` in the map.
   * Push the current element `nums2[i]` onto the stack.
3. **Query Pass (`nums1`)**: Create an answer vector. For each element in `nums1`, retrieve its precomputed next greater element from the map in $O(1)$ time.

## Complexity

Let $N_1$ be the size of `nums1` and $N_2$ be the size of `nums2`.

Time: **$O(N_1 + N_2)$**
* We traverse `nums2` of size $N_2$ once. Although there is a nested `while` loop, each element is pushed onto the stack exactly once and popped at most once. This amortizes to $O(N_2)$ time.
* We traverse `nums1` of size $N_1$ once, doing $O(1)$ map lookups, which takes $O(N_1)$ time.

Space: **$O(N_2)$**
* The hash map stores $N_2$ key-value pairs.
* The stack can hold at most $N_2$ elements in the worst case (e.g., if `nums2` is sorted in descending order).

## Interview Tip

When explaining this to an interviewer:
1. **Start with the amortized analysis**: Interviewers love to see if you understand why a nested `while` loop inside a `for` loop is still $O(N)$ overall. Use the phrase: *"Each element enters the stack at most once and leaves the stack at most once."*
2. **Explain the Monotonic property**: Define clearly that the stack contains candidates for the next greater element, ordered from smallest (at the top) to largest (at the bottom).

## Common Mistake

* **Incorrect Loop Bounds / Direction**: Trying to do a right-to-left traversal but accidentally starting from `n2` instead of `n2 - 1`, causing an out-of-bounds error.
* **Using `<` instead of `<=`**: If duplicate elements were allowed (though not in this specific LeetCode problem), using `<` instead of `<=` in the `while` condition would fail. It is safer to pop equal elements because they cannot be strictly "greater" than elements to their left.

## Alternative Approach

Instead of a right-to-left traversal, you can traverse `nums2` from **left to right**. 

### How it works:
* We iterate through `nums2`.
* We push elements onto the stack.
* Whenever we see a number that is greater than the top of the stack, it means we have found the "next greater element" for the stack's top. We pop the stack, map the popped element to this current number, and repeat until the stack top is no longer smaller.
* Any elements remaining in the stack at the end have no greater element, so they map to `-1`.

This approach is equally optimal ($O(N_1 + N_2)$ time and $O(N_2)$ space) and is preferred by developers who find forward loops more intuitive.
