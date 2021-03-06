/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode(0);
        ListNode* p = sum;
        int carry = 0;

        while(l1 != NULL && l2 != NULL) {
            p->next = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL && l2 == NULL) {
            p->next = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry) /10;
            p = p->next;
            l1 = l1->next;
        }
        while(l1 == NULL && l2 != NULL) {
            p->next = new ListNode((l2->val + carry) % 10);
            carry = (l2->val + carry) /10;
            p = p->next;
            l2 = l2->next;
        }
        if(carry) {
            p->next = new ListNode(carry);
        }
        delete sum;
        return sum->next;
    }
};
