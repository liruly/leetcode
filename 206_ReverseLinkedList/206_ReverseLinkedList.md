# 206. Reverse Linked List
- 問題文: [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/description/)
- 使用言語: C++
- 次に解く問題: [703. Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/)

## 知識セット
### 知っていたこと
- 計算量の概念
- Stackの扱い方
- ポインタの扱い方

### 今回調べたこと
- 

## Step1 Stack
- 所要時間: 10min.
- 方針: Stackに格納して最後に取り出す
	- stackのカテゴリなので一応やってみる
	- 最後のnodeはnextをnullポインタで埋めないといけない
	- for文で要素数を使って実行しようと思ったが、要素数は可変だからうまくいかなかった
- コード
```cpp
#include <stack>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        std::stack<ListNode*> st;
        ListNode *node = head;
        ListNode dummy(0);

        while (node != nullptr) {
            st.push(node);
            node = node->next;
        }
        node = &dummy;
        while (!st.empty()) {
            node->next = st.top();
            st.pop();
            node = node->next;
        }
        node->next = nullptr;
        return dummy.next;
    }
};
```
- 計算量
	- 時間計算量: O(N)
	- 空間計算量: O(N)

## Step2 ポインタ操作
- 所要時間: 20min.
- 方針: ポインタを用いていい感じにreverseする
	- 計算量の観点でも実装のわかりやすさからもこっちが第一選択なように思う
	- ロジックが見えづらくなってしまったのでStep3でリファクタリングする
- コード
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *node = head;
        ListNode *prev = nullptr;
        ListNode *temp = head;

        while (node != nullptr) {
            temp = node->next;
            node->next = prev;
            if (temp == nullptr) {
                break;
            }
            prev = node;
            node = temp;
        }
        return node;
    }
};
```
- 計算量
	- 時間計算量: O(N)
	- 空間計算量: O(1)

## Step3
- 所要時間: min
- 方針: リファクタリング
	- breakは不要で、最後にprevをretすれば足りる
	- tempに避難させてnextを書き換え、prev/nodeを同時に進める
- コード
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *node = head;
        ListNode *prev = nullptr;

        while (node != nullptr) {
            ListNode *temp;
            temp = node->next;
            node->next = prev;
            
            prev = node;
            node = temp;
        }
        return prev;
    }
};
```
- 計算量
	- 時間計算量: O(N)
	- 空間計算量: O(1)
