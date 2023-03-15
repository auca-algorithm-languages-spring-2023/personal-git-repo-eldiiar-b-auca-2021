#include <bits/stdc++.h>
using namespace std;
set<string> global_s1;
vector<string> global_s;
void giveResult(set<string> &words, map<string, int> &mpp, map<string, set<string>> &m)
{
    map<string, vector<int>> v;
    bool printed = true;
    for (auto it : m)
    {
        vector<string> quantity;

        set_intersection(words.begin(), words.end(), it.second.begin(), it.second.end(), back_inserter(quantity));

        if (mpp[it.first] <= quantity.size())
        {
            printed = false;
            // cout << it.first << " ";
            global_s1.insert(it.first);
        }
    }
    bool first = true;
    for (auto it : global_s)
    {
        auto it2 = global_s1.find(it);
        if (it2 != end(global_s1))
        {
            if (first)
            {
                cout << *it2;
            }
            else
            {
                cout << "," << *it2;
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
        // words.insert("these");
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
        cin.ignore(101, '\n');
        string temp;
        while (getline(cin, temp) && !temp.empty())
        {
           string text;
            for (auto it : temp)
            {
                if ((it <= 'z' && it >= 'a') || (it <= 'Z' && it >= 'A'))
                {
                    text += it;
                }
                else
                {
                    words.insert(text);
                    st.insert(text);
                    text = "";
                }
            }
        }
        giveResult(words, mpp, m);
        global_s.clear();
        global_s1.clear();
    }

    for (auto it : st)
        cout << it << " ";
    //cout << endl;
}
