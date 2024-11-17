# 算法设计与分析实验报告

姓名：胡舸耀

学号：22336084

## 一、算法实现思想

### 动态规划思路：

1. 定义 `dp[i][j]` 表示字符串从位置 `i` 和 `j` 开始的子串的最长公共后缀长度。
2. 如果 `s[i] == s[j]`，则 `dp[i][j] = dp[i - 1][j - 1] + 1`，表示两个子串从当前位置开始有相同字符，延续前面匹配的长度。
3. 如果 `s[i] != s[j]`，则 `dp[i][j] = 0`。
4. 由于需要找到重复的子串，并且要求这些子串不重叠，所以我们在更新 `dp[i][j]` 时需要确保 `i` 和 `j` 之间的间隔不小于匹配的长度（即 `|i - j| >= dp[i][j]`）

### 解释：

1. **DP 数组：**
   * `dp[i][j]` 表示从 `i` 和 `j` 位置开始的子串的最长公共后缀的长度。
   * 如果 `s[i] == s[j]`，则 `dp[i][j]` 的值会增加（`dp[i - 1][j - 1] + 1`），表示当前字符匹配，且可以延续前面的匹配。
   * 如果 `s[i] != s[j]`，则 `dp[i][j] = 0`，表示两个子串不匹配。
2. **不重叠的条件：**
   * 对于每一对 `i, j`，我们需要确保 `|i - j| >= dp[i][j]`，即子串的长度不会造成重叠。
3. **最终结果：**
   * `maxLen` 保存最大匹配长度，`startIndex` 保存最长重复子串的起始位置。最后通过 `s.substr(startIndex, maxLen)` 提取子串。

### 时间复杂度：

* `dp` 数组是一个二维数组，大小为 `n x n`，所以时间复杂度为 `O(n^2)`，其中 `n` 是字符串的长度。
* 空间复杂度同样是 `O(n^2)`，因为我们需要存储 DP 表。

## 二、实验结果

![1731826514198](image/实验报告/1731826514198.png)

![1731826621252](image/实验报告/1731826621252.png)

![1731826660199](image/实验报告/1731826660199.png)

可以看到可以实现非重叠子串查找

## 三、源代码

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 函数：找到最长的重复非重叠子串
string longestRepeatedSubstring(const string& s) {
    int n = s.size();
    if (n == 0) return ""; // 空字符串直接返回

    // 初始化DP表
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int maxLen = 0;  // 最长子串长度
    int endIndex = 0;  // 记录最长子串的结束位置

    // 填充DP表
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (s[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                // 确保子串不重叠
                if (dp[i][j] > maxLen && (j - i) >= dp[i][j]) {
                    maxLen = dp[i][j];
                    endIndex = i; // 更新最长子串的结束位置
                }
            }
        }
    }

    // 如果没有找到重复子串，返回空字符串
    if (maxLen == 0) return "";

    // 返回最长重复非重叠子串
    return s.substr(endIndex - maxLen, maxLen);
}

int main() {
    string str;
    cout << "请输入字符串: ";
    cin >> str;

    string result = longestRepeatedSubstring(str);

    if (!result.empty()) {
        cout << "最长的重复非重叠子串是: " << result << endl;
    }
    else {
        cout << "没有找到重复的非重叠子串。" << endl;
    }

    return 0;
}
```
