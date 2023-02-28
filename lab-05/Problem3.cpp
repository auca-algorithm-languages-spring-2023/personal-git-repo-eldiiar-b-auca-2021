#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<pair<string, int>> result;
set<string> control;
void output(map<string, set<string>> &v){
    map<string, set<string>> transmission;
    for (auto it :v)
    {
        if (!it.second.empty() && it.second.size() < 2) {
            transmission[*it.second.begin()].insert(it.first);
        }
    }
    for (auto it : transmission)
    {
        auto it2 = control.find(it.first);
        if (it2 != end(control))
        {
            control.erase(it2);
        }
        result.emplace_back(it.first, it.second.size());
    }
    for (auto it : control)
    {
        result.emplace_back(it, 0);
    }
    sort(result.begin(),result.end(),[](pair<string, int> &f, pair<string, int> &s) {
        if (f.second > s.second){
            return true;
        }else if (f.second == s.second && f.first < s.first)
             return true;
        return false;
    });
    for (auto it : result)
    {
        cout << it.first << " " << it.second << endl;
    }
    control.clear();
    result.clear();
}
int main()
{
    for (string s; getline(cin, s) && s[0] != '0';)
    {
        map<string, set<string>> v;
        string student;
        control.insert(s);
        for (; getline(cin, student) && student[0] != '1';) {
            if (student[0] <= 'z' && student[0] >= 'a') {
                v[student].insert(s);
            }else{
                control.insert(student);
                s = student;
            }
        }
        output(v);
    }
}