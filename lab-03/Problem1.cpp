#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    while(N--)
    {
        int index = 0, add = 0, get = 0;
        cin >> add;
        cin >> get;
        vector<int> elements(add);
        for (int i = 0; i < add; i++)
        {
            int temp;
            cin >> temp;
            elements[i] = temp;
        }
        map<int, vector<int>> map;
        for (int i = 0; i < add; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                map[i].push_back(elements[j]);
            }
            sort(map[i].begin(), map[i].end());
        }
        for (int i = 0; i < get; i++)
        {
            int temp;
            cin >> temp;
            cout << map[--temp][index++] << endl;
        }
        cout << endl;
    }
}