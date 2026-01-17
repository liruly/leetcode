# 703. Kth Largest Element in a Stream
- [Arai60](https://1kohei1.com/leetcode/)
- 問題文: [703. Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/)
- 使用言語: C++
- 次に解く問題: [347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/description/)

## 知識セット
### 知っていたこと
- オブジェクト指向におけるクラスとは何かの概要
	- コンストラクタ
	- インスタンス
	- メンバ変数
	- メンバ関数(メソッド)

### 今回調べたこと
- privateとpublicについて
- thisポインタの使い方
- C++における範囲for文
- C++における初期化子リスト
	- 代入ではなく初期化を行う
	- 効率と、constへの代入が可能なのがメリット

## Step1
- 所要時間: 30min.
- 方針: vectorを毎回sortして[k-1]番目の値を返す
	- TLEしそう
	- TLEしました。そりゃそう。
- コード
```cpp
class KthLargest {
public:
    int k_val;
    std::vector<int> scores;

    KthLargest(int k, std::vector<int>& nums) {
        k_val = k;
        scores = nums;
    }
    
    int add(int val) {
        this->scores.push_back(val);
        std::sort(this->scores.rbegin(), this->scores.rend());
        if (scores.size() < k_val) {
            return -1;
        }
        return scores[this.k_val - 1];
    }
};
```
- 計算量
	- 時間計算量: O(N^2 logN)
		- N回sortで毎回O(N logN)のsort
		- nums.lengthが最大で10^4なのでTLE
		- 大体O(10^9)を超えるとTLEする印象。競プロの話です
	- 空間計算量: O(N)

## Step2
- 所要時間: 10min.
- 方針: priority_queueを使用
	- 要件を読み替えると、上からk件保存して最小の値を返せばいい
	- 最適なデータ構造は、最小値を保持するpriority_queue
		- デフォルトだと最大値を保持するので注意する
	- Google Style Guideに極力準拠してみる
- コード
```cpp
class KthLargest {
public:
    int k_;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap_;

    KthLargest(int k, std::vector<int>& nums) {
        k_ = k;
        for (int n : nums) {
            add(n);
        }
    }
    
    int add(int val) {
        min_heap_.push(val);
        if (min_heap_.size() > k_) {
            min_heap_.pop();
        }
        return min_heap_.top();
    }
};
```
- 計算量
	- 時間計算量: O(N log(N))
		- priority_queueの追加・削除はO(log(N))
	- 空間計算量: O(N)

## Step3
- 所要時間: 15min
- 方針: 
	- 
- コード
```cpp
class KthLargest {
private:
    const int k_;
    std::priority_queue<int, std::vector<int>, std::greater<int>> top_k_;

public:
    KthLargest(int k, vector<int>& nums) : k_(k) {
        for (int n : nums) {
            add(n);
        }
    }
    
    int add(int val) {
        top_k_.push(val);

        if (top_k_.size() > k_) {
            top_k_.pop();
        } else if (top_k_.size() < k_) {
            return -1;
        }

        return top_k_.top();
    }
};
```
- 計算量
	- 時間計算量: O(N log(N))
	- 空間計算量: O(N)