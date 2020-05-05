class Solution {
    public void deleteNode(ListNode node) {
        // ListNode tp = node;
        node.val = node.next.val;
        node.next = node.next.next;
    }
}