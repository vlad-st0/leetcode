/**
 * Custom definition for singly-linked list.
 */
class ListNode {
    int val;
    ListNode next;

    ListNode() {
        val = 0;
        next = null;
    }

    ListNode(int x) {
        val = x;
        next = null;
    }

    ListNode(int x, ListNode node) {
        val = x;
        next = node;
    }
};


class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode res = new ListNode(0);
        ListNode ret = res;
        int carry = 0;
        while (l1 != null || l2 != null) {
            int a = l1 == null ? 0 : l1.val;
            int b = l2 == null ? 0 : l2.val;
            l1 = l1 == null ? null : l1.next;
            l2 = l2 == null ? null : l2.next;
            res.next = new ListNode((a + b + carry) % 10);
            res = res.next;
            carry = ((a + b + carry) / 10);
        }
        if (carry != 0) {
            res.next = new ListNode(carry);
        }
        return ret.next;
    }
}
