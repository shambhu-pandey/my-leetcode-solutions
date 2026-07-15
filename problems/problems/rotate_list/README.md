# 🚀 Rotate List

🔗 **LeetCode Link:**  
https://leetcode.com/problems/rotate-list/

---

## 🎯 Difficulty

**Medium**

---

## 🏷️ Tags

Linked List, Two Pointers

---

## 📖 Problem Description

Given the head of a linked list, rotate the list to the right by k places.

 
Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]


Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]


 
Constraints:


	The number of nodes in the list is in the range [0, 500].
	-100 <= Node.val <= 100
	0 <= k <= 2 * 109



---

## 💻 My Solution

```java
// class Solution {
//     public ListNode rotateRight(ListNode  head , int k)
// {
//     int length = getListLength(head);

//     if(length <= 1 || k==0 || k%length ==0){
//         return head;
//     }

//     if(k>length){
//         k= k%length;
//     }

//     int breakagePoint = length-k;
//     ListNode temp = head;
//     ListNode prev = null;

//     while(breakagePoint >0 && temp!=null){
//         prev = temp;
//         temp = temp.next;
//         breakagePoint--;
//     } 

//     prev.next = null;

//     ListNode iterator = temp;
//     if(iterator != null){
//         while(iterator.next!=null){
//             iterator=iterator.next;
//         }
//         iterator.next = head;
//     }
//     return temp;
// }
//    int getListLength(ListNode head){
//     int count = 0;
//     ListNode temp = head;
//     while(temp!=null){
//         temp=temp.next;
//         count++;
//     }
//     return count;
//    }
// }


class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        
        int len = 0;
        ListNode tmp = head;
        ListNode prev = tmp;
        while (tmp != null) {
            len += 1;
            tmp = tmp.next;
        }
        
        if (k != 0 && len != 0) {
            k = k % len;
        }
        
        if (k == 0 || len == 0) {
            return head;
        }
        
        k = len - k;
        
        tmp = head;
        
        for (int i = 1; i <= k; i++) {
            prev = tmp;
            tmp = tmp.next;
        }
        
        ListNode start = tmp;
        
        while (tmp.next != null) {
            tmp = tmp.next;
        }
        
        tmp.next = head;
        prev.next = null;
        
        return start;
    }
}
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:21:12*
