#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> temp(right - left + 1);
    long long inversions = 0;
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inversions += mid - i + 1; // Count inversions
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (int p = 0; p < k; ++p)
    {
        arr[left + p] = temp[p];
    }

    return inversions % MOD;
}

long long mergeSort(vector<int> &arr, int left, int right)
{
    long long inversions = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        inversions += mergeSort(arr, left, mid);
        inversions += mergeSort(arr, mid + 1, right);
        inversions += merge(arr, left, mid, right);
    }
    return inversions % MOD;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    long long inversions = mergeSort(arr, 0, n - 1);
    cout << inversions << endl;
    return 0;
}