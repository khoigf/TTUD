#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;
int m, n;
int course[MAX];
int TCourse[MAX];
vector<vector<int>> listOfTeacher;
vector<vector<int>> listOfPairsOfConflicting;
int theLoadOfTeacher[MAX];
int theLoadMaxOfTeacher = 0;
int minAll = 2147483647;

void input()
{
    cin >> m >> n;
    int k;
    listOfTeacher.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int temp;
            cin >> temp;
            listOfTeacher[temp].push_back(i);
        }
    }
    cin >> k;
    listOfPairsOfConflicting.resize(n + 1);
    for (int i = 0; i < k; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        listOfPairsOfConflicting[temp1].push_back(temp2);
        listOfPairsOfConflicting[temp2].push_back(temp1);
    }
}

bool check(int a, int i)
{
    int tick = 0;
    for (int j = 0; j < listOfTeacher[a].size(); j++)
        if (listOfTeacher[a].at(j) == i)
            tick++;
    if (tick == 0)
        return false;

    for (int j = 0; j < listOfPairsOfConflicting[a].size(); j++)
    {
        if (course[listOfPairsOfConflicting[a].at(j)] == i && listOfPairsOfConflicting[a].at(j) < a)
            return false;
    }
    return true;
}

void solution()
{
    minAll = min(minAll, theLoadMaxOfTeacher);
}

void TRY(int a)
{
    for (int i = 0; i < m; i++)
    {
        if (check(a, i))
        {
            course[a] = i;
            theLoadOfTeacher[i]++;
            int pre = theLoadMaxOfTeacher;
            theLoadMaxOfTeacher = max(theLoadMaxOfTeacher, theLoadOfTeacher[i]);

            if (a == n)
                solution();
            else if (theLoadMaxOfTeacher < minAll)
                TRY(a + 1);

            theLoadOfTeacher[i]--;
            theLoadMaxOfTeacher = pre;
        }
    }
}

int main()
{
    input();
    TRY(1);
    cout << minAll;
    return 0;
}
