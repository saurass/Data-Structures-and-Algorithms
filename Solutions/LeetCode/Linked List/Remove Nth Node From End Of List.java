class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode tp = head, hp = head;
        int t = n;
        if(tp.next == null) {
            return null;
        }
        while(t-- > 1) {
            tp = tp.next;
        }
        
        ListNode hpr = hp;
        while(tp.next != null) {
            hpr = hp;
            
            tp = tp.next;
            hp = hp.next;
        }
        
        if(hp == head) {
            return head.next;
        }
        
        hpr.next = hp.next;
        
        return head;
    }
}