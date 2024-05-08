#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10;

int H, W, n;
int h[MAX_N], w[MAX_N], x[MAX_N], y[MAX_N], o[MAX_N];
bool mark[11][11];
int dem = 0;

bool check(int vo, int vx, int vy, int k)
{
    int wk = w[k];
    int hk = h[k];
    if (vo == 1)
    {
        swap(wk, hk);
    }
    if (vx + wk > W || vy + hk > H)
        return false;
    for (int i = vx; i < vx + wk; i++)
    {
        for (int j = vy; j < vy + hk; j++)
        {
            if (mark[i][j])
                return false;
        }
    }
    return true;
}

void doMark(int vo, int vx, int vy, int k, bool mark_value)
{
    int wk = w[k];
    int hk = h[k];
    if (vo == 1)
    {
        swap(wk, hk);
    }
    for (int i = vx; i < vx + wk; i++)
    {
        for (int j = vy; j < vy + hk; j++)
        {
            mark[i][j] = mark_value;
        }
    }
}

void Try(int k)
{

    if (k == n)
    {
        cout << 1;
        exit(0);
    }
    for (int vo = 0; vo < 2; vo++)
    {
        int wk = w[k], hk = h[k];
        if (vo == 1)
        {
            swap(wk, hk);
        }
        for (int vx = 0; vx <= W - wk; vx++)
        {
            for (int vy = 0; vy <= H - hk; vy++)
            {
                if (check(vo, vx, vy, k))
                {
                    x[k] = vx;
                    y[k] = vy;
                    o[k] = vo;
                    doMark(vo, vx, vy, k, true);
                    Try(k + 1);
                    doMark(vo, vx, vy, k, false);
                }
            }
        }
    }
}

int main()
{
    cin >> H >> W >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i] >> w[i];
    }
    Try(0);
    cout << 0;
    return 0;
}
