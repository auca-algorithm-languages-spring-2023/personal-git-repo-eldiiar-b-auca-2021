#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int testCases = 1; testCases <= N; testCases++)
    {
        map<int, set<int>> collectorOfInitData;
        map<int, int> collectorOfEquivalents;
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            int stamps, temp;
            cin >> stamps;
            set<int> filter;
            if (stamps == 0)
            {
                collectorOfInitData[i].insert(0);
                //collectorOfEquivalents[i] = 0;
                filter.insert(0);
            }
            for (int j = 1; j <= stamps; j++)
            {
                cin >> temp;
                collectorOfInitData[i].insert(temp);
                filter.insert(temp);
            }
            for (auto &it : filter)
            {
               // cout << it << endl;
                collectorOfEquivalents[it]++;
            }

        }

        for (auto &it1 : collectorOfEquivalents)
        {
            int v = it1.first;
            if (it1.second > 1)
            {
                for (auto &it2 : collectorOfInitData)
                {
                    if (it2.second.find(v) != it2.second.end())
                    {
                        it2.second.erase(v);
                    }
                }
            }
        }
        double totalQuantityOfData = 0;
        for (auto &it : collectorOfInitData)
        {
           totalQuantityOfData +=(double) it.second.size();
        }

        cout << fixed << setprecision(6) << "Case " << testCases << ": ";
        int count = 0;
        for (auto it= collectorOfInitData.begin(); it != collectorOfInitData.end(); it++)
        {
            count++;
            if (totalQuantityOfData != 0 && count != collectorOfInitData.size())
                cout <<(double) it->second.size() * 100.0 / totalQuantityOfData << "% ";
            else
                cout <<(double) it->second.size() * 100.0 / totalQuantityOfData << "%";
        }
        cout << endl;
    }

}