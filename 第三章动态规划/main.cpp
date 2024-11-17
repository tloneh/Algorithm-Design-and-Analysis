#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 函数：找到最长的重复非重叠子串
string longestRepeatedSubstring(const string& s) {
    int n = s.size();
    if (n == 0) return "";

    vector<vector<int>> dp(n, vector<int>(n, 0));  // DP数组初始化为0
    int maxLen = 0;  // 记录最长重复子串的长度
    int startIndex = 0;  // 记录最长重复子串的起始位置

    // 动态规划填充DP表
    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
                // 如果匹配长度超过最大值且满足不重叠条件
                if (dp[i][j] > maxLen && (j - i) >= dp[i][j]) {
                    maxLen = dp[i][j];
                    startIndex = i;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // 如果没有找到重复子串，返回空字符串
    if (maxLen == 0) return "";
    
    // 返回最长重复子串
    return s.substr(startIndex, maxLen);
}

int main() {
    string str1;
    cout<< "enter str:";
    cin>> str1;

    cout << "Longest repeated substring in \"" << str1 << "\": " 
         << longestRepeatedSubstring(str1) << endl;

    return 0;
}
