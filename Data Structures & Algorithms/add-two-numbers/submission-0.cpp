/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        int carry = 0;
        while (temp1 && temp2) {
            int value = temp1->val + temp2->val + carry;
            carry = value / 10;
            value = value % 10;
            ListNode* newNode = new ListNode(value);
            head->next = newNode;
            head = head->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while (temp1) {
            int value = temp1->val + carry;
            carry = value / 10;
            value = value % 10;
            ListNode* newNode = new ListNode(value);
            head->next = newNode;
            head = head->next;
            temp1 = temp1->next;
        }
        while (temp2) {
            int value = temp2->val + carry;
            carry = value / 10;
            value = value % 10;
            ListNode* newNode = new ListNode(value);
            head->next = newNode;
            head = head->next;
            temp2 = temp2->next;
        }
        if (carry) {
            ListNode* newNode = new ListNode(carry);
            head->next = newNode;
        }
        return dummy->next;
    }
};
