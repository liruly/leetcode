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
- c++におけるメモリ管理(new, delete)
	- (コーディング面接では見られるのかな...？)
- early returnの手法

## Step1-1
- 所要時間: 30min.
- 方針1: 
	- 与えられたlistのnodeを順々に見て行って、隣接するnodeのvalが一致していたら片方をスキップする
- コード
```cpp
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
```
- 方針2: 
	- コーナーケースを見落としていたので処理
		- nodeが1つの場合
- コード
```cpp
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
```
## Step2 リファクタリング
- 所要時間: 5min.
- 方針: 
	- 変数の削減
	- 可読性向上
- コード
```cpp
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

```
