#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{

    int N;
    while(cin >> N && N !=0)
    {
        multiset<int> set;

        long long t, b, sum = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> t;
            for (int j = 0; j < t; j++)
            {
                cin >> b;
                set.insert(b);
            }
            auto itB = set.begin();
            auto itE = set.end();
            itE--;
            sum += *itE-*itB;
            set.erase(itB);
            set.erase(itE);
        }
        while(!set.empty())
        {
            itB = set.begin();
            itE = set.end();
            itE--;
            sum += *itE-*itB;
            if (itB == itE)
            {
                break;
            }
            set.erase(itB);
            set.erase(itE);
        }
        cout << sum << "\n";
    }
}