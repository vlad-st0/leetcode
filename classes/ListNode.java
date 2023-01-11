package classes;

import java.util.List;

public class ListNode {

    public int val;

    public ListNode next;

    public ListNode(int x) {
        val = x;
    }

    @Override
    public String toString() {
        ListNode node = next;
        String str = "[" + val;
        while (node != null) {
            str += "->" + node.val;
            node = node.next;
        }
        str += "]";
        return str;
    }

    public static String toString(ListNode head) {
        String result = "";
        ListNode h = head;
        while (h != null) {
            if (h.next != null) {
                result += h.val + "->";
            } else {
                result += h.val;
            }
            h = h.next;
        }
        return result;
    }

    public static boolean isSameList(ListNode head1, ListNode head2) {
        if (head1 == null && head2 == null) {
            return true;
        }
        if (head1 == null && head2 != null) {
            return false;
        }
        if (head2 == null && head1 != null) {
            return false;
        }
        return (head1.val == head2.val) && isSameList(head1.next, head2.next);
    }

    /**
     * Construct a linked list using given integer list.
     * 
     * @param nums
     * @return head node of the constructed list
     */
    public static ListNode constructLinkedList(List<Integer> nums) {
        ListNode dummy = new ListNode(-1);
        ListNode node = dummy;
        for (Integer number : nums) {
            node.next = new ListNode(number);
            node = node.next;
        }
        return dummy.next;
    }

    /**
     * Construct a linked list using given integer array.
     * 
     * @param nums
     * @return head node of the constructed list
     */
    public static ListNode constructLinkedList(int[] nums) {
        ListNode dummy = new ListNode(-1);
        ListNode node = dummy;
        for (int num : nums) {
            node.next = new ListNode(num);
            node = node.next;
        }
        return dummy.next;
    }
}