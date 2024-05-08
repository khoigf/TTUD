#include <bits/stdc++.h>
using namespace std;

struct khobau
{
    int x, y, c;
};
bool compare(khobau a, khobau b)
{
    return a.x <= b.x;
}

int main()
{
    int n;
    cin >> n;
    khobau kb[n];
    for (int i = 0; i < n; i++)
    {
        cin >> kb[i].x >> kb[i].y >> kb[i].c;
    }
    int gold[n];
    sort(kb, kb + n, compare);
    int maxgold = 0;
    gold[0] = kb[0].c;
    for (int i = 1; i < n; i++)
    {
        gold[i] = kb[i].c;
        for (int j = 0; j < i; j++)
        {
            if (kb[i].y >= kb[j].y)
            {
                gold[i] = max(gold[i], gold[j] + kb[i].c);
                maxgold = max(maxgold, gold[i]);
            }
        }
    }
    cout << maxgold << endl;
    return 0;
}
