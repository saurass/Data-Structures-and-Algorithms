public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode t = head, h;
        if(head == null)
            return false;
        if(t.next == null || t.next.next == null) {
            return false;
        }
        
        h = t.next.next;
        
        while(t != null && h != null) {
            if(t == h) {
                return true;
            }
            t = t.next;
            if(h.next != null) {
                h = h.next.next;
            } else {
                return false;
            }
        }
        
        
        return false;
    }
}