/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    
    var dummyHead = new ListNode(0);
    var current = dummyHead;
    var carry = 0;

    for (; l1 !== null || l2 !== null || carry > 0; ) {
        var val1 = 0;
        var val2 = 0;

        if (l1 !== null) {
            val1 = l1.val;
        }
        if (l2 !== null) {
            val2 = l2.val;
        }

        var sum = val1 + val2 + carry;
        carry = Math.floor(sum / 10);

        var newNode = new ListNode(sum % 10);
        current.next = newNode;
        current = current.next;

        if (l1 !== null) {
            l1 = l1.next;
        }
        if (l2 !== null) {
            l2 = l2.next;
        }
    }

    return dummyHead.next;
};