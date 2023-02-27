#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool check(set<int>& s, int n)
{
    for (auto it : s)
    {
        if (it != n)
            return true;
    }
    return false;
}
int main()
{

    int N;
    cin >> N;
    cin.ignore();
    while(N--)
    {
        unordered_map<int, set<int>> S, X;
        set<int> s;
        cin.ignore();
        for (char lock; cin >> lock && lock != '#';) {
            int ti, di;
            cin >> ti;
            cin >> di;
            if (lock == 'S') {
                if (s.count(ti)) {
                    cout << "IGNORED" << endl;
                } else if (check(X[di], ti)) {
                    cout << "DENIED" << endl;
                    s.insert(ti);
                } else {
                    cout << "GRANTED" << endl;
                    S[di].insert(ti);
                }
            } else {
                if (s.count(ti)) {
                    cout << "IGNORED" << endl;
                } else if (check(S[di], ti) || check(X[di], ti)) {
                    cout << "DENIED" << endl;
                    s.insert(ti);
                } else {
                    cout << "GRANTED" << endl;
                    X[di].insert(ti);
                }
            }
        }
        if(N != 0)
            cout << endl;
    }

}