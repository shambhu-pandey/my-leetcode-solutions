
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode slow = new ListNode(-1);
        slow.next= head;
        ListNode fast = head;

        while(fast != null && fast.next !=null){
            slow = slow.next ;// slow ko ek badha rhe hai 
            fast = fast.next.next;// fast ko 2 badha rhe hai
        }
        ListNode prev = null;
        ListNode curr = slow.next;
        while(curr != null){
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        while(prev !=null){
            if(head.val !=prev.val){
                return false;
            }
            prev =prev.next;
            head = head.next;
        }
        return true;
    }
}