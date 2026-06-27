class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* beforeGroup = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* groupEnd = beforeGroup;
            for (int i = 0; i < k; ++i) {
                groupEnd = groupEnd->next;
                if (groupEnd == nullptr) {
                    ListNode* newHead = dummy->next;
                    delete dummy;
                    return newHead;
                }
            }

            ListNode* nextGroupStart = groupEnd->next;
            ListNode* prev = nextGroupStart; 
            ListNode* groupStart = curr;
            
            for (int i = 0; i < k; ++i) {
                ListNode* next_node = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next_node;
            }

            beforeGroup->next = prev;
            beforeGroup = groupStart;
        }

        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};