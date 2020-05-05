class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prv = null, cur = head, nxt = null;
        ListNode tp = head;
        
        ListNode tpr = tp;
        while(tp != null) {
            tpr = tp;
            nxt = tp.next;
            tp.next = prv;
            prv = tpr;
            
            tp = nxt;
        }
        
        return prv;
    }
}