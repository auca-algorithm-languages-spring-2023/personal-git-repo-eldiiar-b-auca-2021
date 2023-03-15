#include <bits/stdc++.h>
using namespace std;
vector<string> global_s;
void giveResult(set<string> &words, map<string, int> &mpp, map<string, set<string>> &m)
{
    bool printed = true;
    set<string> collector;
    for (auto it : words)
    {
        for (auto it2 : m)
        {
            if (it2.second.find(it) != it2.second.end())
            {
                mpp[it2.first]--;
            }
        }
    }
    for (auto it : mpp)
    {
        if (it.second <= 0)
        {
            collector.insert(it.first);
            printed = false;
        }
    }
    bool first = true;
    for (auto it : global_s)
    {
        auto it2 = collector.find(it);
        if (it2 != end(collector) && !global_s.empty())
        {
            if (first)
            {
                cout << it;
            }
            else
            {
                cout << "," << it;
            }
            first = false;
        }
    }
    if (printed)
    {
        cout << "SQF Problem.";
    }
    cout << endl;
}

int main()
{
    int N;
    cin >> N;
    set<string> st;

    while (N--)
    {
        set<string> words;
        int categories;
        cin >> categories;
        map<string, int> mpp;
        map<string, set<string>> m;

        for (int i = 0; i < categories; i++)
        {
            string nCat;
            cin >> nCat;
            global_s.push_back(nCat);
            int pr, re;
            cin >> pr;
            cin >> re;
            mpp[nCat] = re;
            for (int j = 0; j < pr; j++)
            {
                string s;
                cin >> s;
                m[nCat].insert(s);
            }
        }
        cin.ignore(100, '\n');
        string temp;
        while (getline(cin, temp) && !temp.empty())
        {
            string text;
            transform(temp.begin(), temp.end(), temp.begin(), [](char c)
            { return isalpha(c) ? c : ' '; });
            istringstream ss(temp);
            while (ss >> text)
            {
                words.insert(text);
            }
        }
        giveResult(words, mpp, m);
        global_s.clear();
    }
}
