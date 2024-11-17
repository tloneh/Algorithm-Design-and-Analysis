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
