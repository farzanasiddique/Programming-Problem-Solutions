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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* ptr1 = head, *ptr2;
        if (ptr1 == nullptr) return head;
        ptr2 = ptr1->next;
        
        while (true) {
            if (ptr2 == nullptr || ptr2->next == nullptr) return head;
            ListNode* temp1 = ptr1->next;
            ListNode* temp2 = ptr2->next;
            ptr1->next = temp2;
            ptr2->next = temp2->next;
            temp2->next = temp1;
            ptr1 = temp2;
            ptr2 = ptr2->next;
        }
    }
};
