#include <bits/stdc++.h>

using namespace std;

int find_largest_non_intersecting_subset(vector<pair<int, int>> &segments)
{
    sort(segments.begin(), segments.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });

    int chosen_segments = 0;
    int prev_end = -1;

    for (const auto &segment : segments)
    {
        if (segment.first > prev_end)
        {
            chosen_segments++;
            prev_end = segment.second;
        }
    }

    return chosen_segments;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; i++)
    {
        cin >> segments[i].first >> segments[i].second;
    }

    cout << find_largest_non_intersecting_subset(segments) << endl;

    return 0;
}
