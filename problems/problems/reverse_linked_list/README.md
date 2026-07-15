# 🚀 Reverse Linked List

🔗 **LeetCode Link:**  
https://leetcode.com/problems/reverse-linked-list/

---

## 🎯 Difficulty

**Easy**

---

## 🏷️ Tags

Linked List, Recursion

---

## 📖 Problem Description

Given the head of a singly linked list, reverse the list, and return the reversed list.

 
Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]


Example 2:


Input: head = [1,2]
Output: [2,1]


Example 3:


Input: head = []
Output: []


 
Constraints:


	The number of nodes in the list is the range [0, 5000].
	-5000 <= Node.val <= 5000


 
Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?


---

## 💻 My Solution

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp!=NULL){
           ListNode* front =temp->next;
           temp->next = prev;
           prev = temp;
           temp = front;
        }

        return prev;
    }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:22:29*
