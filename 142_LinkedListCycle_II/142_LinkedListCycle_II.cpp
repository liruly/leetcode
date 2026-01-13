// data_structures
#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Step1-1
#include <unordered_set>

ListNode *detectCycle(ListNode *head) {
    struct ListNode *node = head;
    std::unordered_set <struct ListNode *> checker;

    while (node) {
        if (checker.contains(node)) {
            return node;
        }
        checker.insert(node);
        node = node->next;
    }
    return NULL ;
}

// Step1-2
#include <unordered_set>
using namespace std;

ListNode *detectCycle(ListNode *head) {
  unordered_set<ListNode*> visited;
  ListNode *curr = head;

  while (curr != nullptr) {
    if (visited.contains(curr)) {
      return curr;
    }
    visited.insert(curr);
    curr = curr->next;
  }

  return nullptr;
}

// Step2-1
ListNode *detectCycle(ListNode *head) {
  ListNode *fast = head;
  ListNode *slow = head;

  while (fast) {
    if (fast->next != nullptr && fast->next->next != nullptr) {
      fast = fast->next->next;
    }
    else
      return nullptr;
    slow = slow->next;
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

// Step2-2
  ListNode *detectCycle(ListNode *head) {
      ListNode *fast = head;
      ListNode *slow = head;

      while (fast != nullptr && fast->next != nullptr) {
          fast = fast->next->next;
          slow = slow->next;
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
  