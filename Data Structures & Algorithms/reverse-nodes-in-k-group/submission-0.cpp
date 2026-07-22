class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        vector<ListNode*> vec;
        vector<bool> isReversed; // Track which groups were full (length k)

        ListNode* temp = head;
        ListNode* groupHead = head;
        int count = 0;

        // Step 1: Divide the list into groups of size k
        while (temp) {
            count++;
            if (count % k == 0) {
                ListNode* nextNode = temp->next;
                temp->next = nullptr; // Break connection to seal the segment
                
                vec.push_back(groupHead);
                isReversed.push_back(true);

                groupHead = nextNode;
                temp = nextNode;
            } else {
                temp = temp->next;
            }
        }

        // Step 2: Handle remaining nodes (less than k)
        if (groupHead) {
            vec.push_back(groupHead);
            isReversed.push_back(false); // Do NOT reverse this last chunk
        }

        // Step 3: Reverse only the full k-length groups
        for (int i = 0; i < vec.size(); i++) {
            if (isReversed[i]) {
                vec[i] = reverse(vec[i]);
            }
        }

        // Step 4: Stitch all groups back together
        ListNode* dummy = new ListNode(-1);
        ListNode* newNode = dummy;

        for (auto &node : vec) {
            newNode->next = node;
            while (newNode->next) {
                newNode = newNode->next; // Advance to the end of the current group
            }
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};