class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode p1 = l1, p2 = l2;
        ListNode retval = null;
        ListNode ans = null;
        int cry = 0;
        while(p1 != null || p2 != null || cry != 0) {
            int sm = 0;
            if(p1 == null && p2 != null) {
                sm = p2.val + cry;
                p2 = p2.next;
            }
            else if(p2 == null && p1 != null) {
                sm = p1.val + cry;
                p1 = p1.next;
            }
            else if(p2 != null && p2 != null) {
                sm = p1.val + p2.val + cry;
                p1 = p1.next;
                p2 = p2.next;
            }
            else if(p2 == null && p1 == null && cry != 0) {
                sm = cry;
            }
            
            // System.out.println(sm + " " + sm % 10);
            int vls = sm % 10;
            ListNode tps = new ListNode(vls);
            // System.out.println(tps.val);
            
            cry = sm / 10;
            if(ans == null && retval == null) {
                retval = tps;
                ans = tps;
            } else {
                ans.next = tps;
                ans = ans.next;
            }
        }
        
        return retval;
    }
}