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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* forSize = head;
        int size = 0;
        while (forSize) {
            forSize = forSize->next;
            size++;
        }
        int toMove = size - n;
        ListNode* curr = head;
        ListNode* dummy = new ListNode(-1, head);
        ListNode* prev = dummy;
        while (toMove) {
            toMove--;
            curr = curr->next;
            prev = prev->next;
        }
        ListNode* todel = curr;
        prev->next = curr->next;
        delete todel;
        return dummy->next;
    }
};
