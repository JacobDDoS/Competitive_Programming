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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for (int num: nums) s.insert(num);
        ListNode* temp1;
        ListNode* temp2;
        while (head && s.count(head->val)) head = head->next;
        
        temp1 = head;
        temp2 = head;

        while (temp2) {
            temp2 = temp2->next;
            if (temp2 && !s.count(temp2->val)) {
                temp1->next = temp2;
                temp1 = temp1->next;
            }
        }
        temp1->next = nullptr;

        return head;

    }
};