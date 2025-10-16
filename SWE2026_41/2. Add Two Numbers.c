/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ln;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int flag = 0;

    ln* dummy = (ln*)malloc(sizeof(ln));
    ln* cur = dummy;

    ln* l1Cur = l1;
    ln* l2Cur = l2;

    while (l1Cur || l2Cur || flag) {
        int v1 = l1Cur ? l1Cur->val : 0;
        int v2 = l2Cur ? l2Cur->val : 0;

        int sum = v1 + v2 + flag;
        flag = sum / 10;

        ln* newNode = (ln*)malloc(sizeof(ln));
        newNode->val = sum % 10;
        newNode->next = NULL;
        cur->next = newNode;
        cur = newNode;

        if (l1Cur) l1Cur = l1Cur->next;
        if (l2Cur) l2Cur = l2Cur->next;
    }

    ln* result = dummy->next;
    free(dummy);
    return result;
}
