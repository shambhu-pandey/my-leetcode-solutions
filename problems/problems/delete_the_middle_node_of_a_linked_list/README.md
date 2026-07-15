# Delete the Middle Node of a Linked List

🔗 Link:
https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

## Difficulty

Medium

## Tags

Linked List, Two Pointers

## Problem Description

You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the &lfloor;n / 2&rfloor;th node from the start using 0-based indexing, where &lfloor;x&rfloor; denotes the largest integer less than or equal to x.


	For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.


&nbsp;
Example 1:


Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 


Example 2:


Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.


Example 3:


Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.

&nbsp;
Constraints:


	The number of nodes in the list is in the range [1, 105].
	1 &lt;= Node.val &lt;= 105



## Solution

See `solution.cpp`

## Intuition

To delete a node in a singly-linked list, we must find the node **immediately preceding** the target node. Once we have a reference to this predecessor, we can redirect its `next` pointer to bypass the target node. 

In this approach, the intuition is straightforward:
1. Count how many nodes are in the list.
2. Determine the exact index of the middle node ($N/2$).
3. Traverse the list a second time, stopping exactly one node before the middle node to perform the deletion.

---

## Pattern

This solution uses the **Two-Pass (Counting) Pattern** for linked lists. 
* **Pass 1:** Gather global metadata about the structure (in this case, the total length).
* **Pass 2:** Use the metadata to navigate to a precise position.

---

## Key Trick

The key trick lies in the loop condition `if (middle == 0)`. 
By decrementing `middle` (which is initialized to `count / 2`) at each step of the second traversal, we ensure that the loop halts when `temp` is exactly at the **predecessor** of the middle node. This allows us to safely perform `temp->next = temp->next->next` without losing the reference to the rest of the list.

---

## Approach

1. **Edge Case Handling:** If the list is empty (`head == NULL`) or has only one node (`head->next == NULL`), deleting the middle node leaves us with an empty list. Return `NULL` immediately.
2. **First Pass (Counting):** Use a temporary pointer `temp` to traverse the list from head to tail, incrementing a `count` variable to find the total length of the list.
3. **Target Calculation:** Calculate the index of the middle node using integer division: `middle = count / 2`.
4. **Second Pass (Targeting):** Reset `temp` back to the `head`. Traverse the list again, decrementing `middle` by 1 at each step.
5. **Deletion:** When `middle == 0`, `temp` is pointing to the node right before the middle node. 
   * Save the middle node to a pointer (`middleNode = temp->next`).
   * Bypass the middle node: `temp->next = temp->next->next`.
   * Free the memory of `middleNode` using `delete` to prevent memory leaks.
   * Break the loop and return `head`.

---

## Complexity

Time: O(N)  
We traverse the list twice. The first pass takes $N$ operations to count the nodes. The second pass takes $N/2$ operations to reach the middle.  
$O(N + N/2) = O(1.5N) \rightarrow O(N)$.

Space: O(1)  
No extra data structures are used. We only use a few pointers and integer variables, maintaining constant auxiliary space.

---

## Interview Tip

In C++, always show responsibility for **manual memory management**. When you unlink a node in a coding interview, explicitly free its memory using `delete` (or `free` in C). Even though languages like Java and Python have automatic garbage collection, explaining how you prevent memory leaks in lower-level languages shows strong computer science fundamentals.

---

## Common Mistake

* **Off-by-One Pointer Dereferencing:** A common error in this problem is landing directly on the middle node instead of its predecessor. Once you are on the middle node, you cannot delete it in $O(1)$ time because you cannot access its previous neighbor in a singly-linked list.
* **Missing Base Cases:** Forgetting to handle 1-node lists (`head->next == NULL`) will cause a runtime error (segmentation fault) when attempting to access `temp->next->next` on a null pointer.

---

## Alternative Approach

An elegant, **one-pass** alternative is the **Fast and Slow Pointer (Tortoise and Hare)** pattern:

Instead of counting all nodes, you can traverse the list once using two pointers:
* `slow` moves 1 step at a time.
* `fast` moves 2 steps at a time.
* Keep a `prev` pointer tracking the node right behind `slow`.

By the time `fast` reaches the end of the list, `slow` will be pointing exactly at the middle node, and `prev` will be right before it. 

### Code:
```cpp
ListNode* deleteMiddle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    
    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // slow is now the middle node, prev is the node before it
    prev->next = slow->next;
    delete slow;
    
    return head;
}
```
* **Why it's better:** It only traverses the list **once** (visiting each node exactly once), making it roughly twice as fast in practice compared to the two-pass approach.
