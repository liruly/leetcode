// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Step1
// boolの配列でやろうとした

// Step2
// unsorted_setで実装
#include <unordered_set>

bool hasCycle(struct ListNode *head)
{
	struct ListNode *node;
	std::unordered_set<struct ListNode *> adr_set;

	node = head;
	while(node)
	{
		if (adr_set.count(node))
			return (true);
		adr_set.insert(node);
		node = node->next;
	}
	return (false);
}

// Step3
// フロイドのサイクル検出アルゴリズム
bool hasCycle(struct ListNode *head)
{
	struct ListNode *fast;
	struct ListNode *slow;
	
	fast = head;
	slow = head;

	while(fast)
	{
		if (fast->next && fast->next->next)
			fast = fast->next->next;
		else
			return (false);
		slow = slow->next;
		if (fast == slow)
			return (true);
	}
	return (false);
}
