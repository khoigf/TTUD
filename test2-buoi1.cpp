#include <bits/stdc++.h>
using namespace std;

int n, m, r, c;
int a[1000][1000], visited[1000][1000];

void input()
{
    cin >> n >> m >> r >> c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
}
bool canMove(int r, int c)
{
    if (r >= 0 && r < n && c >= 0 && c < m && a[r][c] == 0 && visited[r][c] == 0)
        return true;
    else
        return false;
}
int BFS(int r, int c)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{r, c}, 1});
    visited[r][c] = 1;

    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        if (row == 0 || row == n - 1 || col == 0 || col == m - 1)
        {
            return steps;
        }

        for (const auto &dir : directions)
        {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            if (canMove(newRow, newCol))
            {
                q.push({{newRow, newCol}, steps + 1});
                visited[newRow][newCol] = 1;
            }
        }
    }

    return -1;
}
int main()
{
    input();
    int kq = BFS(r - 1, c - 1);
    cout << kq;
    return 0;
}