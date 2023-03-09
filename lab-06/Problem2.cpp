#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, string> m;
    for (string s; getline(cin, s) && s != "";)
    {
        // cin.ignore();
        istringstream is(s);
        string t, r;
        is >> t;
        is >> r;
        m[r] = t;
    }

    for (string s; cin >> s;)
    {
        if (!m[s].empty())
            cout << m[s] << endl;
        else
            cout << "eh" << endl;
    }
}