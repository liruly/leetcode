# 20. Valid Parentheses
- 問題文: [20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/description/)
- 使用言語: C++
- 次に解く問題: [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/description/)

## 知識セット
### 知っていたこと
- stackというデータ構造

### 今回調べたこと
- std::stackの使い方
	- メソッド:
		- push: スタックに追加
		- top: 一番上の値を返す
		- pop: 一番上の値を削除(返り値は無し)
		- empty: 空ならtrue, 入っていたらfalse
		- size: sizeを返す
- 範囲for文の使い方
- std::unordered_mapの使い方

## Step1
- 所要時間: 10min.
- 方針: 
	- 愚直にstackに積んでいって、対応しているかチェック
- コード
```cpp
#include <stack>
#include <iostream>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
                continue;
            } else if ((c == ')' || c == '}' || c == ']') && !st.empty()) {
                const char top = st.top();
                if ((top == '(' && c == ')') || (top == '{' && c == '}') || (top == '[' && c == ']')) {
                    st.pop();
                    continue;
                }
            }
            return false;
        }
        return st.empty();
    }
};
```
- 計算量
	- 時間計算量: O(N)
	- 空間計算量: O(N)

## Step2
- 所要時間: 20min.
- 方針: 
	- 辞書を使って条件文を簡単に
	- ネストを減らす
- コード
```cpp
#include <stack>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;

        std::unordered_map<char, char> match = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };

        for (char c : s) {
            if (match.count(c)) {
                st.push(c);
                continue;
            } else if (!st.empty() && match[st.top()] == c ) {
                st.pop();
                continue;
            }
            return false;
        }
        return st.empty();
    }
};
```
- 計算量
	- 時間計算量: O(N)
		- dictの分は高々定数倍
	- 空間計算量: O(N)
		- dictの文が追加されたとて