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
    ListNode* rotateOnceRight(ListNode* head) {
        ListNode *a, *b, *c;
        if (head->next == nullptr) return head;
        a = head, b = a->next, c = head;
        while (b->next != nullptr) {
            a = b;
            b = b->next;
        }
        a->next = nullptr;
        b->next = head;
        return b;
    }
    int sizeOfLinkedList(ListNode* head) {
        int ans = 1;
        while (head->next) {
            head = head->next;
            ans++;
        }
        return ans;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        k %= sizeOfLinkedList(head);
        for (int i=0;i<k;i++) {
            head = rotateOnceRight(head);
        }
        return head;
    }
};