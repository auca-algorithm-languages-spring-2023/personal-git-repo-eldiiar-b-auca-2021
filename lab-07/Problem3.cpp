#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    bool first = true;

    while (N--)
    {
        int total = 0;
        map<string, double> m;
        if (first)
            cin.ignore();
        first = false;
        for (string tree; getline(cin, tree) && !tree.empty();)
        {
            m[tree]++;
            total++;
        }
        cout << fixed << setprecision(4);
        for (auto it : m)
        {
            it.second = it.second * 100 / total;
            cout << it.first << " " << it.second << endl;
        }
        if (N != 0)
            cout << endl;
    }
}