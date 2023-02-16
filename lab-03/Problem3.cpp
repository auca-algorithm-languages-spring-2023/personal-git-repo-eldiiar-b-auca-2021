#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    string s, t, r;
    set<string> set;
    string temp;
    bool first = true;
    while (cin >> s)
    {
        for (char ch : s)
        {
            if (isalpha(ch) || ch == '-')
            {
                t += tolower(ch);
                first = true;
            }
            else if (first)
            {
                t += ' ';
                first = false;
            }
        }
        if (t.back() == '-')
            t.pop_back();
        else
        {
            t += ' ';
        }
        r += t;
        t = "";
    }
    vector<string> v;
    string te;
    for (int i = 0; i < r.size(); i++)
    {
        if (r[i] != ' ')
        {
            te += r[i];
        }
        else
        {
            v.push_back(te);
            te = "";
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (isalpha(v[i][0]) || v[i][0] == '-')
            set.insert(v[i]);
    }
    for (auto it = set.begin(); it != set.end(); it++)
    {
        cout << *it << endl;
    }
}