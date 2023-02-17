#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int c = 1;
    while(N--)
    {

        vector<set<int>> v(3);
        vector<int> people(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> people[i];
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < people[i]; j++){
                int t;
                cin >> t;
                v[i].insert(t);
            }
        }
        vector<int> unique(3);
        vector<int> possessed(3);
        for (int i = 0; i < v.size(); i++)
        {
            int count = 0, count2  = 0;
            int first = 0, second = 0;
            for (auto it = v[i].begin(); it != v[i].end(); it++)
            {
                if (i == 0)
                {
                    first = 1;
                    second = 2;
                }else if(i == 1)
                {
                    first = 2;
                    second = 0;
                }else if(i == 2)
                {
                    first = 0;
                    second = 1;
                }
                auto it1 = v[first].find(*it);
                auto it2 = v[second].find(*it);
                if (it1 == end(v[first]) && it2 == end(v[second]))
                {
                    count++;
                }

            }
            for (auto iter = v[first].begin(); iter != v[first].end(); iter++)
            {
                auto it3 = v[i].find(*iter);
                auto it4 = v[second].find(*iter);
                if (it3 == end(v[i]) && it4 != end(v[second]))
                {
                    count2++;
                }
            }
           int index = 0;
           if (i == 0)
           {
               index = 0;
           }else if (i == 1){
               index = i;
           }else if(i == 2)
           {
               index = 2;
           }
            possessed[index] = count2;
            unique[i] =count;
        }

        cout << "Case #" << c++ <<":" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << unique[i] << " " << possessed[i] << endl;
        }

    }
}