/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
          if (head == null)
            return null;

        if (head.next == null)
            return null;

        ListNode temp = head;
        int count = 1;

     while (temp.next != null) {
            count++;
            temp = temp.next;
        }

        int ref = count - n;

        if (ref == 0) {
            return head.next;
        }

        temp = head;

        for (int i = 1; i < ref; i++) {
            temp = temp.next;
        }

        temp.next = temp.next.next;

        return head;
    }
}