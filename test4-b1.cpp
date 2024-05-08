#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1001][1001];

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
}

int maxhcn()
{
    vector<vector<int>> aux(n, vector<int>(m, 0));

    for (int j = 0; j < m; ++j)
    {
        aux[0][j] = a[0][j];
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 1)
            {
                aux[i][j] = aux[i - 1][j] + 1;
            }
        }
    }

    int maxArea = 0;
    stack<int> s;
    for (int i = 0; i < n; ++i)
    {
        while (!s.empty())
        {
            s.pop();
        }
        for (int j = 0; j < m; ++j)
        {
            while (!s.empty() && aux[i][s.top()] >= aux[i][j])
            {
                int tp = s.top();
                s.pop();
                int width = s.empty() ? j : j - s.top() - 1;
                maxArea = max(maxArea, aux[i][tp] * width);
            }
            s.push(j);
        }
        while (!s.empty())
        {
            int tp = s.top();
            s.pop();
            int width = s.empty() ? m : m - s.top() - 1;
            maxArea = max(maxArea, aux[i][tp] * width);
        }
    }

    return maxArea;
}

int main()
{
    input();
    int kq = maxhcn();
    cout << kq;
    return 0;
}
