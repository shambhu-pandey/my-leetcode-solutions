# 🚀 Remove Nth Node From End of List

🔗 **LeetCode Link:**  
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

---

## 🎯 Difficulty

**Medium**

---

## 🏷️ Tags

Linked List, Two Pointers

---

## 📖 Problem Description

Given the head of a linked list, remove the nth node from the end of the list and return its head.

 
Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]


Example 2:


Input: head = [1], n = 1
Output: []


Example 3:


Input: head = [1,2], n = 1
Output: [1]


 
Constraints:


	The number of nodes in the list is sz.
	1 <= sz <= 30
	0 <= Node.val <= 100
	1 <= n <= sz


 
Follow up: Could you do this in one pass?


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count =0;

        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        
        if(count==n){
            ListNode*  newHead =  head->next;
            delete(head);
            return newHead;
        }

        int res = count -n;
        temp = head;
        
        // yh temp ko wha par la kar choor dega jiske aage wala delete karna hai 
        while(temp!=NULL){
            res--;
            if(res==0){
                break;
            }
            temp = temp->next;
        }

        ListNode* delNode  = temp->next;
        temp->next = temp->next->next;
        delete(delNode);

        return head;

    }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:21:02*
