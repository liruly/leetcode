# 83_Remove_Duplicates_from_Sorted_List
- [Arai60](https://1kohei1.com/leetcode/)
- 問題文: [83_Remove_Duplicates_from_Sorted_List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/)
- 使用言語: C++
- 次に解く問題: [82. Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/)

## 知識セット
### 知っていたこと
- 連結リストの仕組み
- アドレス・ポインタの扱い方

### 今回調べたこと
- c++におけるメモリ管理
	- (コーディング面接では見られるのかな...？)

## Step1-1
- 所要時間: 30min.
- 方針1: 
	- 与えられたlistのnodeを順々に見て行って、隣接するnodeのvalが一致していたら片方をスキップする
- コード
```cpp
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
```
- 方針2: 
	- コーナーケースを見落としていたので処理
		- nodeが1つの場合
- コード
```cpp
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
```
## Step2 リファクタリング
- 所要時間: 5min.
- 方針: 
	- 変数の削減
	- 可読性向上
- コード
```cpp
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
```
