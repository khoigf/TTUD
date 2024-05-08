#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000005;
int n, L1, L2;
int a[MAX_N], f[MAX_N];

int ans()
{
    int ans = 0;
    for (int i = 1; i <= n - L1; i++)
    {
        for (int j = i + L1; j <= i + L2 && j <= n; j++)
        {
            f[j] = max(f[j], a[j] + f[i]);
            ans = max(ans, f[j]);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        f[i] = a[i];
    }
    cout << ans();
    return 0;
}

/* Toi uu :
#include <bits/stdc++.h>
using namespace std;


const int MAX_N = 1000005;

int f[MAX_N], a[MAX_N];
int ans = 0;
deque<int> dq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l1, l2;
    cin >> n >> l1 >> l2;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        f[i] = a[i];
    }
    f[0] = 0;
    dq.push_back(1);

    for (int i = l1 + 1; i <= n; i++)
    {
        f[i] = max(f[dq.front()] + a[i], f[i]);
        ans = max(ans, f[i]);
        while ((!dq.empty()) && dq.front() < i - l2)
            dq.pop_front();
        while ((!dq.empty()) && f[i - l1 + 1] >= f[dq.back()])
            dq.pop_back();
        dq.push_back(i - l1 + 1);
    }

    cout << ans;

    return 0;
}*/