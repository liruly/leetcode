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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        
        ListNode *node_head = head;

        if (node_head->next != nullptr && node_head->val == node_head->next->val) {
            while (node_head->next != nullptr && node_head->val == node_head->next->val) {
                node_head = node_head->next;
            }
            node_head = node_head->next;
        }
        if (node_head == nullptr)
            return nullptr;

        ListNode *node = node_head;
        ListNode *node_scanning = node_head->next;

        while (node_scanning != nullptr) {
            if (node->val == node_scanning->val) {
                node_scanning = node_scanning->next;
            } else {
                node = node_scanning;
                node_scanning = node_scanning->next;
            }
        }
    }
};

// Step2
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        
        ListNode dummy(0, head);
        ListNode *unique = &dummy;
        ListNode *node = head;

        while (node != nullptr) {
            if (node->next != nullptr && node->val == node->next->val) {
                while (node->next != nullptr && node->val == node->next->val) {
                    node = node->next;
                }
                unique->next = node->next;
            } else {
                unique = unique->next;
            }
            node = node->next;
        }
        return dummy.next;
    }
};

// Step3 リファクタリング
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode dummy(0, head);
        ListNode *unique = &dummy;
        ListNode *node = head;

        while (node != nullptr) {
            if (node->next != nullptr && node->val == node->next->val) {
                int dupVal = node->val;
                while (node != nullptr && node->val == dupVal) {
                    node = node->next;
                }
                unique->next = node;
            } else {
                node = node->next;
                unique = unique->next;
            }
        }
        return dummy.next;
    }
};

//Step4 再帰
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        if (head->val == head->next->val) {
            while (head->next != nullptr && head->val == head->next->val) {
                head = head->next;
            }
            return deleteDuplicates(head->next);
        } else {
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};