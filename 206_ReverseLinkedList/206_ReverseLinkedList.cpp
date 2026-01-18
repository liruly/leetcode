// data_structures
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Step1
#include <stack>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        std::stack<ListNode*> st;
        ListNode *node = head;
        ListNode dummy(0);

        while (node != nullptr) {
            st.push(node);
            node = node->next;
        }
        node = &dummy;
        while (!st.empty()) {
            node->next = st.top();
            st.pop();
            node = node->next;
        }
        node->next = nullptr;
        return dummy.next;
    }
};

// Step2
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *node = head;
        ListNode *prev = nullptr;
        ListNode *temp = head;

        while (node != nullptr) {
            temp = node->next;
            node->next = prev;
            if (temp == nullptr) {
                break;
            }
            prev = node;
            node = temp;
        }
        return node;
    }
};

// Step3
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *node = head;
        ListNode *prev = nullptr;

        while (node != nullptr) {
            ListNode *temp;
            temp = node->next;
            node->next = prev;
            
            prev = node;
            node = temp;
        }
        return prev;
    }
};
