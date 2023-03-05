#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    while(N--){
        int n,m=0;
        cin >> n;
        set<int> s;
        vector<int> box(n);
        for (int i = 0; i < n; i++)
        {
            cin >> box[i];
        }
        for (int lP= 0,rP = 0 ; lP < n; )
        {
            while(rP < n && !s.count(box[rP]) )
            {
                s.insert(box[rP++]);
            }
            m = max(m,rP-lP);
            s.erase(box[lP++]);
        }
        cout << m << endl;
    }
}