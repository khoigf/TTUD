#include <bits/stdc++.h>
using namespace std;

int n, M;
int a[10];
int dem = 0;

void input()
{
    cin >> n >> M;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void Try(int k, int currentSum)
{
    if (currentSum > M)
        return;

    if (k == n)
    {
        if (currentSum == M)
            dem++;
        return;
    }

    for (int i = 1; i * a[k] + currentSum <= M; i++)
    {
        Try(k + 1, currentSum + i * a[k]);
    }
}

int main()
{
    input();
    Try(0, 0);
    cout << dem << endl;
    return 0;
}
