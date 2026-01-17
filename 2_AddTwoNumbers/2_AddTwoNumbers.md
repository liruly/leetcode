# 2. Add Two Numbers
- [Arai60](https://1kohei1.com/leetcode/)
- 問題文: [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/)
- 使用言語: C++
- 次に解く問題: [20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/description/)

## 知識セット
### 知っていたこと
- 連結リストの扱い方
- boolの扱い方

### 今回調べたこと
- 三項間演算子の使い所
	- constへの代入、単純なA/B選択などで可読性を落とさず使える
- boolのメリットデメリット
	- メリット: 可読性が高い
	- デメリット: 処理のためにif文を介さないといけないため実行速度が落ちる

## Step1
- 所要時間: 30min.
- 方針: returnのための新しい連結リストを作る
	- l1とl2のvalを足し合わせてsumを求める
	- carryUp(繰り上がり)をメモしておいてインクリメント
- コード
```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(0, nullptr);
        ListNode *node = &dummy;

        bool carryUp = false;

        while (l1 != nullptr && l2 != nullptr) {
            node->next = new ListNode(0, nullptr);
            node = node->next;

            int sum = l1->val + l2->val;
            if (carryUp == true) {
                sum++;
            }
            
            if (sum >= 10) {
                carryUp = true;
            } else {
                carryUp = false;
            }

            node->val = sum % 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            node->next = new ListNode(0, nullptr);
            node = node->next;

            int sum = l1->val;
            if (carryUp == true) {
                sum++;
            }
            node->val = sum % 10;
            
            if (sum >= 10) {
                carryUp = true;
            } else {
                carryUp = false;
            }

            l1 = l1->next;
        }
        while (l2 != nullptr) {
            node->next = new ListNode(0, nullptr);
            node = node->next;

            int sum = l2->val;
            if (carryUp == true) {
                sum++;
            }
            node->val = sum % 10;
            
            if (sum >= 10) {
                carryUp = true;
            } else {
                carryUp = false;
            }

            l2 = l2->next;
        }
        if (carryUp == true) {
            node->next = new ListNode(0, nullptr);
            node = node->next;

            node->val = 1;
        }
        return dummy.next;
    }
};
```

## Step2
- 所要時間: 15min.
- 方針: 重複した処理が3つ続いてしまったので関数化もしくは条件分岐で処理
	- 関数化は結局内部で条件分岐が必要だから、あんまり意味ないので条件分岐で実装
	- 三項間演算子を活用
	- constは積極的に使ったほうが可読性高いかも
- コード
```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0, nullptr);
        ListNode *node = &dummy;
        bool carryUp = false;

        while (l1 != nullptr || l2 != nullptr || carryUp == true) {
            const int x = (l1 != nullptr) ? l1->val : 0;
            const int y = (l2 != nullptr) ? l2->val : 0;
            
            int sum = x + y;
            if (carryUp == true) {
                sum++;
            }

            node->next = new ListNode((sum % 10), nullptr);
            node = node->next;
            carryUp = sum >= 10 ? true : false;

            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }
        return dummy.next;
    }
};
```

## Step3 リファクタリング
- 所要時間: 10min
- 方針: 
	- boolではなくintにしてif文を減らす
	- コンストラクタのデフォルト引数を活用する
- コード
```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(0);
        ListNode *node = &dummy;

        int carryUp = 0;

        while (l1 != nullptr || l2 != nullptr || carryUp != 0) {
            const int x = (l1 != nullptr) ? l1->val : 0;
            const int y = (l2 != nullptr) ? l2->val : 0;
            const int sum = x + y + carryUp;

            node->next = new ListNode(sum % 10);
            node = node->next;
            
            carryUp = sum/10;

            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }
        return dummy.next;
    }
};
```
- 計算量
	- 時間計算量: O(N)
	- 空間計算量: O(N)
