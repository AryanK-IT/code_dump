/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* temp1 = head;
    struct ListNode* temp2 = head;

    if (head = NULL){
        return NULL;
    }
    while(temp2 != NULL && temp2->next != NULL){
        temp2 = temp2->next->next;
        temp1 = temp1->next;
    }
    return temp1;
}