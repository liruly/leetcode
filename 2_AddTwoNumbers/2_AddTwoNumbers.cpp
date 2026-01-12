// data_structures
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Step1
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(0, nullptr);
        ListNode *node = &dummy;

        bool carryUp = false;

        while (l1 != nullptr && l2 != nullptr) {
            node->next = new ListNode(0, nullptr);
            node = node->next;

            int sum = l1->val + l2->val;
            if (carryUp == true) {
                sum++;
            }
            
            if (sum >= 10) {
                carryUp = true;
            } else {
                carryUp = false;
            }

            node->val = sum % 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            node->next = new ListNode(0, nullptr);
            node = node->next;

            int sum = l1->val;
            if (carryUp == true) {
                sum++;
            }
            node->val = sum % 10;
            
            if (sum >= 10) {
                carryUp = true;
            } else {
                carryUp = false;
            }

            l1 = l1->next;
        }
        while (l2 != nullptr) {
            node->next = new ListNode(0, nullptr);
            node = node->next;

            int sum = l2->val;
            if (carryUp == true) {
                sum++;
            }
            node->val = sum % 10;
            
            if (sum >= 10) {
                carryUp = true;
            } else {
                carryUp = false;
            }

            l2 = l2->next;
        }
        if (carryUp == true) {
            node->next = new ListNode(0, nullptr);
            node = node->next;

            node->val = 1;
        }
        return dummy.next;
    }
};

// Step2
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0, nullptr);
        ListNode *node = &dummy;
        bool carryUp = false;

        while (l1 != nullptr || l2 != nullptr || carryUp == true) {
            const int x = (l1 != nullptr) ? l1->val : 0;
            const int y = (l2 != nullptr) ? l2->val : 0;
            
            int sum = x + y;
            if (carryUp == true) {
                sum++;
            }

            node->next = new ListNode((sum % 10), nullptr);
            node = node->next;
            carryUp = sum >= 10 ? true : false;

            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }
        return dummy.next;
    }
};

// Step3
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(0);
        ListNode *node = &dummy;

        int carryUp = 0;

        while (l1 != nullptr || l2 != nullptr || carryUp != 0) {
            const int x = (l1 != nullptr) ? l1->val : 0;
            const int y = (l2 != nullptr) ? l2->val : 0;
            const int sum = x + y + carryUp;

            node->next = new ListNode(sum % 10);
            node = node->next;
            
            carryUp = sum/10;

            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }
        return dummy.next;
    }
};
