// data_structures
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Step1
// 方針1
ListNode* deleteDuplicates(ListNode* head) {
	ListNode* node = head;
	ListNode* node_next;

	if (head != nullptr && head->next != nullptr) {
		node_next = head->next;
	} else {
		return nullptr;
	}

	while (node_next != nullptr) {
		if (node->val == node_next->val) {
			node_next = node_next->next; //TODO: Delete this node
  		node->next = node_next;
		} else {
		node = node->next;
		node_next = node_next->next;
		}
	}
	return head;
}

// 方針2
ListNode* deleteDuplicates(ListNode* head) {
	ListNode* node = head;
	ListNode* node_next;

	if (head != nullptr && head->next != nullptr) {
		node_next = head->next;
	} else {
		return head;
	}

	while (node_next != nullptr) {
		if (node->val == node_next->val) {
			node_next = node_next->next; //TODO: Delete this node
			node->next = node_next;
		} else {
		node = node->next;
		node_next = node_next->next;
		}
	}
	return head;
}

// Step2
ListNode* deleteDuplicates(ListNode* head) {
	ListNode* node = head;
	
	while (node != nullptr && node->next != nullptr) {
		if (node->val == node->next->val) {
			// ListNode* temp = node->next;
			node->next = node->next->next;
			// delete temp;
		} else {
			node = node->next;
		}
	}
	return head;
}
