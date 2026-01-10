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
	ListNode* curr = head;
	ListNode* next;

	if (head != nullptr && head->next != nullptr) {
		next = head->next;
	} else {
		return nullptr;
	}

	while (next != nullptr) {
		if (curr->val == next->val) {
			next = next->next; //TODO: Delete this node
			curr->next = next;
		} else {
		curr = curr->next;
		next = next->next;
		}
	}
	return head;
}

// 方針2
ListNode* deleteDuplicates(ListNode* head) {
	ListNode* curr = head;
	ListNode* next;

	if (head != nullptr && head->next != nullptr) {
		next = head->next;
	} else {
		return head;
	}

	while (next != nullptr) {
		if (curr->val == next->val) {
			next = next->next; //TODO: Delete this node
			curr->next = next;
		} else {
		curr = curr->next;
		next = next->next;
		}
	}
	return head;
}

// Step2
ListNode* deleteDuplicates(ListNode* head) {
	ListNode* curr = head;
	
	while (curr != nullptr && curr->next != nullptr) {
		if (curr->val == curr->next->val) {
			// ListNode* temp = curr->next;
			curr->next = curr->next->next;
			// delete temp;
		} else {
			curr = curr->next;
		}
	}
	return head;
}
