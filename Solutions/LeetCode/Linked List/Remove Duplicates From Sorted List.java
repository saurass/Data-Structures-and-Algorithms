class Solution {
    public ListNode deleteDuplicates(ListNode head) {
       Set<Integer> s = new HashSet<Integer>();
        
        ListNode tp = head, tpr = head;
        
        while(tp != null) {
            
            if(!s.contains(tp.val)) {
                s.add(tp.val);
                tpr = tp;
                tp = tp.next;
            } else {
                ListNode loc = tp;
                int tsp = tp.val;
                while(loc != null && loc.val == tsp) {
                    loc = loc.next;
                }
                
                tpr.next = loc;
                tp = loc;
            }
        }
        
        return head;
    }
}