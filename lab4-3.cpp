#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
const int MAX_T = 105;

int n, T, d;
int a[MAX_N], t[MAX_N], f[MAX_N][MAX_T];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> T >> d;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = max(i - d, 0); j < i; j++)
        {
            for (int time = 0; time + t[i] <= T; time++)
            {
                f[i][time + t[i]] = max(f[i][time + t[i]], f[j][time] + a[i]);
                ans = max(ans, f[i][time + t[i]]);
            }
        }
    }

    cout << ans;
    return 0;
}