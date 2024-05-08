#include <bits/stdc++.h>
using namespace std;

bool isFeasible(int mid, int arr[], int n, int c)
{
    int pos = arr[0], elements = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            elements++;
            if (elements == c)
                return true;
        }
    }
    return false;
}

int largestMinDist(int arr[], int n, int c)
{
    sort(arr, arr + n);
    int res = -1;
    int left = 1, right = arr[n - 1] - arr[0];

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isFeasible(mid, arr, n, c))
        {
            res = max(res, mid);
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, n, c;
    cin >> T;
    while (T--)
    {
        cin >> n >> c;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << largestMinDist(a, n, c) << endl;
    }
    return 0;
}