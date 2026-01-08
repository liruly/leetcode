# 141. Linked List Cycle
- 問題文: [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/description/)
- 使用言語: C++
- 次に解く問題: [142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/description/)

## 知識セット
### 知っていたこと
- 連結リストの実装
- hashmap, setなどのデータ構造
### 今回調べたこと
- cppにおけるhashmap, setなどの利用方法
- フロイドの検出アルゴリズム

## Step1
- 所要時間: 10min.
- 方針: bool型の配列を用意して巡回したところにTRUEを格納していく
	- メモリを必要以上に取ってしまうので断念

## Step2
- 所要時間: 30min.
- 方針: hashmapかsetを利用して巡回済みか確認すればいい
	- setは平衡二分探索木
	- unorderedリストはハッシュテーブル
	- setはソートされていてhashtableは非ソート
	- 今回はソートの必要がないからunorderd_setでよさそう
- コード
```cpp
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
```

## Step3
- 所要時間: 5min
- 方針
	- O(1)の実現のために調べたところ、「フロイドのサイクル検出アルゴリズム(2ポインタ法)」なるものがあると知り、実装
	- slowポインタ(1stepずつ進む)とfastポインタ(2stepずつ進む)を用意して、slow_ptrとfast_ptrが出会ったらループが存在する、対してfastポインタがNULLポインタに到達したらループは存在しない
- コード
```cpp
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
```