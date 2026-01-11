# 82. Remove Duplicates from Sorted List II
- [Arai60](https://1kohei1.com/leetcode/)
- 問題文: [82. Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)
- 使用言語: C++
- 次に解く問題: [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/)

## 知識セット
### 知っていたこと
- 連結リストのポインタの扱い方
- 再帰の書き方

### 今回調べたこと
- コーナーケースとエッジケースの違い
	- エッジケース: 境界値などを入れたとき
	- エッジケース: 複数のエッジケースや環境が特殊な組み合わせの時
- dummy node(番兵ノード)
- early return
- 実際のプログラミングではdeleteする、したい

## Step1
- 所要時間: 30min.
- 方針: 現在のvalと一個前のポインタを保管し、valの重複があったらskip、変わっていたらポインタからnextを付け替える
	- headが重複している場合のエッジケースの考慮が必要
	- head一つのみのときの処理が必要
	- 実装を試みたもののロジックが複雑になりすぎたので途中で断念
- コード
```cpp
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        
        ListNode *node_head = head;

        if (node_head->next != nullptr && node_head->val == node_head->next->val) {
            while (node_head->next != nullptr && node_head->val == node_head->next->val) {
                node_head = node_head->next;
            }
            node_head = node_head->next;
        }
        if (node_head == nullptr)
            return nullptr;

        ListNode *node = node_head;
        ListNode *node_scanning = node_head->next;

        while (node_scanning != nullptr) {
            if (node->val == node_scanning->val) {
                node_scanning = node_scanning->next;
            } else {
                node = node_scanning;
                node_scanning = node_scanning->next;
            }
        }
    }
```

## Step2
- 所要時間: 20min.
- 方針: ダミーノードを用意することでheadもその後のnodeも同じロジックで扱える
	- 重複がない安全なnodeをポインタとして保存
	- 重複を検知して、その塊を丸ごとskipする
- コード
```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        
        ListNode dummy(0, head);
        ListNode *unique = &dummy;
        ListNode *node = head;

        while (node != nullptr) {
            if (node->next != nullptr && node->val == node->next->val) {
                while (node->next != nullptr && node->val == node->next->val) {
                    node = node->next;
                }
                unique->next = node->next;
            } else {
                unique = unique->next;
            }
            node = node->next;
        }
        return dummy.next;
    }
};
```

## Step3 リファクタリング
- 所要時間: 15min
- 方針: 
	- 重複検知をdupValという変数を介することで意図をわかりやすくした
	- early return を1行にしてみた
	- 最後にnodeを進めるのをそれぞれの処理に分割した
- コード
```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode dummy(0, head);
        ListNode *unique = &dummy;
        ListNode *node = head;

        while (node != nullptr) {
            if (node->next != nullptr && node->val == node->next->val) {
                int dupVal = node->val;
                while (node != nullptr && node->val == dupVal) {
                    node = node->next;
                }
                unique->next = node;
            } else {
                node = node->next;
                unique = unique->next;
            }
        }
        return dummy.next;
    }
};
```

## Step4 再帰
- 所要時間: 15min
- 方針: 再帰を使うとシンプルに書けるらしいので、やってみる
	- ベースケースは最後のnullptr
	- 基本的には固まりごとに処理
		- 重複があれば重複をskipして値が変わったら再帰
		- 重複がなければそこは確定して次から再帰
- コード
```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        if (head->val == head->next->val) {
            while (head->next != nullptr && head->val == head->next->val) {
                head = head->next;
            }
            return deleteDuplicates(head->next);
        } else {
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};
```
