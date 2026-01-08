# 142. Linked List Cycle II
- [Arai60](https://1kohei1.com/leetcode/)
- 問題文: [142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/description/)
- 使用言語: C++
- 次に解く問題: [83. Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/)

## 知識セット
### 知っていたこと
- unordered_setは順序なし、setは順序あり(昇順)
- idxを付けたければvectorが第一選択、ただし遅いのでunordered_setを併用

### 今回調べたこと
- フロイドのサイクル検出アルゴリズムにおいて、ループの始点を検出する方法

## Step1-1 実装
- 所要時間: 25min.
- 方針1: (読み違えてたのでスルーしてください)順序付き集合のデータ構造を使って実装
	- 141のunordered_setは順序なしなので、順序つきのsetを使用する
	- と思ったけど、setは自動でソートされる模様？
	- じゃあだめだ
	- 整理
		- `std::set`: 順序付き集合
			- データは木構造で管理され、新規データは自動で昇順で格納されていく
		- `std::unordered_set`: 順序なし集合
			- データをhash化して内部的な配列に突っ込んでいく
			- 内部的にhashを用いていて検索が高速(O(1))
- 方針2: (読み違えてたのでスルーしてください)unordered_setを用いて重複を管理し、重複があった際にvectorからindexを取得する
	- 読み違えていたことに気づき(idxは保管する必要も返す必要もない)、方針変更
- 方針3: unordered_setのみで重複管理し、重複があったらループと判断しそのadrを返す
	- 方針は141と同様
- コード
```cpp
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
```
- 計算量: O(N)

## Step1-2 リファクタリング
- 所要時間: 5min.
- 方針: 
	- nullptrを使用
	- 変数名を変更
	- structを省略
- コード
```cpp
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

```

## Step2-1 実装
- 所要時間: 15min
- 方針: 141同様、フロイドのサイクル検出アルゴリズム(2ポインタ法)を実装
	- 必ずループの入り口で合流するとは限らないので工夫が必要
	- まず出会うかどうかを確かめて、カメをスタートに戻してウサギとカメを一歩ずつ歩かせればいいらしい
	- 何これ
		- (https://ja.wikipedia.org/wiki/%E3%83%95%E3%83%AD%E3%82%A4%E3%83%89%E3%81%AE%E5%BE%AA%E7%92%B0%E6%A4%9C%E5%87%BA%E6%B3%95)
- コード
```cpp
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
```
- 計算量: O(1)

## Step2-2 リファクタリング
- 所要時間: 5min
```cpp
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
```
- 計算量: O(1)