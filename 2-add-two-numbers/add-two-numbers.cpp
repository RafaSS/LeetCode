class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            sum %= 10;

            ListNode* newNode = new ListNode(sum);
            if (!result) {
                result = newNode;
                tail = result;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return result;
    }
};
