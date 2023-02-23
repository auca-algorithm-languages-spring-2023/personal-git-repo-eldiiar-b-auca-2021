#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int N,M,t;
        cin >> N;
        cin >> M;
        unordered_multiset<int> s1,s2;
        for (int i = 0; i < N; i++)
        {
            cin >> t;
            s1.insert(t);
        }
        for (int i = 0; i < M; i++)
        {
            cin >> t;
            s2.insert(t);
        }
        int count = 0;
        for (auto it : s1)
        {
            auto i = s2.find(it);
            if (i != end(s2))
            {
                count++;
                s2.erase(i);
            }
        }
        int remnant1 = s1.size()-count;
        int remnant2 = s2.size()+remnant1;
        cout << remnant2 << "\n";
    }
}