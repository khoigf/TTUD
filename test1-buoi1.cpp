#include <bits/stdc++.h>

using namespace std;

int check = 1;
int stringtotime(const string &time)
{
    int hour = stoi(time.substr(0, 2)),
        minute = stoi(time.substr(3, 2)),
        second = stoi(time.substr(6, 2));
    return hour * 3600 + minute * 60 + second;
}
void checkphone(const string &fphone)
{
    if (fphone.length() != 10)
        check = 0;
    for (char ch : fphone)
    {
        if (!isdigit(ch))
            check = 0;
    }
}
int counttime(const string &ftime, const string &ttime)
{
    int fromtime = stringtotime(ftime);
    int totime = stringtotime(ttime);
    return totime - fromtime;
}
int main()
{
    int totalcall = 0;
    unordered_map<string, int> numcall, timecall;
    string line;
    while (getline(cin, line) && line != "#")
    {
        istringstream is(line);
        string call, fphone, tphone, date, ftime, ttime;
        is >> call >> fphone >> tphone >> date >> ftime >> ttime;
        totalcall++;
        numcall[fphone]++;
        checkphone(fphone);
        checkphone(tphone);
        timecall[fphone] += counttime(ftime, ttime);
    }
    while (cin >> line && line != "#")
    {
        if (line == "?check_phone_number")
        {
            cout << check << endl;
        }
        else if (line == "?number_total_calls")
        {
            cout << totalcall << endl;
        }
        else if (line == "?number_calls_from")
        {
            string phone;
            cin >> phone;
            cout << numcall[phone] << endl;
        }
        else if (line == "?count_time_calls_from")
        {
            string phone;
            cin >> phone;
            cout << timecall[phone] << endl;
        }
    }
    return 0;
}
