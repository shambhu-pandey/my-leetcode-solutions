# Palindrome Linked List

🔗 Link:
https://leetcode.com/problems/palindrome-linked-list/

## Difficulty

Easy

## Tags

Linked List, Two Pointers, Stack, Recursion

## Problem Description

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

&nbsp;
Example 1:


Input: head = [1,2,2,1]
Output: true


Example 2:


Input: head = [1,2]
Output: false


&nbsp;
Constraints:


	The number of nodes in the list is in the range [1, 105].
	0 &lt;= Node.val &lt;= 9


&nbsp;
Follow up: Could you do it in O(n) time and O(1) space?

## Solution

See `solution.cpp`

## Intuition

A palindrome reads the same forwards and backwards. To verify this in a singly-linked list, we need a way to compare the first element with the last, the second with the second-to-last, and so on. 

Since a singly-linked list only allows forward traversal, we can leverage a **Stack** (a Last-In-First-Out data structure). By pushing all the elements onto a stack, we can retrieve them in reverse order. Comparing the original list (forward) with the stack pops (backward) naturally validates the palindrome property.

## Pattern

* **LIFO (Last-In-First-Out) Reversal**: Utilizing a stack to reverse the access order of a sequential data structure.

## Key Trick

The stack acts as a "reverse mirror" of the linked list. The top of the stack always represents the end of the uncompared portion of the list. By comparing `head` (moving forward) with `st.top()` (moving backward), we can check for symmetry without needing backward pointers.

## Approach

1. **Initialize**: Create a stack of integers and a temporary pointer `temp` pointing to the `head` of the list.
2. **First Pass (Push)**: Traverse the entire linked list. At each node, push its value onto the stack. Move `temp` to the next node.
3. **Reset**: Point `temp` back to the `head` of the list to prepare for the comparison.
4. **Second Pass (Compare)**: Traverse the list again. In each iteration:
   * Compare the current node’s value (`temp->val`) with the top of the stack (`st.top()`).
   * If they do not match, the list is not a palindrome; return `false`.
   * If they match, pop the top element from the stack and move `temp` to the next node.
5. **Result**: If the loop completes successfully, return `true`.

## Complexity

Time: O(N)  
We traverse the linked list of size $N$ exactly twice: once to populate the stack and once to compare values. Stack operations (`push`, `top`, `pop`) take $O(1)$ time.

Space: O(N)  
We store all $N$ node values in the stack.

## Interview Tip

In an interview, this is a great "first-draft" solution to show you understand the properties of palindromes and stacks. However, the interviewer will almost certainly ask you to optimize the space complexity to **$O(1)$ auxiliary space**. 

Always state this trade-off upfront: *"This stack solution is simple and easy to implement, but it takes $O(N)$ space. I can optimize this to $O(1)$ space by reversing the second half of the list."*

## Common Mistake

* **Forgetting to reset the pointer**: A common bug is forgetting to reassign `temp = head` before the second loop. If you skip this, `temp` will remain `NULL` from the first loop, and the comparison loop will never execute (or crash).
* **Comparing pointers instead of values**: Ensure you compare `temp->val != st.top()` and not node pointers, as the stack only stores values (integers).

## Alternative Approach

The optimal **$O(1)$ Space** approach uses the **Slow & Fast Pointer (Tortoise and Hare)** technique:

1. **Find the Middle**: Use a `slow` pointer (moves 1 step) and a `fast` pointer (moves 2 steps). When `fast` reaches the end, `slow` will be at the middle.
2. **Reverse the Second Half**: Reverse the linked list starting from the `slow` pointer.
3. **Compare**: Compare the first half (starting at `head`) and the reversed second half (starting at the new end) step-by-step.
4. **Restore (Optional)**: Reverse the second half back to restore the original list structure (highly recommended in real-world software engineering).
5. **Return**: If all values match, it's a palindrome.
