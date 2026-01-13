# 142. Linked List Cycle II
- [Arai60](https://1kohei1.com/leetcode/)
- 問題文: [142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/description/)

## Step1: 素直な解法(unordered_set) 5min 
```cpp
#include <vector>

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *node = head;
        unordered_set<ListNode*> visited;

        while (node != nullptr) {
            if (visited.count(node)) {
                return node;
            }
            visited.insert(node);
            node = node->next;
        }
        return nullptr;
    }
};
```

## Step2: うさぎとかめ(フロイドの循環検出アルゴリズム)
```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                slow = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};
```