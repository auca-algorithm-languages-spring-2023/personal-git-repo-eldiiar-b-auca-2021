#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    string n;
    getline(cin, n);
    istringstream is(n);
    int test;
    is >> test;
    bool first = true;
    while (test--)
    {
        set<string> st;
        map<string, int> ve;
        if (first)
            cin.ignore(100, '\n');
        first = false;
        for (string s; getline(cin, s) && !s.empty();)
        {
            st.insert(s);
        }
        bool concat = true;
        for (auto it : st)
        {
            for (auto it2 : st)
            {
                if (it != it2)
                {
                    concat = false;
                    ve[it + it2] += 1;
                }
            }
        }
        int m = 0;
        string result, text = "";
        for (auto it : ve)
        {
            if (it.second > m)
            {
                m = it.second;
            }
        }
        for (auto it : ve)
        {
            if (it.second >= m)
            {
                cout << it.first << endl;
                break;
            }
        }
        if (concat)
        {
            for (auto it : st)
                text += it;
            cout << text + text << endl;
        }
        if (test != 0)
        {
            cout << endl;
        }
    }
}
