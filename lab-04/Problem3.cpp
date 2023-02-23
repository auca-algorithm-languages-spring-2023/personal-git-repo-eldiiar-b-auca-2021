#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M,t;
    while(true)
    {
        cin >>  N;
        cin >> M;
        if (N == 0 && M == 0)
            break;
        set<int> f;
        set<int> s;
        for (int i = 0; i < N; i++)
        {
            cin >> t;
            f.insert(t);
        }
        for (int i = 0; i < M; i++)
        {
            cin >> t;
            s.insert(t);
        }
        set<int> result;
        set_union(f.begin(), f.end(), s.begin(),s.end(), inserter(result, result.begin()));
        int r = f.size()+s.size()-result.size();
        cout << r << "\n";
    }

}