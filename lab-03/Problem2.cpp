#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int count = 1;
    while(N--)
    {
        int n1, n2;
        cin >> n1;
        cin >> n2;
        cin.ignore();
        vector<string> f(n1);
        vector<string> s(n2);
        set<string> m;
        for (int i = 0; i < n1; i++)
        {
            getline(cin, f[i]);
        }
        for (int i = 0; i < n2; i++)
        {
            getline(cin, s[i]);
        }
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                m.insert(f[i] + s[j]);
            }
        }
        cout << "Case " << count++ << ": " << m.size() << endl;

    }
}