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

 struct Compare {
    bool operator() (const ListNode* n1, const ListNode* n2) const {
        return n1->val > n2->val;
    }
 };

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for (ListNode* node : lists) {
            if (node) pq.push(node);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        while (!pq.empty()) {
            ListNode* newNode = pq.top();
            pq.pop();
            head->next = newNode;
            head = head->next;
            if (newNode->next) {
                pq.push(newNode->next);
            }
        }
        return dummy->next;
    }
};
