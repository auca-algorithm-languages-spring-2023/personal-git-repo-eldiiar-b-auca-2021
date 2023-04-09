#include <bits/stdc++.h>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
vector<int> vect;

bool isPerfectSquare(int f, int s) {

    int res = sqrt(f+s);
    return res*res == f+s;
}

void solve(int &n, int &count)
{
    int i = 0;
    for(; ; i++)
    {
        if (i >= n)
            break;
        if (vect[i] == 0 || isPerfectSquare(vect[i],count))
        {
            vect[i] = count;
            break;
        }
    }
    if (i < n)
    {
        count++;
        solve(n, count);
    }
}

int main()
{
    int testCases;
    cin >> testCases;

    while(testCases--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        vect = v;
        int count = 1;
        solve(n, count);
        cout << count-1 << endl;
    }
}