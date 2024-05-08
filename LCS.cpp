#include <bits/stdc++.h>
using namespace std;

int longest_common_subsequence(const string &X, const string &Y)
{
    int m = X.length();
    int n = Y.length();

    // Khởi tạo bảng memoization
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Duyệt qua các hàng và cột để tính toán độ dài của dãy con chung dài nhất
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (X[i - 1] == Y[j - 1] || X[i - 1] == '?' || Y[j - 1] == '?')
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Trả về độ dài của dãy con chung dài nhất
    return dp[m][n];
}

int main()
{
    string X, Y;
    cin >> X >> Y;
    int result = longest_common_subsequence(X, Y);
    cout << result << endl;
    return 0;
}