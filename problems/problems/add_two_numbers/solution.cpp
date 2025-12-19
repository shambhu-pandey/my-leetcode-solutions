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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        int carry =0;
        while(l1!=NULL || l2!= NULL){
        int sum = carry;
        if(l1) sum += l1->val;
        if(l2) sum += l2->val;

        ListNode* newnode = new ListNode(sum%10);
        carry = sum/10;
        
        curr->next = newnode;
        curr = curr->next;

        if(l1) l1= l1->next;
        if(l2) l2 =l2->next;
        }

        if(carry){
            ListNode* newnode = new ListNode(carry);
            curr->next = newnode;
        }

        return dummy->next;
    }
};