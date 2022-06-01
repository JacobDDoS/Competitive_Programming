class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* copy = head;
        while (copy && copy->next) {
            ListNode* temp = copy->next;
            while (temp) {
                if (copy->val == temp->val) {
                    if (temp->next) {
                        temp = temp->next;
                    } else {
                        temp = NULL;
                    }
                } else {
                    break;
                }
            }
            copy->next = temp;
            copy = copy->next;
        }
        return head;
    }
};