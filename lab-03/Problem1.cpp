#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    while(N--)
    {
        multiset<int> set;
        int size, cmd;
        cin >> size;
        vector<int> storage(size);
        cin >> cmd;
        for (int i = 0; i < size; i++)
        {
            cin >> storage[i];
        }
        int index = 0, j = 0;

        for (int i = 0; i < cmd; i++)
        {
           int t;
           cin >> t;
           while(j < t)
           {
               set.insert(storage[j++]);
           }
           auto it = set.begin();

           advance(it, index);
           index++;
           cout << *it << endl;
        }
        cout << endl;
    }
}