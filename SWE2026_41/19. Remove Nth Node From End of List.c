/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* ht = head;
    int maxN = 1;

    while(ht->next) {
        ht = ht->next;
        maxN++;
    }

    int nt = (maxN - n + 1) - 2;
    ht = head;

    if(nt < 0) {
        head = head->next ? head->next : 0;
        return head;
    }

    while(nt-- && ht->next) {
        ht = ht->next;
    }
    if(ht && ht->next)
        ht->next = ht->next->next;

    return head;
}