#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    map<string, double> m;
    int total = 0;
    while (N--)
    {
        cin.ignore();
        for (string tree; getline(cin, tree);)
        {
            m[tree]++;
            total++;
        }
        for (auto it : m)
        {
            it.second = it.second * 100 / total;
            cout << it.first << " " << it.second << endl;
        }
    }
}